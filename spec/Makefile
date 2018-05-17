#g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
#	    -pthread -c ${GTEST_DIR}/src/gtest-all.cc
#ar -rv libgtest.a gtest-all.o

$(warning "${CC}")
CXXFLAGS+=-std=c++11
$(warning "${CXX}")
$(warning "${CXXFLAGS}")

GTEST_DIR=../test/googletest
GMOCK_DIR=../test/googlemock
GTEST_LIB=../test
CPPFLAGS+=-L/usr/local/Cellar/protobuf/3.5.1_1/lib
#protoc --cpp_out=. *.proto
spec:
	${CXX} ${CPPFLAGS} -O2 -std=c++14 -isystem ${GTEST_DIR}/include/ \
            -isystem ${GMOCK_DIR}/include/ \
            -pthread  sprout_math.pb.cc process_forecast_spec.cc process_forecast.cc process.cc sampled_function_spec.cc sampled_function.cc sender_report_spec.cc sender_report.cc factorial_spec.cc factorial.cc \
            ${GTEST_LIB}/libgmock.a \
            -lprotobuf \
            -o s_spec

clean:
	rm -rf s_spec
