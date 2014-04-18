default: all

all:
	g++ -O3 -c Surface.cpp -o Surface.o -O3
	g++ -O3 -c ArgumentParser.cpp -o ArgumentParser.o
	g++ -O3 -c NumericIntegration.cpp -o NumericIntegration.o -fopenmp
	g++ -O3 Surface.o ArgumentParser.o NumericIntegration.o -o NumericIntegration -fopenmp -lpthread

clean:
	rm Surface.o
	rm ArgumentParser.o
	rm NumericIntegration.o
	rm NumericIntegration