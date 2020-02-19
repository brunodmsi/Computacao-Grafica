# Desenhar Linha
Esta aplicação feita em C usando a biblioteca open-source OpenGL, faz com que seja possível desenhar uma única linha com o usuário dando os pontos para desenhar uma linha entre eles.

## Como usar?
Você precisa instalar OpenGL e o GLUT (este método é para você que usa um derivado de Debian)
```
sudo apt-get install freeglut3-dev
```
Depois disto você pode rodar o programa usando `./LineDrawer` ou compilando usando `gcc -o LineDrawer LineProgram.c -lglut -lGL -lGLU -lm` e depois rodar.   