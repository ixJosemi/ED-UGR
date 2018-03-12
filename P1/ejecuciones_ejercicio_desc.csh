#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set salida = tiemps_ejercicio_desc.dat

@ i = $inicio
echo > salida
while ($i <= $fin)
    echo Ejecucion tam = $i
    echo `./ejercicio_desc $i` >> $salida
    @ i += $incremento
end
