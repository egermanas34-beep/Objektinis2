# nauja
## 1 testas
Buvo atliktas testas tam ,kad palyginti programos naudojancios struct is ankstesniojo darbo(v1.0) ir naudojancio class tipo Studentus is dabartines realizacijos sparta (veikimo laika), naudojant viena fiksuota konteiner - vektoriu, 3 dalijimo strategija ir 100000 ir 1000000 dydzio failus.
|           | failo dydis | laikas(s) |
|-----------|-------------|-----------|
| Klase     | 100000      | 0.6402    |
| Struktura | 100000      | 0.6768    |
| Klase     | 1000000     | 6.449     |
| Struktura | 1000000     | 6.86      |

Po sio testo matome, kad programa naudojanti class, o ne struct, veikia truputi greiciau.		
## 2 testas
Buvo atlikta eksperimentine analize tam, kad nustatyti kaip skirsis programos sparta(naudojant studentu faila su 1 mln. irasu) bei .exe failo dydis priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3.
|           | flagas | .exe(dydis) | laikas(s) |
|-----------|--------|-------------|-----------|
| Klase     | O1     | 3058 KB     | 6.413     |
|           | O2     | 3059 KB     | 6.102     |
|           | O3     | 3096 KB     | 6.354     |
| Struktura | O1     | 3057 KB     | 6.583     |
|           | O2     | 3059 KB     | 6.403     |
|           | O3     | 3092 KB     | 6.434     |
Gauti rezultatai parode, kad skirtumai tarp ju yra nedideli, taciau klases realizacija veike siek tiek greiciau. Tai rodo, kad pasirinkimas tarp struct ir class neturi reiksmingos itakos sioje programoje.
