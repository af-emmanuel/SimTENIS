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

}