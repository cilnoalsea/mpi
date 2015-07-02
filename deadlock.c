#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>   
#include "mpi.h"

int main (int argc, char **argv)
	{
		int myid, numprocs, pinkie_pie=0, fluttershy, twilight_sparkle;
		MPI_Init(&argc,&argv);
		MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
		MPI_Comm_rank(MPI_COMM_WORLD,&myid);
		MPI_Send(&twilight_sparkle, 1, MPI_INT, 1, 1000, MPI_COMM_WORLD);
		MPI_Send(&fluttershy, 1, MPI_INT, 0, 1000, MPI_COMM_WORLD);
		MPI_Recv(&twilight_sparkle, 1, MPI_INT, 0, 2000, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(&fluttershy, 1, MPI_INT, 1, 2000, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Finalize();
		
	}
