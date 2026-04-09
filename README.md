# nauja
## 1 testas
Buvo atliktas testas tam ,kad palyginti programos naudojancios struct is ankstesniojo darbo(v1.0) ir naudojancio class tipo Studentus is dabartines realizacijos sparta (veikimo laika), naudojant viena fiksuota konteiner - vektoriu, 3 dalijimo strategija ir 100000 ir 1000000 dydzio failus.

Po sio testo matome, kad programa naudojanti class, o ne struct, veikia truputi greiciau.		
## 2 testas
Buvo atlikta eksperimentine analize tam, kad nustatyti kaip skirsis programos sparta(naudojant studentu faila su 1 mln. irasu) bei .exe failo dydis priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3.

Gauti rezultatai parode, kad skirtumai tarp ju yra nedideli, taciau klases realizacija veike siek tiek greiciau. Tai rodo, kad pasirinkimas tarp struct ir class neturi reiksmingos itakos sioje programoje.
