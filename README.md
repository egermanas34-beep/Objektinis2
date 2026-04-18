# nauja
## 1 testas
Buvo atliktas testas tam ,kad palyginti programos naudojancios struct is ankstesniojo darbo(v1.0) ir naudojancio class tipo Studentus is dabartines realizacijos sparta (veikimo laika), naudojant viena fiksuota konteiner - vektoriu, 3 dalijimo strategija ir 100000 ir 1000000 dydzio failus.
|           | failo dydis | laikas(s) |
|-----------|-------------|-----------|
| Klase     | 100000      | 0.7402    |
| Struktura | 100000      | 0.6768    |
| Klase     | 1000000     | 6.449     |
| Struktura | 1000000     | 7,58      |

Po sio testo matome, kad programa naudojanti class, o ne struct, veikia truputi greiciau.		
## 2 testas
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
