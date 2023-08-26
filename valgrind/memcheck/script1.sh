#Bellow are the commands you should use (one of them only)!

valgrind --tool=memcheck --track-origins=yes --log-file=memcheck_report_2 ./test1 

#valgrind --tool=memcheck --track-origins=yes --log-file=memcheck_report_2 -s ./test1

valgrind --tool=memcheck --track-origins=yes --leak-check=full --log-file=memcheck_report_2 ./test1



#If you don't want to see Compound unit project output printed on your terminal 
#we suggest you to uncomment clear command!
#clear

