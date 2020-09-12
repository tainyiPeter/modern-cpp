#include "stl_header.h"

using namespace std;

class Polynomial {
public:
	using RootsType = std::vector<double>;
	RootsType roots() const
	{
		if (!rootsAreValid) { // if cache not valid
			// compute roots,
			// store them in rootVals
			rootsAreValid = true;
		}
		return rootVals;
	}
private:
	mutable bool rootsAreValid{ false }; // see Item 7 for info
	mutable RootsType rootVals{}; // on initializers
};

//int main()
//{
//
//	return 0;
//}