///
/// @file   count1.cpp
/// @brief  Count the primes up to 10^9.
///
/// Copyright (C) 2017 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the BSD License. See the COPYING
/// file in the top level directory.
///

#include <primesieve.hpp>

#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;
using namespace primesieve;

/// Correct pi(x) values to compare with test results
const uint64_t pix[9] =
{
  4,        // pi(10^1)
  25,       // pi(10^2)
  168,      // pi(10^3)
  1229,     // pi(10^4)
  9592,     // pi(10^5)
  78498,    // pi(10^6)
  664579,   // pi(10^7)
  5761455,  // pi(10^8)
  50847534  // pi(10^9)
};

void check(bool OK)
{
  cout << "   " << (OK ? "OK" : "ERROR") << "\n";
  if (!OK)
    exit(1);
}

int main()
{
  cout << left;
  ParallelPrimeSieve pps;
  pps.setStart(0);
  pps.setStop(0);
  uint64_t count = 0;

  // pi(x) with x = 10^i for i = 1 to 9
  for (int i = 1; i <= 9; i++)
  {
    count += pps.countPrimes(pps.getStop() + 1, (uint64_t) pow(10.0, i));
    cout << "pi(10^" << i << ") = " << setw(12) << count;
    check(count == pix[i - 1]);
  }

  cout << endl;
  cout << "All tests passed successfully!" << endl;

  return 0;
}
