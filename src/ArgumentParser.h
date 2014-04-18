#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <vector>
#include <string>

class ArgumentParser
{
 public: 
	
	ArgumentParser(int argc, const char* argv[]);
	~ArgumentParser() {}

	bool               Validate();
	unsigned long long GetNumDivisions() { return numDivisions; }
	unsigned long long GetNumThreads() { return numThreads; }

 private:

	bool               Parse();
	unsigned long long numThreads;
	unsigned long long numDivisions;

	int                      argc;
	std::vector<std::string> argv;

	ArgumentParser(const ArgumentParser&); // Disable copy constructor
	ArgumentParser& operator=(const ArgumentParser&); // Disable assignment operator
};

#endif
