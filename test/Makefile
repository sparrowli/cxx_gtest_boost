#Note: g++
#CC=g++-8.1
GTEST_DIR=./googletest
GMOCK_DIR=./googlemock

lib:
	${CXX} -std=c++14 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
            -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} \
            -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	${CXX} -std=c++14 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
            -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} \
            -pthread -c ${GMOCK_DIR}/src/gmock-all.cc
	ar -rv libgmock.a gtest-all.o gmock-all.o

clean:
	rm -rf *.o *.a
