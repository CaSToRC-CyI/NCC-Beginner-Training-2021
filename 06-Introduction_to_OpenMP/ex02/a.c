#include <stdio.h>
#include <omp.h>

int
main()
{
  int some_var = 42;
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int nth = omp_get_num_threads();
    printf("Thread: %2d of %2d, some_var = %d\n", tid, nth, some_var);
  }
  return 0;
}
