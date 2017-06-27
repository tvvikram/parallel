#!/bin/sh
file=`basename -s .c $1`
#echo $file
cc -fopenmp $1 -lm
NUM='1 2 3 4 5 6 7 8 9'
for i in $NUM
do
export OMP_NUM_THREADS=$i
./a.out 10000001 >> $file-T.dat 
done
