#include <iostream>
#include <vector>
#include "../src/libalkstat.hpp"

using namespace std;

int main(void) {
  vector test{ 1, 2, 3, 4, 5, 6 };
  vector<vector<int>> output = combine(test, 3);
  for(auto vec: output) {
    for(auto i: vec) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
