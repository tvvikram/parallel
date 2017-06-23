#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "omp.h"

int size = 10000000;
double sum[4] = {0,0,0,0};
int main() {
  double sum1 = 0;
  struct timeval startTime, endTime;
  double runTime;

 
  gettimeofday(&startTime, NULL);

  #pragma omp parallel
  {
	   int n,id = omp_get_thread_num();
    for ( n = id; n < size; n+=omp_get_num_threads())
      		sum[id]  += n*n*sin(n)*sin(n) +2*n*sin(n) + 3*cos(n);
  }

  for(int i=0; i<4; i++)
    sum1 += sum[i];
  gettimeofday(&endTime, NULL);

  runTime = (endTime.tv_sec * 1000 + endTime.tv_usec / 1000) -
            (startTime.tv_sec * 1000 + startTime.tv_usec / 1000);
  printf("sum = %.3f\n",sum1);
  printf("time taken: %f\n", runTime);
  return 0;
}
