#include <stdio.h>
/*
 * Expected values in certain outcomes
 */

#define KK_EXP 3.50f
#define KB_EXP 3.50f
#define BB_EXP 1.00f

double solve(int n, int k) {
  double P_bb = ((n-k) * (n-k-1))
    / ((double) n * (n-1));
  double P_kk = (k * (k-1))
    / ((double)n * (n-1));
  double P_kb = 1.0 - P_bb - P_kk;
  return (P_kk * KK_EXP
	  + P_kb * KB_EXP
	  + P_bb * BB_EXP);
}

int main(void) {
  int n, k;
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d %d", &n, &k);
  #pragma GCC diagnostic pop
  double solution = solve(n, k);
  printf("%f", solution);
  return 0;
}
