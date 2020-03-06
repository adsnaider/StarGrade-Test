CXX=g++
LINKOPTS= -lgradescope_test_listener -lgtest -lpthread
COPTS=-std=c++11 -Wall -I .

mkbin:
	mkdir -p bin/

bin/tests: mkbin tests/tests.cc bin/submission.o
	$(CXX) $(COPTS) tests/tests.cc bin/submission.o $(LINKOPTS) -o bin/tests

bin/submission.o: mkbin submission/submission.cc
	$(CXX) $(COPTS) -c submission/submission.cc -o bin/submission.o

clean:
	rm -rf bin/*
