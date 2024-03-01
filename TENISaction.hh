#ifndef TENISACTION_HH
#define TENISACTION_HH

#include "G4VUserActionInitialization.hh"
#include "TENISgenerator.hh"


class TENISActionInitialization: public G4VUserActionInitialization
{
    public:
        TENISActionInitialization();
        ~TENISActionInitialization();
		
        virtual void Build() const;  //we can create it as constant

};


#endif