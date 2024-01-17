
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  double x, y, z;
  double a = 1, b = 2, c = 3;
  double v;
  double V = 4 * M_PI * a * b * c / 3;
  int try_count = 100;
  double V_DIFF[try_count];
  double V_RECTANGULAR = 8 * a * b * c;
  double V_AVE; // average of V_DIFF
  double V_VAR;

  srand(time(NULL));

  int N = 100;
  for (int k = 0; k < try_count; k++) {
    int sum = 0;
    V_AVE = 0;
    for (int i = 0; i < N; i++) {
      // make random number for each range
      x = ((double)(rand()) / RAND_MAX);
      y = ((double)(rand()) / RAND_MAX) * 2;
      z = ((double)(rand()) / RAND_MAX) * 3;

      // if dot is inside the ellipsoid, sum++
      v = x * x / a / a + y * y / b / b + z * z / c / c;
      if (v <= 1) {
        sum++;
      }
    }
    V_DIFF[k] = ((double)sum / N) * V_RECTANGULAR;
  }

  // calculate average and variance
  for (int j = 0; j < try_count; j++) {
    V_AVE += V_DIFF[j] / try_count;
  }

  for (int j = 0; j < try_count; j++) {
    V_VAR += pow(V_DIFF[j] - V_AVE, 2) / try_count;
  }

  // make histogram
  double V_STD = sqrt(V_VAR);
  double dx = V_STD / 5;
  double V_MAX = 0;
  double V_MIN = 100;
  for (int i = 0; i < try_count; i++) {
    if (V_DIFF[i] > V_MAX) {
      V_MAX = V_DIFF[i];
    }
    if (V_DIFF[i] < V_MIN) {
      V_MIN = V_DIFF[i];
    }
  }
  int N4HIST = (V_MAX - V_MIN) / dx + 1;
  double V_HIST[N4HIST];
  for (int i = 0; i < N4HIST; i++) {
    V_HIST[i] = 0;
  }

  for (double x = V_MIN; x < V_MAX; x += dx) {
    int flag = 0;
    for (int j = 0; j < try_count; j++) {
      if (x <= V_DIFF[j] && V_DIFF[j] < x + dx) {
        flag++;
      }
    }
    V_HIST[(int)((x - V_MIN) / dx)] = flag;
  }
  for (int i = 0; i < N4HIST; i++) {
    printf("%d, %f\n", i, V_HIST[i]);
  }
  return 0;
}
