rm an.log
rm Results/*.root
rm Plots/*.pdf
rm PlotsFit/*.pdf


#-----------------------ConvertIntoRootFiles-------------------

time root -b > an.log 2>&1 <<EOI
.x ConvertIntoRootFiles.C("Trg")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x ConvertIntoRootFiles.C("Trk")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x ConvertIntoRootFiles.C("MuonID")
.q
EOI

#-----------------------CompareMCData-------------------

time root -b > an.log 2>&1 <<EOI
.x CompareMCData.C("Trg")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x CompareMCData.C("Trk")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x CompareMCData.C("MuonID")
.q
EOI

#-----------------------CompareMCData-------------------



time root -b > an.log 2>&1 <<EOI
.x CompareMethods.C("Trg","Pt","MC")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x CompareMethods.C("Trk","Pt","MC")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x CompareMethods.C("MuID","Pt","MC")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x CompareMethods.C("Trg","Pt","Data")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x CompareMethods.C("Trk","Pt","Data")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x CompareMethods.C("MuID","Pt","Data")
.q
EOI


#-----------------------save plots-------------------



time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Trigger","all")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Tracking","all")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","MuonID","all")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Trigger","all")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Tracking","all")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","MuonID","all")
.q
EOI

#---------

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Trigger","etabin0")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Tracking","etabin0")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","MuonID","etabin0")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Trigger","etabin0")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Tracking","etabin0")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","MuonID","etabin0")
.q
EOI

#---------

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Trigger","etabin1")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Tracking","etabin1")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","MuonID","etabin1")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Trigger","etabin1")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Tracking","etabin1")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","MuonID","etabin1")
.q
EOI

#---------

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Trigger","etabin2")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","Tracking","etabin2")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("Data","MuonID","etabin2")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Trigger","etabin2")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","Tracking","etabin2")
.q
EOI

time root -b > an.log 2>&1 <<EOI
.x SaveFitPlots.C("MC","MuonID","etabin2")
.q
EOI



