#include "studentas.h"

//konstruktoriaus realizacija
Studentas::Studentas()  {Vardas = "nepriskirtas"; Pavarde = "nepriskirtas";egz = 0; vidurkis = 0.0; mediana = 0.0; rez = 0.0; lygis = "nepriskirtas";};
Studentas::~Studentas()
{
  Vardas =  "nepriskirtas";
  Pavarde = "nepriskirtas";
  egz = 0;
  vidurkis = 0.0;
  mediana = 0.0;
  rez = 0.0;
  lygis = "nepriskirtas";
 
};
 void Studentas::nuskaityti_ranka(int max_pazymiu)
  {
    Vardas = vardo_skaitymas("Įveskite studento vardą: ");
    Pavarde = vardo_skaitymas("Įveskite studento pavardę: ");

    paz.clear();
    cout << "Iš viso gali būti įvesta " << max_pazymiu << " pažymių." << endl;
    cout << "Įveskite semestro pažymius: " << endl;

    int n = 1;
    int temp = 0;
    int k = 1;

    while (k != 0 && n <= max_pazymiu) {
      temp = skaiciu_mastelis("Įveskite " + std::to_string(n) + " pažymį: ", 1, 10);
      paz.push_back(temp);

      cout << "Jei norite įvesti dar vieną pažymį, įveskite 1, jei ne - 0: ";
      k = skaiciu_mastelis("", 0, 1);
      ++n;
    }

    egz = skaiciu_mastelis("Įveskite egzamino pažymį: ", 1, 10);
  }
void Studentas::nuskaityti_is_eilutes(std::istream& is)
  {
    paz.clear();
    is >> Vardas >> Pavarde;

    int pazymys = 0;
    while (is >> pazymys) {
      paz.push_back(pazymys);
    }

    if (!paz.empty()) {
      egz = paz.back();
      paz.pop_back();
    }
  }
 void Studentas::skaiciuoti_rezultata(int pasirinkimas)
  {
    if (paz.empty()) {
      rez = 0.0;
      return ;
    }

    if (pasirinkimas == 1) {
      int suma = 0;
      for (int pazymys : paz) {
        suma += pazymys;
      }
      rez = suma * 1.0 / (1.0*paz.size()) * 0.4 + egz * 0.6;
     
      return;
    }
    
    
    sort(paz.begin(), paz.end());
    for(int pazymys : paz)
    {
        if(pazymys==0)
        {
            paz.erase(std::remove(paz.begin(), paz.end(), pazymys), paz.end());
        }
    }
    if (paz.size() % 2 == 1) {
      mediana = paz[paz.size() / 2];
    } else {
      mediana = (paz[paz.size() / 2 - 1] + paz[paz.size() / 2]) / 2.0;
    }
    rez = mediana * 0.4 + egz * 0.6;
  }
void Studentas::isvalyti_pazymius()
  {
    paz.clear();
  }
 std::ostream& operator<<(std::ostream& os, const Studentas& s)
{
    os << left << setw(15) << s.Vardas
       << left << setw(30) << s.Pavarde
       << left << setw(45) << fixed << setprecision(2) << s.rez;
    return os;
}