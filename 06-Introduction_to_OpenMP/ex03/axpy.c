#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/***
 * Print usage
 ***/
void
usage(char *argv[])
{
  fprintf(stderr, "usage: %s N\n", argv[0]);
  return;
}

/***
 * Allocate memory; print error if NULL is returned
 ***/
void *
ualloc(size_t size)
{
  void *ptr = malloc(size);
  if(ptr == NULL) {
    fprintf(stderr, "malloc() returned null; quitting...\n");
    exit(-2);
  }
  return ptr;
}

/***
 * Return a random number in [0, 1)
 ***/
double
urand(void)
{
  double x = (double)rand()/(double)RAND_MAX;
  return x;
}

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

int
main(int argc, char *argv[])
{
  /*
   * If number of arguments are not as expected, print usage and exit
   */
  if(argc != 2) {
    usage(argv);
    return 1;
  }

  srand(2147483647);
  unsigned long int n = atol(argv[1]);

  double *x = ualloc(sizeof(double)*n);
  double *y = ualloc(sizeof(double)*n);
  double a = urand();
  for(int i=0; i<n; i++) {
    x[i] = urand();
    y[i] = urand();
  }
    
  double *z_0 = ualloc(sizeof(double)*n);
  double *z_1 = ualloc(sizeof(double)*n);

  double t0 = stop_watch(0);
  for(int i=0; i<n; i++) {
    z_0[i] = a*x[i] + y[i];
  }
  t0 = stop_watch(t0);

  double t1 = stop_watch(0);
  for(int i=0; i<n; i++) {
    z_1[i] = a*x[i] + y[i];
  }
  t1 = stop_watch(t1);

  /*
   * Don't need arrays x and y anymore
   */
  free(x);
  free(y);

  /*
   * Print ||z_0[] - z_1[]|| to stdout
   */
  double norm = 0;
  for(int i=0; i<n; i++) {
    double r = (z_0[i] - z_1[i]);
    norm = r*r;
  }

  printf(" t0 = %lf sec, t1 = %lf sec, diff z norm = %e\n", t0, t1, norm);

  free(z_0);
  free(z_1);
  return 0;
}
