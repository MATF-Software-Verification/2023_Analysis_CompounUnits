default: test

show: Makefile
	cat Makefile

test: ../../2019_Compound-Units/demo.cpp
	g++ -std=c++17 -g -O0 ../../2019_Compound-Units/demo.cpp -o test	

.PHONY: clean

clean:
	rm test massif_report.txt whole_report massif_graph.txt
	
