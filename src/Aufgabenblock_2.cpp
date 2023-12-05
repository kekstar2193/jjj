//============================================================================
// Name        : Aufgabenblock_2.cpp
// Author      : Asidovic
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Fahren.h"
#include "Parken.h"
#include "Verhalten.h"
#include "SimuClient.h"


using namespace std;

void vAufgabe5() {
    Weg meinWeg("Autobahn", 500);

    std::unique_ptr<Fahrzeug> fzg1(new Fahrzeug("BMW", 120));
    std::unique_ptr<Fahrzeug> fzg2(new Fahrzeug("Audi", 150));
    std::unique_ptr<Fahrzeug> fzg3(new Fahrzeug("Mercedes", 130));

    meinWeg.vAnnahme(std::move(fzg1));
    meinWeg.vAnnahme(std::move(fzg2));
    meinWeg.vAnnahme(std::move(fzg3));

    const double zeittakt = 0.25; // 15 dakika (0.25 saat)
    const double gesamtZeit = 10; // 10 saat için simülasyon

    while (dGlobaleZeit < gesamtZeit){
    	dGlobaleZeit += zeittakt;

    	meinWeg.vSimulieren();
    }
    // Sonuçların görüntülenmesi
    // ...
}
void vAufgabe6() {
    Weg autobahn("Autobahn", 500); // 500 km uzunluğunda bir yol

    // Araçları oluştur
    auto bmw = std::make_unique<Fahrzeug>("BMW", 100);
    auto audi = std::make_unique<Fahrzeug>("Audi", 120);

    // Araçları yola ekle
    autobahn.vAnnahme(std::move(bmw)); // BMW, 1 saat sonra yola çıkacak
    autobahn.vAnnahme(std::move(audi),1); // Audi hemen yola çıkacak

    const double zeittakt = 0.25; // 15 dakika (0.25 saat)
    const double gesamtZeit = 10; // Toplam 2 saat için simülasyon

    while (dGlobaleZeit < gesamtZeit){
        	dGlobaleZeit += zeittakt;

        	autobahn.vSimulieren();

        	autobahn.vAusgeben(std::cout);

        	std::cout << "Globale Zeit: " << dGlobaleZeit << " Stunden\n";
        }
}

void vAufgabe8() {
    Weg autobahn("Autobahn", 500); // 500 km uzunluğunda bir yol

    // Araçları oluştur
    auto bmw = std::make_unique<Fahrzeug>("BMW", 100);
    auto audi = std::make_unique<Fahrzeug>("Audi", 120);

    // Araçları yola ekle
    autobahn.vAnnahme(std::move(bmw)); // BMW hemen yola çıkacak
    autobahn.vAnnahme(std::move(audi)); // Audi hemen yola çıkacak

    const double zeittakt = 0.25; // 15 dakika (0.25 saat)
    const double gesamtZeit = 5; // Toplam 5 saat için simülasyon
    bool bmwHatGeparkt = false;

    while (dGlobaleZeit < gesamtZeit) {
        dGlobaleZeit += zeittakt;

        if (!bmwHatGeparkt && dGlobaleZeit >= 2.0) {
            // BMW'yi 2 saat sonra 1 saatliğine park et
            auto bmwPark = std::make_unique<Fahrzeug>("BMW", 100);
            autobahn.vAnnahme(std::move(bmwPark), 1.0); // BMW 1 saatliğine park eder
            bmwHatGeparkt = true;
        }

        autobahn.vSimulieren();

        autobahn.vAusgeben(std::cout);

        std::cout << "Globale Zeit: " << dGlobaleZeit << " Stunden\n";
    }
}



void vAufgabe7(){
    std::vector<std::unique_ptr<Fahrzeug>> vFahrzeuge;
    int anzahlFahrzeuge;
    std::string name;
    double maxGeschwindigkeit, startzeit;
    Weg autobahn("Autobahn", 500); // 500 km uzunluğunda
    Weg landstrasse("Landstrasse", 300); // 300 km uzunluğunda

    std::cout << "Anzahl der Fahrzeuge: ";
    std::cin >> anzahlFahrzeuge;
    for (int i = 0; i < anzahlFahrzeuge; ++i) {
        std::cout << "Fahrzeug #" << i+1 << " Name: ";
        std::cin >> name;
        std::cout << "Maximalgeschwindigkeit: ";
        std::cin >> maxGeschwindigkeit;
        std::cout << "Startzeit (in Stunden, 0 für sofort): ";
        std::cin >> startzeit;

        if (startzeit == 0) {
            vFahrzeuge.push_back(std::make_unique<Fahrzeug>(name, maxGeschwindigkeit));
            vFahrzeuge.back()->vNeueStrecke(autobahn);
        } else {
            vFahrzeuge.push_back(std::make_unique<Fahrzeug>(name, maxGeschwindigkeit));
            vFahrzeuge.back()->vNeueStrecke(landstrasse, startzeit);
        }
    }

    const double zeittakt = 0.25; // 15 Minuten
    const double gesamtZeit = 10; // 10 Stunden für die Simulation


    while (dGlobaleZeit < gesamtZeit) {
        dGlobaleZeit += zeittakt;

        for (auto& fahrzeug : vFahrzeuge) {
            fahrzeug->vSimulieren();

        }

        std::cout << "Globale Zeit: " << dGlobaleZeit << " Stunden\n";
    }
}

void vAufgabe_9() {
    // Yolları oluştur
    Weg autobahn("Autobahn", 500, Tempolimit::Autobahn); // Tempolimitsiz yol
    Weg landstrasse("Landstras", 500, Tempolimit::Landstrasse); // 100 km/h limitli yol

    // Araçları oluştur
    auto bmw = std::make_unique<PKW>("BMW", 150, 2, 55);
    auto audi = std::make_unique<PKW>("Audi", 120, 2, 55);
    auto mercedes = std::make_unique<PKW>("Mercedes", 130,2,55);

    // Araçları yollara yerleştir
    autobahn.vAnnahme(std::unique_ptr<PKW>(std::move(bmw))); // BMW hemen hareket eder
    landstrasse.vAnnahme(std::unique_ptr<PKW>(std::move(audi)), 1); // Audi, 2 saat sonra hareket eder
    landstrasse.vAnnahme(std::unique_ptr<PKW>(std::move(mercedes)), 3); // Mercedes, 1 saat sonra hareket eder

    int koordinaten[] = {700,250,100,250};
    int koordinaten2[] = {500,150,200,150};
    bInitialisiereGrafik(800,500);

    bZeichneStrasse("Autobahn","Landstras", 500, 2 , koordinaten);
    //bZeichneStrasse("Strashin1","Strasruek1", 500, 2 , koordinaten2);

   // bZeichnePKW("Audi","Autohin1", 0.5,120, 55);

    const double zeittakt = 0.25; // 15 dakika (0.25 saat)
    const double gesamtZeit = 5; // Toplam 5 saat için simülasyon

vSleep(2000);
    // Simülasyon döngüsü
    while (dGlobaleZeit < gesamtZeit) {
        	dGlobaleZeit += zeittakt;

           vSetzeZeit(dGlobaleZeit);




            autobahn.vSimulieren();
            landstrasse.vSimulieren();
            autobahn.vAusgeben(std::cout);
            landstrasse.vAusgeben(std::cout);

            for (const auto& fahrzeug : autobahn.getFahrzeuge()) {
                fahrzeug->vZeichnen(autobahn);
            }
            for (const auto& fahrzeug : landstrasse.getFahrzeuge()) {
                fahrzeug->vZeichnen(landstrasse);
            }


            vSleep(1000);
        std::cout << "Globale Zeit: " << dGlobaleZeit << " Stunden\n";
    }
    vBeendeGrafik();
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//vAufgabe2();
	//vAufgabe4();
	//vAufgabe5();
	//vAufgabe6();
	//vAufgabe7();
    vAufgabe_9();
	return 0;
}

