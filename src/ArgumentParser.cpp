#include "ArgumentParser.h"
#include <cstdlib>

ArgumentParser::ArgumentParser(int argc, const char* argv[])
	: numThreads(0)
	, numDivisions(0)
	, argc(argc)
{
	// Copy all the commandline args into a string array
	this->argv = std::vector<std::string>(argv, argv + argc);
}

bool ArgumentParser::Validate()
{
	// Expanded out for readability

	bool returnVal = false;
	
	if (argc == 5 && (Parse() == true)) // Invalid params usage
	{
		returnVal = true;
	}

	return returnVal;
}

bool ArgumentParser::Parse()
{
	bool result = false;

	numDivisions = atoi(argv[2].c_str());
	numThreads = atoi(argv[4].c_str());

	if (argv[1].compare("-D") == 0 && 
	    numDivisions           != 0 && // Make sure the 3rd argument is an integer
	    argv[3].compare("-T")  == 0 && 
	    numThreads             != 0) // Make sure the 5th argument is an integer
	{
		result = true;
	}

	return result;
}
