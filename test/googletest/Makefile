
lib:
	g++ -isystem ./include -I. -pthread -c ./src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

clean:
	rm -rf *.o *.a
