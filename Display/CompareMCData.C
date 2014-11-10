
void CompareMCData(TString id="Trg") {

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetTitle(0);

  char *infile;

  if(id=="Trg"){
   infile= "Results/foutputTrigger.root";
  }
  
  if(id=="Trk"){
   infile= "Results/foutputTracking.root";
  }
  
  if(id=="MuonID"){
   infile= "Results/foutputMuonID.root";
  }
  
  
  TFile *file = new TFile(infile);

  TGraphAsymmErrors *fEff_pt_MC =(TGraphAsymmErrors*)file->Get("fEff_pt_all_MC");
  TGraphAsymmErrors *fEff_pt_Data =(TGraphAsymmErrors*)file->Get("fEff_pt_all_Data");
  TGraphAsymmErrors *fEff_eta_MC =(TGraphAsymmErrors*)file->Get("fEff_eta_all_MC");
  TGraphAsymmErrors *fEff_eta_Data =(TGraphAsymmErrors*)file->Get("fEff_eta_all_Data");


  TCanvas *canvaspt=new TCanvas("canvaspt","canvaspt",500,500);   
  canvaspt->cd();
  canvaspt->Range(-1.989924,-0.2917772,25.49622,2.212202);
  canvaspt->SetFillColor(0);
  canvaspt->SetBorderMode(0);
  canvaspt->SetBorderSize(2);
  canvaspt->SetLeftMargin(0.1451613);
  canvaspt->SetRightMargin(0.05443548);
  canvaspt->SetTopMargin(0.08474576);
  canvaspt->SetBottomMargin(0.1165254);
  canvaspt->SetFrameBorderMode(0);
  canvaspt->SetFrameBorderMode(0);

  
  TH2F* hemptyPt=new TH2F("hemptyPt","",10,0.,30,10.,0,1.1);  
  hemptyPt->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hemptyPt->GetYaxis()->SetTitle(Form("Eff %s",id.Data()));
  hemptyPt->GetXaxis()->SetTitleOffset(1.);
  hemptyPt->GetYaxis()->SetTitleOffset(1.3);
  hemptyPt->GetXaxis()->SetTitleSize(0.045);
  hemptyPt->GetYaxis()->SetTitleSize(0.045);
  hemptyPt->GetXaxis()->SetTitleFont(42);
  hemptyPt->GetYaxis()->SetTitleFont(42);
  hemptyPt->GetXaxis()->SetLabelFont(42);
  hemptyPt->GetYaxis()->SetLabelFont(42);
  hemptyPt->GetXaxis()->SetLabelSize(0.04);
  hemptyPt->GetYaxis()->SetLabelSize(0.04);  
  hemptyPt->SetMaximum(1.1);
  hemptyPt->SetMinimum(0.);
  hemptyPt->Draw();
    
  
  fEff_pt_MC->SetMarkerColor(1);
  fEff_pt_MC->SetMarkerStyle(21);  
  fEff_pt_MC->SetLineColor(1);
  fEff_pt_MC->SetLineWidth(2);
  fEff_pt_MC->Draw("epsame");
  
  fEff_pt_Data->SetMarkerColor(2);
  fEff_pt_Data->SetMarkerStyle(21);  
  fEff_pt_Data->SetLineColor(2);
  fEff_pt_Data->SetLineWidth(2);
  fEff_pt_Data->Draw("epsame");
  
  TLegend *legendpt=new TLegend(0.3770161,0.2881356,0.8245968,0.4194915,"");
  legendpt->SetBorderSize(0);
  legendpt->SetTextFont(42);
  legendpt->SetTextSize(0.04);

  TLegendEntry *ent_MC=legendpt->AddEntry(fEff_pt_MC,"Monte Carlo","pf");
  ent_MC->SetTextFont(42);
  ent_MC->SetLineColor(1);
  ent_MC->SetMarkerColor(1);
  
  TLegendEntry *ent_Data=legendpt->AddEntry(fEff_pt_Data,"Data","pf");
  ent_Data->SetTextFont(42);
  ent_Data->SetLineColor(1);
  ent_Data->SetMarkerColor(1);
  
  legendpt->Draw();
  canvaspt->SaveAs(Form("Plots/canvaspt%s.pdf",id.Data()));
  

  TCanvas *canvaseta=new TCanvas("canvaseta","canvaseta",500,500);   
  canvaseta->cd();
  canvaseta->Range(-1.989924,-0.2917772,25.49622,2.212202);
  canvaseta->SetFillColor(0);
  canvaseta->SetBorderMode(0);
  canvaseta->SetBorderSize(2);
  canvaseta->SetLeftMargin(0.1451613);
  canvaseta->SetRightMargin(0.05443548);
  canvaseta->SetTopMargin(0.08474576);
  canvaseta->SetBottomMargin(0.1165254);
  canvaseta->SetFrameBorderMode(0);
  canvaseta->SetFrameBorderMode(0);

  
  TH2F* hemptyEta=new TH2F("hemptyEta","",10,-3.,3.,10.,0,1.1);  
  hemptyEta->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hemptyEta->GetYaxis()->SetTitle(Form("Eff %s",id.Data()));
  hemptyEta->GetXaxis()->SetTitleOffset(1.);
  hemptyEta->GetYaxis()->SetTitleOffset(1.3);
  hemptyEta->GetXaxis()->SetTitleSize(0.045);
  hemptyEta->GetYaxis()->SetTitleSize(0.045);
  hemptyEta->GetXaxis()->SetTitleFont(42);
  hemptyEta->GetYaxis()->SetTitleFont(42);
  hemptyEta->GetXaxis()->SetLabelFont(42);
  hemptyEta->GetYaxis()->SetLabelFont(42);
  hemptyEta->GetXaxis()->SetLabelSize(0.04);
  hemptyEta->GetYaxis()->SetLabelSize(0.04);  
  hemptyEta->SetMaximum(1.1);
  hemptyEta->SetMinimum(0.);
  hemptyEta->Draw();
    
  
  fEff_eta_MC->SetMarkerColor(1);
  fEff_eta_MC->SetMarkerStyle(21);  
  fEff_eta_MC->SetLineColor(1);
  fEff_eta_MC->SetLineWidth(2);
  fEff_eta_MC->Draw("epsame");
  
  fEff_eta_Data->SetMarkerColor(2);
  fEff_eta_Data->SetMarkerStyle(21);  
  fEff_eta_Data->SetLineColor(2);
  fEff_eta_Data->SetLineWidth(2);
  fEff_eta_Data->Draw("epsame");
  
  TLegend *legendeta=new TLegend(0.3770161,0.2881356,0.8245968,0.4194915,"");
  legendeta->SetBorderSize(0);
  legendeta->SetTextFont(42);
  legendeta->SetTextSize(0.04);

  TLegendEntry *ent_MC=legendeta->AddEntry(fEff_eta_MC,"Monte Carlo","pf");
  ent_MC->SetTextFont(42);
  ent_MC->SetLineColor(1);
  ent_MC->SetMarkerColor(1);
  
  TLegendEntry *ent_Data=legendeta->AddEntry(fEff_eta_Data,"Data","pf");
  ent_Data->SetTextFont(42);
  ent_Data->SetLineColor(1);
  ent_Data->SetMarkerColor(1);
  
  legendeta->Draw();
  canvaseta->SaveAs(Form("Plots/canvaseta%s.pdf",id.Data()));
  




}