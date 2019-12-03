main: main.o
	g++ -std=c++11 main.o -o ProjectEncrypt
main.o: main.cpp encryption.h
	g++ -c main.cpp
clean:
	rm main.o
