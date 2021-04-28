/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "demogState.h"
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

dataAQ::dataAQ() {}

/* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
void dataAQ::createStateData(std::vector<shared_ptr<demogData>> theData) {
//FILL in 

	//std::map<std::string, shared_ptr<demogState>>::iterator it;
	
	for (auto const& DD : theData)
	{
		string state = DD->getState();
		//stateData.clear();
		//for( auto const& it: stateData ) 
		//cout << state << endl;
		
		
		/*
		for (auto it = stateData.begin(); it != stateData.end(); it++)
		{	
			cout << "2" << endl;
			if (DD->getState() == it->first)
			{
				it->second->setCounties(it->second->getCounties() + 1);
				it->second->setpopOver65Count(DD->getpopOver65Count() + it->second->getpopOver65Count());
				it->second->setpopUnder18Count(DD->getpopUnder18Count() + it->second->getpopUnder18Count());
				it->second->setpopUnder5Count(DD->getpopUnder5Count() + it->second->getpopUnder5Count());
				it->second->setBAupCount(DD->getBAupCount()+ it->second->getBAupCount());
				it->second->setHSupCount(DD->getHSupCount() + it->second->getHSupCount());
				it->second->setpopBelowPovertyCount(DD->getpopBelowPovertyCount() + it->second->getpopBelowPovertyCount());
				it->second->setPop(DD->getPop() + it->second->getPop());
				matchState = true;
			}
		}
		*/
		//if(stateData.find(state) != stateData.end())
		if (stateData.count(state) < 1)
		{
			//cout << "3" << endl;
			stateData.insert(std::pair<std::string, shared_ptr<demogState>>(DD->getState(), make_shared<demogState>(DD->getState(), 1, DD->getpopOver65Count(), DD->getpopUnder18Count(), DD->getpopUnder5Count(), DD->getBAupCount(), DD->getHSupCount(), DD->getpopBelowPovertyCount(), DD->getPop())));
		}
		else
		{
			//cout << "2" << endl;
			stateData.at(state)->setCounties(stateData.at(state)->getCounties() + 1);
			stateData.at(state)->setpopOver65Count(DD->getpopOver65Count() + stateData.at(state)->getpopOver65Count());
			stateData.at(state)->setpopUnder18Count(DD->getpopUnder18Count() + stateData.at(state)->getpopUnder18Count());
			stateData.at(state)->setpopUnder5Count(DD->getpopUnder5Count() + stateData.at(state)->getpopUnder5Count());
			stateData.at(state)->setBAupCount(DD->getBAupCount() + stateData.at(state)->getBAupCount());
			stateData.at(state)->setHSupCount(DD->getHSupCount() + stateData.at(state)->getHSupCount());
			stateData.at(state)->setpopBelowPovertyCount(DD->getpopBelowPovertyCount() + stateData.at(state)->getpopBelowPovertyCount());
			stateData.at(state)->setPop(DD->getPop() + stateData.at(state)->getPop());
			
		}		
	}


}

//return the name of the state with the largest population under age 5
string dataAQ::youngestPop() {
	string maxState = "AL";

	for (std::map<std::string, shared_ptr<demogState>>::iterator it = stateData.begin(); it != stateData.end(); it++)
	{
		if (it->second->getpopUnder5Percent() > stateData.at(maxState)->getpopUnder5Percent())
			maxState = it->first;
	}

	return maxState; 
} 

//return the name of the state with the largest population under age 18
string dataAQ::teenPop()  {
	string maxState = "AL";

	for (std::map<std::string, shared_ptr<demogState>>::iterator it = stateData.begin(); it != stateData.end(); it++)
	{
		if (it->second->getpopUnder18Percent() > stateData.at(maxState)->getpopUnder18Percent())
			maxState = it->first;
	}

	return maxState;
}

//return the name of the state with the largest population over age 65
string dataAQ::wisePop()  {
	string maxState = "AL";

	for (std::map<std::string, shared_ptr<demogState>>::iterator it = stateData.begin(); it != stateData.end(); it++)
	{
		if (it->second->getpopOver65Percent() > stateData.at(maxState)->getpopOver65Percent())
			maxState = it->first;
	}

	return maxState;
}

//return the name of the state with the largest population who did not receive high school diploma
string dataAQ::underServeHS() {
	string maxState = "AL";

	for (std::map<std::string, shared_ptr<demogState>>::iterator it = stateData.begin(); it != stateData.end(); it++)
	{
		if (100 - it->second->getHSupPercent() > 100 - stateData.at(maxState)->getHSupPercent())
			maxState = it->first;
	}

	return maxState;
} 

//return the name of the state with the largest population who did receive bachelors degree and up
string dataAQ::collegeGrads() {
	string maxState = "AL";

	for (std::map<std::string, shared_ptr<demogState>>::iterator it = stateData.begin(); it != stateData.end(); it++)
	{
		if (it->second->getBAupPercent() > stateData.at(maxState)->getBAupPercent())
			maxState = it->first;
	}

	return maxState;
}

//return the name of the state with the largest population below the poverty line
string dataAQ::belowPoverty() {
	string maxState = "AL";

	for (std::map<std::string, shared_ptr<demogState>>::iterator it = stateData.begin(); it != stateData.end(); it++)
	{
		if (it->second->getpopBelowPovertyPercent() > stateData.at(maxState)->getpopBelowPovertyPercent())
			maxState = it->first;
	}

	return maxState;
} 
