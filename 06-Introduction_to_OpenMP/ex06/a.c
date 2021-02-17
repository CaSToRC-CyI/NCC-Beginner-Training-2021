#include <stdio.h>
#include <omp.h>

int
main()
{
  #pragma omp parallel
  {
    #pragma omp single
    {
      printf("one ");
      printf("two ");
      printf("three ");
    }
  }
  printf("\n");
  return 0;
}
