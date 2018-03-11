#include <iostream>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>


// (C) 2018 Boguslaw Krawczuk


using namespace std;


class Divisors {
public:
  void setN(const int n);
  void setM(const int m);
  void generateRandoms();
  void sieve();
  void map();
  void inM();
  void inN();
private:
  set<int> values, primes;
  multimap<int,int> pv;
  int N, M;
};


