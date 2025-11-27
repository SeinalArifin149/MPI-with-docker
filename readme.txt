How to run in docker?
First u need Docker(windows?install docker desktop,linux?install docker engine)


sudo docker compose exec master bash
mpicc main.c -o program_mpi
mpirun --allow-run-as-root --host master,worker -np 2 ./program_mpi