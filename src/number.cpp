#include <iostream>
#include <algorithm>
#include "libalkstat.hpp"

using namespace std;

double solve(vector<vector<int>> vecvec) {
  // decartes products
  size_t x_pos = 1;
  size_t x_neg = 1;
  size_t x_sz = 1;
  for(auto vec: vecvec) {
    size_t acc_pos = 0;
    size_t acc_neg = 0;
    for_each(vec.begin(), vec.end(),
	     [&] (int e){
	       if (e > 0) acc_pos++;
	       if (e < 0) acc_neg++;
	     });
    x_pos *= acc_pos;
    x_neg *= acc_neg;
    x_sz *= vec.size();
  }
  return (double)(x_pos + x_neg) / x_sz;
}

int main(void) {
  vector<vector<int>> vec;
  stdin_to_2dvec(vec);
  vec.erase(vec.begin());
  cout << solve(vec);
  
  return 0;
}
