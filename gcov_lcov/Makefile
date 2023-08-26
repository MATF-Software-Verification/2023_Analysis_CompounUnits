default: option1

show: Makefile
	cat Makefile

option1: ../2019_Compound-Units/demo.cpp
	g++ -std=c++17 -g -Wall -fprofile-arcs -ftest-coverage -O0 ../2019_Compound-Units/demo.cpp -o test

option2: ../2019_Compound-Units/demo.cpp
	g++ -std=c++17 -g -Wall --coverage -O0 main.cpp -o test		

.PHONY: clean

clean:
	rm -rf test *.gcda *.gcno *.info Reports/
	
