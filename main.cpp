#include <iostream>
#include <array>
#include <cstring>
#include <ostream>
#include <vector>
#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"


class Hrana {
private:
    std::string tip;
    double cantitate;
    double valoare_nutritiva;
public:
    //Hrana(const std::string &tip, double cantitate, double valoare_nutritiva);

    Hrana(const std::string &tip, const double cantitate, const double valoare_nutritiva)
        : tip(tip),
          cantitate(cantitate),
          valoare_nutritiva(valoare_nutritiva) {
    }

    Hrana(const Hrana &other)
        : tip(other.tip),
          cantitate(other.cantitate),
          valoare_nutritiva(other.valoare_nutritiva) {
    }

    Hrana & operator=(const Hrana &other) {
        if (this == &other)
            return *this;
        tip = other.tip;
        cantitate = other.cantitate;
        valoare_nutritiva = other.valoare_nutritiva;
        return *this;
    }

    ~Hrana() = default;

    friend std::ostream & operator<<(std::ostream &os, const Hrana &obj) {
        return os
               << "tip: " << obj.tip
               << " cantitate: " << obj.cantitate
               << " valoare_nutritiva: " << obj.valoare_nutritiva;
    }
};

class Animal {
private:
    char* nume;
    std::string specie;
    double greutate;
    int varsta;
    Hrana hrana_preferata;


    void functie(const char* src) {
        if (src) {
            nume= new char[strlen(src) + 1];
            strcpy(nume,src);
        }else {
            nume= nullptr;
        }
    }
public:
    //Animal(const char* nume, const std::string& specie, double greutate, int varsta, const Hrana& hrana_preferata);

    Animal(const char* nume, const std::string &specie, double greutate, int varsta,
        const Hrana &hrana_preferata)
        : specie(specie),
          greutate(greutate),
          varsta(varsta),
          hrana_preferata(hrana_preferata) { functie(nume); }


    Animal(const Animal &other)
        :
          specie(other.specie),
          greutate(other.greutate),
          varsta(other.varsta),
          hrana_preferata(other.hrana_preferata) { functie(other.nume);}


    Animal & operator=(const Animal &other) {
        if (this == &other)
            return *this;
        delete[] nume;
        functie(other.nume);
        specie = other.specie;
        greutate = other.greutate;
        varsta = other.varsta;
        hrana_preferata = other.hrana_preferata;
        return *this;
    }

    ~Animal() {
        delete[] nume;
    }


    friend std::ostream & operator<<(std::ostream &os, const Animal &obj) {
        return os
               << "nume: " << (obj.nume ? obj.nume : "(null)")
               << " specie: " << obj.specie
               << " greutate: " << obj.greutate
               << " varsta: " << obj.varsta
               << " hrana_preferata: " << obj.hrana_preferata;
    }
};

class Bazin {
private:
    std::vector<Animal> animale;
    int volum;
    double temperatura;
    int salinitate;

public:
    //Bazin(int volum, double temperatura, int salinitate);


    Bazin(const std::vector<Animal> &animale, const int volum, const double temperatura, const int salinitate)
        : animale(animale),
          volum(volum),
          temperatura(temperatura),
          salinitate(salinitate) {
    }

    ~Bazin() = default;
};

class Acvariu{
private:
    std::vector<Bazin> bazine;
    std::string nume;
    double buget;

public:
    //Acvariu(const std::string& nume, double buget);

    Acvariu(const std::vector<Bazin> &bazine, const std::string &nume, const double buget)
        : bazine(bazine),
          nume(nume),
          buget(buget) {
    }

    ~Acvariu() = default;
};


int main() {
    std::cout << "Hello, world!\n";
    Example e1;
    e1.g();
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
