#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <math.h>
void main(int argc,char *argv[])
{
	if(argc==1)return;
	int N;
	N=atoi(argv[1]);
	struct timeval startTime,endTime;
	double runTime;
	int i,n;
	long long *sum=(long long *)malloc(300*300*sizeof(long long));   
	long long s=0;

	gettimeofday(&startTime,NULL);
	#pragma omp parallel 
	{
		
		int i=0;
		int num=omp_get_num_threads();
		n=num;
		int id=omp_get_thread_num();
		//printf("%d\n",num);
		for(i=id;i<N;i+=num){
					*(sum+300*id+id)+=i*i+sin(i)+pow(cos(i),10)-i+sin(i)-cos(i)+sin(i)-cos(i);
		}
		#pragma omp critical
			s+=*(sum+300*id+id);
	}		
	
	

	gettimeofday(&endTime,NULL);
	runTime=(endTime.tv_sec * 1000 + endTime.tv_usec/1000)-
	(startTime.tv_sec * 1000 + startTime.tv_usec/1000);
	
	printf("%d %f\n",n,runTime);
	//printf("\nTime is:%f \nSum %lld\n",runTime,s);
}