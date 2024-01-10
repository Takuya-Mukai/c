#include <stdio.h>
#include <math.h>

int main(void){
  double e = 0.5;
  double x = 1-e, y = 0, u = 0, v = sqrt((1+e)/(1-e)), dt = 0.01, t = 0, T = 0;
  int n = 644 + 1;
  // scanf("%d", &n);
  double E = 0.5*(u*u + v*v) - 1/sqrt(x*x + y*y);
  printf("%e, %e, %e, %e, %e, %e, \n", t, x, y, u, v, E);
  for(int i = 0; i <= n; i ++){
    t = dt*i;
    if (y+v*dt < 0 && T == 0){
      T = t*2;
      printf("T = %e\n", T);
    };
    x += u*dt; y += v*dt;
    double r = sqrt(x*x + y*y);
    double r3 = r*r*r;
    u -= x*dt/r3; v -= y*dt/r3;
    E = 0.5*(u*u + v*v) - 1/r;
    printf("%e, %e, %e, %e, %e, %e, \n",t, x, y, u, v, E);
  };
  printf("T = %e\n", T);
  return 0;
}

