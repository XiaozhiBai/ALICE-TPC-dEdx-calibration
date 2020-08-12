
#include "TObject.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "V0FlatAna.h"
//#include "TrackFaltAna.h"

class TH2F;
class THnSparse;
class TArrayF;
template <class X>
class THnSparseT;
typedef class THnSparseT<TArrayF> THnSparseF;


class AliSkimmedDataAnalysisMaker :public TObject {

  
 public:
  AliSkimmedDataAnalysisMaker(const char*);
  //const char*
  virtual ~AliSkimmedDataAnalysisMaker();

  void bookHistogram();
  void read_V0(TString filename);
  void read_Nuclei(TString filename);

  void WriteHistogram();
  void BinLogAxis(THnSparseF *h, Int_t axisNumber);
  void SetAxisNamesFromTitle(const THnSparseF *h);
  

 private:

  // const int ndim_splineQA=12;

  static  const int kNdim_clean_v0=16;
  
  TFile*  mOutputFile;
 TH2F*  mh2pTdEdxVspT;

 
 TH2F* pileUp_cut;
 TH2F *mh2pTdEdxVspT_K0Like;
 TH2F *mh2pTdEdxVspT_ELike;
 TH2F *mh2pTdEdxVspT_LLike;
 TH2F *mh2pTdEdxVspT_ALLike;

 TH2F *mh2dEdxVspT_Electron;

 TH2F *mh2dEdxVspT_Pion;
 TH2F *mh2dEdxVspT_Proton;

 TH2F *mh2dEdxVspT_lowpProton;
 TH2F *mh2dEdxVspT_Nuclei;


 
 THnSparseF* fHistPidQA;
 THnSparseF* fHistPid_separation_power;

 THnSparse* clean_gamma_electron;
 THnSparse* clean_k0_pion;
 THnSparse* clean_lambda_proton;

 THnSparse* clean_gamma_electron_only_eta_corr;
 THnSparse* clean_k0_pion_only_eta_corr;
 THnSparse* clean_lambda_proton_only_eta_corr;

 THnSparse* clean_gamma_electron_only_multi_corr;
 THnSparse* clean_k0_pion_only_multi_corr;
 THnSparse* clean_lambda_proton_only_multi_corr;

 THnSparse* clean_gamma_electron_only_pileup_corr;
 THnSparse* clean_k0_pion_only_pileup_corr;
 THnSparse* clean_lambda_proton_only_pileup_corr;

 
  ClassDef(AliSkimmedDataAnalysisMaker,1);
};
