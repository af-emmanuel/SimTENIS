#include "TENISaction.hh"

TENISActionInitialization::TENISActionInitialization()
{}
TENISActionInitialization::~TENISActionInitialization()
{}


void TENISActionInitialization::Build() const
{

	TENISPrimaryGenerator *generator = new TENISPrimaryGenerator();
    SetUserAction(generator);
}