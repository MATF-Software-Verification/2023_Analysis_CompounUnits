sudo perf record --call-graph dwarf ./test
sudo perf report

#----------------------------------------------------------------------
#perf

#perf stat -h

#perf list

#perf stat -B dd if=/dev/zero of=/dev/null count=1000000

#perf stat -e cycles dd if=/dev/zero of=/dev/null count=100000

#perf stat -e instructions:u dd if=/dev/zero of=/dev/null count=100000

#perf stat -e cycles,instructions,cache-misses ...

#perf stat -e cycles -p <id> sleep 2

#----------------------------------------------------------------------
#Uzorkovanje
#sudo perf record -F 99 -a -g -- sleep 20

#sudo perf report -n --stdio
