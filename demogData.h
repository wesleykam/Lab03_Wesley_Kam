#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>

using namespace std;

/*
  class to represent county demographic data
  from CORGIS
*/
class demogData {
  public:
    demogData(string inN, string inS, double in65, double in18,
        double in5, int totPop14) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), BAup(0), HSup(0), belowPoverty(0), totalPopulation2014(totPop14) {}

    demogData(string inN, string inS, double in65, double in18,
        double in5, double BA, double HS, double inP, int totPop14) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), BAup(BA), HSup(HS), belowPoverty(inP), totalPopulation2014(totPop14) {}

    string getName() const { return name; }
    string getState() const { return state; }
    double getpopOver65() const { return popOver65; }
    double getpopUnder18() const { return popUnder18; }
    double getpopUnder5() const { return popUnder5; }
    double getBAup() const { return BAup; }
    double getHSup () const { return HSup; }
    double getpopBelowPoverty() const { return belowPoverty; }
    int getPop() const { return totalPopulation2014; }

    int getpopOver65Count() const {
        return (popOver65/100.00) * totalPopulation2014;
    }
    int getpopUnder18Count() const {
        return (popUnder18/100.00) * totalPopulation2014;
    }
    int getpopUnder5Count() const {
        return (popUnder5/100.00) * totalPopulation2014;
    }    
    int getBAupCount() const {
        return (BAup/100.00) * totalPopulation2014;
    }    
    int getHSupCount() const {
        return (HSup/100.00) * totalPopulation2014;
    }
    int getpopBelowPovertyCount() const {
        return (belowPoverty/100.00) * totalPopulation2014;
    }
   
   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

private:
    const string name;
    const string state;
    const double popOver65;
    const double popUnder18;
    const double popUnder5;
    const double BAup;
    const double HSup;
    const double belowPoverty;
    const int totalPopulation2014;

};
#endif
