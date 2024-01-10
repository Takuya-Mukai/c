#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){

  int i,  uraomote, Sum=0, Nend=10000;

  srand((unsigned) time(NULL));


  for(i=1; i<=Nend; i++){

    uraomote  = 2*(rand()%2 ) -1; 
    Sum      = Sum + uraomote; 

    printf("%6d  %3d  %8d \n",i,uraomote, Sum); 

  }

  return 0;
}
