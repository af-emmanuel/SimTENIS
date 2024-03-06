#include "TENISEvent.hh"

TENISEventAction::TENISEventAction(TENISRunAction*)
{
    fEdep=0.;
}

TENISEventAction::~TENISEventAction()
{
}

void TENISEventAction ::BeginOfEventAction(const G4Event*){
    fEdep=0;
} 

void TENISEventAction:: EndOfEventAction(const G4Event*){

    G4cout <<"energy deposited: "<<fEdep<<G4endl;

    G4AnalysisManager *man=G4AnalysisManager::Instance();

}