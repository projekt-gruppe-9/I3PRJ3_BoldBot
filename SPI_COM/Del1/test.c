#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int receiveSPI();
void sendSPI(int);

int main(){

  while(1){
    sendSPI(12);

    usleep(200);
/*
    int rec = receiveSPI();
    printf("Value received: %d",rec);*/
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

  read(fd,ubuf,strlen(ubuf));

  int return_val = 0;

  sscanf(ubuf,"%i", return_val);


  close(fd);

  return return_val;
}
