#!/bin/csh 
@ inicio = 4
@ fin = 1000000

alias MATH 'set \!:1 = `echo "\!:3-$" | bc -l`' 
set ejecutable = ejercicio3
set salida = tiempos_busqueda.dat
@ factor = 1
@ i = $inicio

echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
   
   MATH ff = $factor*2
   if ($ff >= 32) then
    @ ff = 16
   endif 
   MATH  nuevo = $i*$ff
   @ factor = $ff
   echo $nuevo
   @ i = $nuevo 
   
end
