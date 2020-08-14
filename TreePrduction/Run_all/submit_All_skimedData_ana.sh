#!/bin/bash 
#title           :submit_All_skimedData_ana.sh
#description     :This script will submit the job to GSI batch farm.
#author          :Xiaozhi Bai xiaozhi.bai@cern.ch  x.bai@gsi.de
#date            :Fri May  8 12:18:32 EDT 2020
#version         :1.0

pass=pass3   # pass1, pass2..

MAX_runs=99 #99 for LHC18r, 136 for 18q, user can give a small number for testing 
MAX_chunks=1 # how many chunks per job, split the large runs with into several jobs,  

run_pariod=LHC18r #LHC18q, LHC18r.
run_list=LHC18r_pass3_full.txt #LHC18r_pass3_full.txt
#user can modify the below path according to the input 
input_base_path=/lustre/alice/DETdata/triggeredESD/alice 
data=data # data or sim
year=2018 # 2018. 2015

prod_id=AODFilterTrees01/AOD 
file_name=FilterEvents_Trees.root

#User splines input

#18r
spline_path_18r='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCPIDResponseOADB_2020_07_22_LHC18r_pass3_woPileupcor.root'
eta_crrection_path_18r='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCetaMaps_2020_07_22_LHC18r_pass3_woPileupcor.root'


aodbPath="/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/lib/OADB"  
pileUpCorrection="/lustre/alice/users/miranov/NOTESData/alice-tpc-notes/JIRA/PWGPP-538/new/alice/data/2018/LHC18r/pass3/AOD_FilterTrees/fit_version_08062020/dEdxFitLight.root"

 

output_base_dir=/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/Run_all/output
current_dir=/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/Run_all
input_path=$input_base_path/$data/$year/$run_pariod

[ ! -d ${input_path} ] && echo "Input files dir is not exist!!! please check"  && return
[ ! -s ${output_base_dir} ] && echo "output can not wirite to this dir. !!! please check"  && return

run_counting=1;
exec 6>&1
exec 6<inputRunList/$run_list

#18q
spline_path_18q='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCPIDResponseOADB_2020_08_13_18q_pass3_It3.root'
eta_crrection_path_18q='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCetaMaps_2020_08_13_18q_pass3_It3.root'

while read -u 6 runNumber
do
    echo "run index" $run_counting
    [[ run_counting -gt MAX_runs ]] && exit 0;
    ./submit_one_run.sh $input_base_path $data $year $run_pariod $runNumber $pass $prod_id $file_name $output_base_dir $current_dir $MAX_chunks $spline_path_18r $eta_crrection_path_18r $aodbPath $pileUpCorrection
    echo 'submit_one_run.sh' $input_base_path $data $year $run_pariod $runNumber $pass $prod_id $file_name $output_base_dir $current_dir $MAX_chunks   
    ((run_counting=run_counting+1))
done




MAX_runs=136
run_pariod=LHC18q #LHC18q, LHC18r.
run_list=LHC18q_pass3_full.txt #LHC18r_pass3_full.txt
#prod_id=AOD 

run_counting=1;
exec 6>&1
exec 6<inputRunList/$run_list

while read -u 6 runNumber
do
    echo "run index" $run_counting
    [[ run_counting -gt MAX_runs ]] && exit 0;
    ./submit_one_run.sh $input_base_path $data $year $run_pariod $runNumber $pass $prod_id $file_name $output_base_dir $current_dir $MAX_chunks $spline_path_18q $eta_crrection_path_18q $aodbPath $pileUpCorrection
    ((run_counting=run_counting+1))
done


