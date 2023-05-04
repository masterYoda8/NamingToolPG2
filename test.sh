g++ -std=c++20 -o test -lgtest -lgtest_main src/utils.cpp tests/test.cpp
clear
./test
rm test
