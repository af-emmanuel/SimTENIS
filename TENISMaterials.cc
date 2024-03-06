#include "TENISMaterials.hh"





using namespace CLHEP;


// Used to set up all material properties.Careful of
// memory leaks.  Careful of files and how they are read in.
TENISMaterials::TENISMaterials()
{
	Construct(); //very important!!!! Links to the construct function when an instance is created in another class to access all objects defined in the construct function 

}

TENISMaterials::~TENISMaterials()
{
}


void TENISMaterials::Construct()
{

	G4double R = 8.3144621; //(en J/K/mole => Constante gaz parfait)
	G4double T = 273.15; //en K

 	G4double a,z,density,fractionmass;
 	G4String name,symbol;
	G4int ncomponents;

	//***********************
	// Define the Elements  *
	//***********************

	elementH = new G4Element( "Hydrogen", "H", 1, 1.00794*g/mole );
	elementLi = new G4Element( "Lithium", "Li", 3, 6.941*g/mole );
	elementC = new G4Element( "Carbon", "C", 6, 12.011*g/mole );
	elementCl = new G4Element( "Chlore", "Cl", 17, 35.453*g/mole );
	elementO = new G4Element( "Oxygen", "O", 8, 15.9994*g/mole );
	elementF = new G4Element ("Fluor", "F", 9., 18.9984032*g/mole);
	elementTi = new G4Element( "Titanium","Ti", 22, 47.88*g/mole);
	elementSi = new G4Element("Silicon","Si",14,28.0855*g/mole);
	elementB = new G4Element("Boron","B",5,10.811*g/mole);
	elementNa = new G4Element("Sodium","Na",11,22.989770*g/mole);
	elementAl = new G4Element("Aluminum","Al",13,26.981538*g/mole);
  	elementCa=new G4Element(name="Calcium","Ca",z=20.,40.08*g/mole);
	//elementFe = new G4Element ("Fer", "Fe", 26., 55.845*g/mole);
	elementNi = new G4Element ("Nickel", "Nickel", 28., 58.6939*g/mole);
	elementCr = new G4Element ("Chrome", "Chrome", 24., 51.9961*g/mole);
	elementMn = new G4Element ("Manganese", "Manganese", 25., 54.938044*g/mole);
	elementCu = new G4Element ("Cuivre", "Cuivre", 29., 63.546*g/mole);
	elementSn = new G4Element ("Etain", "Etain", 50., 118.71*g/mole);
	elementSb = new G4Element ("Antimoine", "Antimoine", 51., 121.760*g/mole);
	elementMg = new G4Element ("Magnesium", "Magnesium", 12., 24.305*g/mole);
	elementZn = new G4Element ("Zinc", "Zinc", 30., 65.38*g/mole);
	elementK = new G4Element ("Potassium", "Potassium", 19., 39.0983*g/mole);
	elementN = new G4Element ("Nitrogen", "N", 7., 14.01*g/mole);
	elementPb = new G4Element ("Plomb", "Plomb", 82., 207.2*g/mole);
	elementLa = new G4Element ("Lanthane", "Lanthane", 57., 138.90547*g/mole);
	elementBr = new G4Element ("Brome", "Brome", 35., 79.904*g/mole);
	elementW = new G4Element ("Tungsten", "Tungsten", 74., 183.84*g/mole);
	elementAu = new G4Element ("Au", "Au", 79., 196.966569*g/mole);
	elementCd = new G4Element ("Cadmium", "Cadmium", 48., 112.414*g/mole);
	elementTe = new G4Element ("Tellure", "Tellure", 52., 127.60*g/mole);
	Fe56 = new G4Isotope("Fe56", 26, 56);
	elementFe = new G4Element("Fer", "Fer", 1);
	elementFe->AddIsotope(Fe56, 1);

	// G4Isotope* N14 = new G4Isotope("N14", 7, 14);
	// elementN = new G4Element("Azote", "Azote", 1);
	// elementN->AddIsotope(N14, 100.*perCent);






	//***********************
	// Build Materials      *
	//***********************
  
	G4NistManager* manager = G4NistManager::Instance();


	G4_BORON_CARBIDE = manager->FindOrBuildMaterial("G4_BORON_CARBIDE");

	//diborate
	B2O5=new G4Material("B2O5", 2.1000*g/cm3, 2);
	B2O5->AddElement(elementB, 2);
	B2O5->AddElement(elementO, 5);

  	//Oxygen= new G4Material(name="Oxygen",z=8,15.99*g/mole,15.1*g/cm3);

	//Calcium= new G4Material(name="Calcium",z=20,40.08*g/mole,1.55*g/cm3);

	BN_ceramic= new G4Material("BN_ceramic", 2.1000*g/cm3, 2);
	BN_ceramic->AddElement(elementB, 1);
	BN_ceramic->AddElement(elementN, 1);

	//BN_ceramic->AddMaterial (name="Oxygen", fractionmass=3* perCent);
	//BN_ceramic->AddMaterial (name="Calcium", fractionmass = 1* perCent);
	//BN_ceramic->AddMaterial (B2O5 , fractionmass = 0.4* perCent);

	//it might be better to create mine
	G4_POLYETHYLENE= manager->FindOrBuildMaterial("G4_POLYETHYLENE");

	//polyisoprene
	C5H8=new G4Material("C5H8", 0.92*g/cm3, 2);
	C5H8->AddElement(elementC, 5);
	C5H8->AddElement(elementH, 8);

	
	Elastobore=new G4Material("Elastobore", 1.6*g/cm3, 2);
	Elastobore->AddMaterial(C5H8, fractionmass=50* perCent);
	Elastobore->AddMaterial(B2O5, fractionmass=50* perCent);


	//Polyethylene_TS= new G4Material( "Polyethylene_TS" , density = 1.04 * g/cm3 , ncomponents = 2, kStateSolid, 296*kelvin, 1*atmosphere);

	//Aluminium
	G4Material*G4_Al=manager->FindOrBuildMaterial("G4_Al");
	G4Material*G4_Mg=manager->FindOrBuildMaterial("G4_Mg");
	G4Material*G4_Si=manager->FindOrBuildMaterial("G4_Si");
	G4Material*G4_Fe=manager->FindOrBuildMaterial("G4_Fe");
	G4Material*G4_Cr=manager->FindOrBuildMaterial("G4_Cr");

	Al=new G4Material("Al", 2.7*g/cm3, 5);
	Al->AddMaterial(G4_Al, fractionmass=96.46* perCent);
	Al->AddMaterial(G4_Mg, fractionmass=3.05* perCent);
	Al->AddMaterial(G4_Si, fractionmass=0.19* perCent);
	Al->AddMaterial(G4_Fe, fractionmass=0.14* perCent);
	Al->AddMaterial(G4_Cr, fractionmass=0.16* perCent);

	//Concrete
	G4Material*G4_H=manager->FindOrBuildMaterial("G4_H");
	G4Material*G4_B=manager->FindOrBuildMaterial("G4_B");
	G4Material*G4_C=manager->FindOrBuildMaterial("G4_C");
	G4Material*G4_O=manager->FindOrBuildMaterial("G4_O");
	G4Material*G4_Na=manager->FindOrBuildMaterial("G4_Na");
	G4Material*G4_S=manager->FindOrBuildMaterial("G4_S");
	G4Material*G4_F=manager->FindOrBuildMaterial("G4_F");
	G4Material*G4_Ca=manager->FindOrBuildMaterial("G4_Ca");
	G4Material*G4_Ti=manager->FindOrBuildMaterial("G4_Ti");



	Concrete=new G4Material("Concrete", 5.2*g/cm3, 13);
	Concrete->AddMaterial(G4_H, fractionmass=0.41* perCent);
	Concrete->AddMaterial(G4_B, fractionmass=0.07* perCent);
	Concrete->AddMaterial(G4_C, fractionmass=1.24* perCent);
	Concrete->AddMaterial(G4_O, fractionmass=8.3* perCent);
	Concrete->AddMaterial(G4_Na, fractionmass=0.02* perCent);
	Concrete->AddMaterial(G4_Mg, fractionmass=0.06* perCent);
	Concrete->AddMaterial(G4_Al, fractionmass=2.26* perCent);
	Concrete->AddMaterial(G4_Si, fractionmass=1.52* perCent);
	Concrete->AddMaterial(G4_S, fractionmass=0.08* perCent);
	Concrete->AddMaterial(G4_F, fractionmass=0.07* perCent);
	Concrete->AddMaterial(G4_Ca, fractionmass=4.02* perCent);
	Concrete->AddMaterial(G4_Ti, fractionmass=0.09* perCent);
	Concrete->AddMaterial(G4_Fe, fractionmass=81.80* perCent);
	

	//Steel G4_STAINLESS-STEEL 

	G4Material*G4_STAINLESS_STEEL=manager->FindOrBuildMaterial("G4_STAINLESS-STEEL");
	G4Material*G4_Mn=manager->FindOrBuildMaterial("G4_Mn");
	G4Material*G4_Cu=manager->FindOrBuildMaterial("G4_Cu");



	Low_alloy_Steel=new G4Material("Low_alloy_Steel", 7.85*g/cm3, 3);

	Low_alloy_Steel->AddMaterial(G4_STAINLESS_STEEL, fractionmass=98.0* perCent);
	Low_alloy_Steel->AddMaterial(G4_Mn, fractionmass=1.4* perCent);
	Low_alloy_Steel->AddMaterial(G4_Cu, fractionmass=0.6* perCent);
	
	
	//LiF for beam dump
	LiF=new G4Material("LiF", 1.0*g/cm3, 2);
	LiF->AddElement(elementLi, 1);
	LiF->AddElement(elementF, 1);


	//#######################################################################################################################################
	//#######################################################################################################################################


	// DiAzote
	G4double M_mole_N2 = 2*14; //en g/mole
	G4double Pression = 100000; //(en Pa => 1 bar = 100 000 Pa)
	N2 = new G4Material("Diazote", ((Pression * M_mole_N2)/(R*T))*g/m3, 1, kStateGas, T, (Pression*0.00000986923*atmosphere));
	N2->AddElement(elementN,2);

	//#######################################################################################################################################
	//#######################################################################################################################################

	H2O = new G4Material("Eau", 1.000*g/cm3, 2);
	H2O->AddElement(elementH, 2);
	H2O->AddElement(elementO, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Or = new G4Material("Or", 19.3*g/cm3, 1);
	Or->AddElement(elementAu, 1);


	//#######################################################################################################################################
	//#######################################################################################################################################

	CdTe = new G4Material("CdTe", 5.85*g/cm3, 2);
	CdTe->AddElement(elementCd, 1);
	CdTe->AddElement(elementTe, 1);


	//#######################################################################################################################################
	//#######################################################################################################################################

	Polypropylene = new G4Material("Polypropylene", 0.900*g/cm3, 2);
	Polypropylene->AddElement(elementC, 3);
	Polypropylene->AddElement(elementH, 6);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Tungstene = new G4Material("Tungstene", 19.3*g/cm3, 1, kStateSolid);
	Tungstene->AddElement(elementW, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Plomb = new G4Material("Plomb", 11.35*g/cm3, 1, kStateSolid);
	Plomb->AddElement(elementPb, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Neoprene = new G4Material("Neoprene", 1.23*g/cm3, 3);
	Neoprene->AddElement(elementC, 4);
	Neoprene->AddElement(elementH, 5);
	Neoprene->AddElement(elementCl, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Papier = new G4Material("Papier", 1.2*g/cm3, 3);
	Papier->AddElement(elementC, 6);
	Papier->AddElement(elementH, 10);
	Papier->AddElement(elementO, 5);

	//#######################################################################################################################################
	//#######################################################################################################################################

	mylar = new G4Material("mylar", 1.40*g/cm3, 3);
	mylar->AddElement(elementH, 4);
	mylar->AddElement(elementC, 5);
	mylar->AddElement(elementO, 2);

	//#######################################################################################################################################
	//#######################################################################################################################################

	//Teflon
	teflon = new G4Material("teflon", 0.40*g/cm3, 4);
	teflon->AddElement(elementH, 6);
	teflon->AddElement(elementC, 2);
	teflon->AddElement(elementO, 1);
	teflon->AddElement(elementSi, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Alu = new G4Material("Alu", 2.6989*g/cm3, 1, kStateSolid);
	Alu->AddElement(elementAl, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Plomb_Antimoine = new G4Material("Plomb_Antimoine"  , 11.04*g/cm3, 2);
	Plomb_Antimoine->AddElement(elementPb, 0.96);
	Plomb_Antimoine->AddElement(elementSb, 0.04);

	//#######################################################################################################################################
	//#######################################################################################################################################

	plastic = new G4Material("plastic", 0.96*g/cm3, 2,	kStateSolid);
	plastic->AddElement( elementH, 4 );
	plastic->AddElement( elementC, 2 );

	//#######################################################################################################################################
	//#######################################################################################################################################

	Nylon = new G4Material("Nylon", 1.4*g/cm3, 4);
	Nylon->AddElement( elementH, 22 );
	Nylon->AddElement( elementC, 12 );
	Nylon->AddElement( elementN, 2 );
	Nylon->AddElement( elementO, 2 );

	
	//#######################################################################################################################################
	//#######################################################################################################################################

	Kapton = new G4Material("Kapton", 1.413*g/cm3, 4);
	Kapton->AddElement(elementO,5);
	Kapton->AddElement(elementC,22);
	Kapton->AddElement(elementN,2);
	Kapton->AddElement(elementH,10);


	//#######################################################################################################################################
	//#######################################################################################################################################

	Air = new G4Material("Air"  , 1.290*mg/cm3, 2);
	Air->AddElement(elementN, 0.7);
	Air->AddElement(elementO, 0.3);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Fer = new G4Material("Fer"  , 7.87*g/cm3, 1);
	Fer->AddElement(elementFe, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Silicon = new G4Material("Silicon"  , 2.3*g/cm3, 1);
	Silicon->AddElement(elementSi, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	Carbon = new G4Material("Carbon"  , 2.0*g/cm3, 1);
	Carbon->AddElement(elementC, 1);

	//#######################################################################################################################################
	//#######################################################################################################################################

	//Fake Vacuum *************************************************************

	// Be careful of this vacuum definition.  This is only used to define
	// a refractive index so that the detector boundaries are defined.

	VacuumWorld = new G4Material ("VacuumWorld",
	1.0,
	1.01*g/mole,
	universe_mean_density,
	kStateGas,
	3.e-18*pascal,
	2.73*kelvin);





}

G4Material* TENISMaterials::GetMaterial(G4String material)
{
	G4Material* pttoMaterial = G4Material::GetMaterial(material);
	return pttoMaterial;
}
