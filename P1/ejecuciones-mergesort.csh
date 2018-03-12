#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 100
set salida = tiempos_mergesort.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./mergesort $i` >> $salida
  @ i += $incremento
end
