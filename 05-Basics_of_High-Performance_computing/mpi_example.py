
from mpi4py import MPI

comm = MPI.COMM_WORLD

print(f"Hello from rank {comm.rank}/{comm.size}")
