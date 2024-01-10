#include<stdio.h>
#include<math.h>

int main(void){

  int i, n, M=100, Nend=100000/M;
  double En;

  for(i=1;i<=Nend;i++){
 
   n  = i*M;
   En = pow(1.+ 1./n,n);

   printf("%d %e %e \n", n, En, exp(1.));

   //printf("%d %e %e \n",n,pow(1.+ 1./n,n),exp(1.));
  }

  return 0;
}
