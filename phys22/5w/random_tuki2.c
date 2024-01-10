#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

  int i,  uraomote, Sum=0, length=0, num0=1, Nend=10000;
  int kachimake;

  srand((unsigned) time(NULL));

  for(i=1;i<=Nend;i++){

    uraomote = 2*( rand()%2 ) -1; 
    Sum      = Sum + uraomote; 
    length   = length +1;

    if(Sum==0){
      printf("# %6d %8d \n",num0,length*kachimake); 
	num0      = num0 + 1;
    	length =0;  
    }
    else{
	  kachimake = Sum/abs(Sum); 
    }

    printf("%6d %2d %8d \n",i, uraomote, Sum); 

    if(i==Nend) printf("# %6d %8d \n",num0,length*kachimake); 
  }

  return 0;
}
