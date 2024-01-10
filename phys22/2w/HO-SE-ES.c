//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//C言語用プログラム
// 単振動: symplectic Euler法を用いたシミュレーション
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <stdio.h>
#include <math.h>

int main( void )
{

  double x, v, xb, vb; 
  double dt, t; 
  double E; 
  int i,N;
 
// N：繰り返し回数
  N = 10000;

//  刻み幅 
  dt = 1.0e-2;

// 初期値 
  i = 0;
  t = 0.0e0;
  x = 1.0e0;
  v = 0.0e0;
  
  xb = 1.0e0;
  vb = 0.0e0;
  
   E = 0.5e0*(x*x +v*v);
   printf("%d %e %e %e %e %e %e \n",i, t, x, v, cos(t), -sin(t), E );

    
  for(i=0;i<=N;i++){
    t = dt * i;
    x = xb + dt * vb;
//  v = vb - dt * xb; 
    v = vb - dt * x;

    xb = x;
    vb = v;
    E = 0.5e0*(x*x +v*v);
    printf("%d %e %e %e %e %e %e \n",i, t, x, v, cos(t), -sin(t), E );
					
      }
   
 
  return 0;
}
  
