#pragma once
#include "bibliotekos.h"

class Studentas {
public:
  string Vardas = "A", Pavarde = "B";
  vector<int> paz;
  int egz = 0;
  double vidurkis = 0.0;
  double mediana = 0.0;
  double rez = 0.0;
  string lygis;

  Studentas() = default;
  Studentas(const string& vardas, const string& pavarde, const vector<int>& pazymiai, int egzaminas)
      : Vardas(vardas), Pavarde(pavarde), paz(pazymiai), egz(egzaminas) {}

  Studentas(const string& vardas, const string& pavarde, const vector<int>& pazymiai, int egzaminas, int pasirinkimas)
      : Vardas(vardas), Pavarde(pavarde), paz(pazymiai), egz(egzaminas)
  {
    skaiciuoti_rezultata(pasirinkimas);
  }

  Studentas(const Studentas&) = default;
  Studentas(Studentas&&) noexcept = default;
  Studentas& operator=(const Studentas&) = default;
  Studentas& operator=(Studentas&&) noexcept = default;

  ~Studentas() = default;

  void skaiciuoti_rezultata(int pasirinkimas)
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
    if (paz.size() % 2 == 1) {
      mediana = paz[paz.size() / 2];
    } else {
      mediana = (paz[paz.size() / 2 - 1] + paz[paz.size() / 2]) / 2.0;
    }
    rez = mediana * 0.4 + egz * 0.6;
  }

  void isvalyti_pazymius()
  {
    paz.clear();
  }
  friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
};

inline std::ostream& operator<<(std::ostream& os, const Studentas& s)
{
    os << left << setw(15) << s.Vardas
       << left << setw(30) << s.Pavarde
       << left << setw(45) << fixed << setprecision(2) << s.rez;
    return os;
}

//sukurti alias StudentuGrupe, kuri galima nuadoti kaip vektoriu, lista arba deque tipo konteineri, tam, kad patikrinti programos sparta, su skirtingo tipo konteineriais.
using StudentuGrupe = std::vector<Studentas>;  // vector
//using StudentuGrupe = std::list<Studentas>;      // list
//using StudentuGrupe = std::deque<Studentas>;   // deque
const int Maxpazymiu=20;
