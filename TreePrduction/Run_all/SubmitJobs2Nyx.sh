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
#SBATCH --array=1-100:2
# Execute application code

#jobId=$1
#alisource=1
#if [ $alisource -eq 1 ];
#then source /lustre/nyx/alice/users/eperezl/alicesw/alice-env.sh -n 1
#else alikronos -n 1
#fi

#singularity exec /lustre/alice/users/miranov/NOTESData/alice-tpc-notes/JIRA/ATO-500//alidockSingularity.sif aliroot -l -b <<EOF

echo "running on $(hostname)" 

echo "job_id: " ${SLURM_JOB_ID}
echo "array_job_id: " ${SLURM_ARRAY_JOB_ID}
echo "task_id: " ${SLURM_ARRAY_TASK_ID}

run=${1}
nChunks=${2}
input_file_path=${3};


spline_path=${4}  
eta_crrection_path=${5}  
aodbPath=${6}   
pileUpCorrection=${7}  



chunk_index=$((${SLURM_ARRAY_TASK_ID}))

mkdir -p chunks_${chunk_index}

cd chunks_${chunk_index}
g
if [ ${chunk_index} -lt 9 ]
then
    ls $input_file_path/00${chunk_index}/FilterEvents_Trees.root > filtered.list
elif [ ${chunk_index} -lt 100 ] 
then
    ls $input_file_path/0${chunk_index}/FilterEvents_Trees.root > filtered.list
else
    ls $input_file_path/${chunk_index}/FilterEvents_Trees.root > filtered.list
fi




#18r
#spline_path='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCPIDResponseOADB_2020_07_22_LHC18r_pass3_woPileupcor.root'
#eta_crrection_path='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCetaMaps_2020_07_22_LHC18r_pass3_woPileupcor.root'
#18q
#spline_path='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCPIDResponseOADB_2020_08_13_18q_pass3_It3.root'
#eta_crrection_path='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCetaMaps_2020_08_13_18q_pass3_It3.root'


#spline_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCPIDResponseOADB_2020_08_12_18q_pass3_It9.root"
#eta_crrection_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCetaMaps_2020_08_12_18q_pass3_It9.root"


#spline_path='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCPIDResponseOADB_2020_08_03_18q_pass3_It3.root'
#eta_crrection_path='/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCetaMaps_2020_08_03_18q_pass3_It3.root'

#eta_crrection_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/wPileup_minBias/TPCetaMaps_LHC18r_pass3_wPileupcorr_allEvents.root"
#spline_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/wPileup_minBias/TPCPIDResponseOADB_LHC18r_pass3_wPileupcorr_allEvents.root"



#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCPIDResponseOADB_2020_07_22_18r_pass3_It8.root
#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCetaMaps_2020_07_22_18r_pass3_It8.root
#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCPIDResponseOADB_2020_08_12_18q_pass3_It9.root
#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCetaMaps_2020_08_12_18q_pass3_It9.root



#pileUpCorrection="/lustre/alice/users/miranov/NOTESData/alice-tpc-notes/JIRA/PWGPP-538/new/alice/data/2018/LHC18r/pass3/AOD_FilterTrees/fit_version_08062020/dEdxFitLight.root"  

pidIndex=1
#run=296690 
passNumber=3
recoPass="pass3"                                                     
#aodbPath="/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/lib/OADB"     



today=$(date +%Y%m%d)
echo "Today's date: "$today


echo $run
echo $nChunks
singularity exec /lustre/alice/users/miranov/NOTESData/alice-tpc-notes/JIRA/ATO-500//alidockSingularity.sif aliroot -l -b <<EOF
TStopwatch timer;
timer.Start();
.L /lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/lib/fitdEdxCorrectionFiltered_C.so
InitTree(1,1,$run);
registerPID($pidIndex,$run,$passNumber,"$recoPass","$aodbPath","$spline_path","$eta_crrection_path","$pileUpCorrection");
cacheCleanV0();
timer.Print();
EOF






