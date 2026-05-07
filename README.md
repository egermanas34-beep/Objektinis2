# v2.0
## is v1.2 
### Perdengti ivesties/isvesties operatoriai
Programoje buvo realizuoti ivesties ir isvesties operatoriai darbui su Studentas klase. 
Isvesties operatorius - operator<<, leidzia isvesti studento duomenis tiek i ekrana, tiek i faila. sis operatorius isveda studento varda, pavarde ir galutini pazimi. 
Ivesties operatorius - operator>>, leidia nuskaityti duomenis is failo, arba ivesti juos rankiniu budu( ivedant rankiniu budu, norint nutraukti pazymiu ivedima reikia ivesti 0).
### Duomenu ivedimas ranka
Norint ivesti studento duomenis ranka, patogiausia yra naudoti funkcija nuskaityti-ranka, todel ji ir buvo palikta kaip pagrindine ivedimo funkcija. Taciau, norint pratestuoti perdengtus operatorius testineje funkcijoje tyrimasKlasesMetodams buvo naudojamasi operator>>.
### Studentu generavimas
Generuojant studentus yra realizuotos dvi funkcijos generavimasSk ir generavimasVisko.
generavimasSk funkcijoje vartotojas iveda studento varda ir pavarde, o pazymiai yra sugeneruojami. 
generavimasVisko visi duomenys yra sugeneruojami automatiskai.
Šiose funkcijose naudojami klasės metodai (setVardas, setPavarde, setPaz, setEgz) duomenims priskirti.

### Programos testavimas
Buvo atliktas testas patikrinti, per kiek laiko bus nuskaitomas failas su 1,000,000 irasu, bei isvedimas jau suskirscius studentus i vargsciukus ir smartukus. Abu sie procesai buvo vykdomi naudojantis isvedimo ir nuskaitymo operatoriais.

studentai_1000000.txt nuskaitymo ir apdorojimo laikas: 3.04705 s
Duomenų išvedimas užtruko: 2.69627 sekundžių.
## v1.5
### sukurta bazine klase Zmogus
Klaseje Zmogus yra saugomi zmogaus vardas ir pavarde, kurie yra saugomi kaip protected nariai. Taip pat buvo padaryta taip, kad sia bazine klase galetu pasiekti tik paveldincios ja klases ir taip buvo patikrinta tyrimasKlasesMetodams funkcoijoje, kai buvo bandoma priskirti tiesiogiai Zmogui varda ir pavarde.
## Nauja versijoje v2.0
### Prideta
Sioje versijoje realizuoti unit testai naudojant Google test. Patikrinta 5 metodu taisykle: copy/move konstruktoriai bei copy/move assignment operator ir destruktoriaus veikimas. Prideti rezultatu skaiciavimo testai ir ivesties/isvesties testai.
### Projekto strukturos pakeitimai
Projektas pertvarkytas naudojant CMake. Sukurti atskiri CMakeLists.txt failai: pagrindiniam projektui, src/ katalogui ir tests/ katalogui.
### Dokumentacija
Sugeneruota Doxygen dokumentacija. Paruosti: HTML dokumentacijos failai, LaTeX dokumentacija ir PDF dokumentacija.
### Programos paleidimas
Atidare aplankala, kuriame yra musu projektas D:\objektinis\2uzdClass PowerShell terminale rasome
cmake -S . -B build
cmake --build build
.\build\src\Debug\StudentuSistema.exe
### Unit testu paleidimas
Tame paciame aplankale Powershell terminale ivedame
"ctest --test-dir build"

