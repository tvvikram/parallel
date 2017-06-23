#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main() {

  int size = 10000000;
  double sum = 0;
  struct timeval startTime, endTime;
  double runTime;

 
  gettimeofday(&startTime, NULL);


  for (int n = 0; n < size; n++)
      sum  += n*n*sin(n)*sin(n) +2*n*sin(n) + 3*cos(n);
  
  gettimeofday(&endTime, NULL);

  runTime = (endTime.tv_sec * 1000 + endTime.tv_usec / 1000) -
            (startTime.tv_sec * 1000 + startTime.tv_usec / 1000);
  printf("Without threads\nSum = %.3f\n",sum);
  printf("Time taken: %f\n", runTime);
  return 0;
}
