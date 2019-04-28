#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//variabler
int searchBall =  1;
int forwards =    2;
int backwards =   3;
int stop_ =       4;
int turn_r =      5;
int turn_l =      6;
int stop_f  =     7;

//prototyper
int receiveSPI();
void sendSPI(int);

int main(){
  while(1){
    sendSPI(forwards);
    usleep(2000000);

    sendSPI(backwards);
    usleep(2000000);

    sendSPI(stop_);
    usleep(1000000);

    sendSPI(turn_r);
    usleep(1000000);
    sendSPI(turn_l);

  }

  return 0;
}

void sendSPI(int sendbyte){
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];

  int len = snprintf(ubuf, sizeof(ubuf), "%d\n", sendbyte);
  if(len < 0){
    printf("Error in receiving");
  }

  write(fd,ubuf,strlen(ubuf));

  close(fd);
}

int receiveSPI(void){
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];

  int result = read(fd,ubuf,strlen(ubuf));

  int return_val = 0;

  sscanf(ubuf,"%d", result);


  close(fd);

  return result;
}
