/*
 * Losfahren.h
 *
 *  Created on: 28 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme {
public:

	Losfahren(Fahrzeug& _fzg, Weg& _weg);

    void vBearbeiten() override;

    virtual ~Losfahren();

};




#endif /* LOSFAHREN_H_ */
