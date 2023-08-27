#Bellow are commands you should use (one of them only)!
#valgrind --tool=massif --log-file=massif_report.txt ./test 

#valgrind --tool=massif --log-file=massif_report.txt --stacks=yes ./test

#valgrind --tool=massif --log-file=massif_report.txt --stacks=yes --massif-out-file=whole_report ./test

valgrind --tool=massif --log-file=massif_report.txt --detailed-freq=1 --massif-out-file=whole_report ./test 

#This is how default setup look like (we are just checking --detailed-freq option)!
#valgrind --tool=massif --log-file=massif_report.txt --detailed-freq=10 --massif-out-file=whole_report ./test 

#Ignore the line bellow!
#ms_print massif.out.PID > massif_graph.txt

ms_print whole_report > massif_graph.txt
