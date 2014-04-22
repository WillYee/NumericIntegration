#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#include <omp.h>
#include <stdint.h>

#include "ArgumentParser.h"
#include "Surface.h"

void print_usage()
{
	std::cout << "Usage: Assign1.exe -D <divisions> -T <num_threads>\n";
	return;
}

int main(int argc, char* argv[])
{
#ifndef _OPENMP
	fprintf(stderr, "OpenMP is not supported - sorry!\n");
	return 1;
#endif
	
	ArgumentParser parser(argc, (const char**) argv);
	
	if (parser.Validate() == false)
	{
		print_usage();
		return 1;
	}

	Surface surface((double) parser.GetNumDivisions());

	unsigned long long input_number = parser.GetNumDivisions();

	omp_set_num_threads(parser.GetNumThreads());

	double total_volume   = 0;
	double fullTileArea = surface.GetTileArea();
	double start        = omp_get_wtime();

#pragma omp parallel for default(none), shared(input_number, fullTileArea, surface), reduction(+:total_volume)
	for (unsigned long long i = 0; i < input_number*input_number; i++)
	{
		unsigned long long iu = i % input_number;
		unsigned long long iv = i / input_number;

		if ((iv == 0 && iu > 0) || // bottom edge
			(iu == 0 && iv > 0) || // left edge
			(iv == input_number && (iu < input_number && iu != 0)) || // top edge
			(iu == input_number && (iv < input_number && iv != 0))) // right edge
		{
			total_volume += (fullTileArea / 2) * surface.Height(iu, iv, input_number);
			continue;
		}

		if ((iv == 0 && iu == 0)		|| // corner 0,0
			(iv == 0 && iu == input_number) || // corner 0, max
			(iv == input_number && iu == 0) || // corner max, 0
			(iv == input_number && iu == input_number)) // corner max,max
		{
			total_volume += (fullTileArea / 4) * surface.Height(iu, iv, input_number);
			continue;
		}

		total_volume += fullTileArea * surface.Height(iu, iv, input_number);
	}

	double end = omp_get_wtime();

	std::cout.precision(10);
	std::cout << end - start << "s" <<  "," << total_volume << std::endl;

	return 0;
}
