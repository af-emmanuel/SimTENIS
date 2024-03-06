#include "TENISSteppingAction.hh"


TENISSteppingAction::TENISSteppingAction(TENISEventAction*eventAction)
{
    fEventAction=eventAction;
}

TENISSteppingAction::~TENISSteppingAction()
{

}

void TENISSteppingAction:: UserSteppingAction(const G4Step* aStep)  //most important function
{

    G4Track* aTrack=aStep->GetTrack();
    G4String particleName=aTrack->GetDefinition()->GetParticleName();

    G4cout<< "particle name  "<<particleName <<G4endl;

    G4double edep =aStep->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);
}