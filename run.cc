#include "run.hh"


TENISRunAction::TENISRunAction()
{}

TENISRunAction::~TENISRunAction()
{}


void TENISRunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man= G4AnalysisManager:: Instance();
    man->OpenFile("output.root");

}

void TENISRunAction::EndOfRunAction(const G4Run *)
{

    G4AnalysisManager *man= G4AnalysisManager:: Instance();

    man->Write();
    man->CloseFile();

}

