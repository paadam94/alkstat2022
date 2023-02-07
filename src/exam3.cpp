#include <stdio.h>
#include <assert.h>

double get_p(int n, int k) {
  return 1 - ((double)(n - k) * (n - k - 1) / (n * (n - 1)));
}

double solve(int n, double p) {
  int k = 0;
  assert(n <= 30);
  while(get_p(n, k) < p) {
    k++;
  }
  return k;
}

int main(void) {
  int n;
  double p;
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d %lf", &n, &p);
  #pragma GCC diagnostic pop
  int solution = solve(n, p);
  if (!solution && p > 0 && n > 0) solution = 1;
  printf("%d", solution);
  
  return 0;
}
