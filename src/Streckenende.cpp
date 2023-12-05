/*
 * Streckenende.cpp
 *
 *  Created on: 28 Kas 2023
 *      Author: kekillialiresid
 */

#include "Streckenende.h"


Streckenende::Streckenende(Fahrzeug& _fzg, Weg& _weg) : Fahrausnahme(_fzg, _weg) {}

Streckenende::~Streckenende(){


}
void Streckenende::vBearbeiten() {
    std::cout << "Streckenende Ausnahme: Fahrzeug " << fzg.getName()
              << " auf Weg " << weg.getName() << std::endl;
    // Burada diğer işlemler yapılabilir

}



