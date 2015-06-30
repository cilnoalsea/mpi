#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>   
#include "mpi.h"

int main(int argc, char **argv){
int n, myid, numprocs, i;
double mypi, pi, h, sum, x, time;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&myid);
if (myid == 0) {
fflush(stdout); scanf("%d",&n);
time = MPI_Wtime();
}
MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
h = 1.0 / (double) n;
sum = 0.0;
for (i = myid + 1; i <= n; i += numprocs) {
	x = h * ((double)i - 0.5);
	sum += 4.0 / (1.0 + x*x);
}
mypi = h * sum;
MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,
MPI_COMM_WORLD);
if (myid == 0) {
time = MPI_Wtime() - time;
printf("pi is approximately %.16f, Run time is %fs\n",
pi, time);
}
MPI_Finalize();
}

