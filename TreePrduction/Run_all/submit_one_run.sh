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
prod_id=${7}
file_name=${8}
output_base_dir=${9}
current_dir=${10}


max_chunks=${11}


spline_path=${12} 
eta_crrection_path=${13}  
aodbPath=${14}  
pileUpCorrection=${15} 



if [ "${data}"x = "data"x ]
then
    runPrefix="000"
elif [ "${data}"x = "sim"x ]
then
    runPrefix=""
fi

#echo "input files path: " $base_path/$data/$year/$run_pariod/
#echo "run number "$runPrefix$run
#echo "input pass "$pass
#echo "input production id" $prod_id
#echo "input file name"=$file_name
#echo "output dir path" $output_base_dir

#echo $spline_path  
#echo $eta_crrection_path 
#echo $aodbPath 
#echo $pileUpCorrection


output_dir=${output_base_dir}/$data/$year/$run_pariod/$run/$pass

mkdir -p $output_dir
[[ ! -d $output_dir ]] && echo "output dir not exist" && exit 0; 
ls ${base_path}/${data}/${year}/${run_pariod}/$runPrefix${run}/${pass}/${prod_id}/*/${file_name} > $output_dir/filtered.list

input_file_path=${base_path}/${data}/${year}/${run_pariod}/$runPrefix${run}/${pass}/${prod_id}/

echo $input_file_path

nChunks=`cat $output_dir/filtered.list | wc -l`



[[ ${nChunks} -gt $max_chunks ]] && echo "number of chunks" echo $nChunks


    cp $current_dir/submit_one_run.sh $output_dir/
    cp /lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/fitdEdxCorrectionFiltered.C $output_dir/
    cd $output_dir

    sbatch --array=1-${nChunks}   $current_dir/SubmitJobs2Nyx.sh $run  ${output_dir} ${input_file_path}   $spline_path   $eta_crrection_path  $aodbPath  $pileUpCorrection
echo "submit is done for run :" $run

