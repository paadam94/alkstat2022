#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
  // FINAL
  int n, M;
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d %d", &n, &M);
  #pragma GCC diagnostic pop
  double P = 0.0f;
  if(M < 7) {
    double under_M = pow(M/6.0, n);
    double under_Mminus1 = pow((M-1)/6.0, n);
    P = under_M - under_Mminus1;
  }
  printf("%f\n", P);
  return 0;
}
