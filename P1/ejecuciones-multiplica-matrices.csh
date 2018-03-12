#!/bin/csh
@ inicio = 100
@ fin = 10000
@ incremento = 100
set salida = tiempos_multiplicacion.dat

@ i = $inicio
echo > salida
while ($i <= $fin)
    echo Ejecucion tam = $i
    echo `./multiplica-matrices $i 10000` >> $salida
    @ i += $incremento
end
