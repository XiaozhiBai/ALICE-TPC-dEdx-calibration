
#include <iostream>
#include "V0FlatAna.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2F.h"
#include "TF1.h"
#include "THnSparse.h"
#include "AliSkimmedDataAnalysisMaker.h"

using namespace std;

bool pileUp_cut_flag=true;

ClassImp(AliSkimmedDataAnalysisMaker);

AliSkimmedDataAnalysisMaker::AliSkimmedDataAnalysisMaker( const char * outName) {
  cout<< outName<<endl;
  mOutputFile=new TFile(outName,"RECREATE");
}
AliSkimmedDataAnalysisMaker::~AliSkimmedDataAnalysisMaker(){
  //~
}
void AliSkimmedDataAnalysisMaker::bookHistogram()
{
  mh2pTdEdxVspT=new TH2F("mh2pTdEdxVspT","",1500,0,15,500,0,1000);
  mh2pTdEdxVspT_K0Like=new TH2F("mh2pTdEdxVspT_K0Like","",1500,0,15,500,0,1000);
  mh2pTdEdxVspT_ELike=new TH2F("mh2pTdEdxVspT_ELike","",1500,0,15,500,0,1000);
  mh2pTdEdxVspT_LLike=new TH2F("mh2pTdEdxVspT_LLike","",1500,0,15,500,0,1000);
  mh2pTdEdxVspT_ALLike=new TH2F("mh2pTdEdxVspT_ALLike","",1500,0,15,500,0,1000);

  mh2dEdxVspT_Electron=new TH2F("mh2dEdxVspT_Electron","",1500,0,15,500,0,1000);
  mh2dEdxVspT_Pion=new TH2F("mh2dEdxVspT_Pion","",1500,0,15,500,0,1000);
  mh2dEdxVspT_Proton=new TH2F("mh2dEdxVspT_Proton","",1500,0,15,500,0,1000);

  mh2dEdxVspT_lowpProton=new TH2F("mh2dEdxVspT_lowpProton","",500,0,5,500,0,1000);
  mh2dEdxVspT_Nuclei=new TH2F("mh2dEdxVspT_Nuclei","",500,0,5,500,0,1000);


  //  300,0.,6e6,AliReducedVarManager::kNTPCclusters,300,0.,50000,AliReducedVarManager::kTotaSDDandSSDcluster);

  pileUp_cut=new TH2F("pileUp_cut","",300,0.,6e6,300,0.,50000);
  

  TString  name="fHistPidQA";
  TString  title="fHistPidQA";

  //SetAxisNamesFromTitle(fThnspTpc);
  // BinLogAxis(fThnspTpc, 8);
  
  bool IsPbPb=true;
  const Int_t kNdim = 7;
  Int_t    binsHistQA[kNdim] = {135, 1980,    4,    5, 40, 10,  IsPbPb ? 40 : 40 };
  Double_t xminHistQA[kNdim] = {0.1,   20., -0.5, -0.5, -10., -5.,   0.};
  Double_t xmaxHistQA[kNdim] = {50., 2000.,  3.5,  4.5,  10.,  5., IsPbPb ? 20000. : 4000.};
  fHistPidQA = new THnSparseF(name.Data(), title.Data(), kNdim, binsHistQA, xminHistQA, xmaxHistQA);

  BinLogAxis(fHistPidQA, 0);
  SetAxisNamesFromTitle(fHistPidQA);

  
  
  const Int_t kNdim_separation_power = 5;
  //p,dedx,eta,centrality,particle
  Int_t    binsHist_separation_power[kNdim_separation_power] = {15, 1980,   20,    100, 4}; 
  Double_t xminHist_separation_power[kNdim_separation_power] = {0,   20.,   -1,    0,  0.};
  Double_t xmaxHist_separation_power[kNdim_separation_power] = {15., 2000.,  1.,  100,  4.};
  fHistPid_separation_power = new THnSparseF("fHistPid_separation_power","fHistPid_separation_power", kNdim_separation_power, binsHist_separation_power, xminHist_separation_power, xmaxHist_separation_power);
  

  // for saperation power check

  //kNdim_clean_v0 = 12; // dedx, dedx_exp, Log(dedx-dedx_expe) , nsigma, p, eta, centrality , V0 cut, 



  // Int_t    binsHist_clean_v0[kNdim_clean_v0] = {200, 2000, 2000, 200, 400,  40,   100,  100,     80,   400,  400, 400 }; 
  // Double_t xminHist_clean_v0[kNdim_clean_v0] = {0.,  0.,   0.,   -50., -20.,  -1.,   0.,    0.,  -4.,  -20., -20., -20.};
  // Double_t xmaxHist_clean_v0[kNdim_clean_v0] = {20., 800., 200,   50.,  20.,    1.,   100.,  1.,  4.,  20.,  20.,   20.};

  
  // TString  clean_gamma_electron_title="";
  // clean_gamma_electron_title.Append(";p (GeV/c);tpc signal; tpc signal _expected; diff(tpc_signa;nsigma;eta;centrality;GammaLike;nSigmaTOF");
  // clean_gamma_electron = new THnSparseF("clean_gamma_electron",clean_gamma_electron_title, kNdim_clean_v0, binsHist_clean_v0, xminHist_clean_v0, xmaxHist_clean_v0);

  // TString  clean_k0_pi_title="";
  // clean_k0_pi_title.Append(";p (GeV/c);tpc signal; tpc signal _expected; diff(tpc_signa;nsigma;eta;centrality;K0Like;nSigmaTOF");
  // clean_k0_pion = new THnSparseF("clean_k0_pion",clean_k0_pi_title, kNdim_clean_v0, binsHist_clean_v0, xminHist_clean_v0, xmaxHist_clean_v0);

  // TString  clean_lambda_proton_title="";
  // clean_lambda_proton_title.Append(";p (GeV/c);tpc signal; tpc signal _expected; diff(tpc_signa;nsigma;eta;centrality;ALLike;nSigmaTOF");
  // clean_lambda_proton = new THnSparseF("clean_lambda_proton",clean_lambda_proton_title, kNdim_clean_v0, binsHist_clean_v0, xminHist_clean_v0, xmaxHist_clean_v0);

  Int_t    binsHist_clean_v0[kNdim_clean_v0] = {200, 40,   100,   2000,   400,   400,   400,  400,  400,   400,   200,   200,   200,  200,  200,   200}; 
  Double_t xminHist_clean_v0[kNdim_clean_v0] = {0.,  -1.,   0.,    0.,    -20.,  -20., -20.,  -20.,  -20., -20,   -10.,  -10.,  -10., -10., -10.,  -10.};
  Double_t xmaxHist_clean_v0[kNdim_clean_v0] = {20., 1.,   100.,   800.,   20.,   20.,  20.,  20.,   20.,  20.,   10.,   10.,    10.,  10.,  10.,   10.};

  
  TString  clean_gamma_electron_title="";
  clean_gamma_electron_title.Append(";p (GeV/c); eta; centrality; tpc signal; diff(dedx_expeced eta correction); diff(dedx_expeced multi correction); diff(dedx_expeced pileup correction); diff(dedx_expeced eta and muti. correction); diff(dedx_expeced eta+mui+pileup correction);diff(dedx_expeced no correction; tpc nsigma eta correction; tpc nsigma multi correction; tpc nsigma pileup correction; tpc nsigma eta and muti. correction; tpc nsigma eta+mui+pileup correction;tpc nsigma no correction");



  clean_gamma_electron = new THnSparseF("clean_gamma_electron",clean_gamma_electron_title, kNdim_clean_v0, binsHist_clean_v0, xminHist_clean_v0, xmaxHist_clean_v0);

  TString  clean_k0_pi_title="";
  clean_k0_pi_title.Append(";p (GeV/c); eta; centrality; tpc signal; diff(dedx_expeced eta correction); diff(dedx_expeced multi correction); diff(dedx_expeced pileup correction); diff(dedx_expeced eta and muti. correction); diff(dedx_expeced eta+mui+pileup correction);diff(dedx_expeced no correction; tpc nsigma eta correction; tpc nsigma multi correction; tpc nsigma pileup correction; tpc nsigma eta and muti. correction; tpc nsigma eta+mui+pileup correction;tpc nsigma no correction");

  clean_k0_pion = new THnSparseF("clean_k0_pion",clean_k0_pi_title, kNdim_clean_v0, binsHist_clean_v0, xminHist_clean_v0, xmaxHist_clean_v0);

  TString  clean_lambda_proton_title="";
  clean_lambda_proton_title.Append(";p (GeV/c); eta; centrality; tpc signal; diff(dedx_expeced eta correction); diff(dedx_expeced multi correction); diff(dedx_expeced pileup correction); diff(dedx_expeced eta and muti. correction); diff(dedx_expeced eta+mui+pileup correction);diff(dedx_expeced no correction; tpc nsigma eta correction; tpc nsigma multi correction; tpc nsigma pileup correction; tpc nsigma eta and muti. correction; tpc nsigma eta+mui+pileup correction;tpc nsigma no correction");

  clean_lambda_proton = new THnSparseF("clean_lambda_proton",clean_lambda_proton_title, kNdim_clean_v0, binsHist_clean_v0, xminHist_clean_v0, xmaxHist_clean_v0);




  


}

void AliSkimmedDataAnalysisMaker::read_V0(TString fileName)
{
  cout<<"!!!!!!!!!!!!!!!!!read"<<fileName<<endl;
  TFile * infile=new TFile(fileName.Data());
  TTree* Tree=(TTree*) infile->Get("V0Flat");
  V0FlatAna *V0ana=new V0FlatAna();
  V0ana->Init(Tree);

  TF1 *fpol2=new TF1(TString("fpol2"),"[0]+[1]*x+[2]*x*x",0,1e9);
  fpol2->SetParameter(0,-3000);
  fpol2->SetParameter(1,0.0099);
  fpol2->SetParameter(2,9.426e-10);

  
  for(Int_t iV0=0;iV0<Tree->GetEntries();iV0++) 
    {
      if(iV0%1000==0)
	cout<<"working on Event  "<<iV0<<endl;

      V0ana->GetEntry(iV0);
      mh2pTdEdxVspT->Fill(V0ana->track0P,V0ana->track0_fTPCsignal);
      mh2pTdEdxVspT->Fill(V0ana->track1P,V0ana->track1_fTPCsignal);



      if(pileUp_cut_flag)
      	{
	  Double_t ssdsdd_corr_cut=fpol2->Eval(V0ana->tpcClusterMult);


	  if((V0ana->multSSD+V0ana->multSDD)<ssdsdd_corr_cut)
	    continue;
	
	  
	}
      pileUp_cut->Fill(V0ana->tpcClusterMult,V0ana->multSSD+V0ana->multSDD);
      if(V0ana->K0Like>0.85)
	{
	  mh2pTdEdxVspT_K0Like->Fill(V0ana->track0P,V0ana->track0_fTPCsignal);
	  mh2pTdEdxVspT_K0Like->Fill(V0ana->track1P,V0ana->track1_fTPCsignal);
	}

      if(V0ana->ELike>0.85)
	{
	  mh2pTdEdxVspT_ELike->Fill(V0ana->track0P,V0ana->track0_fTPCsignal);
	  mh2pTdEdxVspT_ELike->Fill(V0ana->track1P,V0ana->track1_fTPCsignal);
	}
      if(V0ana->LLike>0.85)
	{
	  mh2pTdEdxVspT_LLike->Fill(V0ana->track0P,V0ana->track0_fTPCsignal);
	  mh2pTdEdxVspT_LLike->Fill(V0ana->track1P,V0ana->track1_fTPCsignal);
	}
      if(V0ana->ALLike>0.85)
	{
	  mh2pTdEdxVspT_ALLike->Fill(V0ana->track0P,V0ana->track0_fTPCsignal);
	  mh2pTdEdxVspT_ALLike->Fill(V0ana->track1P,V0ana->track1_fTPCsignal);
	}

      //kNdim_clean_v0 track0DCAxy

      if((V0ana->cleanGamma==1)&&V0ana->ELike>0.85){

	Double_t vecHist_clean_el_track0[kNdim_clean_v0] = {V0ana->track0P,V0ana->track0Eta,V0ana->centV0,V0ana->track0_fTPCsignal, 

							    V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_no_corrected_el,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_el,
							    V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_multip_el,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_pileup_el,
							    V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_multip_el,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_pileup_el,

							    V0ana->track0tpcNsigma_no_corrected_el, V0ana->track0tpcNsigma_corrected_eta_el,
							    V0ana->track0tpcNsigma_corrected_multip_el,V0ana->track0tpcNsigma_corrected_pileup_el,
							    V0ana->track0tpcNsigma_corrected_eta_multip_el,V0ana->track0tpcNsigma_corrected_eta_pileup_el};

	Double_t vecHist_clean_el_track1[kNdim_clean_v0] = {V0ana->track1P,V0ana->track1Eta,V0ana->centV0,V0ana->track1_fTPCsignal, 

							    V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_no_corrected_el,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_el,
							    V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_multip_el,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_pileup_el,
							    V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_multip_el,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_pileup_el,

							    V0ana->track1tpcNsigma_no_corrected_el, V0ana->track1tpcNsigma_corrected_eta_el,
							    V0ana->track1tpcNsigma_corrected_multip_el,V0ana->track1tpcNsigma_corrected_pileup_el,
							    V0ana->track1tpcNsigma_corrected_eta_multip_el,V0ana->track1tpcNsigma_corrected_eta_pileup_el};

	
	//	cout<< " " << V0ana-> track0DCAxy<< "  "<< abs(V0ana-> track0DCAxy)<<endl;

      	if(((V0ana->track0tofNsigmaElectron<2.5&&-2.5<V0ana->track0tofNsigmaElectron)||V0ana->track0tofNsigmaElectron<-998)&&abs(V0ana->track0DCAxy)<3&&abs(V0ana->track0DCAz)<3)
      	  {
      	    clean_gamma_electron ->Fill(vecHist_clean_el_track0);
      	  }
      
	if(((V0ana->track1tofNsigmaElectron<2.5&&-2.5<V0ana->track1tofNsigmaElectron)||(V0ana->track1tofNsigmaElectron<-998))&&abs(V0ana->track1DCAxy)<3&&abs(V0ana->track1DCAz)<3)
      	  {
      	    clean_gamma_electron ->Fill(vecHist_clean_el_track1);
      	  }
      }


      if((V0ana->cleanK0==1)&&V0ana->K0Like>0.9){

	Double_t vecHist_clean_pi_track0[kNdim_clean_v0] = {V0ana->track0P,V0ana->track0Eta,V0ana->centV0,V0ana->track0_fTPCsignal, 

							    V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_no_corrected_pi,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_pi,
							    V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_multip_pi,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_pileup_pi,
							    V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_multip_pi,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_pileup_pi,

							    V0ana->track0tpcNsigma_no_corrected_pi, V0ana->track0tpcNsigma_corrected_eta_pi,
							    V0ana->track0tpcNsigma_corrected_multip_pi,V0ana->track0tpcNsigma_corrected_pileup_pi,
							    V0ana->track0tpcNsigma_corrected_eta_multip_pi,V0ana->track0tpcNsigma_corrected_eta_pileup_pi};



	Double_t vecHist_clean_pi_track1[kNdim_clean_v0] = {V0ana->track1P,V0ana->track1Eta,V0ana->centV0,V0ana->track1_fTPCsignal, 

							    V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_no_corrected_pi,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_pi,
							    V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_multip_pi,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_pileup_pi,
							    V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_multip_pi,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_pileup_pi,

							    V0ana->track1tpcNsigma_no_corrected_pi, V0ana->track1tpcNsigma_corrected_eta_pi,
							    V0ana->track1tpcNsigma_corrected_multip_pi,V0ana->track1tpcNsigma_corrected_pileup_pi,
							    V0ana->track1tpcNsigma_corrected_eta_multip_pi,V0ana->track1tpcNsigma_corrected_eta_pileup_pi};


	if(abs(V0ana->track0DCAxy)<3&&abs(V0ana->track0DCAz)<3)
	  {
	    clean_k0_pion ->Fill(vecHist_clean_pi_track0);
	  }
	if(abs(V0ana->track1DCAxy)<3&&abs(V0ana->track1DCAz)<3)
	  {
	    clean_k0_pion ->Fill(vecHist_clean_pi_track1);
	  }
      }

      
      if((V0ana->cleanLambda==1)&&V0ana->LLike>0.9){

	Double_t vecHist_clean_pro_track0[kNdim_clean_v0] = {V0ana->track0P,V0ana->track0Eta,V0ana->centV0,V0ana->track0_fTPCsignal, 

							     V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_no_corrected_pr,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_pr,
							     V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_multip_pr,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_pileup_pr,
							     V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_multip_pr,V0ana->track0_fTPCsignal-V0ana->track0ExpectedTPCSignalV0_corrected_eta_pileup_pr,

							     V0ana->track0tpcNsigma_no_corrected_pr, V0ana->track0tpcNsigma_corrected_eta_pr,
							     V0ana->track0tpcNsigma_corrected_multip_pr,V0ana->track0tpcNsigma_corrected_pileup_pr,
							     V0ana->track0tpcNsigma_corrected_eta_multip_pr,V0ana->track0tpcNsigma_corrected_eta_pileup_pr};

      	if((V0ana->track0tofNsigmaProton<2.5 && -2.5<V0ana->track0tofNsigmaProton)||(V0ana->track0tofNsigmaProton<-998)&&abs(V0ana->track0DCAxy)<3 && abs(V0ana->track0DCAz)<3)
      	  {
      	    clean_lambda_proton ->Fill(vecHist_clean_pro_track0);
      	  }
      }

      if((V0ana->cleanLambda==1)&&V0ana->ALLike>0.9){

	Double_t vecHist_clean_pro_track1[kNdim_clean_v0] = {V0ana->track1P,V0ana->track1Eta,V0ana->centV0,V0ana->track1_fTPCsignal, 

							     V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_no_corrected_pr,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_pr,
							     V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_multip_pr,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_pileup_pr,
							     V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_multip_pr,V0ana->track1_fTPCsignal-V0ana->track1ExpectedTPCSignalV0_corrected_eta_pileup_pr,

							     V0ana->track1tpcNsigma_no_corrected_pr, V0ana->track1tpcNsigma_corrected_eta_pr,
							     V0ana->track1tpcNsigma_corrected_multip_pr,V0ana->track1tpcNsigma_corrected_pileup_pr,
							     V0ana->track1tpcNsigma_corrected_eta_multip_pr,V0ana->track1tpcNsigma_corrected_eta_pileup_pr};



      	if((V0ana->track1tofNsigmaProton<2.5 && -2.5<V0ana->track1tofNsigmaProton)||V0ana->track1tofNsigmaProton<-998 && abs(V0ana->track1DCAxy)<3 && abs(V0ana->track1DCAz)<3)
      	  {
      	    clean_lambda_proton ->Fill(vecHist_clean_pro_track1);
      	  }
	
      }

      
      
      

      const Int_t numCases = 5;
      Double_t tpcQA[numCases];
      Double_t tofQA[numCases];
      for (Int_t i = 0; i < numCases; i++) {
	tpcQA[i] = 0.;
	tofQA[i] = 0.;
      }
      Int_t particleID = -1;
      Int_t  alicePID=-1;
      Double_t tpcsignal = -1.;
      Double_t tanTheta = -999.;
      Double_t precin = -1.;
      Double_t  nTotESDTracks=-999;
      Double_t tofNsigma=-9999;
      Double_t tpcNsigma=-9999;
      Double_t log_dedx_over_dedx_exp=-9999;
      Double_t dedx_exp=-9999;
      
      
      //V0
      for (Int_t track = 0; track < 2; track++) {

	bool isTreeK0=false;
	bool isTreeGamma=false;
	bool isTreeLambda=false;
	bool isTreeALambda=false;

	if(V0ana->K0Like>0.9&&(V0ana->cleanK0==1))
	  {
	    isTreeK0=true;   
	  }
	if(V0ana->ELike>0.9&&(V0ana->cleanGamma==1))
	  {
	    isTreeGamma=true;   
	  }

	if(V0ana->LLike>1.1&&(V0ana->cleanLambda==1)) // exclude it for the testing
	  {
	    isTreeLambda=true;   
	  }

	if(V0ana->ALLike>1.1&&(V0ana->cleanALambda==1)) // exclude it for the testing
	  {
	    isTreeALambda=true;   
	  }

	if(!(isTreeK0||isTreeGamma||isTreeLambda||isTreeALambda)) continue;
	
	if(track==0)
	  {
	    tpcsignal=V0ana->track0_fTPCsignal;
	    precin=V0ana->track0P;
	    tanTheta=V0ana->track1Eta;    

	    // tpcQA[0]=V0ana->track0tpcNsigma_el;
	    // tofQA[0]=V0ana->track0tofNsigmaElectron;

	    // tpcQA[1]=V0ana->track0tpcNsigma_pi;
	    // tofQA[1]=V0ana->track0tofNsigmaPion;

	    // tpcQA[2]=V0ana->track0tpcNsigma_ka;
	    // tofQA[2]=V0ana->track0tofNsigmaKaon;

	    // tpcQA[3]=V0ana->track0tpcNsigma_pro;
	    // tofQA[3]=V0ana->track0tofNsigmaProton;

	    // tpcQA[4]=V0ana->track0tpcNsigma_ka;
	    // tofQA[4]=V0ana->track0tofNsigmaKaon;
	    
	    
	    
	    
	  }
	else if(track==1)
	  {
	    tpcsignal=V0ana->track1_fTPCsignal;
	    precin=V0ana->track1P;
	    tanTheta=V0ana->track1Eta;    

	    // tpcQA[0]=V0ana->track1tpcNsigma_el;
	    // tofQA[0]=V0ana->track1tofNsigmaElectron;

	    // tpcQA[1]=V0ana->track1tpcNsigma_pi;
	    // tofQA[1]=V0ana->track1tofNsigmaPion;

	    // tpcQA[2]=V0ana->track1tpcNsigma_ka;
	    // tofQA[2]=V0ana->track1tofNsigmaKaon;

	    // tpcQA[3]=V0ana->track1tpcNsigma_pro;
	    // tofQA[3]=V0ana->track1tofNsigmaProton;

	    // tpcQA[4]=V0ana->track1tpcNsigma_ka;
	    // tofQA[4]=V0ana->track1tofNsigmaKaon;

	  }
	
	
	if (isTreeK0) {
	  particleID = 2; //pion
	  //	  alicePID=AliPID::kPion;
	  alicePID=2;
	  
	} else if (isTreeGamma) {
	  particleID = 1; // electron
	  //  alicePID=AliPID::kElectron;
	  alicePID=0;//AliPID::kElectron;
	} else if (isTreeLambda) {
	  if (track == 0) {
	    particleID = 3; // proton
	    //	    alicePID=AliPID::kProton;
	    alicePID=4.;
	  } else {
	    particleID = 2; // pion
	    //	    alicePID=AliPID::kPion;
	    alicePID=2;//AliPID::kPion;
	  }
	}
	else if (isTreeALambda) {
	  if (track == 0) {
	    particleID = 2; // pion
	    //	    alicePID=AliPID::kPion;
	    alicePID=2.;//AliPID::kPion;

	  } else {
	    particleID = 3; // proton
	    //alicePID=AliPID::kProton;
	    alicePID=4;;
	  }
	}

	// if(particleID==1)
	//   {
	//     if(track==0)
	//       {
	// 	tofNsigma=V0ana->track0tofNsigmaElectron;
	// 	tpcNsigma=V0ana
	//       }
	//     else{
	//       tofNsigma=V0ana->track0tofNsigmaElectron;
	//       tpcNsigma=V0ana->track0tpcNsigma_el;
	//     }
	//   }

	// if(particleID==2)
	//   {
	//     if(track==0)
	//       {
	// 	tofNsigma=V0ana->track0tofNsigmaPion;
	// 	tpcNsigma=V0ana->track0tpcNsigma_pi;
	//       }
	//     else
	//       {
	// 	tofNsigma=V0ana->track0tofNsigmaPion;
	// 	tofNsigma=V0ana->track0tofNsigmaPion;
	//       }
	//   }
	// if(particleID==3)
	//   {
	//     if(track==0)
	//       tofNsigma=V0ana->track0tofNsigmaProton;
	//     else
	//       tofNsigma=V0ana->track0tofNsigmaProton;
	//   }


	
	// processedTPCsignal[0] 
	//   processedTPCsignal[1]
	//   processedTPCsignal[2] 
	//   processedTPCsignal[3] 
	  
	
	//	if(abs(tofNsigma)>3&&tofNsigma>-99) continue;
	
	
	if(particleID==1&&isTreeGamma){
	  mh2dEdxVspT_Electron->Fill(precin,tpcsignal);
	}
	if(particleID==2&&(isTreeK0||(isTreeLambda&&track==1)||(isTreeALambda&&track==0))){
	  mh2dEdxVspT_Pion->Fill(precin,tpcsignal);
	}
	if(particleID==3&&(isTreeLambda&&track==0)||(isTreeALambda&&track==1)){
	  mh2dEdxVspT_Proton->Fill(precin,tpcsignal);
	}
	
	// make signal correction for transfer function and BB shape
	// TODO: Perhaps this should be steerable
	//const Double_t corrTransferBB = fPIDResponse->GetTPCResponse().GetCombinedTransferFunctionBBCorrection(trk, alicePID);
	//const Double_t corrTransferBB = fPIDResponse->GetTPCResponse().GetTransferFunctionCorrection(trk);
	//printf("signal: %.2f/%.2f = %.2f\n", tpcsignal, corrTransferBB, tpcsignal/corrTransferBB);
	//tpcsignal/=corrTransferBB;

	Double_t processedTPCsignal[5] = { tpcsignal, tpcsignal, tpcsignal, tpcsignal, tpcsignal };	

	nTotESDTracks=V0ana->tpcTrackBeforeClean;
	
	// id 5 is just again Kaons in restricted eta range
	processedTPCsignal[4] = processedTPCsignal[2];

	for(Int_t iPart = 0; iPart < numCases; iPart++) {
	  // Only accept "Kaons" within |eta| < 0.2 for index 4 (eta ~ tanTheta in this eta range)
	  if (iPart == 4 && abs(tanTheta) > 0.2)
	    continue;

	  Double_t vecHistQA[7] = {precin, processedTPCsignal[iPart], (Double_t)particleID, (Double_t)iPart, tpcQA[iPart], tofQA[iPart],
				   (Double_t)nTotESDTracks};
	  //cout << vecHistQA[0] << "\t" <<  vecHistQA[1] << "\t" <<  vecHistQA[2] << "\t" <<  vecHistQA[3] << "\t" <<  vecHistQA[4] << "\t" <<  vecHistQA[5] <<  endl;
	  fHistPidQA->Fill(vecHistQA);

	  
	  Double_t vecHist_separation_power[5] = {precin, tpcsignal, tanTheta, (Double_t) V0ana->centV0, (Double_t)particleID};
	
	  fHistPid_separation_power->Fill(vecHist_separation_power);

	  
	}
      }
      
      
      
      
    }
}


// void AliSkimmedDataAnalysisMaker::read_Nuclei(TString fileName)
// {
//   cout<<"!!!!!!!!!!!!!!!!!read"<<fileName<<endl;
//   TFile * infile=new TFile(fileName.Data());
//   TTree* Tree=(TTree*) infile->Get("ITSNucleiTriggerFlat");
//   NucleiFlat *V0ana=new NucleiFlat();
//   V0ana->Init(Tree);

//   for(Int_t iV0=0;iV0<Tree->GetEntries();iV0++) 
//     {
//       if(iV0%1000==0)
// 	cout<<"working on Event  "<<iV0<<endl;
//       V0ana->GetEntry(iV0);


//       if(V0ana-> ncrROCA>100){
// 	mh2dEdxVspT_Nuclei->Fill(V0ana->trackP,V0ana->esdTrack_fTPCsignal);      
//       }

//       if(V0ana-> ncrROCA>100&&V0ana->signal_BetheBlochSolid<11.6)
// 	{
// 	  mh2dEdxVspT_lowpProton->Fill(V0ana->trackP,V0ana->esdTrack_fTPCsignal);      
// 	  // mh2pTdEdxVspT_K0Like
// 	  // mh2pTdEdxVspT_K0Like->Fill(V0ana->track1P,V0ana->track1_fTPCsignal);
// 	}

      
      
//     }
// }
void AliSkimmedDataAnalysisMaker::WriteHistogram()
{

  cout<<"  write"<<endl;
  mOutputFile->cd();
  mh2pTdEdxVspT->Write();

  pileUp_cut->Write();
  mh2pTdEdxVspT_K0Like->Write();
  mh2pTdEdxVspT_ELike->Write();
  mh2pTdEdxVspT_LLike->Write();
  mh2pTdEdxVspT_ALLike->Write();

  mh2dEdxVspT_Electron->Write();
  mh2dEdxVspT_Pion->Write();
  mh2dEdxVspT_Proton->Write();

  mh2dEdxVspT_lowpProton->Write();
  mh2dEdxVspT_Nuclei->Write();
  
    
  fHistPidQA->Write();
  fHistPid_separation_power->Write();

  clean_gamma_electron->Write();
  clean_k0_pion->Write();
  clean_lambda_proton->Write();
    
}
  
void AliSkimmedDataAnalysisMaker::BinLogAxis(THnSparseF *h, Int_t axisNumber)
{
  //
  // Method for the correct logarithmic binning of histograms
  //
  TAxis *axis = h->GetAxis(axisNumber);
  int bins = axis->GetNbins();

  Double_t from = axis->GetXmin();
  Double_t to = axis->GetXmax();
  Double_t *newBins = new Double_t[bins + 1];

  newBins[0] = from;
  Double_t factor = pow(to/from, 1./bins);

  for (int i = 1; i <= bins; i++) {
    newBins[i] = factor * newBins[i-1];
  }
  axis->Set(bins, newBins);
  delete [] newBins;

}
void AliSkimmedDataAnalysisMaker::SetAxisNamesFromTitle(const THnSparseF *h)
{
  // set the histogram axis names from the axis titles
  for (Int_t i=0; i<h->GetNdimensions(); ++i) {
    h->GetAxis(i)->SetName(h->GetAxis(i)->GetTitle());
  }
}
