

#ifndef TENISDETECTORCONSTRUCTION_HH
#define TENISDETECTORCONSTRUCTION_HH


#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "TENISMaterials.hh"


class TENISDetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        TENISDetectorConstruction();
        ~TENISDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();  //constrcuts the whole detector geometry.The whole detector has to be put into that fucntion
        //virtual because it is defined in the class implemented in geant4 

        G4Material*air;
        TENISMaterials*tenmat;

        
};



#endif