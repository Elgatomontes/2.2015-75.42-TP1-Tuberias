#!/bin/bash

# Make task.
echo
echo "********** Make Task start **********"
make clean
make
echo "*********** Make Task end ***********"
echo

# CPPLint task.
echo "********* CPPLint Task start ********"
python ./cpplint.py --extensions=h,hpp,c,cpp --filter=`cat filter_options` `find -regextype posix-egrep -regex '.*\.(h|hpp|c|cpp)'`
echo "********* CPPLint Task start ********"
echo

# Valgrind task.
echo "******** Valgrind Task start ********"
sh execute_valgrind_and_verify_result_code.sh ./tp mediciones.dat tuberias.txt recorrido.txt
#sh execute_valgrind_and_verify_result_code.sh ./tp mediciones tuberias.txt recorrido.txt
#sh execute_valgrind_and_verify_result_code.sh ./tp mediciones inexistente recorrido.txt
echo "******** Valgrind Task start ********"
echo
