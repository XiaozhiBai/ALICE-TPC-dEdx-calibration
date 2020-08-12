#!/bin/bash
# Task name
#SBATCH -J TPCPID
# Run time limit
#SBATCH --mem-per-cpu=16000
#SBATCH --time=8:00:00
# Working directory on shared storage
# Standard and error output in different files
#SBATCH -o %j_%N.out.log
#SBATCH -e %j_%N.err.log
# Execute application code

#jobId=$1
#alisource=1
#if [ $alisource -eq 1 ];
#then source /lustre/nyx/alice/users/eperezl/alicesw/alice-env.sh -n 1
#else alikronos -n 1
#fi


echo "running on $(hostname)"


echo "job_id: " ${SLURM_JOB_ID}
echo "array_job_id: " ${SLURM_ARRAY_JOB_ID}
echo "task_id: " ${SLURM_ARRAY_TASK_ID}


run=${1}
output_dir=${2}
input_file_path=${3};
chunk_index=$((${SLURM_ARRAY_TASK_ID}))

mkdir -p chunks_${chunk_index}
cd chunks_${chunk_index}

ls $input_file_path/chunks_${chunk_index}/V0tree.root > V0.list

file_path=$input_file_path/chunks_${chunk_index}/V0tree.root

root -l -b <<EOF
gSystem->Load("/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreeAna/AliSkimmedDataAnalysisMaker.so");
AliSkimmedDataAnalysisMaker *ana=new AliSkimmedDataAnalysisMaker("hist.root");
ana->bookHistogram();
ana->read_V0("$file_path");
ana->WriteHistogram();
EOF



