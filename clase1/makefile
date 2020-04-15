out: main.o fx.o
	g++ main.o fx.o -o out

main.o: main.cpp
	g++ -c main.cpp

fx.o: fx.cpp fx.hpp
	g++ -c fx.cpp

clean:
	rm *.o out