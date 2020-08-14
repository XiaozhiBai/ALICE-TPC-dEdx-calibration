#!/bin/bash 
#title           :submit_All_skimedData_ana.sh
#description     :This script will submit the job to GSI batch farm.
#author          :Xiaozhi Bai xiaozhi.bai@cern.ch  x.bai@gsi.de
#date            :Fri May  8 12:18:32 EDT 2020
#version         :1.0

MAX_runs=999 #99 for LHC18r, 136 for 18q, user can give a small number for testing 


#user can modify the below path according to the input 
input_base_path=/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/Run_all/output

data=data # data or sim
year=2018 # 2018. 2015
run_pariod=LHC18r #LHC18q, LHC18r.
pass=pass3   # pass1, pass2..
file_name=V0tree.root
run_list=LHC18r_pass3_full.txt #LHC18r_pass3_full.txt

output_base_dir=/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreeAna/Run_all/output
current_dir=/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreeAna/Run_all
input_path=$input_base_path/$data/$year/$run_pariod


#[ ! -d ${input_path} ] && echo "Input files dir is not exist!!! please check"  && echo $input_path &&exit 0
#[ ! -s ${output_base_dir} ] && echo "output can not wirite to this dir. !!! please check"  && $output_base_dir &&exit 0

run_counting=1;
exec 6>&1
exec 6<inputRunList/$run_list

while read -u 6 runNumber
do
    echo "run index" $run_counting
 #   [[ run_counting -gt MAX_runs ]] && exit 0;
#    ./submit_one_run.sh $input_base_path $data $year $run_pariod $runNumber $pass $file_name $output_base_dir $current_dir 
    ((run_counting=run_counting+1))
done

run_pariod=LHC18q #LHC18q, LHC18r.
run_list=LHC18q_pass3_full.txt #LHC18r_pass3_full.txt



run_counting=1;
exec 6>&1
exec 6<inputRunList/$run_list

while read -u 6 runNumber
do
    echo "run index" $run_counting
    [[ run_counting -gt MAX_runs ]] && exit 0;
    ./submit_one_run.sh $input_base_path $data $year $run_pariod $runNumber $pass $file_name $output_base_dir $current_dir
    ((run_counting=run_counting+1))
done



