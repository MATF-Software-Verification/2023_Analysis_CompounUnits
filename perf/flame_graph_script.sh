cd FlameGraph
sudo perf record -F 99 -ag -- sleep 60

#sudo perf script | ./stackcollapse-perf.pl > out.perf-folded
#cat out.perf-folded | ./flamegraph.pl > perf-kernel.svg

sudo perf script | ./stackcollapse-perf.pl | ./flamegraph.pl > perf-kernel.svg

firefox perf-kernel.svg
