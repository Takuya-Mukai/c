#include <math.h>
#include <stdio.h>

void fermi(double *p, double *q, double dt, int N);

int main(void) {
  int N = 32;
  double p[N];
  double q[N];
  double dt = 0.1;
  for (int i = 0; i < N; i++) {
    q[i] = sin(M_PI * i / 31);
  };

  for (int j = 1; j <= 3000; j++) {

    fermi(p, q, 0.1, N);

    // print p, q
    // printf("%e, ", dt*j);
    for (int i = 0; i < N; i++) {
      if (i == N - 1) {
        printf("%e\n", p[i]);
      } else {
        printf("%e, ", p[i]);
      };
    };
    // printf("%e, ", dt*j);
    for (int i = 0; i < N; i++) {
      if (i == N - 1) {
        printf("%e\n", q[i]);
      } else {
        printf("%e, ", q[i]);
      };
    };
  };

  return 0;
}

void fermi(double *p, double *q, double dt, int N) {
  double a = 0.25;
  double p_new[N], q_new[N];
  for (int j = 1; j <= N-2; j++) {
    p_new[j] = p[j] -
           dt * (( -q[j + 1] - q[j - 1] + 2.0 * q[j]) +
                 a * (pow((q[j + 1] - q[j]), 2) - pow((q[j] - q[j - 1]), 2)));
    q_new[j] = q[j] + dt * p_new[j];
  };

  for (int j = 1; j <= N-2; j++) {
  p[j] = p_new[j];
  q[j] = q_new[j];
  };

};

