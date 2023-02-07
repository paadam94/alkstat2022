#include <math.h>
#include <stdio.h>

// number of disjoint sets 3^n - https://math.stackexchange.com/a/1580058
// number of sets twice, since we pick twice 2 * 2^n
// -> (3/4) ^ n

int main(void) {
  int n;
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d", &n);
  #pragma GCC diagnostic pop
  printf("%lf", pow(0.75, n));
  return 0;
}
