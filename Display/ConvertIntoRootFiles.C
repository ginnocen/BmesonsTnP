#include <iostream>
#include <TSystem.h>
#include <TTree.h>
#include <TKey.h>
#include <TH1.h>
#include <TH2.h>
#include <TPave.h>
#include <TText.h>
#include <fstream>
#include <sstream>
#include <string.h>

#include <TROOT.h>
#include <TFile.h>
#include <TGraphAsymmErrors.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLegend.h>

#include <TStyle.h>
#include <TLatex.h>
#include <TDirectory.h>
#include <TCollection.h>
#include <TPostScript.h>

using namespace RooFit;
using namespace std;


void ConvertIntoRootFiles();
TH2F *plotEff2D(RooDataSet *a, TString b);
TGraphAsymmErrors *plotEffPt(RooDataSet *a, int aa);
TGraphAsymmErrors *plotEffEta(RooDataSet *a, int aa);

const int nbins = 5;
const int etabins=1;



void ConvertIntoRootFiles(TString id="Trg") {

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetTitle(0);

  char *infileMC;
  char *infileData;
  char *rootstring_etabin0;
  char *rootstring_etabin1;
  char *rootstring_etabin2;
  char *rootstring_pt_all;
  char *rootstring_eta_all;
  char *outfile;
  
  if(id=="Trg"){
   infileMC= "../ResultsFit/outputTriggerMC.root";
   infileData= "../ResultsFit/outputTriggerData.root";
   rootstring_etabin0="tpTree/Trg_pt_etabin0/fit_eff";
   rootstring_etabin1="tpTree/Trg_pt_etabin1/fit_eff";
   rootstring_etabin2="tpTree/Trg_pt_etabin2/fit_eff";
   rootstring_pt_all="tpTree/Trg_pt_all/fit_eff";
   rootstring_eta_all="tpTree/Trg_eta_all/fit_eff";
   outfile="Results/foutputTrigger.root";
  }
  
  if(id=="Trk"){
   infileMC= "../ResultsFit/outputTrackingMC.root";
   infileData= "../ResultsFit/outputTrackingData.root";
   rootstring_etabin0="tpTreeSta/Trk_pt_etabin0/fit_eff";
   rootstring_etabin1="tpTreeSta/Trk_pt_etabin1/fit_eff";
   rootstring_etabin2="tpTreeSta/Trk_pt_etabin2/fit_eff";
   rootstring_pt_all="tpTreeSta/Trk_pt_all/fit_eff";
   rootstring_eta_all="tpTreeSta/Trk_eta_all/fit_eff";
   outfile="Results/foutputTracking.root";
  }
  
  if(id=="MuonID"){
   infileMC= "../ResultsFit/outputMuonIDMC.root";
   infileData= "../ResultsFit/outputMuonIDData.root";
   rootstring_etabin0="tpTree/MuID_pt_etabin0/fit_eff";
   rootstring_etabin1="tpTree/MuID_pt_etabin1/fit_eff";
   rootstring_etabin2="tpTree/MuID_pt_etabin2/fit_eff";
   rootstring_pt_all="tpTree/MuID_pt_all/fit_eff";
   rootstring_eta_all="tpTree/MuID_eta_all/fit_eff";
   outfile="Results/foutputMuonID.root";
  }
  
  
  TFile *fMC = new TFile(infileMC);
  TFile *fData = new TFile(infileData);
  RooDataSet *daPtMC_etabin0 = (RooDataSet*)fMC->Get(rootstring_etabin0);
  RooDataSet *daPtMC_etabin1 = (RooDataSet*)fMC->Get(rootstring_etabin1);
  RooDataSet *daPtMC_etabin2 = (RooDataSet*)fMC->Get(rootstring_etabin2);
  RooDataSet *daPtMC_all = (RooDataSet*)fMC->Get(rootstring_pt_all);
  RooDataSet *daEtaMC_all = (RooDataSet*)fMC->Get(rootstring_eta_all);

  RooDataSet *daPtData_etabin0 = (RooDataSet*)fData->Get(rootstring_etabin0);
  RooDataSet *daPtData_etabin1 = (RooDataSet*)fData->Get(rootstring_etabin1);
  RooDataSet *daPtData_etabin2 = (RooDataSet*)fData->Get(rootstring_etabin2);
  RooDataSet *daPtData_all = (RooDataSet*)fData->Get(rootstring_pt_all);
  RooDataSet *daEtaData_all = (RooDataSet*)fData->Get(rootstring_eta_all);

  
  TGraphAsymmErrors *fEff_pt_etabin0_MC = plotEffPt(daPtMC_etabin0, 1);
  TGraphAsymmErrors *fEff_pt_etabin1_MC = plotEffPt(daPtMC_etabin1, 1);
  TGraphAsymmErrors *fEff_pt_etabin2_MC = plotEffPt(daPtMC_etabin2, 1);
  TGraphAsymmErrors *fEff_pt_all_MC = plotEffPt(daPtMC_all, 1);
  TGraphAsymmErrors *fEff_eta_all_MC = plotEffEta(daEtaMC_all, 1);


  TGraphAsymmErrors *fEff_pt_etabin0_Data = plotEffPt(daPtData_etabin0, 1);
  TGraphAsymmErrors *fEff_pt_etabin1_Data = plotEffPt(daPtData_etabin1, 1);
  TGraphAsymmErrors *fEff_pt_etabin2_Data = plotEffPt(daPtData_etabin2, 1);
  TGraphAsymmErrors *fEff_pt_all_Data = plotEffPt(daPtData_all, 1);
  TGraphAsymmErrors *fEff_eta_all_Data = plotEffEta(daEtaData_all, 1);

   
  fEff_pt_etabin0_MC->SetName("fEff_pt_etabin0_MC");
  fEff_pt_etabin1_MC->SetName("fEff_pt_etabin1_MC");
  fEff_pt_etabin2_MC->SetName("fEff_pt_etabin2_MC");
  fEff_pt_all_MC->SetName("fEff_pt_all_MC");
  fEff_eta_all_MC->SetName("fEff_eta_all_MC");
  
  
  fEff_pt_etabin0_Data->SetName("fEff_pt_etabin0_Data");
  fEff_pt_etabin1_Data->SetName("fEff_pt_etabin1_Data");
  fEff_pt_etabin2_Data->SetName("fEff_pt_etabin2_Data");
  fEff_pt_all_Data->SetName("fEff_pt_all_Data");
  fEff_eta_all_Data->SetName("fEff_eta_all_Data");

  
 // for (int i=0;i<ptbins;i++){
 //  for (int j=0;j<etabins;j++){
 //   TCanvas *canvasMC = (TCanvas*)fMC->Get(Form("tpTree/MuID_pt/eta_bin%d_pt_bin%d_Acc_JPsi_GlobalCuts_pass_cbGaussPlusExpo/fit_canvas",j,i));
 //   canvasMC->SaveAs(Form("Plots/canvas_ptbin_%d_etabin_%d",i,j));
 //   }
 // 
 // }
    
  TFile*foutput=new TFile(outfile,"recreate");
  foutput->cd();
  fEff_pt_etabin0_MC->Write();
  fEff_pt_etabin1_MC->Write();
  fEff_pt_etabin2_MC->Write();
  fEff_pt_all_MC->Write();
  fEff_eta_all_MC->Write();

  
  fEff_pt_etabin0_Data->Write();
  fEff_pt_etabin1_Data->Write();
  fEff_pt_etabin2_Data->Write();
  fEff_pt_all_Data->Write();
  fEff_eta_all_Data->Write();

}


TGraphAsymmErrors *plotEffPt(RooDataSet *a, int aa){
    const RooArgSet *set = a->get();
    RooRealVar *xAx = (RooRealVar*)set->find("pt");
    RooRealVar *eff = (RooRealVar*)set->find("efficiency");

    //const int nbins = xAx->getBinning().numBins();

    double tx[nbins], txhi[nbins], txlo[nbins];
    double ty[nbins], tyhi[nbins], tylo[nbins];

    for (int i=0; i<nbins; i++) {
        a->get(i);
        ty[i] = eff->getVal();
        tx[i] = xAx->getVal();
        txhi[i] = fabs(xAx->getErrorHi());
        txlo[i] = fabs(xAx->getErrorLo()); 
        tyhi[i] = fabs(eff->getErrorHi());
        tylo[i] = fabs(eff->getErrorLo()); 
    }

    cout<<"NBins : "<<nbins<<endl;

    const double *x = tx;
    const double *xhi = txhi;
    const double *xlo = txlo;
    const double *y = ty;
    const double *yhi = tyhi;
    const double *ylo = tylo;

    TGraphAsymmErrors *b = new TGraphAsymmErrors();
    if(aa == 1) {*b = TGraphAsymmErrors(nbins,x,y,xlo,xhi,ylo,yhi);}
    if(aa == 0) {*b = TGraphAsymmErrors(nbins,x,y,0,0,ylo,yhi);}
    b->SetMaximum(1.1);
    b->SetMinimum(0.0);
    b->SetMarkerStyle(20);
    b->SetMarkerColor(kRed+2);
    b->SetMarkerSize(1.0);
    b->SetTitle("");
    b->GetXaxis()->SetTitleSize(0.05);
    b->GetYaxis()->SetTitleSize(0.05);
    b->GetXaxis()->SetTitle("p_{T} [GeV/c]");
    b->GetYaxis()->SetTitle("Efficiency");
    b->GetXaxis()->CenterTitle();
    b->Draw("apz");

    for (int i=0; i<nbins; i++) {
        cout << x[i] << " " << y[i] << " " << yhi[i] << " " << ylo[i] << endl;
    }

    return b;

}


TGraphAsymmErrors *plotEffEta(RooDataSet *a, int aa){
    const RooArgSet *set = a->get();
    RooRealVar *xAx = (RooRealVar*)set->find("eta");
    RooRealVar *eff = (RooRealVar*)set->find("efficiency");

    //const int nbins = xAx->getBinning().numBins();
    const int nbins = 3;

    double tx[nbins], txhi[nbins], txlo[nbins];
    double ty[nbins], tyhi[nbins], tylo[nbins];

    for (int i=0; i<nbins; i++) {
        a->get(i);
        ty[i] = eff->getVal();
        tx[i] = xAx->getVal();
        txhi[i] = fabs(xAx->getErrorHi());
        txlo[i] = fabs(xAx->getErrorLo()); 
        tyhi[i] = fabs(eff->getErrorHi());
        tylo[i] = fabs(eff->getErrorLo()); 
    }

    cout<<"NBins : "<<nbins<<endl;

    const double *x = tx;
    const double *xhi = txhi;
    const double *xlo = txlo;
    const double *y = ty;
    const double *yhi = tyhi;
    const double *ylo = tylo;

    TGraphAsymmErrors *b = new TGraphAsymmErrors();
    if(aa == 1) {*b = TGraphAsymmErrors(nbins,x,y,xlo,xhi,ylo,yhi);}
    if(aa == 0) {*b = TGraphAsymmErrors(nbins,x,y,0,0,ylo,yhi);}
    b->SetMaximum(1.1);
    b->SetMinimum(0.0);
    b->SetMarkerStyle(20);
    b->SetMarkerColor(kRed+2);
    b->SetMarkerSize(1.0);
    b->SetTitle("");
    b->GetXaxis()->SetTitleSize(0.05);
    b->GetYaxis()->SetTitleSize(0.05);
    b->GetXaxis()->SetTitle("#eta");
    b->GetYaxis()->SetTitle("Efficiency");
    b->GetXaxis()->CenterTitle();
    b->Draw("apz");

    for (int i=0; i<nbins; i++) {
        cout << x[i] << " " << y[i] << " " << yhi[i] << " " << ylo[i] << endl;
    }

    return b;

}

TH2F *plotEff2D(RooDataSet *a, TString b){
    const RooArgSet *set = a->get();
    RooRealVar *yAx = (RooRealVar*)set->find("pt");
    RooRealVar *xAx = (RooRealVar*)set->find("eta");
    RooRealVar *eff = (RooRealVar*)set->find("efficiency");

    //const int xnbins = xAx->getBinning().numBins();
    //const int ynbins = yAx->getBinning().numBins();

    const double *xvbins = xAx->getBinning().array();
    const double *yvbins = yAx->getBinning().array();

    TH2F* h = new TH2F(b, "", xAx->getBinning().numBins(), xvbins, yAx->getBinning().numBins(), yvbins);

    gStyle->SetPaintTextFormat("5.2f");
    gStyle->SetPadRightMargin(0.12);
    gStyle->SetPalette(1);
    h->SetOption("colztexte");
    h->GetZaxis()->SetRangeUser(-0.001,1.001);
    h->SetStats(kFALSE);
    h->GetYaxis()->SetTitle("p_{T} [GeV/c]");
    h->GetXaxis()->SetTitle("#eta");
    h->GetXaxis()->CenterTitle();
    h->GetYaxis()->CenterTitle();
    h->GetXaxis()->SetTitleSize(0.05);
    h->GetYaxis()->SetTitleSize(0.05);
    h->GetYaxis()->SetTitleOffset(0.8);
    h->GetXaxis()->SetTitleOffset(0.9);
    for(int i=0; i<a->numEntries(); i++){
        a->get(i);
        h->SetBinContent(h->FindBin(xAx->getVal(), yAx->getVal()), eff->getVal());
        h->SetBinError(h->FindBin(xAx->getVal(), yAx->getVal()), (eff->getErrorHi()-eff->getErrorLo())/2.);
    }

    return h;

}
