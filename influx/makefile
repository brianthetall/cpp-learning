CXX = clang++
#CXX=g++
CXXFLAGS = -std=c++11 -I. -Wall -Wextra -pthread

BROTLI_DIR = /usr/bin/brotli
OPENSSL_INC_DIR = /usr/include
OPENSSL_LIB_DIR = /usr/lib/x86_64-linux-gnu
OPENSSL_SUPPORT = -DCPPHTTPLIB_OPENSSL_SUPPORT -I$(OPENSSL_INC_DIR)/include -L$(OPENSSL_LIB_DIR) -lssl -lcrypto
ZLIB_SUPPORT = -DCPPHTTPLIB_ZLIB_SUPPORT -lz
# BROTLI_SUPPORT = -DCPPHTTPLIB_BROTLI_SUPPORT -I$(BROTLI_DIR)/include -L$(BROTLI_DIR)/lib -lbrotlicommon-static -lbrotlienc-static -lbrotlidec-static

all: influxConnector

influxConnector : influxConnector.cpp main.cpp ./httplib.h ./influxConnector.h makefile
	$(CXX) -o influxConnector $(CXXFLAGS) main.cpp influxConnector.cpp $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) 

pem:
	openssl genrsa 2048 > key.pem
	openssl req -new -key key.pem | openssl x509 -days 3650 -req -signkey key.pem > cert.pem

clean:
	rm influxConnector
