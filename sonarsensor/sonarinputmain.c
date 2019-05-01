#include <errno.h>      //System error numbers
#include <stdio.h>       //standard c library
#include <fcntl.h>      //file control options
#include <unistd.h>     //For at anvende write(), close(), open()
#include <string.h>     //char
#include <sys/stat.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <stdlib.h>

#define MAX_READ 1
int main(int argc, char *argv[])
{
  int fd; //for sonarinput
  int status; //resultater for sonarinputs af funktionen oictl
  int num_red; //resultater for read() funktion
  int buffer[MAX_READ]; //den buffer vi læser sonarinput fra gpio17
 // u_int8_t buf[1];

  //read+write, se evt. slide 11 uge 6
  fd = open("/dev/gpio17", O_RDONLY); // O_RDONLY åbner filen for læsning kun. 12c-1 findes ved at skrive i2cdetect -l

  //status = ioctl(fd, 0x0703, 0x48); // i2cdev sys call (0x0703) til at sætte i2c address. 0x48 findes ved at skrive i2cdetect (busnummer) hvilket er 1

  if (fd == -1)
  {
    printf("failed to open with err: %s\n", strerror(errno));

    return -1; //return -1 on any error
  }

  while (1)
  {
    num_red = read(fd, buffer, MAX_READ);

        if (num_red == -1)
        {
            printf("Failed to read with err: %s\n", strerror(errno));
        }

    printf("Det logiske niveau er: %c \n", buffer[0]);

    sleep(1);
  }

  close(fd);

  return status;
}
