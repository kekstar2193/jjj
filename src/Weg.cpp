/*
 * Weg.cpp
 *
 *  Created on: 16 Kas 2023
 *      Author: kekillialiresid
 */


#include "Weg.h"
#include <iostream>
#include "vertagt_aktion.h"
#include "vertagt_liste.h"


Weg::Weg() : Simulationsobjekt(""), p_dLaenge(0.0), p_eTempolimit(Tempolimit::Autobahn) {} // @suppress("Symbol is not resolved")

Weg::Weg(const std::string& name, double laenge, Tempolimit tempolimit) : Simulationsobjekt(name), p_dLaenge(laenge), p_eTempolimit(tempolimit) {}

double Weg::getTempolimit() const {
    switch (p_eTempolimit) {
        case Tempolimit::Innerorts: return 50.0;
        case Tempolimit::Landstrasse: return 100.0;
        case Tempolimit::Autobahn: return std::numeric_limits<int>::max();
        default: return 0.0;
    }
}

std::ostream& operator<<(std::ostream& os, const Weg& weg)
{
	weg.vAusgeben(os);
	return os;
};
void Weg::vSimulieren() {
    try
    {
    	if (p_pFahrzeuge.empty())
    {
    		std::cout << "Keine Fahrzeuge auf dem Weg: " << p_sName << std::endl;
    		return;
    }

    	for (auto& fahrzeug : p_pFahrzeuge)
    	{
        fahrzeug->vSimulieren();

        //std::cout << fahrzeug->getName() << " ";
    	}
    	p_pFahrzeuge.vAktualisieren();
    }
    catch (Fahrausnahme& e){
    	e.vBearbeiten();
    }
    std::cout << std::endl;
}

void Weg::vAusgeben(std::ostream& os) const {
    Simulationsobjekt::vAusgeben(os);
    os << std::left
       << std::setw(10) << "ID"
       << " | "
       << std::setw(12) << "Name"
       << " | "
       << std::setw(8) << "Laenge"
       << " | "
       << "Fahrzeuge"
       << '\n'
       << std::setfill('*') << std::setw(50) << "" << std::setfill(' ') << '\n';

    os << std::left
       << std::setw(10) << p_iID
       << " | "
       << std::setw(12) << p_sName
       << " | "
       << std::setw(8) << p_dLaenge
       << " | ";

    for (const auto& fahrzeug : p_pFahrzeuge) {
        os << fahrzeug->getName() << " ";
    }
    os << std::endl;
}


void Weg::vKopf() {

	std::cout << std::left
	          << std::setw(5) << "ID"
	          << " | "
	          << std::setw(12) << "Name"
	          << " | "
	          << std::setw(8) << "Laenge"
	          << " | "
	          << "Fahrzeuge"
	          << '\n'
	          << std::setfill('-') << std::setw(50) << "" << std::setfill(' ') << '\n';
}

double Weg::dGeschwindigkeit() const {
    switch (p_eTempolimit) {
        case Tempolimit::Innerorts:
            return 50.0;
        case Tempolimit::Landstrasse:
            return 100.0;
        case Tempolimit::Autobahn:
            return std::numeric_limits<double>::infinity();
        default:
            return 0.0;
    }
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFzg) {
    std::cout << "Fahrzeug " << pFzg->getName() << " hat den Weg " << p_sName << " betreten." << std::endl;
    pFzg->vNeueStrecke(*this);
    p_pFahrzeuge.push_back(std::move(pFzg));
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double startzeit) {
    std::cout << "Fahrzeug " << fahrzeug->getName() << " parken " << p_sName << " betreten." << std::endl;
    fahrzeug->vNeueStrecke(*this, startzeit);
    p_pFahrzeuge.push_front(std::move(fahrzeug));
}

std::unique_ptr<Fahrzeug> Weg::vAbgabe(const Fahrzeug& fzg) {
    for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it) {
        if ((*it).get() == &fzg) {
            auto ptr = std::move(*it);
            p_pFahrzeuge.erase(it);
            return ptr;
        }
    }
    return nullptr;
}



