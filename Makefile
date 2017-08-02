all: A02_Algorithm

A20_Algorithm: A02_Algorithm.c
	gcc -o A02_Algorithm A02_Algorithm.c -std=c++11 -g
