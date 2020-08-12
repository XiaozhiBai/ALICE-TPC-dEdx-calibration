
#include "V0FlatAna.h"
#include <iostream>

ClassImp(V0FlatAna);

V0FlatAna::V0FlatAna() {
  // nothing to do here. The class has no member data so
  // nothing to be initialized
}

V0FlatAna::~V0FlatAna() {
  // nothing to do here. The class has no member data so
  // nothing to be initialized
}

void V0FlatAna::Loop()
{
  //   In a ROOT session, you can do:
  //      Root > .L h.C
  //      Root > h t
  //      Root > t.GetEntry(12); // Fill t data members with entry number 12
  //      Root > t.Show();       // Show values of entry 12
  //      Root > t.Show(16);     // Read and show values of entry 16
  //      Root > t.Loop();       // Loop on all entries
  //

  //     This is the loop skeleton where:
  //    jentry is the global entry number in the chain
  //    ientry is the entry number in the current Tree
  //  Note that the argument to GetEntry must be:
  //    jentry for TChain::GetEntry
  //    ientry for TTree::GetEntry and TBranch::GetEntry
  //
  //       To read only selected branches, Insert statements like:
  // METHOD1:
  //    fChain->SetBranchStatus("*",0);  // disable all branches
  //    fChain->SetBranchStatus("branchname",1);  // activate branchname
  // METHOD2: replace line
  //    fChain->GetEntry(jentry);       //read all branches
  //by  b_branchname->GetEntry(ientry); //read only this branch
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  std::cout<<"total entries" <<nentries<<std::endl;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    std::cout<< ientry<<std::endl;
    // if (Cut(ientry) < 0) continue;
  }
}
Int_t V0FlatAna::Cut(Long64_t entry)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  return 1;
}
Int_t V0FlatAna::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t V0FlatAna::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}
void V0FlatAna::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

   fChain->SetBranchAddress("v0.fPointAngle", &v0_fPointAngle, &b_v0_fPointAngle);
   fChain->SetBranchAddress("kf.fChi2", &kf_fChi2, &b_kf_fChi2);
   fChain->SetBranchAddress("K0Like", &K0Like, &b_K0Like);
   fChain->SetBranchAddress("ELike", &ELike, &b_ELike);
   fChain->SetBranchAddress("LLike", &LLike, &b_LLike);
   fChain->SetBranchAddress("ALLike", &ALLike, &b_ALLike);
   fChain->SetBranchAddress("cleanK0", &cleanK0, &b_cleanK0);
   fChain->SetBranchAddress("cleanGamma", &cleanGamma, &b_cleanGamma);
   fChain->SetBranchAddress("cleanLambda", &cleanLambda, &b_cleanLambda);
   fChain->SetBranchAddress("cleanALambda", &cleanALambda, &b_cleanALambda);
   fChain->SetBranchAddress("centV0", &centV0, &b_centV0);
   fChain->SetBranchAddress("centITS0", &centITS0, &b_centITS0);
   fChain->SetBranchAddress("centITS1", &centITS1, &b_centITS1);
   fChain->SetBranchAddress("tpcClusterMult", &tpcClusterMult, &b_tpcClusterMult);
   fChain->SetBranchAddress("multSSD", &multSSD, &b_multSSD);
   fChain->SetBranchAddress("multSDD", &multSDD, &b_multSDD);
   fChain->SetBranchAddress("tpcTrackBeforeClean", &tpcTrackBeforeClean, &b_tpcTrackBeforeClean);
   fChain->SetBranchAddress("triggerMask", &triggerMask, &b_triggerMask);
   fChain->SetBranchAddress("track0.fTPCsignal", &track0_fTPCsignal, &b_track0_fTPCsignal);
   fChain->SetBranchAddress("track1.fTPCsignal", &track1_fTPCsignal, &b_track1_fTPCsignal);
   fChain->SetBranchAddress("track0.fTPCsignalN", &track0_fTPCsignalN, &b_track0_fTPCsignalN);
   fChain->SetBranchAddress("track1.fTPCsignalN", &track1_fTPCsignalN, &b_track1_fTPCsignalN);
   fChain->SetBranchAddress("type", &type, &b_type);
   fChain->SetBranchAddress("track0P", &track0P, &b_track0P);
   fChain->SetBranchAddress("track0Pt", &track0Pt, &b_track0Pt);
   fChain->SetBranchAddress("track0Eta", &track0Eta, &b_track0Eta);
   fChain->SetBranchAddress("track0Phi", &track0Phi, &b_track0Phi);
   fChain->SetBranchAddress("track0Px", &track0Px, &b_track0Px);
   fChain->SetBranchAddress("track0Py", &track0Py, &b_track0Py);
   fChain->SetBranchAddress("track0Pz", &track0Pz, &b_track0Pz);
   fChain->SetBranchAddress("track0DCAxy", &track0DCAxy, &b_track0DCAxy);
   fChain->SetBranchAddress("track0DCAz", &track0DCAz, &b_track0DCAz);
   fChain->SetBranchAddress("track1P", &track1P, &b_track1P);
   fChain->SetBranchAddress("track1Pt", &track1Pt, &b_track1Pt);
   fChain->SetBranchAddress("track1Eta", &track1Eta, &b_track1Eta);
   fChain->SetBranchAddress("track1Phi", &track1Phi, &b_track1Phi);
   fChain->SetBranchAddress("track1Px", &track1Px, &b_track1Px);
   fChain->SetBranchAddress("track1Py", &track1Py, &b_track1Py);
   fChain->SetBranchAddress("track1Pz", &track1Pz, &b_track1Pz);
   fChain->SetBranchAddress("track1DCAxy", &track1DCAxy, &b_track1DCAxy);
   fChain->SetBranchAddress("track1DCAz", &track1DCAz, &b_track1DCAz);
   fChain->SetBranchAddress("track0tofNsigmaElectron", &track0tofNsigmaElectron, &b_track0tofNsigmaElectron);
   fChain->SetBranchAddress("track0tofNsigmaPion", &track0tofNsigmaPion, &b_track0tofNsigmaPion);
   fChain->SetBranchAddress("track0tofNsigmaKaon", &track0tofNsigmaKaon, &b_track0tofNsigmaKaon);
   fChain->SetBranchAddress("track0tofNsigmaProton", &track0tofNsigmaProton, &b_track0tofNsigmaProton);
   fChain->SetBranchAddress("track1tofNsigmaElectron", &track1tofNsigmaElectron, &b_track1tofNsigmaElectron);
   fChain->SetBranchAddress("track1tofNsigmaPion", &track1tofNsigmaPion, &b_track1tofNsigmaPion);
   fChain->SetBranchAddress("track1tofNsigmaKaon", &track1tofNsigmaKaon, &b_track1tofNsigmaKaon);
   fChain->SetBranchAddress("track1tofNsigmaProton", &track1tofNsigmaProton, &b_track1tofNsigmaProton);
   fChain->SetBranchAddress("track0tpcNsigma_no_corrected_el", &track0tpcNsigma_no_corrected_el, &b_track0tpcNsigma_no_corrected_el);
   fChain->SetBranchAddress("track0tpcNsigma_no_corrected_pi", &track0tpcNsigma_no_corrected_pi, &b_track0tpcNsigma_no_corrected_pi);
   fChain->SetBranchAddress("track0tpcNsigma_no_corrected_pr", &track0tpcNsigma_no_corrected_pr, &b_track0tpcNsigma_no_corrected_pr);
   fChain->SetBranchAddress("track1tpcNsigma_no_corrected_el", &track1tpcNsigma_no_corrected_el, &b_track1tpcNsigma_no_corrected_el);
   fChain->SetBranchAddress("track1tpcNsigma_no_corrected_pi", &track1tpcNsigma_no_corrected_pi, &b_track1tpcNsigma_no_corrected_pi);
   fChain->SetBranchAddress("track1tpcNsigma_no_corrected_pr", &track1tpcNsigma_no_corrected_pr, &b_track1tpcNsigma_no_corrected_pr);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_no_corrected_el", &track0ExpectedTPCSignalV0_no_corrected_el, &b_track0ExpectedTPCSignalV0_no_corrected_el);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_no_corrected_pi", &track0ExpectedTPCSignalV0_no_corrected_pi, &b_track0ExpectedTPCSignalV0_no_corrected_pi);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_no_corrected_pr", &track0ExpectedTPCSignalV0_no_corrected_pr, &b_track0ExpectedTPCSignalV0_no_corrected_pr);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_no_corrected_el", &track1ExpectedTPCSignalV0_no_corrected_el, &b_track1ExpectedTPCSignalV0_no_corrected_el);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_no_corrected_pi", &track1ExpectedTPCSignalV0_no_corrected_pi, &b_track1ExpectedTPCSignalV0_no_corrected_pi);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_no_corrected_pr", &track1ExpectedTPCSignalV0_no_corrected_pr, &b_track1ExpectedTPCSignalV0_no_corrected_pr);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_el", &track0tpcNsigma_corrected_eta_el, &b_track0tpcNsigma_corrected_eta_el);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_pi", &track0tpcNsigma_corrected_eta_pi, &b_track0tpcNsigma_corrected_eta_pi);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_pr", &track0tpcNsigma_corrected_eta_pr, &b_track0tpcNsigma_corrected_eta_pr);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_el", &track1tpcNsigma_corrected_eta_el, &b_track1tpcNsigma_corrected_eta_el);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_pi", &track1tpcNsigma_corrected_eta_pi, &b_track1tpcNsigma_corrected_eta_pi);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_pr", &track1tpcNsigma_corrected_eta_pr, &b_track1tpcNsigma_corrected_eta_pr);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_el", &track0ExpectedTPCSignalV0_corrected_eta_el, &b_track0ExpectedTPCSignalV0_corrected_eta_el);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_pi", &track0ExpectedTPCSignalV0_corrected_eta_pi, &b_track0ExpectedTPCSignalV0_corrected_eta_pi);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_pr", &track0ExpectedTPCSignalV0_corrected_eta_pr, &b_track0ExpectedTPCSignalV0_corrected_eta_pr);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_el", &track1ExpectedTPCSignalV0_corrected_eta_el, &b_track1ExpectedTPCSignalV0_corrected_eta_el);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_pi", &track1ExpectedTPCSignalV0_corrected_eta_pi, &b_track1ExpectedTPCSignalV0_corrected_eta_pi);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_pr", &track1ExpectedTPCSignalV0_corrected_eta_pr, &b_track1ExpectedTPCSignalV0_corrected_eta_pr);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_multip_el", &track0tpcNsigma_corrected_multip_el, &b_track0tpcNsigma_corrected_multip_el);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_multip_pi", &track0tpcNsigma_corrected_multip_pi, &b_track0tpcNsigma_corrected_multip_pi);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_multip_pr", &track0tpcNsigma_corrected_multip_pr, &b_track0tpcNsigma_corrected_multip_pr);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_multip_el", &track1tpcNsigma_corrected_multip_el, &b_track1tpcNsigma_corrected_multip_el);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_multip_pi", &track1tpcNsigma_corrected_multip_pi, &b_track1tpcNsigma_corrected_multip_pi);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_multip_pr", &track1tpcNsigma_corrected_multip_pr, &b_track1tpcNsigma_corrected_multip_pr);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_multip_el", &track0ExpectedTPCSignalV0_corrected_multip_el, &b_track0ExpectedTPCSignalV0_corrected_multip_el);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_multip_pi", &track0ExpectedTPCSignalV0_corrected_multip_pi, &b_track0ExpectedTPCSignalV0_corrected_multip_pi);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_multip_pr", &track0ExpectedTPCSignalV0_corrected_multip_pr, &b_track0ExpectedTPCSignalV0_corrected_multip_pr);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_multip_el", &track1ExpectedTPCSignalV0_corrected_multip_el, &b_track1ExpectedTPCSignalV0_corrected_multip_el);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_multip_pi", &track1ExpectedTPCSignalV0_corrected_multip_pi, &b_track1ExpectedTPCSignalV0_corrected_multip_pi);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_multip_pr", &track1ExpectedTPCSignalV0_corrected_multip_pr, &b_track1ExpectedTPCSignalV0_corrected_multip_pr);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_pileup_el", &track0tpcNsigma_corrected_pileup_el, &b_track0tpcNsigma_corrected_pileup_el);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_pileup_pi", &track0tpcNsigma_corrected_pileup_pi, &b_track0tpcNsigma_corrected_pileup_pi);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_pileup_pr", &track0tpcNsigma_corrected_pileup_pr, &b_track0tpcNsigma_corrected_pileup_pr);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_pileup_el", &track1tpcNsigma_corrected_pileup_el, &b_track1tpcNsigma_corrected_pileup_el);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_pileup_pi", &track1tpcNsigma_corrected_pileup_pi, &b_track1tpcNsigma_corrected_pileup_pi);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_pileup_pr", &track1tpcNsigma_corrected_pileup_pr, &b_track1tpcNsigma_corrected_pileup_pr);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_pileup_el", &track0ExpectedTPCSignalV0_corrected_pileup_el, &b_track0ExpectedTPCSignalV0_corrected_pileup_el);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_pileup_pi", &track0ExpectedTPCSignalV0_corrected_pileup_pi, &b_track0ExpectedTPCSignalV0_corrected_pileup_pi);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_pileup_pr", &track0ExpectedTPCSignalV0_corrected_pileup_pr, &b_track0ExpectedTPCSignalV0_corrected_pileup_pr);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_pileup_el", &track1ExpectedTPCSignalV0_corrected_pileup_el, &b_track1ExpectedTPCSignalV0_corrected_pileup_el);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_pileup_pi", &track1ExpectedTPCSignalV0_corrected_pileup_pi, &b_track1ExpectedTPCSignalV0_corrected_pileup_pi);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_pileup_pr", &track1ExpectedTPCSignalV0_corrected_pileup_pr, &b_track1ExpectedTPCSignalV0_corrected_pileup_pr);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_multip_el", &track0tpcNsigma_corrected_eta_multip_el, &b_track0tpcNsigma_corrected_eta_multip_el);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_multip_pi", &track0tpcNsigma_corrected_eta_multip_pi, &b_track0tpcNsigma_corrected_eta_multip_pi);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_multip_pr", &track0tpcNsigma_corrected_eta_multip_pr, &b_track0tpcNsigma_corrected_eta_multip_pr);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_multip_el", &track1tpcNsigma_corrected_eta_multip_el, &b_track1tpcNsigma_corrected_eta_multip_el);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_multip_pi", &track1tpcNsigma_corrected_eta_multip_pi, &b_track1tpcNsigma_corrected_eta_multip_pi);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_multip_pr", &track1tpcNsigma_corrected_eta_multip_pr, &b_track1tpcNsigma_corrected_eta_multip_pr);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_multip_el", &track0ExpectedTPCSignalV0_corrected_eta_multip_el, &b_track0ExpectedTPCSignalV0_corrected_eta_multip_el);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_multip_pi", &track0ExpectedTPCSignalV0_corrected_eta_multip_pi, &b_track0ExpectedTPCSignalV0_corrected_eta_multip_pi);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_multip_pr", &track0ExpectedTPCSignalV0_corrected_eta_multip_pr, &b_track0ExpectedTPCSignalV0_corrected_eta_multip_pr);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_multip_el", &track1ExpectedTPCSignalV0_corrected_eta_multip_el, &b_track1ExpectedTPCSignalV0_corrected_eta_multip_el);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_multip_pi", &track1ExpectedTPCSignalV0_corrected_eta_multip_pi, &b_track1ExpectedTPCSignalV0_corrected_eta_multip_pi);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_multip_pr", &track1ExpectedTPCSignalV0_corrected_eta_multip_pr, &b_track1ExpectedTPCSignalV0_corrected_eta_multip_pr);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_pileup_el", &track0tpcNsigma_corrected_eta_pileup_el, &b_track0tpcNsigma_corrected_eta_pileup_el);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_pileup_pi", &track0tpcNsigma_corrected_eta_pileup_pi, &b_track0tpcNsigma_corrected_eta_pileup_pi);
   fChain->SetBranchAddress("track0tpcNsigma_corrected_eta_pileup_pr", &track0tpcNsigma_corrected_eta_pileup_pr, &b_track0tpcNsigma_corrected_eta_pileup_pr);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_pileup_el", &track1tpcNsigma_corrected_eta_pileup_el, &b_track1tpcNsigma_corrected_eta_pileup_el);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_pileup_pi", &track1tpcNsigma_corrected_eta_pileup_pi, &b_track1tpcNsigma_corrected_eta_pileup_pi);
   fChain->SetBranchAddress("track1tpcNsigma_corrected_eta_pileup_pr", &track1tpcNsigma_corrected_eta_pileup_pr, &b_track1tpcNsigma_corrected_eta_pileup_pr);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_pileup_el", &track0ExpectedTPCSignalV0_corrected_eta_pileup_el, &b_track0ExpectedTPCSignalV0_corrected_eta_pileup_el);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_pileup_pi", &track0ExpectedTPCSignalV0_corrected_eta_pileup_pi, &b_track0ExpectedTPCSignalV0_corrected_eta_pileup_pi);
   fChain->SetBranchAddress("track0ExpectedTPCSignalV0_corrected_eta_pileup_pr", &track0ExpectedTPCSignalV0_corrected_eta_pileup_pr, &b_track0ExpectedTPCSignalV0_corrected_eta_pileup_pr);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_pileup_el", &track1ExpectedTPCSignalV0_corrected_eta_pileup_el, &b_track1ExpectedTPCSignalV0_corrected_eta_pileup_el);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_pileup_pi", &track1ExpectedTPCSignalV0_corrected_eta_pileup_pi, &b_track1ExpectedTPCSignalV0_corrected_eta_pileup_pi);
   fChain->SetBranchAddress("track1ExpectedTPCSignalV0_corrected_eta_pileup_pr", &track1ExpectedTPCSignalV0_corrected_eta_pileup_pr, &b_track1ExpectedTPCSignalV0_corrected_eta_pileup_pr);
  

     Notify();
}
Bool_t V0FlatAna::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void V0FlatAna::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}

