#include <set>
#include <map>

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
  int N = 0 , M = 0;
};


