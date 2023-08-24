Label4:
	cd FlameGraph
Label3:
	sudo perf record -F 99 -ag -- sleep 60
Label2:
	perf script | ./stackcollapse-perf.pl > out.perf-folded
Label1:
	cat out.perf-folded | ./flamegraph.pl > perf-kernel.svg



