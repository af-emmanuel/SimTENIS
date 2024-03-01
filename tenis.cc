#include <iostream>
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"

#include "TENISDetectorConstruction.hh"
#include "TENISphys.hh"
#include "TENISaction.hh"
#include "TENISgenerator.hh"




int main(int argc,char**argv)
{

//standard procedures in geant4/////////////////
    G4RunManager*runManager = new G4RunManager();
	
	//set all important initialisations
    runManager->SetUserInitialization(new TENISDetectorConstruction());
    runManager->SetUserInitialization(new TENISphysicsList());
    runManager->SetUserInitialization(new TENISActionInitialization());


    runManager->Initialize(); //this will create errors if all the steps and events actions are not in place

    G4UIExecutive *ui=new G4UIExecutive(argc, argv);

    G4VisManager *visManager = new G4VisExecutive();

    visManager->Initialize();

    G4UImanager *UImanager=G4UImanager::GetUIpointer();
	
	//here we instruct about the visualisation of the geometry //////////
    UImanager->ApplyCommand("/vis/open OGL");  //tell Geant4 to show geometry
    UImanager->ApplyCommand("/vis/drawVolume"); //tell Geant4 to show geometry
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1"); 
	UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");  //refresh images for new runs?
	UImanager->ApplyCommand("/vis/scene/add/trajectories smooth"); //show trajectories of particles

    ui->SessionStart();
/////////////////////////////////////

    return 0;
}