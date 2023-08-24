# 2023_Analysis_Compound_Unit

## Analiza projekta Compound Unit (složene merne jedinice)
Ovaj repozitorijum predstavlja samostalni praktični seminarski rad izrađen za potrebe kursa Verifikacija softvera na master studijama Matematičkog fakulteta u Beogradu. Samostalni praktični seminarski rad podrazumeva primenu alata za statičku i dinamičku verifikaciju softvera na nekom od studentskih projekata. <br>

## O projektu:
Projekat je urađen za potrebe kursa Programske paradigme. <br>
Projekat je napisan u programskom jeziku C++ i mogao bi se svrstati pod funkcionalnu i generičku programsku paradigmu. <br>
Osnovna ideja iza samog projekta jeste pokušaj za definisanjem generičkog tipa "compound_unit" (složena jedinica) koji bi bio korišćen za reprezentovanje različitih mernih jedinica. <br>
Na primer: compound_unit<meter<1>, second<-2>> bi predstavljalo m/s^2 (mernu jedinicu za ubrzanje). <br>
Ukoliko bismo pomnožili različite veličine, na primer: 32m/s^2 * 5s <br>
...trebalo bi da dobijemo m/s, odnosno <meter<1>, second<-1>>. <br>

## Korišćeni alati:

- **gcov lcov**
- **QtTest**
- **Valgrind - massif**
- **Valgrind - memcheck**
- **Valgrind - callgrind**
- **KLEE**
- **Perf**


## Izvedeni zaključci:
U projektu nisu pronađeni veći propusti. Projekat je po obimu mali. Implementirano je dosta funkcionalnosti u .hpp fajlovima, ali je mali broj njih testiran u demo.cpp fajlu.
