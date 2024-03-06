#include "TENISgenerator.hh"

TENISPrimaryGenerator::TENISPrimaryGenerator()
{
    
    fGeneralParticleSource=new G4GeneralParticleSource();  //one primary vertex per event

    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName="proton";
    G4ParticleDefinition *particle=particleTable->FindParticle(particleName);
    G4ThreeVector pos(0.,0.,0.); //position of particle creation
    G4ThreeVector mom (0.,0.,1.); //PARTICLE MOMENTUM direction

    //fparticleGun=new G4ParticleGun(1);  //one primary vertex per event
    // fparticleGun->SetParticlePosition(pos);
    // fparticleGun->SetParticleMomentumDirection(mom);
    // fparticleGun->SetParticleMomentum(100.*GeV);  //high energy
    // fparticleGun->SetParticleDefinition(particle);
    
}

TENISPrimaryGenerator::~TENISPrimaryGenerator()
{
   // delete fparticleGun;
    delete fGeneralParticleSource;
}

void TENISPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{

    //fparticleGun->GeneratePrimaryVertex(anEvent);

    fGeneralParticleSource->GeneratePrimaryVertex(anEvent);

    //these two important lines too to connect to event action class
    G4EventManager*evtMan=G4EventManager::GetEventManager();
    TENISEventAction *evtac=(TENISEventAction*)evtMan->GetUserEventAction();
    

}
