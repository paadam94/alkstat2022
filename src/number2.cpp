#include <iostream>
#include <cmath>
#include "libalkstat.hpp"

using namespace std;

void multiply_through_helper(double *result,
			     double arr[][2], size_t arr_sz,
			     size_t row, double sofar) {
  if(row == arr_sz){
    if(sofar > 0) *result += sofar;
  } else {
    multiply_through_helper(result, arr, arr_sz, row+1, sofar * arr[row][0]);
    multiply_through_helper(result, arr, arr_sz, row+1, sofar * arr[row][1]);
  }
}

double multiply_through(double arr[][2], size_t rows) {
  double result = 0;
  multiply_through_helper(&result, arr, rows, 0, 1);
  return result;
}

double solve(vector<vector<int>> input) {
  size_t rows = input.size();
  // matrix of probabilities picking negative or positive
  // neg_n is negatively signed
  auto pick_probs = new double[rows][2];
  for(size_t i = 0; i < rows; ++i) {
    int neg_n = 0;
    int pos_n = 0;
    for(auto e: input[i]) {
      if ( e < 0 ) neg_n++;
      if ( e > 0 ) pos_n++;
    }
    pick_probs[i][0] = (double)(-neg_n) / input[i].size();
    pick_probs[i][1] = (double)pos_n / input[i].size();
  }
  return multiply_through(pick_probs, rows);
}

int main(void) {
  vector<vector<int>> vec;
  stdin_to_2dvec(vec);
  // drop first two rows
  vec.erase(vec.begin());
  vec.erase(vec.begin());
  cout << solve(vec);
  return 0;
}
