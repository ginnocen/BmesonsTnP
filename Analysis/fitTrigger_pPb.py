import FWCore.ParameterSet.Config as cms

process = cms.Process("TagProbe")

process.load('FWCore.MessageService.MessageLogger_cfi')
process.source = cms.Source("EmptySource")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )

process.TnP_Trigger = cms.EDAnalyzer("TagProbeFitTreeAnalyzer", 
    ## Input, output 
    #InputFileNames = cms.vstring("file:../Inputs/tnpJPsi_MC_19October_testtriggerHyunchul_testtag_v1.root"), 
    #OutputFileName = cms.string("../ResultsFit/outputTriggerMC.root"),
    InputFileNames = cms.vstring("file:../Inputs/tnpJPsi_Data_LastRuns_19October_testtriggerHyunchul_testtag_v1.root"), 
    OutputFileName = cms.string("../ResultsFit/outputTriggerData.root"),
    InputTreeName = cms.string("fitter_tree"),
    InputDirectoryName = cms.string("tpTree"),
    ## Variables for binning
    Variables = cms.PSet(
        mass   = cms.vstring("Tag-Probe Mass", "2.9", "3.3", "GeV/c^{2}"),
        pt     = cms.vstring("Probe p_{T}", "0", "1000", "GeV/c"),
        eta    = cms.vstring("Probe #eta", "-2.5", "2.5", ""),
        abseta = cms.vstring("Probe |#eta|", "0", "2.5", ""),
    ),
    ## Flags you want to use to define numerator and possibly denominator
    Categories = cms.PSet(
	PAMu3 = cms.vstring("PAMu3", "dummy[pass=1,fail=0]"),
	PAMu3_standard = cms.vstring("PAMu3_standard", "dummy[pass=1,fail=0]"),
	tag_PAMu3 = cms.vstring("tag_PAMu3", "dummy[pass=1,fail=0]"),
	tag_PAMu3_standard = cms.vstring("tag_PAMu3_standard", "dummy[pass=1,fail=0]"),
	Acc_JPsi= cms.vstring("Acc_JPsi", "dummy[pass=1,fail=0]"),	
	TrackCuts= cms.vstring("TrackCuts", "dummy[pass=1,fail=0]"),
	MuonID= cms.vstring("MuonID", "dummy[pass=1,fail=0]"),
	
    ),
    ## What to fit
    Efficiencies = cms.PSet(
        Trg_pt_all = cms.PSet(
            UnbinnedVariables = cms.vstring("mass"),
            EfficiencyCategoryAndState = cms.vstring("PAMu3_standard", "pass"), ## Numerator definition
            BinnedVariables = cms.PSet(
                ## Binning in continuous variables
                eta = cms.vdouble(-2.4,2.4),
                pt = cms.vdouble(1.5,3.,4.5,6.,9.,30.),
                ## flags and conditions required at the denominator, 
                tag_PAMu3_standard = cms.vstring("pass"), 
                Acc_JPsi = cms.vstring("pass"), 
                TrackCuts = cms.vstring("pass"), 
                MuonID = cms.vstring("pass"), 
            ),
            BinToPDFmap = cms.vstring("cbGaussPlusExpo"), ## PDF to use, as defined below
        ),
        Trg_pt_etabin0 = cms.PSet(
            UnbinnedVariables = cms.vstring("mass"),
            EfficiencyCategoryAndState = cms.vstring("PAMu3_standard", "pass"), ## Numerator definition
            BinnedVariables = cms.PSet(
                ## Binning in continuous variables
                eta = cms.vdouble(-2.4,-0.8),
                pt = cms.vdouble(1.5,3.,4.5,6.,9.,30.),
                ## flags and conditions required at the denominator, 
                tag_PAMu3_standard = cms.vstring("pass"), 
                Acc_JPsi = cms.vstring("pass"), 
                TrackCuts = cms.vstring("pass"), 
                MuonID = cms.vstring("pass"), 
            ),
            BinToPDFmap = cms.vstring("cbGaussPlusExpo"), ## PDF to use, as defined below
        ),

        Trg_pt_etabin1 = cms.PSet(
            UnbinnedVariables = cms.vstring("mass"),
            EfficiencyCategoryAndState = cms.vstring("PAMu3_standard", "pass"), ## Numerator definition
            BinnedVariables = cms.PSet(
                ## Binning in continuous variables
                eta = cms.vdouble(-0.8,0.8),
                pt = cms.vdouble(1.5,3.,4.5,6.,9.,30.),
                ## flags and conditions required at the denominator, 
                tag_PAMu3_standard = cms.vstring("pass"), 
                Acc_JPsi = cms.vstring("pass"), 
                TrackCuts = cms.vstring("pass"), 
                MuonID = cms.vstring("pass"), 
            ),
            BinToPDFmap = cms.vstring("cbGaussPlusExpo"), ## PDF to use, as defined below
        ),
        Trg_pt_etabin2 = cms.PSet(
            UnbinnedVariables = cms.vstring("mass"),
            EfficiencyCategoryAndState = cms.vstring("PAMu3_standard", "pass"), ## Numerator definition
            BinnedVariables = cms.PSet(
                ## Binning in continuous variables
                eta = cms.vdouble(0.8,2.4),
                pt = cms.vdouble(1.5,3.,4.5,6.,9.,30.),
                ## flags and conditions required at the denominator, 
                tag_PAMu3_standard = cms.vstring("pass"), 
                Acc_JPsi = cms.vstring("pass"), 
                TrackCuts = cms.vstring("pass"), 
                MuonID = cms.vstring("pass"), 
            ),
            BinToPDFmap = cms.vstring("cbGaussPlusExpo"), ## PDF to use, as defined below
        ),
    ),

    ## PDF for signal and background (double voigtian + exponential background)
    PDFs = cms.PSet(

    cbGaussPlusExpo = cms.vstring(
        "CBShape::signal1(mass, mean[3.1,3.0,3.2], sigma1[0.01,0.01,0.1], alpha[0.5, 0.2, 3.0], n[2, 0.5, 100.])",
		"Gaussian::signal2(mass, mean[3.1, 3.0, 3.2], sigma2[0.04,0.01,0.1])",
		"SUM::signal(signal1,vFrac[0.8,0,1]*signal2)",
        "Exponential::backgroundPass(mass, lp[0,-5,5])",
        "Exponential::backgroundFail(mass, lf[0,-5,5])",
        "efficiency[0.9,0,1]",
        "signalFractionInPassing[0.9]"
      ),

    ),


    ## How to do the fit
    binnedFit = cms.bool(True),
    binsForFit = cms.uint32(100),
    saveDistributionsPlot = cms.bool(True),
    NumCPU = cms.uint32(1), ## leave to 1 for now, RooFit gives funny results otherwise
    SaveWorkspace = cms.bool(True),
)

process.p = cms.Path(process.TnP_Trigger)
