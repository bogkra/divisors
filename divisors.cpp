#include <iostream>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include "divisors.hpp"


// (C) 2018 Boguslaw Krawczuk


using namespace std;



void Divisors::setN(const int n) 
{
  N = n;
}


void Divisors::setM(const int m)
{
  M = m;
}



// 1
void Divisors::generateRandoms()
{
  srand (time(NULL));
  for (int i=0; i<N; i++) {
    int m;
    do
      m = random() % (M+1);
    while (values.find(m)!=values.end());
    values.insert(m);
  };
  cout << "values: " << endl;
  for (int i : values)
    cout << i << " ";
  cout << endl;
} 



// 2 : sieve of Erastotenes
void Divisors::sieve() 
{
  for (int i=2; i<=M; i++)
    primes.insert(i); 
//  for_each(primes.begin(), primes.lower_bound(sqrt(M+1)), [&](int prime){//});
  for (int prime =2; prime<=M; prime++)
    if (primes.find(prime) != primes.end())
      for (int j=2*prime; j<=M; j+=prime)
        primes.erase(j);
//  });
  cout << "primes: " << endl;
  for (int i : primes)
    cout << i << " ";
  cout << endl;
}


// 3
void Divisors::map()
{
  for (int value : values)
    for (int prime : primes)
      if (value % prime == 0)
        pv.insert(pair<int,int> (prime,value) );

  cout << "map: " << endl;

  int last = -1;
  for (auto p : pv) {
    if (last!=p.first) {
      if (last!=-1) 
        cout << "] ";
      last = p.first;
      cout << " " << p.first << " -> [" << p.second;
    }
    else      
      cout << "," << p.second;
  }
  if (last!=-1) 
    cout << "] ";
  cout << endl;
}  

// 4
void Divisors::inM()
{
  bool outside;
  do {
    cout << "M = ? ";
    cin >> M;
    const int reason = 500000;
    if ((outside = ((M < 0) or (M > reason)))) {
      if (M < 0)
         cout << "M must be >= 0!" << endl;
      else
         cout << "Oh really?!" << endl;  // be reasonable!
    }
  } while (outside);
}

void Divisors::inN()
{
  bool outside;
  do {
    cout << "N = ? ";
    cin >> N;
    if  ((outside = (N < 0 or N > M+1)))
      cout << "N must be between 0 and " << M+1 << "!" << endl;
  } while (outside);
}


/*
Exercise 12B:
B. Divisors Finder
Requirements:
1. Generate N random values (int numbers from 0 to M)
2. Generate all prime numbers from 0 to M
3. Create a map Prime-> Values , where Prime is a divisor of Value. (eg . 3 -> [6,9]  where 6,9 are generated random numbers )
4. Input data: N, M (from cin )

Use as much STL as possible :smiley:
*/



