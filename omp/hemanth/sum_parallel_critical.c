#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include<string.h> 
#include <math.h> 
#include "omp.h"
#define N 10000001
void main(int argc, char *argv[]){
	int i,id,th;
	int x=atoi(getenv("OMP_NUM_THREADS"));
	double s=0,sum[x];
	memset(sum, 0, sizeof(int) * x);
	int *num=(int*)malloc(N*sizeof(int));
	struct timeval t1, t2;
    	double elapsedTime;
    	
	
	for(i=0;i<N; i++)
  		num[i]=i;
 	
 	gettimeofday(&t1, NULL);
 	//start of parallel region
 	#pragma omp parallel 
 	{ 
 		int j;
 		th=omp_get_num_threads();
 		id=omp_get_thread_num();
 		for(j=id; j<N; j+=th){			
  				sum[omp_get_thread_num()]+=num[j]+0*(sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i));	
 		}
 		//critial section
 		#pragma omp critical
 		s+=sum[omp_get_thread_num()];
 	}
 	//end of paralle region
 	gettimeofday(&t2, NULL);
 	
 	printf("\nsum  is:%lf\n",s);
 	elapsedTime = (t2.tv_sec * 1000 +t2.tv_usec /1000) - (t1.tv_sec *1000 + t1.tv_usec /1000) ;
 	printf("time consumed %f\n",elapsedTime);
}
