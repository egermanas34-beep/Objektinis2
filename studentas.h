
#pragma once
#include "bibliotekos.h"

int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);

class Studentas {
  private:
  string Vardas;
  string Pavarde;
  vector<int> paz;
  int egz;
  double vidurkis;
  double mediana;
  double rez;
  string lygis;
public:
 

  Studentas();//default konstruktorius
  const string& getVardas() const { return Vardas; } // getteriai
  const string& getPavarde() const { return Pavarde; }
  const vector<int>& getPaz() const { return paz; }
  int getEgz() const { return egz; }
  double Rezultatas() const {return rez;} //getteris
  std::istream& readStudent(std::istream&); //setteris
  
  void setVardas(const string& v) {
    Vardas = v;
  }
  void setPavarde(const string& p) {
    Pavarde = p;
  }
  void setPaz(int p) {
    paz.push_back(p);
  }
  void setEgz(int e) {
    egz = e;
  }
  


  ~Studentas(); //destruktorius


  void nuskaityti_ranka(int max_pazymiu);
  void nuskaityti_is_eilutes(std::istream& is);
  void skaiciuoti_rezultata(int pasirinkimas);
  void isvalyti_pazymius();
  friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
};




//sukurti alias StudentuGrupe, kuri galima nuadoti kaip vektoriu, lista arba deque tipo konteineri, tam, kad patikrinti programos sparta, su skirtingo tipo konteineriais.
using StudentuGrupe = std::vector<Studentas>;  // vector
//using StudentuGrupe = std::list<Studentas>;      // list
//using StudentuGrupe = std::deque<Studentas>;   // deque
const int Maxpazymiu=20;
