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
sh execute_valgrind_and_verify_result_code.sh ./tp mediciones.dat tuberias.txt recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la primer prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la primer prueba."

sh execute_valgrind_and_verify_result_code.sh ./tp mediciones tuberias.txt recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la segunda prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la segunda prueba."

sh execute_valgrind_and_verify_result_code.sh ./tp mediciones inexistente recorrido.txt
# Check if Valgrind succeeded.
if [ $? != 0 ]
then
	echo "Error al correr el comando 'Valgrind' en la tercera prueba."
	return
fi
echo "El comando 'Valgrind' se ejecutó correctamente en la tercera prueba."

echo "*************************** Valgrind Task end ***************************"
echo
