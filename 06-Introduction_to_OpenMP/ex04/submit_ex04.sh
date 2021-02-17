#!/bin/bash
#SBATCH --job-name=ex04
#SBATCH --nodes=1 # 1 nodes
#SBATCH --ntasks-per-node=10 # Number of OpenMP tasks to be invoked on each node
#SBATCH --time=00:02:00 # Run time in hh:mm:ss
#SBATCH --error=ex04.err
#SBATCH --output=ex04.out

echo "Starting at `date`"
echo "Running on hosts: $SLURM_NODELIST"
echo "Running on $SLURM_NNODES nodes."
echo "Running on $SLURM_NPROCS processors."
echo "Job id is $SLURM_JOBID"

./xdoty  $((1024*1024*32))

echo "Program finished with exit code $? at: `date`"
