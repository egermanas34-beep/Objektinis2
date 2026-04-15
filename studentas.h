#pragma once
#include "bibliotekos.h"

int skaiciu_mastelis(const string &prompt, int min_val, int max_val);
string vardo_skaitymas(const string &prompt);

class Studentas {
public:
  string Vardas = "A", Pavarde = "B";
  vector<int> paz;
  int egz = 0;
  double vidurkis = 0.0;
  double mediana = 0.0;
  double rez = 0.0;
  string lygis;

  Studentas()
  {

  }// Naudojame numatytąjį konstruktorių, kuris leidžia sukurti tuščią Studentas objektą
 /* Studentas(const string& vardas, const string& pavarde, const vector<int>& pazymiai, int egzaminas)// Konstruktorius, kuris leidžia sukurti Studentas objektą su visais duomenimis
      : Vardas(vardas), Pavarde(pavarde), paz(pazymiai), egz(egzaminas) {}

  Studentas(const string& vardas, const string& pavarde, const vector<int>& pazymiai, int egzaminas, int pasirinkimas)// Konstruktorius, kuris leidžia sukurti Studentas objektą su visais duomenimis ir iš karto apskaičiuoti rezultatą
      : Vardas(vardas), Pavarde(pavarde), paz(pazymiai), egz(egzaminas)
  {
    skaiciuoti_rezultata(pasirinkimas);
  }

  Studentas(const Studentas&) = default;// Naudojame numatytąjį kopijavimo konstruktorių, kuris leidžia sukurti Studentas objektą kopijuojant kitą Studentas objektą
  Studentas(Studentas&&) noexcept = default;// Naudojame numatytąjį perkelimo konstruktorių, kuris leidžia sukurti Studentas objektą perkelti kitą Studentas objektą
  Studentas& operator=(const Studentas&) = default;// Naudojame numatytąjį kopijavimo priskyrimo operatorių, kuris leidžia priskirti vieną Studentas objektą kitam Studentas objektui
  Studentas& operator=(Studentas&&) noexcept = default;// Naudojame numatytąjį perkelimo priskyrimo operatorių, kuris leidžia priskirti vieną Studentas objektą kitam Studentas objektui perkelti
*/
  ~Studentas() {}// Naudojame numatytąjį destruktorių, kuris leidžia sunaikinti Studentas objektą, kai jis nebereikalingas

  void nuskaityti_ranka(int max_pazymiu)
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

  void nuskaityti_is_eilutes(std::istream& is)
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
