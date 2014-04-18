#include "Surface.h"

Surface::Surface(double num_divisions)
	: subdivisions(num_divisions)
{
}

double Surface::Height(unsigned long long iu, unsigned long long iv, unsigned long long number)
{
	double u = (double) iu / (double)(number - 1);
	double v = (double) iv / (double)(number - 1);

	// the basis functions:

	double bu0 = (1. - u) * (1. - u) * (1. - u);
	double bu1 = 3. * u * (1. - u) * (1. - u);
	double bu2 = 3. * u * u * (1. - u);
	double bu3 = u * u * u;

	double bv0 = (1. - v) * (1. - v) * (1. - v);
	double bv1 = 3. * v * (1. - v) * (1. - v);
	double bv2 = 3. * v * v * (1. - v);
	double bv3 = v * v * v;

	// finally, we get to compute something:

	double height = bu0 * ( bv0 * Z00 + bv1 * Z01 + bv2 * Z02 + bv3 * Z03 )
			+ bu1 * ( bv0 * Z10 + bv1 * Z11 + bv2 * Z12 + bv3 * Z13 )
			+ bu2 * ( bv0 * Z20 + bv1 * Z21 + bv2 * Z22 + bv3 * Z23 )
			+ bu3 * ( bv0 * Z30 + bv1 * Z31 + bv2 * Z32 + bv3 * Z33 );

	return height;
}

double Surface::GetTileArea()
{
	return (((XMAX-XMIN) / (double)(subdivisions - 1)) * ((YMAX - YMIN) / (double)(subdivisions - 1)));
}
