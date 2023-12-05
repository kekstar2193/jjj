/*
 * Parken.cpp
 *
 *  Created on: 19 Kas 2023
 *      Author: kekillialiresid
 */


#include "Parken.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Losfahren.h"


Parken::Parken(Weg& weg, double startzeit) : Verhalten(weg), p_dStartzeit(startzeit) {}

double Parken::dStrecke(Fahrzeug& fzg, double dZeitIntervall) {
    // Eğer global zaman, park başlangıç zamanından küçükse, araç hareket etmez
	const double epsilon = 0.001;
	if (fzg.getGesamtzeit() >= (p_dStartzeit - epsilon)) {
       throw Losfahren(fzg, getWeg());
    }




    return 0.0;
}

