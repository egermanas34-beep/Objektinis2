# v2.0
## v1.1
### 1 testas
Buvo atliktas testas tam ,kad palyginti programos naudojancios struct is ankstesniojo darbo(v1.0) ir naudojancio class tipo Studentus is dabartines realizacijos sparta (veikimo laika), naudojant viena fiksuota konteiner - vektoriu, 3 dalijimo strategija ir 100000 ir 1000000 dydzio failus.
|           | failo dydis | laikas(s) |
|-----------|-------------|-----------|
| Klase     | 100000      | 0.7402    |
| Struktura | 100000      | 0.6768    |
| Klase     | 1000000     | 6.449     |
| Struktura | 1000000     | 7,58      |

Po sio testo matome, kad programa naudojanti class, o ne struct, veikia truputi greiciau.		
### 2 testas
Buvo atlikta eksperimentine analize tam, kad nustatyti kaip skirsis programos sparta(naudojant studentu faila su 1 mln. irasu) bei .exe failo dydis priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3. Testas buvo atliktas naudojant tyrimo funkcija, kuri skaiciavo programos veikimo laika su is anksto nustatytais parametrais.
|           | flagas | .exe(dydis) | laikas(s) |
|-----------|--------|-------------|-----------|
| Klase     | O1     | 3041 KB     | 5.05      |
|           | O2     | 3051 KB     | 5.11      |
|           | O3     | 3088 KB     | 5.13      |
| Struktura | O1     | 3057 KB     | 6.583     |
|           | O2     | 3059 KB     | 6.403     |
|           | O3     | 3092 KB     | 6.434     |
Gauti rezultatai parode, kad class tipo programa veikia greiciau negu struct.

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

ctest --test-dir build

