#include "libalkstat.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
void stdin_to_2dvec(vector<vector<T>> &vec) {
  string line;
  while (getline(cin, line)) {
    int number;
    istringstream iss(line);
    vec.push_back({});
    while( iss >> number ) {
      vec.back().push_back(number);
    }
  }
}

template void stdin_to_2dvec(vector<vector<int>> &vec);
template void stdin_to_2dvec(vector<vector<double>> &vec);

// https://stackoverflow.com/a/17996834
template <typename T>
void combine_helper(vector<vector<T>>&result, vector<T> curr, const vector<T> &pool, size_t i, size_t k) {
  if (k == 0) result.push_back(curr);
  else {
    for(int j = i; j < pool.size(); ++j) {
      vector<T> new_vec = curr;
      new_vec.push_back(pool[j]);
      combine_helper(result, new_vec, pool, j+1, k-1);
    }
  }
}

template <typename T>
vector<vector<T>> combine(vector<T> vec, size_t k) {
  vector<vector<T>> result;
  vector<T> curr;
  combine_helper(result, curr, vec, 0, k);
  return result;
}

template vector<vector<int>> combine(vector<int> vec, size_t k);
template vector<vector<size_t>> combine(vector<size_t> vec, size_t k);
