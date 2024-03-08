#include "TENISphys.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4HadronElasticPhysicsXS.hh"
#include "G4HadronPhysicsFTFP_BERT_HP.hh"


#include "G4ParticleHPElastic.hh"
#include "G4ParticleHPElasticData.hh"
#include "G4ParticleHPThermalScattering.hh"
#include "G4ParticleHPThermalScatteringData.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronicProcess.hh"
#include "G4IonElasticPhysics.hh"
#include "G4IonPhysics.hh"
#include "G4HadronElasticPhysicsXS.hh"
#include "G4StoppingPhysics.hh"
//#include "GammaNuclearPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4IonPhysicsXS.hh"

//partly borrowed from neutronSource physicslist extended example, hadr05
//from maire Geant4
//you do not have to define G4NeutronCaptureProcess here. 
//It is already included in G4HadronPhysicsFTFP_BERT_HP

TENISphysicsList::TENISphysicsList()
{
    G4int verbos=0;
    SetVerboseLevel(verbos);

    RegisterPhysics (new G4EmStandardPhysics());
    //RegisterPhysics (new G4OpticalPhysics());

///// for the hadron inelestic processes //////////////////////////
    RegisterPhysics( new G4HadronPhysicsFTFP_BERT(verbos));
    //RegisterPhysics(new G4HadronPhysicsQGSP_BIC_HP(verbos));
    //RegisterPhysics(new G4HadronInelasticQBBC(verbos));
  

/// for the hadron elastic processes
  //RegisterPhysics(new G4HadronElasticPhysics(verbos));
  RegisterPhysics( new G4HadronElasticPhysicsXS(verbos) );  

////////////////////////////ion/////////////////////
///// Ion Elastic scattering
    RegisterPhysics( new G4IonElasticPhysics(verbos));
  
////// Ion Inelastic physics
  RegisterPhysics( new G4IonPhysicsXS(verbos));
  ////RegisterPhysics( new G4IonINCLXXPhysics(verb));
  
  // stopping Particles
  RegisterPhysics( new G4StoppingPhysics(verbos));
      
  // Gamma-Nuclear Physics  ///////////////////////////////
  //RegisterPhysics( new GammaNuclearPhysics("gamma"));
  ////RegisterPhysics( new GammaNuclearPhysicsLEND("gamma"));
    RegisterPhysics( new G4EmExtraPhysics());


}

TENISphysicsList::~TENISphysicsList()
{}

