#!/bin/bash
#SBATCH --job-name=ex08
#SBATCH --nodes=1 # 1 nodes
#SBATCH --ntasks-per-node=10 # Number of OpenMP tasks to be invoked on each node
#SBATCH --time=00:02:00 # Run time in hh:mm:ss
#SBATCH --error=ex08.err
#SBATCH --output=ex08.out

echo "Starting at `date`"
echo "Running on hosts: $SLURM_NODELIST"
echo "Running on $SLURM_NNODES nodes."
echo "Running on $SLURM_NPROCS processors."
echo "Job id is $SLURM_JOBID"

./axpy  $((1024*1024*32))

echo "Program finished with exit code $? at: `date`"
