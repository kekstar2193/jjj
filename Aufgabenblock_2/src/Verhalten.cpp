/*
 * Verhalten.cpp
 *
 *  Created on: 19 Kas 2023
 *      Author: kekillialiresid
 */

// Verhalten.cpp
#include "Verhalten.h"

double Verhalten::dStrecke(Fahrzeug& fzg, double dZeitIntervall) {

	double dGeschwindigkeit = fzg.dGeschwindigkeit(); // Fahrzeug'ın hızını al
    double dStrecke = dGeschwindigkeit * dZeitIntervall; // Hesaplanan mesafe

    // Yolun sonuna ulaşıp ulaşmadığını kontrol et
    if (p_Weg.getLaenge() - fzg.getAbschnittStrecke() < dStrecke) {
        return p_Weg.getLaenge() - fzg.getAbschnittStrecke();
    }


    return dStrecke;
}



