#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>   
#include "mpi.h"

int main (int argc, char **argv)
	{
		int i, j, myid, numprocs, pinkie_pie, apple_jack;
		MPI_Init(&argc,&argv);
		MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
		MPI_Comm_rank(MPI_COMM_WORLD,&myid);
		for(i=0; i<numprocs; i++)
			{
				j=(i+1)%numprocs;
				if(myid==i)
					MPI_Sendrecv(&pinkie_pie, 1, MPI_INT, j, 42, &apple_jack, 1, 
							MPI_INT, i, 42, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			}
		MPI_Finalize();
	}
