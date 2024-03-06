#include "TENISDetectorConstruction.hh"

TENISDetectorConstruction::TENISDetectorConstruction(){
    tenmat=new TENISMaterials(); //instance of the material class
}

TENISDetectorConstruction::~TENISDetectorConstruction(){
    delete tenmat;
}

G4VPhysicalVolume *TENISDetectorConstruction::Construct()
{   
    

    G4NistManager*nist = G4NistManager::Instance();

    //G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
    //air=tenmat->Air;
    G4Material *worldMat =tenmat->GetMaterial("BN_ceramic");

    G4Box *solidWorld = new G4Box("solidWorld",0.5*m,0.5*m,0.5*m);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,worldMat,"logicWorld");

    G4VPhysicalVolume *physicalWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,"physicalWorld", 0,false,0,true);

    return physicalWorld;

}