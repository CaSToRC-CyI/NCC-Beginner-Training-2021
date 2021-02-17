
void axpy(double*z, double*x, double *y, double a,int n)
{
 for (int i=0;i<n;i++)
	z[i]=a*x[i]+y[i];
}
