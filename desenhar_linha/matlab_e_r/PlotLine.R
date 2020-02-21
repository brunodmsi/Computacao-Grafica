PlotLine <- function()
{ 
  x1 <- readline(prompt="Entre com o X1 => ")
  x2 <- readline(prompt="Entre com o X2 => ")
  y1 <- readline(prompt="Entre com o Y1 => ")
  y2 <- readline(prompt="Entre com o Y2 => ")
  
  Eixo_X = c(x1,x2)
  Eixo_Y = c(y1,y2)
  plot(Eixo_X,Eixo_Y,type="l",lty=1)
}

print(PlotLine())