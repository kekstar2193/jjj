/*
 * PKW.h
 *
 *  Created on: 9 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
#include <limits>
#include "SimuClient.h"

class PKW : public Fahrzeug {

private:
    double p_dVerbrauch;       // Liter/100km
    double p_dTankvolumen;     // Liter
    double p_dTankinhalt;      // Liter
public:

    PKW(std::string name, double maxGeschwindigkeit, double verbrauch, double tankvolumen = 55);
    void dTanken(double menge = std::numeric_limits<double>::infinity());
    virtual ~PKW();
    virtual void vAusgeben(std::ostream& os) const override;
    virtual void vSimulieren() override;
    double dGeschwindigkeit() const override;
    void vZeichnen(const Weg& weg) const override;

};



#endif /* PKW_H_ */
