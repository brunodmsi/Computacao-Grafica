# Rasterização de Linha
Esta aplicação feita em C usando a biblioteca open-source OpenGL, nela se vê a rasterização, que é a tarefa de converter uma imagem vetorial (curvas funcionais) em uma imagem raster (pixels ou pontos) para a possível leitura do documento. Neste caso é usado uma linha com input do próprio usuário pelo mouse

## Como usar?
Você precisa instalar OpenGL e o GLUT (este método é para você que usa um derivado de Debian)
```
sudo apt-get install freeglut3-dev
```
Depois disto você pode rodar o programa usando `./main` ou compilando usando `gcc -o main main.c -lglut -lGL -lGLU -lm` e depois rodar.   

## Feito por
- [Bruno De Masi](https://github.com/brunodmsi)
- [João Tomé](https://github.com/joaotf)
