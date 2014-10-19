void SaveFitPlots(TString data="Data",TString type="Trigger"){

  TFile *file = new TFile(Form("../ResultsFit/output%s%s.root",type.Data(),data.Data()));
  
  TDirectory *dir;  
  TCanvas *canvas;
  
  for (int ipt=0;ipt<9;ipt++){
  
  
  if(type=="Trigger")dir=(TDirectory*)file->GetDirectory(Form("tpTree/Trg_pt/eta_bin0__pt_bin%d__Acc_JPsi_pass__MuonID_pass__TrackCuts_pass__tag_PAMu3_standard_pass__cbGaussPlusExpo",ipt));
  if(type=="MuonID") dir=(TDirectory*)file->GetDirectory(Form("tpTree/MuID_pt/eta_bin0__pt_bin%d__Acc_JPsi_pass__TrackCuts_pass__tag_PAMu3_standard_pass__cbGaussPlusExpo",ipt));
  if(type=="Tracking") dir=(TDirectory*)file->GetDirectory(Form("tpTreeSta/Trk_pt/eta_bin0__pt_bin%d__Acc_JPsi_pass__tag_PAMu3_standard_pass__twoGaussPlusPoly1",ipt));

   canvas=(TCanvas*)dir->Get("fit_canvas");

   canvas->SaveAs(Form("PlotsFit/canvas%s_%s_PtBin%d.pdf",type.Data(),data.Data(),ipt));
  }
}