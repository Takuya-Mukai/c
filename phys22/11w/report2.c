#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  double x, y, z;
  double a = 1, b = 2, c = 3;
  double v;
  double V = 4 * M_PI * a * b * c / 3;
  int try_count = 10000;
  double V_DIFF[try_count];
  double V_RECTANGULAR = 8 * a * b * c;
  double V_AVE;

  srand(time(NULL));

  for (int N = 1; N <= 100; N++) {
    for (int k = 0; k < try_count; k++) {
      int sum = 0;
      V_AVE = 0;
      for (int i = 0; i < N; i++) {
        // make random number for each range
        x = ((double)(rand()) / RAND_MAX);
        y = ((double)(rand()) / RAND_MAX)*2;
        z = ((double)(rand()) / RAND_MAX)*3;

        v = x*x/a/a + y*y/b/b + z*z/c/c;

        if (v <= 1) {
          sum++;
        }
      }
      V_DIFF[k] = ((double)sum / N) - (V/V_RECTANGULAR);
    }
    for (int j = 0; j < try_count; j ++) {
      V_AVE += V_DIFF[j]/try_count;
    }
    printf("%d, %f\n", N, fabs(V_AVE));
  }
  return 0;
}
