CC=g++
CFLAGS=-lboost_system -lboost_chrono
CLIENTFLAGS=-lboost_system

httpClientEx: httpClientEx.o
	$(CC) $(CLIENTFLAGS) -o clientHttpEx clientHttpEx.cpp

clocksmake: clocks.o	
	$(CC) $(CFLAGS) -o clocks clocks.o

json: json.o
	$(CC) -o json json.o

clean:
	rm -rf clocks.o clocks json.o json
