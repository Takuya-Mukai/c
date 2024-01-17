#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double f(double t) {
  return (2 * (1 + t * t)) / (pow((1 - t * t), 2) + t * t);
}


int main(void) {
  double x, y, sum = 0;
  int i, N;
  srand((unsigned)time(NULL));

  for (N = 100; N <= pow(10, 5); N = N * 10) {
    for (i = 0; i < N; i++) {
      x = (double)rand() / RAND_MAX;
      y = ((double)rand() / RAND_MAX) * (2+(4/sqrt(3)));
      double Y = f(x);
      if (y <= Y) {
        sum += 1;
      }
    }
    sum = sum * (2+(4/sqrt(3)))/ N;
    printf("When N=%d, sum=%f\n", N, sum);
    sum = 0;
  }
  return 0;
}


