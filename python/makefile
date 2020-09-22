CC=g++
#python3.7-config --cflags
PY=-I/usr/include/python3.7m/ -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.7-3.7.3=. -specs=/usr/share/dpkg/no-pie-compile.specs -fstack-protector -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall

#python3.7-config --ldflags
PYLINK=-L/usr/lib/python3.7/config-3.7m-x86_64-linux-gnu -L/usr/lib -lpython3.7m -lcrypt -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions

#PYINC=-I/usr/include/python3.7m

PYCFG=pkg-config --cflags --libs


functionCall: functionCall.o
	$(CC) functionCall.o `python3.7-config --cflags --ldflags`


simple:	simple.o
	$(CC) simple.o `python3.7-config --cflags --ldflags`

