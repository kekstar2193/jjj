/*
 * Losfahren.cpp
 *
 *  Created on: 28 Kas 2023
 *      Author: kekillialiresid
 */

#include "Losfahren.h"



Losfahren::Losfahren(Fahrzeug& _fzg, Weg& _weg) : Fahrausnahme(_fzg, _weg) {}

Losfahren::~Losfahren() {

}

void Losfahren::vBearbeiten() {

	 std::cout << "Losfahren Ausnahme: Fahrzeug " << fzg.getName()
	                  << " auf Weg " << weg.getName() << std::endl;

	 // Losfahren.cpp içinde
	 // ...
	 // Eğer fzg bir Fahrzeug nesnesi ise
	 // Eğer fzg bir Fahrzeug referansı veya nesnesi ise



	 // ...

	 fzg.vNeueStrecke(weg);
}
