#include <stdio.h>

double solve(int n) {
  if( n % 2 == 1 ) return 0.0;

  long half_pascal[2][n];
  size_t read_buf = 0;
  size_t write_buf = 0;

  // preset
  half_pascal[0][0] = 1;
  half_pascal[1][0] = 1;
  for(size_t i = 1; i < n; ++i) {
    half_pascal[0][i] = 0;
    half_pascal[1][i] = 0;
  }

  for(int i = 1; i < n+1; ++i) {
    // swap buffers
    if(read_buf) {
      read_buf = 0;
      write_buf = 1;
    } else {
      read_buf = 1;
      write_buf = 0;
    }
    
    for(int j = 1; j < n; ++j) {
      half_pascal[write_buf][j] = half_pascal[read_buf][j-1] + half_pascal[read_buf][j];
    }
  }

  // for(int i = 0; i < n; ++i) {
  //   printf("%ld ", half_pascal[write_buf][i]);
  // }

  long k = half_pascal[write_buf][n/2];

  long nk = 0;
  for(size_t i = 0; i < n/2; ++i) {
    nk += half_pascal[write_buf][i];
  }
  nk *= 2;
  nk += k;
  
  return (double)k / nk;
}

int main(void) {
  int n;
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d", &n);
  #pragma GCC diagnostic pop
  printf("%lf", solve(n));
  return 0;
}
