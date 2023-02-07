#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "../src/alkstatlib.h"

#define NUMBER_OF_SUBSETS(x) pow(2, x)

int main(void) {
  int n;
  int m;
  long test = factorial(13);
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d %d", &n, &m);
  #pragma GCC diagnostic pop
  assert(n <= 20);
  printf("%lf", (double)combination(n, m) / NUMBER_OF_SUBSETS(n));
  return 0;
}
