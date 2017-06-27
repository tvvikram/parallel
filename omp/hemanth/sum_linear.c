#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h> 
#include <math.h> 
void main(int argc, char * argv[]){
	int j,N;
	double s=0;
	double z;
	if(argc!=0){
		N=atoi(argv[1]);
	}
	else
		N=10000001;
	int *num=(int*)malloc(N*sizeof(int));
	struct timeval t1, t2;
    	double elapsedTime;
	
	for(j=0;j<N;j++)
  		num[j]=j;
  		
  	gettimeofday(&t1, NULL);
 	for(j=0;j<N;j++)
 		s+=num[j]+0*(sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j)+sin(j)+cos(j));
 	gettimeofday(&t2, NULL);
 	elapsedTime = (t2.tv_sec * 1000 +t2.tv_usec /1000) - (t1.tv_sec *1000 + t1.tv_usec /1000) ;
 	printf("%d %.3lf \n",N,elapsedTime);
}
