# fract-ol

Renderizador interativo de fractais (Mandelbrot, Julia e Tricorn) em **C** com **MiniLibX** (Linux/X11). Suporta *zoom* suave com o rato, *pan* com as setas e ajuste dinâmico da qualidade (iterações) — tudo em tempo real.

> Resolução por omissão: **800×800**. Iterações iniciais: **50**. Limites do plano complexos: `[-2, 2]` em ambos os eixos. ([GitHub][1])

---

## Demo rápida

```bash
# Mandelbrot
./fractol mandelbrot

# Julia (constante complexa: parte real e imaginária)
./fractol julia -0.8 0.156

# Tricorn
./fractol tricorn
```

Também podes pedir ajuda pela linha de comandos: `./fractol --help`. ([GitHub][2])

---

## Requisitos

* **Linux com X11** (usa MiniLibX para Linux).
* **MiniLibX (Linux)** incluída no repo sob `minilibx-linux/` (link estático `libmlx_Linux.a`).
* **libft** (biblioteca pessoal da 42): o *Makefile* aponta, por omissão, para `LIBFT_DIR=/home/hroxo/lib` → ajusta para o teu caminho local.
* Bibliotecas do sistema tipicamente necessárias (dependendo da distro): `X11`, `Xext`, `Xrandr`, `Xi`, `Xcursor`, `Xrender`, `Xfixes`, `glfw`, `dl`, `pthread`, `m`. Estas são ligadas via *flags* no *Makefile*. ([GitHub][3])

---

## Compilação

```bash
# Clonar
git clone https://github.com/hroxo/fract-ol.git
cd fract-ol

# (Opcional) ajusta o caminho da libft no Makefile
# LIBFT_DIR=/o/teu/caminho/para/libft

# Compilar
make

# Limpezas
make clean    # remove .o
make fclean   # remove .o e binário
make re       # recompila de raiz
```

O *Makefile* usa `cc` com `-Wall -Wextra -Werror -O3` e liga contra `libft.a` e `minilibx-linux/libmlx_Linux.a`. ([GitHub][3])

---

## Utilização

```bash
./fractol mandelbrot
./fractol julia <real> <imag>
./fractol tricorn
./fractol --help
```

* Se os argumentos forem inválidos, o programa termina com a mensagem:
  `Wrong input use --help to view options`. ([GitHub][2])

---

## Controlos

* **Scroll ↑**: *zoom in* (centra no cursor)
* **Scroll ↓**: *zoom out*
* **Setas**: *pan* (cima/baixo/esquerda/direita)
* **Q**: repõe os limites e iterações iniciais
* **Rato – botão direito**: duplica iterações (mais qualidade)
* **Rato – botão esquerdo**: reduz iterações (mais rápido)
* **ESC** ou **fechar janela**: sair

Estes controlos são geridos em `hook_func.c` e descritos também no *help* embutido. ([GitHub][4])

---

## Fractais suportados

* **Mandelbrot** (`./fractol mandelbrot`)
  Implementado em `ft_mandelbrot`: itera `z ← z² + c` a partir de `z=0` para cada ponto `c`. ([GitHub][5])
* **Julia** (`./fractol julia <re> <im>`)
  Implementado em `ft_julia`: itera `z ← z² + c` fixando `c` nos valores passados na linha de comandos; `z` começa na posição do píxel. ([GitHub][5])
* **Tricorn** (`./fractol tricorn`)
  Variante do Mandelbrot com conjugação: `z ← conj(z)² + c`. No código, a componente imaginária é invertida a cada iteração. ([GitHub][5])

A escolha do fractal em `render_fractol` depende de `fractol->name` e é aplicada a todos os píxeis antes de enviar a imagem para a janela (`mlx_put_image_to_window`). ([GitHub][5])

---

## Como funciona (alto nível)

* **Mapa de coordenadas** – Cada coordenada de píxel `(x,y)` é mapeada para o plano complexo de acordo com os limites atuais (`min`, `max`, *shifts* `x_shift`, `y_shift`). Função: `map_values`. ([GitHub][6])
* **Iteração/escape** – Para cada ponto, itera-se até `iter` vezes ou até `|z|² > esc²` (escape radius). ([GitHub][5])
* **Coloração** – Píxeis que escapam recebem uma cor derivada do número de iterações; os internos recebem um azul escuro (ver `encode_color`). ([GitHub][5])
* ***Double buffering*** – A imagem é desenhada em `img` (buffer) com `my_mlx_pixel_put`, e depois apresentada na janela. ([GitHub][5])

---

## Estrutura do projeto

* `main.c` – *Parsing* dos argumentos, *bootstrap* da janela e *loop* da MLX. ([GitHub][2])
* `init.c` – Inicialização de MLX/janela/imagem e *hooks*; *defaults* de limites/iterações. ([GitHub][7])
* `hook_func.c` – *Handlers* de teclado e rato (zoom, pan, iterações, reset). ([GitHub][4])
* `render.c` – Renderização dos três fractais e *dispatcher* por nome. ([GitHub][5])
* `math.c` – Utilitários de matemática e conversão (`encode_color`, `map_values`, `calc_z`, `atodl`). ([GitHub][6])
* `exit.c` – Limpeza de recursos, mensagens de erro, `--help`. ([GitHub][8])
* `util.h` – *Types*, *defines* (incl. `WIDTH`, `HEIGHT`), *keycodes* e *prototypes*. ([GitHub][1])
* `Makefile` – Compilação e *linking* (MiniLibX + libft + X11/GLFW). ([GitHub][3])

---

## Performance & qualidade

* **Itérações** – A qualidade/tempo de renderização é dominante no número de iterações. Usa *Rato Direito* para aumentar (mais detalhe), *Rato Esquerdo* para reduzir (mais rápido). ([GitHub][4])
* **Zoom centrado** – O *zoom* é recentrado para o cursor ao ajustar `min/max` e *shifts* com base nas coordenadas do rato. ([GitHub][4])
* **Optimizações** – Compila com `-O3`; o *render* escreve píxel a píxel no *buffer* e faz um único *blit* para a janela. ([GitHub][3])

---

## Erros comuns

* **`Wrong input use --help...`** → argumentos inválidos; verifica o comando. ([GitHub][1])
* **Falha a iniciar MLX/janela/imagem** → ver mensagens `perror(...)`; garante que as libs X11/GLFW/MLX estão instaladas e que o `DISPLAY` existe. ([GitHub][8])
* **`libft.a` não encontrada** → ajusta `LIBFT_DIR` no *Makefile* para o caminho correto. ([GitHub][3])

---

## Roadmap / Ideias

* Coloração contínua (gradientes suaves)
* Guardar imagem para ficheiro (BMP/PNG)
* Mais conjuntos (Burning Ship, Multibrot, etc.)
* UI de *overlays* (HUD com iterações/zoom/posições)
