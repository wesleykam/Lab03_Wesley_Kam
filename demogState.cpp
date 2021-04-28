#include "demogState.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

using namespace std;

//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogState&SD) {
	out << fixed << showpoint;
	out << setprecision(2);

	out << "State Info: " << SD.getName() << endl;
	out << "Number of Counties: " << SD.getCounties() << endl;
	out << "Population info: " << endl;
	out << "(over 65): " << SD.getpopOver65Percent() << "% and total: " << (int)(SD.getpopOver65Count() + .5)<< endl;
	out << "(under 18): " << SD.getpopUnder18Percent() << "% and total: " << (int)(SD.getpopUnder18Count() + .5) << endl;
	out << "(under 5): " << SD.getpopUnder5Percent() << "% and total: " << (int)(SD.getpopUnder5Count() + .5) << endl;
	out << "Education info: " << endl;
	out << "(Bachelor or more): " << SD.getBAupPercent() << "% and total: " << (int)(SD.getBAupCount() + .5) << endl;
	out << "(high school or more): " << SD.getHSupPercent() << "% and total: " << (int)(SD.getHSupCount() + .5) << endl;
	out << "persons below poverty: " << SD.getpopBelowPovertyPercent() << "% and total: " << (int)(SD.getpopBelowPovertyCount() + .5) << endl;
	out << "Total population: " << SD.getPop();
	return out;
}

/*
*** the state that needs the most pre-schools**
State Info: UT
Number of Counties: 29
Population info: 
(over 65): 10.03% and total: 295146
(under 18): 30.71% and total: 903830
(under 5): 8.58% and total: 252378
Education info: 
(Bachelor or more): 30.54% and total: 898886
(high school or more): 91.01% and total: 2678412
persons below poverty: 12.67% and total: 372832
Total population: 2942902
*/
