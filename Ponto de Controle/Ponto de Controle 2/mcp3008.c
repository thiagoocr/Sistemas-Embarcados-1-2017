#include <wiringPi.h>
#include <mcp3004.h>
#include <stdio.h>
#include <unistd.h>

int main(){

  wiringPiSetup() ;
    mcp3004Setup(100, 0);

      while(1){
         usleep(500);
          printf("%d\n",analogRead(100+1));
            
              }

              }
