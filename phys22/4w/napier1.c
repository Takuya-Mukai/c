#include <math.h>
#include <stdio.h>
int main (int argc, char *argv[]) {
  
  int N;
  double En = 1.0, i;

  printf("N = ");
  scanf("%d",&N);
  for (i = 1; i <= N; i++) {
    En = pow(1 + 1./i, i);
    printf("%lf %lf\n", i, En);
  }
  return 0; 
}
