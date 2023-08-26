#Option 1 for the first command in the script!
#g++ -std=c++17 -g -Wall -fprofile-arcs -ftest-coverage -O0 ../2019_Compound-Units/demo.cpp -o test

#Option 2 for the first command in the script!
#g++ -g -Wall --coverage -O0 main.cpp -o test

#After building a project we have to execute it, otherwise we won't receive any information
#about project's code coverage!
./test

lcov --rc lcov_branch_coverage=1 -c -d . -o coverage-test.info

lcov --rc lcov_branch_coverage=1 -r coverage-test.info ’/usr/*’ ’/opt/*’ ’*.moc’ -o coverage-filtered.info

genhtml --rc lcov_branch_coverage=1 -o Reports coverage-filtered.info

firefox Reports/index.html
