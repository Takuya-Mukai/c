//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//  C言語用プログラム
//  単振動: Euler法を用いたシミュレーション
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <stdio.h>
#include <math.h>

int main( void )
{

  double x, v, xb, vb; 
  double dt, t; 
  double Xe, Ve;
  double E; 
  int i,N;
 
// N：繰り返し回数 
  N = 10000;

// 刻み幅 
  dt = 1.0e-2;

// 初期値 
  i = 0;
  t = 0.0e0;
  x = 1.0e0;
  v = 0.0e0;
  
  xb = 1.0e0;
  vb = 0.0e0;
  
  Xe = sin(t);
  Ve = cos(t);
  E = 0.5*(v*v + x*x);

  printf("%d %e %e %e %e %e %e \n",i, t, x, v, Xe, Ve, E );
  printf("hello");
  for(i=0;i<=N;i++){
    t = dt * i;
    x = xb + dt * vb;
    v = vb - dt * xb; 
//  v = vb - dt * x;

    xb = x;
    vb = v;
    printf("%d %e %e %e %e %e %e \n",i, t, x, v, Xe, Ve, E );
  }
   
 
  return 0;
}
  
