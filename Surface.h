#ifndef SURFACE_H
#define SURFACE_H

class Surface
{
 public:
	
	Surface(double num_divisions);
	~Surface() {}

	double Height(unsigned long long iu, unsigned long long iv, unsigned long long number);
	double GetTileArea();
 private:
	static const double XMIN = 0;
	static const double XMAX = 3;
	static const double YMIN = 0;
	static const double YMAX = 3;
	
	static const double Z00 = 0;
	static const double Z10 = 1;
	static const double Z20 = 0;
	static const double Z30 = 0;

	static const double Z01 = 1;
	static const double Z11 = 6;
	static const double Z21 = 1;
	static const double Z31 = 0;

	static const double Z02 = 0;
	static const double Z12 = 1;
	static const double Z22 = 0;
	static const double Z32 = 4;

	static const double Z03 = 3;
	static const double Z13 = 2;
	static const double Z23 = 3;
	static const double Z33 = 3;

	double subdivisions;

	Surface(const Surface& copy); // Disable copy constructor
	Surface& operator=(const Surface&);
};

#endif

