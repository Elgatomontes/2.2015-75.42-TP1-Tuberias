#!/bin/bash

# Make task.
echo "**************************** Make Task start ****************************"

make clean
make

# Check if make succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Make'."
  	return
fi
echo "El comando 'Make' se ejecutó correctamente."

echo "***************************** Make Task end *****************************"

# CPPLint task.
echo "************************** CPPLint Task start ***************************"

python ./cpplint.py --extensions=h,hpp,c,cpp --filter=`cat filter_options` `find -regextype posix-egrep -regex '.*\.(h|hpp|c|cpp)'`

# Check if CPPlint succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'CPPLint'."
	return
fi
echo "El comando 'CPPLint' se ejecutó correctamente."

echo "*************************** CPPLint Task end ****************************"

# Valgrind task.
echo "************************** Valgrind Task start **************************"
sh execute_valgrind_and_verify_result_code.sh ./tp 1/mediciones.dat 1/tuberias.txt 1/recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la primer prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la primer prueba."

sh execute_valgrind_and_verify_result_code.sh ./tp 2/mediciones 2/tuberias.txt 2/recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la segunda prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la segunda prueba."

sh execute_valgrind_and_verify_result_code.sh ./tp 3/mediciones.dat 3/tuberias.txt 3/recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la tercera prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la tercera prueba."

sh execute_valgrind_and_verify_result_code.sh ./tp 4/mediciones.dat 4/tuberias.txt 4/recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la cuarta prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la cuarta prueba."

sh execute_valgrind_and_verify_result_code.sh ./tp 5/mediciones 5/tuberias.txt 5/recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la quinta prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la quinta prueba."

sh execute_valgrind_and_verify_result_code.sh ./tp 6/mediciones 6/inexistente 6/recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la sexta prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la sexta prueba."

echo "*************************** Valgrind Task end ***************************"
# Run task.
echo "**************************** Run Task start *****************************"
./tp 1/mediciones.dat 1/tuberias.txt 1/recorrido.txt
# Check if Run succeeded.
if [ $? != 0 ]
then
	echo "La salida de la prueba uno dió ERROR."
	return
fi
echo "Prueba uno superada sin errores."

./tp 2/mediciones 2/tuberias.txt 2/recorrido.txt
# Check if Run succeeded.
if [ $? != 0 ]
then
	echo "La salida de la prueba dos dió ERROR."
	return
fi
echo "Prueba dos superada sin errores."

./tp 3/mediciones.dat 3/tuberias.txt 3/recorrido.txt
# Check if Run succeeded.
if [ $? != 0 ]
then
	echo "La salida de la prueba tres dió ERROR."
	return
fi
echo "Prueba tres superada sin errores."

./tp 4/mediciones.dat 4/tuberias.txt 4/recorrido.txt
# Check if Run succeeded.
if [ $? != 0 ]
then
	echo "La salida de la prueba cuatro dió ERROR."
	return
fi
echo "Prueba cuatro superada sin errores."

./tp 5/mediciones 5/tuberias.txt 5/recorrido.txt
# Check if Run succeeded.
if [ $? != 0 ]
then
	echo "La salida de la prueba cinco dió ERROR."
	return
fi
echo "Prueba cinco superada sin errores."

./tp 6/mediciones 6/inexistente 6/recorrido.txt
# Check if Run succeeded.
if [ $? != 0 ]
then
	echo "La salida de la prueba seis dió ERROR."
	return
fi
echo "Prueba seis superada sin errores."

echo "***************************** Run Task end ******************************"
echo
