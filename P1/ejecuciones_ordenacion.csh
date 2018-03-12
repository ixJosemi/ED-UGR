#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set salida = tiempos_ordenacion.dat

@ i = $inicio
echo > salida
while ($i <= $fin)
    echo Ejecucion tam = $i
    echo `./ordenacion $i 30000` >> $salida
    @ i += $incremento
end
