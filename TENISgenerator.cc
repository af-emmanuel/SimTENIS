#include "TENISgenerator.hh"

TENISPrimaryGenerator::TENISPrimaryGenerator()
{
    fparticleGun=new G4ParticleGun(1);  //one primary vertex per event
}

TENISPrimaryGenerator::~TENISPrimaryGenerator()
{
    delete fparticleGun;
}

void TENISPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleTable *particleTable =G4ParticleTable::GetParticleTable();
    G4String particleName="proton";
    G4ParticleDefinition *particle=particleTable->FindParticle(particleName);
    G4ThreeVector pos(0.,0.,0.); //position of particle creation
    G4ThreeVector mom (0.,0.,1.); //PARTICLE MOMENTUM direction

    fparticleGun->SetParticlePosition(pos);
    fparticleGun->SetParticleMomentumDirection(mom);
    fparticleGun->SetParticleMomentum(100.*GeV);  //high energy
    fparticleGun->SetParticleDefinition(particle);

    fparticleGun->GeneratePrimaryVertex(anEvent);



}
