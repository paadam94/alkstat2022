#include <stdio.h>
#include <assert.h>

#define MAX_DICE 55
#define NUMBER_OF_SIDES 6
#define BUF_SZ NUMBER_OF_SIDES * MAX_DICE - (MAX_DICE-1)

void calc_next(double *next_buf, double *prev_buf, size_t buf_sz) {
  for(size_t i = 0;
      i < NUMBER_OF_SIDES || prev_buf[i-NUMBER_OF_SIDES + 1] != -1;
      ++i) {
    next_buf[i] = 0;
    for(int j = 0;
	j <= i && j < NUMBER_OF_SIDES;
	++j) {
      double curr = prev_buf[i - j];
      if(curr > 0) {
	next_buf[i] += curr;
      }
    }
  }
}

int main(void) {
  int ndice;
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d", &ndice);
  #pragma GCC diagnostic pop
  assert(ndice > 0 && ndice < MAX_DICE);

  double bbuf[BUF_SZ];
  double fbuf[BUF_SZ];
  // zeroing out
  for(size_t i = 0; i < BUF_SZ; ++i) {
    bbuf[i] = -1;
    fbuf[i] = -1;
  }

  // first row
  for(size_t i = 0; i < NUMBER_OF_SIDES; ++i) {
    bbuf[i] = 1;
  }

  double *res = bbuf;
  for(size_t i = 1; i <= ndice; ++i) {
    // alternating buffers
    if (i % 2 == 0) {
      calc_next(bbuf, fbuf, BUF_SZ);
      res = fbuf;
    } else {
      calc_next(fbuf, bbuf, BUF_SZ);
      res = bbuf;
    }
  }

  double sum = 0;
  for(size_t i = 0; res[i] != -1; ++i) {
    sum += res[i];
  }

  for(size_t i = 0; res[i] != -1; ++i) {
    printf("%f\n", res[i] / sum);
  }
  return 0;
}
