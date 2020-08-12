#!/bin/bash


#SBATCH -J test # job name
#SBATCH -t 0-0:10  # time limit 10 minutes (D-HH:MM)

echo "running on $(hostname)" 

echo "job_id: " ${SLURM_JOB_ID}
echo "array_job_id: " ${SLURM_ARRAY_JOB_ID}
echo "task_id: " ${SLURM_ARRAY_TASK_ID}
