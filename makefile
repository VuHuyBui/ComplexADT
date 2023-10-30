all: complex mandelbrot

complex: main.o Complex.o
	g++ -o complex main.o Complex.o

mandelbrot: mandelbrot.o Complex.o
	g++ -o mandelbrot mandelbrot.o Complex.o

main.o: main.cpp Complex.h
	g++ -c main.cpp

mandelbrot.o: mandelbrot.cpp Complex.h
	g++ -c mandelbrot.cpp

Complex.o: Complex.cpp Complex.h
	g++ -c Complex.cpp
