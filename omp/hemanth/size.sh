#!/bin/bash
if [ $# -lt 4 ] 
then 
echo -e "please provide 4 arguments \nsyntax: ./script.sh filename start end steps" 
exit 1
fi
export OMP_NUM_THREADS=4
file=`basename -s .c $1`
start= $2
end= $3
steps=$4
cc -fopenmp $1 -lm
for (( i=  star ; i <= end ; i +=steps ))
do
./a.out $i >> $file.dat 
done
