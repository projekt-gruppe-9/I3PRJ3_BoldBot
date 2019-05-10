
#include SPIFunc.h

void sendSPI(int sendbyte){
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];

  int len = snprintf(ubuf, sizeof(ubuf), "%u\n", sendbyte);
  if(len < 0){
    printf("Error in receiving");
  }

  write(fd,ubuf,strlen(ubuf));

  close(fd);
}

int receiveSPI(void){
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];
FILE *fp;
fp = fopen ("filename.txt","w");
if (fp!=NULL)
{
  fprintf(fp,"Some String\n");
  fclose (fp);
}
  read(fd,ubuf,strlen(ubuf));

  int return_val = 0;

  sscanf(ubuf,"%i", return_val);


  close(fd);

  return return_val;
}
