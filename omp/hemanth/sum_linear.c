#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h> 
#include <math.h> 
#define N 10000001
void main(int argc, char * argv[]){
	int j;
	double s=0;
	double z;
	int *num=(int*)malloc(N*sizeof(int));
	struct timeval t1, t2;
    	double elapsedTime;
	
	for(j=0;j<N;j++)
  		num[j]=j;
  		
  	//start linear computation	
  	gettimeofday(&t1, NULL);
 	for(j=0;j<N;j++)
 		s+=num[j]+0*(sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j));
 	gettimeofday(&t2, NULL);
 	//end linear computation
 	
 	printf("\nsum is is:%lf\n",s);
 	
 	elapsedTime = (t2.tv_sec * 1000 +t2.tv_usec /1000) - (t1.tv_sec *1000 + t1.tv_usec /1000) ;
 	printf("time consumed %f\n",elapsedTime);
}
