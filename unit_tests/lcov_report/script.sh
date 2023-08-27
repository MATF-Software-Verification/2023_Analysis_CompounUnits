lcov -d ../build-CU_UnitTests-Desktop-Debug/ -c -o coverage.info

lcov -r "coverage.info" "*Qt*.framework*" "*.h" "*/tests/*" "*Xcode.app*" "*.moc" "*moc_*.cpp" "*/test/*" "*/build*/*" -o "coverage-filtered.info"

genhtml -o coverage_html coverage-filtered.info

#Last command! You can comment it and type it via terminal if you prefer that way.
firefox coverage_html/index.html
