#include <iostream>
#include <iomanip>

double tests[] = {
  10, 0.57,  3, 4,
  12, 0.59,  4, 5,
  13, 0.82,  7, 8,
  14, 0.51,  4, 5,
  14, 0.78,  7, 8,
  14, 0.84,  8, 9,
  16, 0.64,  6, 7,
  17, 0.75,  8, 9,
  20, 0.54,  6, 7,
  21, 0.37,  4, 5,
  21, 0.69,  9, 10,
  22, 0.49,  6, 7,
  25, 0.24,  3, 4, //
  26, 0.3,   4, 5,
  29, 0.15,  2, 3,
  29, 0.89, 19, 20,
  30, 0.33,  5, 6,
};

double get_p(int n, int k) {
  return 1 - ((double)(n - k) * (n - k - 1) / (n * (n-1)));
}

int main(void) {
  std::cout << std::fixed;
  std::cout << "LIMIT\t\tCACLED\t\tBUMPED" << std::endl;
  for(int i = 0; i < sizeof(tests)/sizeof(tests[0]); i += 4) {
    std::cout << tests[i+1] << "\t"
	      << get_p(tests[i], tests[i+2]) << "\t"
	      << get_p(tests[i], tests[i+3]) << std::endl;
  }

  return 0;
}
