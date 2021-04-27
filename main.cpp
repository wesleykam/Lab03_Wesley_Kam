#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "demogData.h"
#include "parse.h"
#include "dataAQ.h"

using namespace std;

int main() {

    dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data
    std::vector<shared_ptr<demogData>> theData = read_csv(
            "county_demographics.csv", DEMOG);

     //debug print out - uncomment if you want to double check your data
    /*
    for (const auto &obj : theData) {
        std::cout << *obj << std::endl;
    }
    */

    theAnswers.createStateData(theData);

    //one example of how to print required - ADD OTHERS
    cout << "*** the state that needs the most pre-schools**" << endl;
    string needPK = theAnswers.youngestPop();
    //cout << "Name of state: " << needPK << endl;
    if (theAnswers.getStateData(needPK) != nullptr){
        cout << *(theAnswers.getStateData(needPK)) << endl;
    } else{
        cout << "Did you read the lab instructions?" << endl;
    }

    //NOW fill in these too
    cout << "*** the state that needs the most high schools**" << endl;
    string needHS = theAnswers.teenPop();
    //cout << "Name of state: " << needHS << endl;
    if (theAnswers.getStateData(needHS) != nullptr) {
        cout << *(theAnswers.getStateData(needHS)) << endl;
    }
    else {
        cout << "Did you read the lab instructions?" << endl;
    }

    cout << "*** the state that needs the most vaccines**" << endl;
    string needVaccines = theAnswers.wisePop();
    //cout << "Name of state: " << needVaccines << endl;
    if (theAnswers.getStateData(needVaccines) != nullptr) {
        cout << *(theAnswers.getStateData(needVaccines)) << endl;
    }
    else {
        cout << "Did you read the lab instructions?" << endl;
    }

    cout << "*** the state that needs the most help with education**" << endl;
    string needEdu = theAnswers.underServeHS();
    //cout << "Name of state: " << needEdu << endl;
    if (theAnswers.getStateData(needEdu) != nullptr) {
        cout << *(theAnswers.getStateData(needEdu)) << endl;
    }
    else {
        cout << "Did you read the lab instructions?" << endl;
    }

    cout << "*** the state with most college grads**" << endl;
    string mostBA = theAnswers.collegeGrads();
    //cout << "Name of state: " << mostBA << endl;
    if (theAnswers.getStateData(mostBA) != nullptr) {
        cout << *(theAnswers.getStateData(mostBA)) << endl;
    }
    else {
        cout << "Did you read the lab instructions?" << endl;
    }

    cout << "*** the state with largest percent of the population below the poverty line**" << endl;
    string mostPov = theAnswers.belowPoverty();
    //cout << "Name of state: " << mostPov << endl;
    if (theAnswers.getStateData(mostPov) != nullptr) {
        cout << *(theAnswers.getStateData(mostPov)) << endl;
    }
    else {
        cout << "Did you read the lab instructions?" << endl;
    }

    return 0;
}

