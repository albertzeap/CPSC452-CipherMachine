all:	cipher

cipher:	cipher.o Playfair.o RowTransposition.o Caesar.o RailFence.o Vigenre.o
	g++ cipher.o Playfair.o RowTransposition.o Caesar.o RailFence.o Vigenre.o -o cipher
	

cipher.o:	cipher.cpp
	g++ -g -c cipher.cpp 

Playfair.o:	Playfair.cpp Playfair.h CipherInterface.h
	g++ -g -c Playfair.cpp

RowTransposition.o:	RowTransposition.cpp RowTransposition.h CipherInterface.h
	g++ -g -c RowTransposition.cpp

Caesar.o: Caesar.cpp Caesar.h CipherInterface.h
	g++ -g -c Caesar.cpp

RailFence.o: RailFence.cpp RailFence.h CipherInterface.h
	g++ -g -c RailFence.cpp

Vigenre.o: Vigenre.cpp Vigenre.h CipherInterface.h
	g++ -g -c Vigenre.cpp

clean:
	rm -rf *.o cipher
