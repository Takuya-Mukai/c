
// kepler problem with newton method
#include <math.h>
#include <stdio.h>

double f(double theta, double e, double t) {
  return theta - e * sin(theta) - t;
}

double df(double theta, double e) { return 1.0 - e * cos(theta); }

double Df(double theta, double e, double t, double h) {
  return (f(theta + h, e, t) - f(theta, e, t)) / h;
}

double calculate_x(double theta, double e) { return cos(theta) - e; }
double calculate_y(double theta, double e) {
  return sqrt(1 - e * e) * sin(theta);
}

double define_h(void);
double newton(double theta, double e, double t);



int main(void) {
  double t = 0, theta0 = 1. / 2;
  double e = 0.5, dt = 0.01;

  // calculate the time when theta0 = 2*pi
  for (int i = 0; theta0 < 2 * M_PI; i++) {
    t = i * dt;
    double theta0 = newton(theta0, e, t);
  }
  double T = t;

  // calculate the position of the planet
  theta0 = 1. / 2;
  t = 0;
  dt = 0.05;
  int N = T / dt + 1;
  for (int i = 0; i <= N; i++) {
    t = i * dt;
    double theta0 = newton(theta0, e, t);
    printf("%d, %e, %e, %e, %e\n", i, t, theta0, calculate_x(theta0, e),
           calculate_y(theta0, e));
  }
  return 0;
}

double define_h(void) {
  double theta = 1. / 2, e = 1. / 2, t = 10, h;
  double h0 = 1;
  double diff0 = 1.0;
  for (int i = 0; i <= 16; i++) {
    // define order of h
    h = pow(10, -i);

    for (int j = 9; j >= 1; j--) {
      h += j * pow(10, -i - 1);
      double df1 = df(theta, e);
      double Df1 = Df(theta, e, t, h);

      // compare the difference between df and Df
      double diff = fabs(df1 - Df1);

      // compare the difference between now and before
      if (diff <= diff0) {
        h0 = h;
        diff0 = diff;
      }
    }
  }
  printf("%e\n", h0);
  return h0;
}

double newton(double theta, double e, double t) {
  double h = define_h();
  double theta0 = theta;
  double theta1 = theta0 - f(theta0, e, t) / Df(theta0, e, t, h);

  // continue until the difference between theta1 and theta0 is less than 1e-10
  while (fabs(theta1 - theta0) > 1e-10) {
    theta0 = theta1;
    theta1 = theta0 - f(theta0, e, t) / Df(theta0, e, t, h);
  }
  return theta1;
}

