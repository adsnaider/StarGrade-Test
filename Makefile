CXX=g++
LINKOPTS= -lgradescope_test_listener -lgtest -lpthread
COPTS=-std=c++11 -Wall -I .

bin/tests: tests/tests.cc bin/submission.o
	$(CXX) $(COPTS) tests/tests.cc bin/submission.o $(LINKOPTS) -o bin/tests

bin/submission.o: submission/submission.cc
	$(CXX) $(COPTS) -c submission/submission.cc -o bin/submission.o

clean:
	rm -rf bin/*
