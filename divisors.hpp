#include <set>
#include <map>

// (C) 2018 Boguslaw Krawczuk


using namespace std;


class Divisors {
public:
  void generateRandoms();
  void sieve();
  void map(); 
  void inM();
  void inN();
  Divisors(const int n, const int m);
private:
  set<int> values, primes;
  int N = 0 , M = 0;
};


