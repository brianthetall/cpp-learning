CC=g++
CFLAGS=-lboost_system -lboost_chrono
clocksmake: clocks.o	
	$(CC) $(CFLAGS) -o clocks clocks.o

json: json.o
	$(CC) -o json json.o

clean:
	rm -rf clocks.o clocks
