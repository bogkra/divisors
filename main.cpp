#include <iostream>
#include <set>
#include <cmath>
#include <map>

// (C) 2018 Boguslaw Krawczuk
// first fully working version, more STL and safer input needed


using namespace std;

int main()
{
  int M, N;

// 4  
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

  do {
    cout << "N = ? ";
    cin >> N;
    if  ((outside = (N < 0 or N > M+1)))
      cout << "N must be between 0 and " << M+1 << "!" << endl;
  } while (outside);

// 1
  set<int> values, primes;

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

// 2 : sieve of Erastotenes
  for (int i=2; i<=M; i++)
    primes.insert(i);
  for (int prime=2; prime<=sqrt(M); prime++)
    if (primes.find(prime) != primes.end())
      for (int j=2*prime; j<=M; j+=prime)
        primes.erase(j);

  cout << "primes: " << endl;
  for (int i : primes)
    cout << i << " ";
  cout << endl;

// 3
  multimap<int,int> pv;
  for (int value : values)
    for (int prime : primes)
      if (value % prime == 0)
        pv.insert(pair<int,int> (prime,value) );

  cout << "map: " << endl;
  for (auto p : pv)
    cout << p.first << ":" << p.second << " ";
  cout << endl;
    
    
  return 0;
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

