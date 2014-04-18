default: all

all:	
	mkdir ../build
	g++ -O3 -c Surface.cpp -o build/Surface.o -O3
	g++ -O3 -c ArgumentParser.cpp -o build/ArgumentParser.o
	g++ -O3 -c NumericIntegration.cpp -o build/NumericIntegration.o -fopenmp
	g++ -O3 Surface.o ArgumentParser.o build/NumericIntegration.o -o build/NumericIntegration -fopenmp -lpthread

clean:
	rm Surface.o
	rm ArgumentParser.o
	rm NumericIntegration.o
	rm NumericIntegration