#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"

/*
  class to represent state data - fairly redundent at this point but will use
  inheritence later - FILL IN
*/
class demogState {
  public:
   //FILL IN
      demogState(string inN, int inC, double in65, double in18,
          double in5, double BA, double HS, int inP, int totPop14) :
          name(inN), counties(inC), popOver65Count(in65), popUnder18Count(in18),
          popUnder5Count(in5), BAupCount(BA), HSupCount(HS), popBelowPovertyCount(inP), totalPopulation2014(totPop14) {}

      string getName() const { return name; }
      int getCounties() const{ return counties; }
      double getpopOver65Count() const { return popOver65Count; }
      double getpopUnder18Count() const { return popUnder18Count; }
      double getpopUnder5Count() const { return popUnder5Count; }
      double getBAupCount() const { return BAupCount; }
      double getHSupCount() const { return HSupCount; }
      double getpopBelowPovertyCount() const { return popBelowPovertyCount;  }
      int getPop() const { return totalPopulation2014; }

      void setCounties(int count) { counties = count; }
      void setpopOver65Count(double pop) { popOver65Count = pop; }
      void setpopUnder18Count(double pop) { popUnder18Count = pop; }
      void setpopUnder5Count(double pop) { popUnder5Count = pop; }
      void setBAupCount(double pop) { BAupCount = pop; }
      void setHSupCount(double pop) { HSupCount = pop; }
      void setpopBelowPovertyCount(double pop) { popBelowPovertyCount = pop; }
      void setPop(double pop) { totalPopulation2014 = pop; }


      double getpopOver65Percent() const {
          return (popOver65Count / (totalPopulation2014 * 1.00)) * 100;
      }
      double getpopUnder18Percent() const {
          return (popUnder18Count / (totalPopulation2014 * 1.00)) * 100;
      }
      double getpopUnder5Percent() const {
          return (popUnder5Count / (totalPopulation2014 * 1.00)) * 100;
      }
      double getBAupPercent() const {
          return (BAupCount / (totalPopulation2014 * 1.00)) * 100;
      }
      double getHSupPercent() const {
          return (HSupCount / (totalPopulation2014 * 1.00)) * 100;
      }
      double getpopBelowPovertyPercent() const {
          return (popBelowPovertyCount / (totalPopulation2014 * 1.00)) * 100;
      }


 friend std::ostream& operator<<(std::ostream &out, const demogState &SD);
	private:
	//DATA here
        string name;
        int counties;
        double popOver65Count;
        double popUnder18Count;
        double popUnder5Count;
        double BAupCount;
        double HSupCount;
        double popBelowPovertyCount;
        int totalPopulation2014;
};
#endif
