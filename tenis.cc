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

    G4UIExecutive *ui= 0;  //for now it points to nothing

    if(argc ==1) //number of command line argument 
    {
    
        ui= new G4UIExecutive(argc, argv);

    }

    G4VisManager *visManager = new G4VisExecutive();

    visManager->Initialize();
    G4UImanager *UImanager=G4UImanager::GetUIpointer();

    if (ui)  //i.e argc is indeed one.
    {
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }
    else  //if argc != 1 or no ui
    {
        G4String command ="/control/execute ";
        G4String fileName=argv[1];  //command line argument
        UImanager->ApplyCommand(command+fileName);
    }
/////////////////////////////////////

    return 0;
}