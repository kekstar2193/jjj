/*
 * Steckenende.h
 *
 *  Created on: 28 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme {

public:
	Streckenende(Fahrzeug& _fzg, Weg& _weg);
    void vBearbeiten() override;

    virtual ~Streckenende();


};

#endif /* STRECKENENDE_H_ */
