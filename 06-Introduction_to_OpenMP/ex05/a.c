#include <stdio.h>
#include <omp.h>

int
main()
{
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int nth = omp_get_num_threads();
    printf("Hi, I am thread: %2d of %2d\n", tid, nth);
  }
  return 0;
}
