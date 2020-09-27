CC=g++
FLAGS = -std=c++11 -I. -Wall -Wextra -lcgicc

all: getForm example

getForm:
	$(CC) getForm.cpp -o getForm.cgi $(FLAGS)
	sudo cp getForm.cgi $(CGI)/

example:
	$(CC) cgicc_example.cpp -o example.cgi $(FLAGS)
	sudo cp example.cgi $(CGI)/

clean:
	rm getForm.cgi



