#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include  "TENISDetectorConstruction.hh"
#include  "TENISEvent.hh"
#include  "G4Track.hh"
#include  "G4ParticleDefinition.hh"

class TENISSteppingAction:public G4UserSteppingAction
{
    public:
        TENISSteppingAction(TENISEventAction*eventAction);
        ~TENISSteppingAction();

        virtual void UserSteppingAction(const G4Step*);

    private:
        TENISEventAction *fEventAction;


};

#endif