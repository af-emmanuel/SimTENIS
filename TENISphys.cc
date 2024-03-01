#include "TENISphys.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"


TENISphysicsList::TENISphysicsList()
{

    RegisterPhysics (new G4EmStandardPhysics());
    RegisterPhysics (new G4OpticalPhysics());

}

TENISphysicsList::~TENISphysicsList()
{}

