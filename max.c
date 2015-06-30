#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>   
#include "mpi.h"

unsigned int n=10;

int main(int argc, char **argv)
	{
		double temps;
		srand(time(NULL));
		int unsigned seele[n];
		int i;
		int myid, numprocs;
		int unsigned max_local=0;
		int unsigned max_global;
		for(i=0;i<=n;i++) 
			seele[i]=rand();
		printf("seele = %d ou %d\n", seele[0], seele[n]);
		MPI_Init(&argc,&argv);
		MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
		MPI_Comm_rank(MPI_COMM_WORLD,&myid);
		if (myid==0)
			temps = MPI_Wtime();
		MPI_Bcast(seele, n, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
		for (i=0; i<n; i+=numprocs)
			if (max_local<seele[i])
				max_local=seele[i];
		MPI_Reduce(&max_local, &max_global, n, MPI_UNSIGNED, MPI_MAX, 0,MPI_COMM_WORLD);
		if (myid==0)
			temps = MPI_Wtime() - temps;
		MPI_Finalize();
		printf("MAX= %d\nRun time is %fs\n", max_global, temps);
		return 0;
	}
