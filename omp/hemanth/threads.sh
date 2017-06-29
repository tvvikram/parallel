#!/bin/bash
if [ $# -lt 4 ] 
then 
echo -e "please provide 3 arguments \nsyntax: ./script.sh filename start end " 
exit 1
fi
file=`basename -s .c $1`
start=$2
end=$3
cc -fopenmp $1 -lm
for (( i=start; i <= end; i++ ))
do
export OMP_NUM_THREADS=$i
./a.out 10000001 >> $file-T.dat 
done
