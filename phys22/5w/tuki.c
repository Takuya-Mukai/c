#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum, length=0, num0, n=10000, uraomote;
int main(void)
{
  srand((unsigned)time(NULL));
  for (int i = 1; i <= n; i++){

    uraomote = 2*(rand() % 2) - 1;
    sum += uraomote;

    if (sum == 0){
      num0++;
      printf("%5d, %d, \n", num0, length);
      length = 0;
    }
    if (sum > 0){
      length++;
    }
    if (sum < 0){
      length--;
    }
  }

  return 0;
}

