show: Makefile
	cat Makefile
test1: ../../2019_Compound-Units/demo.cpp
	g++ -std=c++17 -Wall -Wextra -g -O0 ../../2019_Compound-Units/demo.cpp -o test1
test2: ../../2019_Compound-Units/demo.cpp
	g++ -std=c++17 -g -O0 ../../2019_Compound-Units/demo.cpp -o test2	

.PHONY: clean

clean:
	rm test1 test2 memcheck_report_*
	
