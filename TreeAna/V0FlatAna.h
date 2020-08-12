#ifndef V0FlatAna_H
#define V0FlatAna_H


#include "TObject.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class V0FlatAna :public TObject {

 public:

  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   // Declaration of leaf types
   Double_t        v0_fPointAngle;
   Double_t        kf_fChi2;
   Double_t        K0Like;
   Double_t        ELike;
   Double_t        LLike;
   Double_t        ALLike;
   Double_t        cleanK0;
   Double_t        cleanGamma;
   Double_t        cleanLambda;
   Double_t        cleanALambda;
   Double_t        centV0;
   Double_t        centITS0;
   Double_t        centITS1;
   Double_t        tpcClusterMult;
   Double_t        multSSD;
   Double_t        multSDD;
   Double_t        tpcTrackBeforeClean;
   Double_t        triggerMask;
   Double_t        track0_fTPCsignal;
   Double_t        track1_fTPCsignal;
   Double_t        track0_fTPCsignalN;
   Double_t        track1_fTPCsignalN;
   Double_t        type;
   Double_t        track0P;
   Double_t        track0Pt;
   Double_t        track0Eta;
   Double_t        track0Phi;
   Double_t        track0Px;
   Double_t        track0Py;
   Double_t        track0Pz;
   Double_t        track0DCAxy;
   Double_t        track0DCAz;
   Double_t        track1P;
   Double_t        track1Pt;
   Double_t        track1Eta;
   Double_t        track1Phi;
   Double_t        track1Px;
   Double_t        track1Py;
   Double_t        track1Pz;
   Double_t        track1DCAxy;
   Double_t        track1DCAz;
   Double_t        track0tofNsigmaElectron;
   Double_t        track0tofNsigmaPion;
   Double_t        track0tofNsigmaKaon;
   Double_t        track0tofNsigmaProton;
   Double_t        track1tofNsigmaElectron;
   Double_t        track1tofNsigmaPion;
   Double_t        track1tofNsigmaKaon;
   Double_t        track1tofNsigmaProton;
   Double_t        track0tpcNsigma_no_corrected_el;
   Double_t        track0tpcNsigma_no_corrected_pi;
   Double_t        track0tpcNsigma_no_corrected_pr;
   Double_t        track1tpcNsigma_no_corrected_el;
   Double_t        track1tpcNsigma_no_corrected_pi;
   Double_t        track1tpcNsigma_no_corrected_pr;
   Double_t        track0ExpectedTPCSignalV0_no_corrected_el;
   Double_t        track0ExpectedTPCSignalV0_no_corrected_pi;
   Double_t        track0ExpectedTPCSignalV0_no_corrected_pr;
   Double_t        track1ExpectedTPCSignalV0_no_corrected_el;
   Double_t        track1ExpectedTPCSignalV0_no_corrected_pi;
   Double_t        track1ExpectedTPCSignalV0_no_corrected_pr;
   Double_t        track0tpcNsigma_corrected_eta_el;
   Double_t        track0tpcNsigma_corrected_eta_pi;
   Double_t        track0tpcNsigma_corrected_eta_pr;
   Double_t        track1tpcNsigma_corrected_eta_el;
   Double_t        track1tpcNsigma_corrected_eta_pi;
   Double_t        track1tpcNsigma_corrected_eta_pr;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_el;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_pi;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_pr;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_el;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_pi;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_pr;
   Double_t        track0tpcNsigma_corrected_multip_el;
   Double_t        track0tpcNsigma_corrected_multip_pi;
   Double_t        track0tpcNsigma_corrected_multip_pr;
   Double_t        track1tpcNsigma_corrected_multip_el;
   Double_t        track1tpcNsigma_corrected_multip_pi;
   Double_t        track1tpcNsigma_corrected_multip_pr;
   Double_t        track0ExpectedTPCSignalV0_corrected_multip_el;
   Double_t        track0ExpectedTPCSignalV0_corrected_multip_pi;
   Double_t        track0ExpectedTPCSignalV0_corrected_multip_pr;
   Double_t        track1ExpectedTPCSignalV0_corrected_multip_el;
   Double_t        track1ExpectedTPCSignalV0_corrected_multip_pi;
   Double_t        track1ExpectedTPCSignalV0_corrected_multip_pr;
   Double_t        track0tpcNsigma_corrected_pileup_el;
   Double_t        track0tpcNsigma_corrected_pileup_pi;
   Double_t        track0tpcNsigma_corrected_pileup_pr;
   Double_t        track1tpcNsigma_corrected_pileup_el;
   Double_t        track1tpcNsigma_corrected_pileup_pi;
   Double_t        track1tpcNsigma_corrected_pileup_pr;
   Double_t        track0ExpectedTPCSignalV0_corrected_pileup_el;
   Double_t        track0ExpectedTPCSignalV0_corrected_pileup_pi;
   Double_t        track0ExpectedTPCSignalV0_corrected_pileup_pr;
   Double_t        track1ExpectedTPCSignalV0_corrected_pileup_el;
   Double_t        track1ExpectedTPCSignalV0_corrected_pileup_pi;
   Double_t        track1ExpectedTPCSignalV0_corrected_pileup_pr;
   Double_t        track0tpcNsigma_corrected_eta_multip_el;
   Double_t        track0tpcNsigma_corrected_eta_multip_pi;
   Double_t        track0tpcNsigma_corrected_eta_multip_pr;
   Double_t        track1tpcNsigma_corrected_eta_multip_el;
   Double_t        track1tpcNsigma_corrected_eta_multip_pi;
   Double_t        track1tpcNsigma_corrected_eta_multip_pr;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_multip_el;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_multip_pi;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_multip_pr;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_multip_el;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_multip_pi;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_multip_pr;
   Double_t        track0tpcNsigma_corrected_eta_pileup_el;
   Double_t        track0tpcNsigma_corrected_eta_pileup_pi;
   Double_t        track0tpcNsigma_corrected_eta_pileup_pr;
   Double_t        track1tpcNsigma_corrected_eta_pileup_el;
   Double_t        track1tpcNsigma_corrected_eta_pileup_pi;
   Double_t        track1tpcNsigma_corrected_eta_pileup_pr;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_pileup_el;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_pileup_pi;
   Double_t        track0ExpectedTPCSignalV0_corrected_eta_pileup_pr;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_pileup_el;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_pileup_pi;
   Double_t        track1ExpectedTPCSignalV0_corrected_eta_pileup_pr;

   // List of branches
   TBranch        *b_v0_fPointAngle;   //!
   TBranch        *b_kf_fChi2;   //!
   TBranch        *b_K0Like;   //!
   TBranch        *b_ELike;   //!
   TBranch        *b_LLike;   //!
   TBranch        *b_ALLike;   //!
   TBranch        *b_cleanK0;   //!
   TBranch        *b_cleanGamma;   //!
   TBranch        *b_cleanLambda;   //!
   TBranch        *b_cleanALambda;   //!
   TBranch        *b_centV0;   //!
   TBranch        *b_centITS0;   //!
   TBranch        *b_centITS1;   //!
   TBranch        *b_tpcClusterMult;   //!
   TBranch        *b_multSSD;   //!
   TBranch        *b_multSDD;   //!
   TBranch        *b_tpcTrackBeforeClean;   //!
   TBranch        *b_triggerMask;   //!
   TBranch        *b_track0_fTPCsignal;   //!
   TBranch        *b_track1_fTPCsignal;   //!
   TBranch        *b_track0_fTPCsignalN;   //!
   TBranch        *b_track1_fTPCsignalN;   //!
   TBranch        *b_type;   //!
   TBranch        *b_track0P;   //!
   TBranch        *b_track0Pt;   //!
   TBranch        *b_track0Eta;   //!
   TBranch        *b_track0Phi;   //!
   TBranch        *b_track0Px;   //!
   TBranch        *b_track0Py;   //!
   TBranch        *b_track0Pz;   //!
   TBranch        *b_track0DCAxy;   //!
   TBranch        *b_track0DCAz;   //!
   TBranch        *b_track1P;   //!
   TBranch        *b_track1Pt;   //!
   TBranch        *b_track1Eta;   //!
   TBranch        *b_track1Phi;   //!
   TBranch        *b_track1Px;   //!
   TBranch        *b_track1Py;   //!
   TBranch        *b_track1Pz;   //!
   TBranch        *b_track1DCAxy;   //!
   TBranch        *b_track1DCAz;   //!
   TBranch        *b_track0tofNsigmaElectron;   //!
   TBranch        *b_track0tofNsigmaPion;   //!
   TBranch        *b_track0tofNsigmaKaon;   //!
   TBranch        *b_track0tofNsigmaProton;   //!
   TBranch        *b_track1tofNsigmaElectron;   //!
   TBranch        *b_track1tofNsigmaPion;   //!
   TBranch        *b_track1tofNsigmaKaon;   //!
   TBranch        *b_track1tofNsigmaProton;   //!
   TBranch        *b_track0tpcNsigma_no_corrected_el;   //!
   TBranch        *b_track0tpcNsigma_no_corrected_pi;   //!
   TBranch        *b_track0tpcNsigma_no_corrected_pr;   //!
   TBranch        *b_track1tpcNsigma_no_corrected_el;   //!
   TBranch        *b_track1tpcNsigma_no_corrected_pi;   //!
   TBranch        *b_track1tpcNsigma_no_corrected_pr;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_no_corrected_el;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_no_corrected_pi;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_no_corrected_pr;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_no_corrected_el;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_no_corrected_pi;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_no_corrected_pr;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_el;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_pi;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_pr;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_el;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_pi;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_pr;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_el;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_pi;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_pr;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_el;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_pi;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_pr;   //!
   TBranch        *b_track0tpcNsigma_corrected_multip_el;   //!
   TBranch        *b_track0tpcNsigma_corrected_multip_pi;   //!
   TBranch        *b_track0tpcNsigma_corrected_multip_pr;   //!
   TBranch        *b_track1tpcNsigma_corrected_multip_el;   //!
   TBranch        *b_track1tpcNsigma_corrected_multip_pi;   //!
   TBranch        *b_track1tpcNsigma_corrected_multip_pr;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_multip_el;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_multip_pi;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_multip_pr;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_multip_el;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_multip_pi;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_multip_pr;   //!
   TBranch        *b_track0tpcNsigma_corrected_pileup_el;   //!
   TBranch        *b_track0tpcNsigma_corrected_pileup_pi;   //!
   TBranch        *b_track0tpcNsigma_corrected_pileup_pr;   //!
   TBranch        *b_track1tpcNsigma_corrected_pileup_el;   //!
   TBranch        *b_track1tpcNsigma_corrected_pileup_pi;   //!
   TBranch        *b_track1tpcNsigma_corrected_pileup_pr;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_pileup_el;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_pileup_pi;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_pileup_pr;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_pileup_el;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_pileup_pi;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_pileup_pr;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_multip_el;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_multip_pi;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_multip_pr;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_multip_el;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_multip_pi;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_multip_pr;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_multip_el;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_multip_pi;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_multip_pr;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_multip_el;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_multip_pi;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_multip_pr;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_pileup_el;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_pileup_pi;   //!
   TBranch        *b_track0tpcNsigma_corrected_eta_pileup_pr;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_pileup_el;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_pileup_pi;   //!
   TBranch        *b_track1tpcNsigma_corrected_eta_pileup_pr;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_pileup_el;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_pileup_pi;   //!
   TBranch        *b_track0ExpectedTPCSignalV0_corrected_eta_pileup_pr;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_pileup_el;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_pileup_pi;   //!
   TBranch        *b_track1ExpectedTPCSignalV0_corrected_eta_pileup_pr;   //!


  
  V0FlatAna();
  ~V0FlatAna();

  virtual Int_t    Cut(Long64_t entry);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
  

  ClassDef(V0FlatAna, 1);
};


#endif
