//#include "/lustre/nyx/alice/users/xbai/work/SkimmedDataAna/Run18/TPCsplines/FlatTreeAna/lib/AliSkimmedDataAnalysisMaker.h"
#include "AliSkimmedDataAnalysisMaker.h"

void runV0(TString filelist="Ana/V0list",TString outfile="Ana/TPCresidualPID.root") {


    gSystem->Load("AliSkimmedDataAnalysisMaker.so");
  gROOT->Reset();  
  //  gROOT->ProcessLine(".L AliSkimmedDataAnalysisMaker.so"); //load TUser class 

  //  R__LOAD_LIBRARY(HelloWorld.so);
  // V0FlatAna* V0ana = new V0FlatAna();
  // TFile* inputFile = new TFile("V0tree.root","READ");
  // TTree *tree_v0=  (TTree *) inputFile->Get("V0Flat");

  // V0ana->Init(tree_v0);
  // V0ana->Loop();
   AliSkimmedDataAnalysisMaker *ana=new AliSkimmedDataAnalysisMaker(outfile);
  //  ana->read();
  //  ana->WriteHistogram();

}
