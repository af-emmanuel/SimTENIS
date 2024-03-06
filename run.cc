#include "run.hh"


TENISRunAction::TENISRunAction()
{}

TENISRunAction::~TENISRunAction()
{}


void TENISRunAction::BeginOfRunAction(const G4Run*run)
{
    G4AnalysisManager *man= G4AnalysisManager:: Instance();

    G4int runID=run->GetRunID();

    std::stringstream strRunID;
    strRunID<<runID;

    man->OpenFile("output.root"+strRunID.str()+".root");

}

void TENISRunAction::EndOfRunAction(const G4Run *)
{

    G4AnalysisManager *man= G4AnalysisManager:: Instance();

    man->Write();
    man->CloseFile();

}

