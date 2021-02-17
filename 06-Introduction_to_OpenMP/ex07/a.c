#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 10

/***
 * Return seconds elapsed since t0, with t0 = 0 the epoch
 ***/
double
stop_watch(double t0)
{
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec/1e6 - t0;
}

/***
 * Return a random number in [0, 100000000)
 ***/
int
irand(void)
{
  int r = rand() % 100000000;
  return r;
}

/***
 * Do $\sum_{i=0}^{x-1} i$ and set to x
 ***/
void
process(int *x)
{
  int sum = 0;
  for(int i=0; i<*x; i++) {
    sum += i;
  }
  *x = sum;
  return;
}

int
main()
{
  srand(2147483641);
  int a[N];
  for(int i=0; i<N-1; i++)
    a[i] = irand();
  
  a[N-1] = -1;

  double t0 = stop_watch(0);
  int *p = &a[0];
  while(*p >= 0) {
    process(p);
    p = p+1;
  }
  t0 = stop_watch(t0);

  printf(" t = %lf\n", t0);
  return 0;
}
