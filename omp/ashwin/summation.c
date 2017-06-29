#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>
#include <string.h>
void main(int argc,char *argv[])
{
	if(argc==1)return;
	int N;
	N=atoi(argv[1]);
	int i;
	long long sum=0; 
	struct timeval startTime,endTime;
	double runTime;
	
	FILE *fp;
	fp=fopen("timeLoop.txt","a");

	gettimeofday(&startTime,NULL);
	for(i=0;i<N;i++){
			sum+=i*i+sin(i)+pow(cos(i),10)-i+sin(i)-cos(i)+sin(i)-cos(i);
	}
	gettimeofday(&endTime,NULL);
	runTime=(endTime.tv_sec * 1000 + endTime.tv_usec/1000)-
	(startTime.tv_sec * 1000 + startTime.tv_usec/1000);
	
	fprintf(fp,"%d %f\n",N,runTime);


	close(fp);

	printf("\nTime is:%f \nSum %lld\n",runTime,sum);
	//printf("%d\n",sum);
}