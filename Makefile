CPPFLAGS = -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main_testowy.o  obj/LZespolona.o
	g++ -g -Wall -pedantic -o uklad_rownan obj/main_testowy.o obj/LZespolona.o      

obj/main_testowy.o: src/main_testowy.cpp inc/SWektor.hh inc/rozmiar.h inc/LZespolona.hh 
	g++ ${CPPFLAGS} -o obj/main_testowy.o src/main_testowy.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

clean:
	rm -f obj/*.o uklad_rownan