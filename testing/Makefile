all: exam3_test.bin set_example.bin combine.bin

exam3_test.bin: exam3_test.cpp
	g++ -o $@ $^

set_example.bin: set_example.c
	gcc -o $@ $^ -lm

combine.bin: combine.cpp ../src/libalkstat.cpp
	g++ -o $@ $^ -g

