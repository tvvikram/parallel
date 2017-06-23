#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define N 300000000
void main()
{
	int i;
	long long sum=0; 
	struct timeval startTime,endTime;
	double runTime;
	gettimeofday(&startTime,NULL);
	for(i=0;i<N;i++){
			sum+=i*i+sin(i)+cos(i);//-i+sin(i)-cos(i);
	}
	gettimeofday(&endTime,NULL);
	runTime=(endTime.tv_sec * 1000 + endTime.tv_usec/1000)-
	(startTime.tv_sec * 1000 + startTime.tv_usec/1000);
	
	printf("\nTime is:%f \nSum %lld\n",runTime,sum);
	//printf("%d\n",sum);
}