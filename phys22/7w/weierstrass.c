#include <stdio.h>
#include <math.h>

double weierstrass(double ai[101], double bi[101], double x);

int main(void){
  double a = 0.5, b = 15, x = -2;
  double ai[101], bi[101];

  for (int i = 0; i <= 100; i++){
    ai[i] = pow(a, i);
    bi[i] = pow(b, i);
  };

  for (int i = 0; i <= 5000; i++){
    x += 0.0008 ;
    printf("%lf, %lf\n", x, weierstrass(ai, bi, x));
  };

  return 0;

};

double weierstrass(double ai[101], double bi[101], double x){
  double sum = 0;
  for (int i = 0; i <= 100; i++) {
    sum += ai[i] * cos(bi[i] * M_PI * x);
  };
  return sum;
};
