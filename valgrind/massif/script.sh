g++ -std=c++17 ../../2019_Compound-Units/demo.cpp

valgrind --tool=massif --log-file=massif_output_1.txt ./a.out 

#valgrind --tool=massif --log-file=massif_output_1.txt --stack=yes ./a.out 
#ms_print massif.out.PID > massif_graph.txt

rm a.out
