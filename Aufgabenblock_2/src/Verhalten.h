/*
 * Verhalten.h
 *
 *  Created on: 18 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

#include "Weg.h"
#include "Fahrzeug.h"

class Fahrzeug;
class Weg;

class Verhalten {
private:
    Weg& p_Weg;

public:
    Verhalten(Weg& weg) : p_Weg(weg) {}

    double dStrecke(Fahrzeug& fzg, double dZeitIntervall);
};



#endif /* VERHALTEN_H_ */
