#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int receiveSPI();
void sendSPI(int);

int main(){

  while(true){
    sendSPI(12);
  }

  return 0;
}

void sendSPI(int sendbyte){
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];

  sscanf(ubuf,"%i", &sendbyte);

  write(fd,ubuf,strlen(ubuf));

  close(fd);
}

int receiveSPI(void){
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];

  read(fd,ubuf,strlen(ubuf));

  int return_val = 0;
  int len = snprintf(ubuf, 8, "%d\n", return_val);
  if(len < 0){
    printf("Error in receiving");
  }

  close(fd);

  return return_val;
}
