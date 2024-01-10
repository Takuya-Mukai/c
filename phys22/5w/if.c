#include <stdio.h>

int main(void){
  int a;

  printf("Enter an integer you like: ");
  scanf("%d", &a );
  printf("The integer you engerd is %d. \n", a);

  if (a%2 != 0){
    printf("%d is odd number. \n", a);
  }
  else {
    printf("%d is even number. \n", a);
  }
}

