#pragma once
#include <string>

/*C.  Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY,
NETWORK, and SOFTWARE.*/

enum DegreeProgram {
	SECURITY,
	NETWORK,
	SOFTWARE,
	UNDECIDED
};

//created array to get a string output for the user rather than a 0 or 1
static const std::string degreeType[] = { "SECURITY", "NETWORK","SOFTWARE","UNDECIDED" };
