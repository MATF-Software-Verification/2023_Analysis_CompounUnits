# 2023_Analysis_Compound_Unit

## Analiza projekta Compound Unit (složene merne jedinice)
Ovaj repozitorijum predstavlja samostalni praktični seminarski rad izrađen za potrebe kursa Verifikacija softvera na master studijama Matematičkog fakulteta u Beogradu. Samostalni praktični seminarski rad podrazumeva primenu alata za statičku i dinamičku verifikaciju softvera na nekom od studentskih projekata. <br>

## O projektu:
Projekat je urađen za potrebe kursa Programske paradigme. <br>
Projekat je napisan u programskom jeziku C++ i mogao bi se svrstati pod funkcionalnu i generičku programsku paradigmu. <br>
Osnovna ideja iza samog projekta jeste pokušaj za definisanjem generičkog tipa "compound_unit" (složena jedinica) koji bi bio korišćen za reprezentovanje različitih mernih jedinica. <br>
Na primer: ```compound_unit<meter<1>, second<-2>>``` bi predstavljalo m/s^2 (mernu jedinicu za ubrzanje). <br>
Ukoliko bismo pomnožili različite veličine, na primer: 32m/s^2 * 5s <br>
...trebalo bi da dobijemo m/s, odnosno ```<meter<1>, second<-1>>```. <br>

Za prevođenje projekta neophodno je koristiti verziju 17 programskog jezika C++.

## Korišćeni alati:

- **gcov lcov**
- **QtTest**
- **Valgrind - massif**
- **Valgrind - memcheck**
- **Valgrind - callgrind**
- **Perf**

## Izvedeni zaključci:
U projektu nisu pronađeni veći propusti. Projekat je po obimu mali. Implementirano je dosta funkcionalnosti u .hpp fajlovima, ali je mali broj njih testiran u demo.cpp fajlu u kome se nalazi main funkcija. Trebalo bi 
napomenuti da je ideja Compound unit projekta bila da se u toku prevođenja projekta (eng. in compile time) konstruišu sve merne jedinice, a da se potom u toku izvršavanja eventualno ispišu neke njihove osobine. S toga 
nas ne iznađuju izveštaji alata **memcheck** i **massif** koji kažu da je hip memorija mali broj puta alocirana i to pri samom kraju izvršavanja programa.

## Autor
Petar Tešić 1064/2022 5I
