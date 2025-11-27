#include <mpi.h>
#include <stdio.h>  // INGAT: stdio.h (bukan studio)

int main(int argc, char** argv) {
    // FIX 1: MPI_Init (I besar), NULL (Huruf besar semua)
    MPI_Init(NULL, NULL);

    int rank, size, len;
    char hostname[256];

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // FIX 2: Nama fungsi yang benar MPI_Get_processor_name
    // Masukkan variabel 'hostname', bukan 'MPI_COMM_WORLD'
    MPI_Get_processor_name(hostname, &len);

    // FIX 3: Akhiri dengan titik koma (;), bukan titik dua (:)
    printf("Halo Linux! Ini proses rank %d dari total %d di host %s\n", rank, size, hostname);

    MPI_Finalize();
    return 0;
}