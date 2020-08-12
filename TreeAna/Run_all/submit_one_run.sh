#!/bin/bash
#title           :submit_one_run.sh
#description     :This script will submit the job for each run
#author          :Xiaozhi Bai xiaozhi.bai@cern.ch  x.bai@gsi.de
#date            :Fri May  8 12:18:32 EDT 2020
#version         :1.0



base_path=${1}
data=${2}
year=${3}
run_pariod=${4}
run=${5}
pass=${6}
file_name=${7}
output_base_dir=${8}
current_dir=${9}


#echo "input files path: " $base_path/$data/$year/$run_pariod/
#echo "run number "$runPrefix$run
#echo "input pass "$pass
#echo "input production id" $prod_id
#echo "input file name"=$file_name
#echo "output dir path" $output_base_dir


output_dir=${output_base_dir}/$data/$year/$run_pariod/$run/$pass

mkdir -p $output_dir
[[ ! -d $output_dir ]] && echo "output dir not exist" && exit 0; 
ls ${base_path}/${data}/${year}/${run_pariod}/${run}/${pass}/chunks_*/${file_name} > $output_dir/input.list
nChunks=`cat $output_dir/input.list | wc -l`

input_file_path=${base_path}/${data}/${year}/${run_pariod}/${run}/${pass}

cd $output_dir

#echo $run $nChunks
sbatch --array=1-$nChunks -- $current_dir/SubmitJobs2Nyx.sh $run ${output_dir} ${input_file_path}

echo "submit is done for run :" $run

