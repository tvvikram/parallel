#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <math.h>
#define thread_num 4
#define N 100000000
void main()
{
	struct timeval startTime,endTime;
	double runTime;
	int i;
	long long sum[thread_num]={0,0,0,0}; 
	long long s=0;
	gettimeofday(&startTime,NULL);
	#pragma omp parallel 
	{
		int i=0;
		int num=omp_get_num_threads();
		int id=omp_get_thread_num();
		for(i=id;i<N;i+=num){
					sum[id]+=i*i+sin(i)+cos(i)-i+sin(i)-cos(i);
		}
		#pragma omp critical
			s+=sum[id];
	}		
	
	

	gettimeofday(&endTime,NULL);
	runTime=(endTime.tv_sec * 1000 + endTime.tv_usec/1000)-
	(startTime.tv_sec * 1000 + startTime.tv_usec/1000);
	
	printf("\nTime is:%f \nSum %lld\n",runTime,s);
}