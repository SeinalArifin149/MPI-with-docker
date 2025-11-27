#include <mpi.h>
#include <studio.h>

int main(int argc,char** argv) {
    MPI_init(Null, Null);
    int rank, size, len ;
    char hostname[256];

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_processor_name(MPI_COMM_WORLD, &len);

    printf("Halo Linux ! this process rank %d from total %d in host %s\n",rank, size, hostname):
    
    MPI_Finalize()

}