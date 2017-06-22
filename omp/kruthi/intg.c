#include <stdio.h>
#include "omp.h"

void main()
{
	int i,sum,n;
	for(i=0;i<n;i++)
		sum += i*i + 2*i + 3;
	printf("Sum = %d\n",sum);
}
