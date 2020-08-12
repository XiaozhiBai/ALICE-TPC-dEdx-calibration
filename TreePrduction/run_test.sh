#spline_path='/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/splines/TPCPIDResponseOADB_2020_06_22_18r_pass3_It4_woPileup.root'
#eta_crrection_path='/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/splines/TPCetaMaps_2020_06_22_18r_pass3_It4_woPileup.root'

#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCPIDResponseOADB_2020_07_22_18r_pass3_It8.root
#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCetaMaps_2020_07_22_18r_pass3_It8.root
#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCPIDResponseOADB_2020_08_12_18q_pass3_It9.root
#/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18q/withoutpileup/TPCetaMaps_2020_08_12_18q_pass3_It9.root

eta_crrection_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCetaMaps_2020_07_22_18r_pass3_It8.root"
spline_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/withoutPileup/TPCPIDResponseOADB_2020_07_22_18r_pass3_It8.root"


pileUpCorrection="/lustre/alice/users/miranov/NOTESData/alice-tpc-notes/JIRA/PWGPP-538/new/alice/data/2018/LHC18r/pass3/AOD_FilterTrees/fit_version_08062020/dEdxFitLight.root"  

pidIndex=1
run=296690 
passNumber=3
recoPass="pass3"                                                     
aodbPath="/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/TreePrduction/lib/OADB"                                                 
#spline_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/wPileup_minBias/TPCPIDResponseOADB_LHC18r_pass3_wPileupcorr_allEvents.root"                                               
#eta_crrection_path="/lustre/nyx/alice/users/mciupek/TPCSpline/Splines/LHC18r/wPileup_minBias/TPCetaMaps_LHC18r_pass3_wPileupcorr_allEvents.root"                                   



#
#valgrind --leak-check=full --log-file=xxx.txt -v aliroot -l -b <<EOF
aliroot -l  -b <<EOF             
TStopwatch timer;
timer.Start();
.L  fitdEdxCorrectionFiltered.C++g
InitTree(1);
registerPID($pidIndex,$run,$passNumber,"$recoPass","$aodbPath","$spline_path","$eta_crrection_path","$pileUpCorrection");
cacheCleanV0(100000);
EOF

#
#
#SetUpNewSpline($run);
