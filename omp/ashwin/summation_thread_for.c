#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <math.h>
//#define thread_num 4

void main(int argc,char *argv[])
{
	if(argc==1)return;
	int N;
	N=atoi(argv[1]);
	struct timeval startTime,endTime;
	double runTime;
	long long *sum;
	sum=(long long *)malloc(300*sizeof(long long)); 
	long  s=0;
	int i=0;

	
	//int num=omp_get_num_threads();
	//int id=omp_get_thread_num();
	int n=0;
	gettimeofday(&startTime,NULL);
	#pragma omp parallel for 	private(i) 
		for(i=0;i<N;i++){
			n=omp_get_num_threads();
			int id=omp_get_thread_num();
			sum[id]+=i*i+sin(i)+pow(cos(i),10)-i+sin(i)-cos(i)+sin(i)-cos(i);
			//printf("id-%d num-%d\n",id,n);
			//printf("%lld <-sum and i*i-> %d \n",sum[id],i*i);
			//printf("%lld  %d\n",sum[id],omp_get_thread_num());
		}

	gettimeofday(&endTime,NULL);
	runTime=(endTime.tv_sec * 1000 + endTime.tv_usec/1000)-
	(startTime.tv_sec * 1000 + startTime.tv_usec/1000);

		printf("%d %f\n",n,runTime);

	for(i=1;i<n;i++){
		sum[0]+=sum[i];
	}
	//printf("\nTime is:%f \nSum %lld\n",runTime,sum[0]);
}