#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int size = 100000000;
int main() {
  double *sinTable;
  struct timeval startTime, endTime;
  double runTime;

  sinTable = (double *)malloc(sizeof(double) * size);
  gettimeofday(&startTime, NULL);

#ifdef OMP
#pragma omp parallel for
#endif
  for (int n = 0; n < size; ++n)
    sinTable[n] = std::sin(n / size);
  gettimeofday(&endTime, NULL);

  runTime = (endTime.tv_sec * 1000 + endTime.tv_usec / 1000) -
            (startTime.tv_sec * 1000 + startTime.tv_usec / 1000);
  printf("rt: %f\n", runTime);
  return 0;
}
