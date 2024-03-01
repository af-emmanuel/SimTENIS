#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"


class TENISPrimaryGenerator: public G4VUserPrimaryGeneratorAction
{
    public:
        TENISPrimaryGenerator();
       ~TENISPrimaryGenerator();

        virtual void GeneratePrimaries(G4Event*); 
    private:
        G4ParticleGun *fparticleGun;

};
#endif