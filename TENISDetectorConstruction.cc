#include "TENISDetectorConstruction.hh"
#include "G4Tubs.hh"

TENISDetectorConstruction::TENISDetectorConstruction(){
    tenmat=new TENISMaterials(); //instance of the material class
}

TENISDetectorConstruction::~TENISDetectorConstruction(){
    delete tenmat;
}

G4VPhysicalVolume *TENISDetectorConstruction::Construct()
{   

    G4NistManager*nist = G4NistManager::Instance();

//////////////world volume//////////////////////////////////////////////
    //G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
    //air=tenmat->Air;
    G4Material *worldMat =tenmat->GetMaterial("Air");

    G4Box *solidWorld = new G4Box("solidWorld",3*m,3*m,0.5*14*m);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,worldMat,"logicWorld");

    G4VPhysicalVolume *physicalWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicWorld,"physicalWorld", 0,false,0,true);

////////////////////////////

    G4Material *Concrete =tenmat->GetMaterial("Air");
    G4double rmax, rmin, dphi,dz;
    rmax = 1*m;
    rmin = rmax/5;
    dz = 2 *m;
    G4VSolid* solidBarrel = new G4Tubs("Barrel", rmin, rmax, dz, 0., 2*M_PI);
    G4LogicalVolume* logicBarrel = new G4LogicalVolume(solidBarrel, Concrete, "Barrel");
    G4VPhysicalVolume *physBarrel = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logicBarrel,"physBarrel",logicWorld,false,0);

    return physicalWorld;

}