#Bellow are commands you should use (one of them only)!
valgrind --tool=massif --log-file=massif_report.txt ./test 

#valgrind --tool=massif --log-file=massif_report.txt --stack=yes ./a.out



#Ignore the line bellow!
#ms_print massif.out.PID > massif_graph.txt

