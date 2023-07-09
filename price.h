#ifndef PRICE_H
#define PRICE_H

#include <iostream>
using namespace std;

class Price
{
  friend ostream& operator<<(ostream& out, const Price& p);
 private:
  int dollar;
  int cent;

 public:
  Price();
  Price(int d, int c);
  //ostream& operator<<(ostream& out, const Price& p);
  Price operator+(const Price& pr);
  Price operator-(const Price& pri);
};

#endif

