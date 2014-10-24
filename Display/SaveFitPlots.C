void SaveFitPlots(TString data="MC",TString type="MuonID",TString etabin="all"){

  TFile *file = new TFile(Form("../ResultsFit/output%s%s.root",type.Data(),data.Data()));
  
  TDirectory *dir;  
  TCanvas *canvas;
  
  for (int ipt=0;ipt<5;ipt++){
  
  
  if(type=="Trigger")dir=(TDirectory*)file->GetDirectory(Form("tpTree/Trg_pt_%s/eta_bin0__pt_bin%d__Acc_JPsi_pass__MuonID_pass__TrackCuts_pass__tag_PAMu3_standard_pass__cbGaussPlusExpo",etabin.Data(),ipt));
  if(type=="MuonID") dir=(TDirectory*)file->GetDirectory(Form("tpTree/MuID_pt_%s/eta_bin0__pt_bin%d__Acc_JPsi_pass__TrackCuts_pass__tag_PAMu3_standard_pass__cbGaussPlusExpo",etabin.Data(),ipt));
  if(type=="Tracking") dir=(TDirectory*)file->GetDirectory(Form("tpTreeSta/Trk_pt_%s/eta_bin0__pt_bin%d__Acc_JPsi_pass__tag_PAMu3_standard_pass__twoGaussPlusPoly1",etabin.Data(),ipt));

   canvas=(TCanvas*)dir->Get("fit_canvas");

   canvas->SaveAs(Form("PlotsFit/canvas%s_%s_PtBin%d_%s.pdf",type.Data(),data.Data(),ipt,etabin.Data()));
  }
}