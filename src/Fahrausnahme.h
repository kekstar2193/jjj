/*
 * Fahrausnahme.h
 *
 *  Created on: 28 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include <exception>

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Tempolimit.h"
#include <list>
#include <memory>
#include "Weg.h"

class Fahrzeug;
class Weg;

class Fahrausnahme : public std::exception
{
protected:
	Fahrzeug& fzg ;
	Weg& weg;

public:
	Fahrausnahme(Fahrzeug& _fzg, Weg& _weg) : fzg(_fzg), weg(_weg) {}

	virtual void vBearbeiten() = 0; // Saf sanal fonksiyon

	Weg& getWeg1() const { return weg; }

	Fahrzeug& getFahrzeug() const { return fzg; }

	virtual ~Fahrausnahme() = default;
};



#endif /* FAHRAUSNAHME_H_ */
