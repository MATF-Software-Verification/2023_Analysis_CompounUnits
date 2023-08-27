#Bellow are commands you should use (one of them only)!
valgrind --tool=callgrind --cache-sim=yes --log-file=callgrind_report --callgrind-out-file=callgrind_report ./test

#valgrind --tool=callgrind --branch-sim=yes --log-file=callgrind_report --callgrind-out-file=callgrind_report ./test

#We could open callgrind report via kcachegrind tool!
#kcachegrind callgrind_report
