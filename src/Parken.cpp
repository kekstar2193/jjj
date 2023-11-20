/*
 * Parken.cpp
 *
 *  Created on: 19 Kas 2023
 *      Author: kekillialiresid
 */


#include "Parken.h"
#include "Fahrzeug.h"
#include "Weg.h"

Parken::Parken(Weg& weg, double startzeit) : Verhalten(weg), p_dStartzeit(startzeit) {}

double Parken::dStrecke(Fahrzeug& fzg, double dZeitIntervall) {
    if (dGlobaleZeit >= p_dStartzeit) {
        std::cout << "Fahrzeug " << fzg.getName() << " hat die Startzeit erreicht und beginnt zu fahren." << std::endl;
        return 0.0; // veya hareket etmeye başlayabilir
    }
    return 0.0;
}


