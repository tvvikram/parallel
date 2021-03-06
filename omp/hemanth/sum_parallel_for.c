#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include<string.h> 
#include <math.h> 
#include "omp.h"

void main(int argc, char *argv[]){
	int i,id,th,N;
	int x=atoi(getenv("OMP_NUM_THREADS"));
	if(argc>1){
		N=atoi(argv[1]);
	}
	else
		N=101;
	double s=0,sum[x];
	memset(sum, 0, sizeof(double)  * x);
	int *num=(int*)malloc(N*sizeof(int));
	struct timeval t1, t2;
    	double elapsedTime;
	
	for(i=0;i<N; i++)
  		num[i]=i;
 	
	//start of parallel region
	gettimeofday(&t1, NULL);
	#pragma omp parallel shared(num,sum) private(id)
 	{ 
 		int j;
 		th=omp_get_num_threads();
 		#pragma omp for  private(j)
 			for(j=0; j<N; j++){
 				id=omp_get_thread_num();
  				sum[id]+=num[j]+0*(sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i)+sin(i)+cos(i));	
 			}
 	}
 	//end of parallel region	
 	for(i=0;i<th;i++)
 		s+=sum[i];
 		
 	gettimeofday(&t2, NULL);
 	elapsedTime = (t2.tv_sec * 1000 +t2.tv_usec /1000) - (t1.tv_sec *1000 + t1.tv_usec /1000) ;
	printf("%d %.3lf \n",th,elapsedTime);
}
