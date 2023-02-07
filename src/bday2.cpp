#include <stdio.h>

int solve(double P) {
  int M = 0;
  for(double comp_P = 1.0;
      ((1 - comp_P) <= P) && (M < 365);
      ++M) {
    comp_P *= (365 - M) / 365.0L;
  }

  return M;
}

int main(void) {
  double P;
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%lf", &P);
  #pragma GCC diagnostic pop
  int M = solve(P);
  printf("%d\n", M);
  return 0;
}
