#!/bin/sh
export OMP_NUM_THREADS=4
file=`basename -s .c $1`
#echo $file
cc -fopenmp $1 -lm
NUM='1000000 2000000 3000000 4000000 5000000'
for i in $NUM
do
./a.out $i >> $file.dat 
done
