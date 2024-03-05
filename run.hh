#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"

class TENISRunAction: public G4UserRunAction
{
    public:
        TENISRunAction();
        ~TENISRunAction();

        virtual void BeginOfRunAction(const G4Run*);
        virtual void EndOfRunAction(const G4Run *);


};

#endif