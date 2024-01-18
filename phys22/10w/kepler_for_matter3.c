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
double newton(double theta, double e, double t);

double define_h(void) {
  double theta = 0, e = 1. / 2, t = 0, h;
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

int main(void) {
  double t = 1./4, theta0 = 1./2;
  double e = 1./2;
  double theta = newton(theta0, e, t);
  define_h();
  printf("theta = %e\n", theta);
  return 0;
}
