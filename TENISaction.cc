#include "TENISaction.hh"
#include "run.hh"

TENISActionInitialization::TENISActionInitialization()
{}
TENISActionInitialization::~TENISActionInitialization()
{}


void TENISActionInitialization::Build() const
{

	TENISPrimaryGenerator *generator = new TENISPrimaryGenerator();
    SetUserAction(generator);

    TENISRunAction*runact=new TENISRunAction();
    SetUserAction(runact);

    TENISEventAction*eventAction=new TENISEventAction(runact);
    SetUserAction(eventAction);

    TENISSteppingAction*steppingAction=new TENISSteppingAction(eventAction);
    SetUserAction(steppingAction);
}