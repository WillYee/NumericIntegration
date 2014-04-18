default: all

all:	
	mkdir build
	g++ -O3 -c src/Surface.cpp -o build/Surface.o -O3
	g++ -O3 -c src/ArgumentParser.cpp -o build/ArgumentParser.o
	g++ -O3 -c src/NumericIntegration.cpp -o build/NumericIntegration.o -fopenmp
	g++ -O3 build/Surface.o build/ArgumentParser.o build/NumericIntegration.o -o build/NumericIntegration -fopenmp -lpthread

clean:
	rm -rf build