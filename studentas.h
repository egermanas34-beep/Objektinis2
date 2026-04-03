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

  
  ~Studentas() = default;

  void skaiciuoti_rezultata(int pasirinkimas)
  {
    if (paz.empty()) {
      rez = 0.0;
      return;
    }

    if (pasirinkimas == 1) {
      int suma = 0;
      for (int pazymys : paz) {
        suma += pazymys;
      }
      rez = suma * 1.0 / (1.0*paz.size()) * 0.4 + egz * 0.6;
      vidurkis = rez;
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
};
//sukurti alias StudentuGrupe, kuri galima nuadoti kaip vektoriu, lista arba deque tipo konteineri, tam, kad patikrinti programos sparta, su skirtingo tipo konteineriais.
using StudentuGrupe = std::vector<Studentas>;  // vector
//using StudentuGrupe = std::list<Studentas>;      // list
//using StudentuGrupe = std::deque<Studentas>;   // deque
const int Maxpazymiu=20;
