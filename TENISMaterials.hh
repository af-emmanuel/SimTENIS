/// TENISMaterials.hh




#ifndef TENISMATERIALS_HH
#define TENISMATERIALS_HH


#include "G4MaterialPropertiesTable.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4MaterialPropertyVector.hh"
#include "G4NistManager.hh"
#include <fstream>
#include <iostream>
#include "G4UnitsTable.hh"
#include "G4ThreeVector.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4Scintillation.hh"

class TENISMaterials
{

private:

  static const G4String path;
  
public:

  //TENISMaterials(G4String prop_buildfile);
  TENISMaterials();
  ~TENISMaterials();
  void Construct();

  int good =20;

public:
  G4Material *GetMaterial(G4String);

  G4Element* elementH;
	G4Element* elementLi;
  G4Element* elementC;
  G4Element* elementO;
  G4Element* elementF;
  G4Element* elementTi;
  G4Element* elementSi;
  G4Element* elementB;
  G4Element* elementNa;
  G4Element* elementAl;
  G4Element* elementN;
  G4Element* elementFe;
  G4Element* elementNi;
	G4Element* elementCa;
  G4Element* elementCr;
  G4Element* elementMn;
  G4Element* elementCu;
  G4Element* elementSn;
  G4Element* elementSb;
  G4Element* elementMg;
  G4Element* elementZn;
  G4Element* elementCl;
  G4Element* elementK;
  G4Element* elementPb;
  G4Element* elementLa;
  G4Element* elementBr;
  G4Element* elementW;
  G4Element* elementAu;
  G4Element* elementCd;
  G4Element* elementTe;

  G4Isotope* Fe56;

  G4Material *SiO2;
  G4Material *B2O3;
  G4Material *Na2O;
  G4Material *Al2O3;
  G4Material *Air;
  G4Material *Fer;
  G4Material *Inox;
  G4Material *Cuivre;
  G4Material *Carbon;
  G4Material *Kapton;
  G4Material *Acier;
  G4Material *N2;
  G4Material *H2O;
  G4Material *Polypropylene;
  G4Material *Compensation;
  G4Material *Papier;
  G4Material *Silicon;
  G4Material *Nylon;
  G4Material *teflon;
  G4Material *mousse;
  G4Material *Neoprene;
  G4Material *Mica;
  G4Material *Plomb_Antimoine;
  G4Material *Plomb;
  G4Material *LaBr3;
  G4Material *bs_glass;
  G4Material *polysty;
  G4Material *Ti02;
  G4Material *coating;
  G4Material *scintillator;
  G4Material *Vacuum;
  G4Material *VacuumWorld;
  G4Material *plastic;
  G4Material *mylar;
  G4Material *grease;
  G4Material *cargille;
  G4Material *PMMA;
  G4Material *Alu;
  G4Material* Tungstene;
  G4Material* Or;
  G4Material* CdTe;
	G4Material* BN_ceramic;
	G4Material* B2O5;
	G4Material* Oxygen;
	G4Material* Calcium;
	G4Material* G4_BORON_CARBIDE;
	G4Material* G4_POLYETHYLENE;
	G4Material* C5H8;
	G4Material* Elastobore;
	G4Material*Al;
	G4Material*Concrete;
	G4Material*Low_alloy_Steel;
	G4Material*LiF;


};

#endif
