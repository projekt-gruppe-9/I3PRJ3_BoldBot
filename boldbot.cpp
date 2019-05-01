#include "boldbot.h"
#include "SPIFunc.hpp"
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <errno.h>
#include "/home/stud/projekt3_rpi/projekt3/src/host/libpixyusb2/include/libpixyusb2.h"
using namespace std;
static bool run_flag = true;
#define searchBall  1
#define forwards    2
#define backwards   3
#define stop_       4
#define turn_right  5
#define turn_left   6
#define full_stop   7
#define pickup_     8
int count = 0;

Pixy2 pixy;

//Funktion til at sende signal
void sendSPI(int sendbyte)
{
  int fd = open("/dev/spi_drv0", O_RDWR);
  char ubuf[8];

  int len = snprintf(ubuf, sizeof(ubuf), "%u\n", sendbyte);
  if(len < 0)
  {
    printf("Error in receiving");
  }

  write(fd,ubuf,strlen(ubuf));

  close(fd);
}
//Fuktion til at modtage signal
int receiveSPI(void)
{
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];

  read(fd,ubuf,strlen(ubuf));

  int return_val = 0;

  sscanf(ubuf,"%i", return_val);

  close(fd);

  return return_val;
}

// håndtere afslutning af program via ctrl_c
int boldbot::handle_ctr_c()
{
  run_flag = false;
  return 0;
}

void boldbot::get_blocks()
{
  pixy.ccc.getBlocks();

  // De blocks vi skal bruge ligger i numBlocks, som er størrelsen af blokken
  // blocks indeholder den data vi skal bruge
  if (pixy.ccc.numBlocks)
  {
    /* Løber igennem block index for at få fat i alle de bloks vi skal bruge.
       Der vil aldrig være flere blocks end størrelsen af blokken, derfor tjekkes der på
       pixy.ccc.numBlocks, da det er størrelsen af blokken.
    */
    for (Block_Index = 0; Block_Index < pixy.ccc.numBlocks; ++Block_Index)
    {
      /* Henter de nødvændige værdier som vi skal bruge til at styre bilen
         henholdsvis x, y, højde og bredde værdierne.
      */
      x = pixy.ccc.blocks->m_x;
      y = pixy.ccc.blocks->m_y;
      hojde = pixy.ccc.blocks->m_height;
      bredde = pixy.ccc.blocks->m_width;

      if (hojde<80 && bredde<80 && x > 140 && x < 215) {
            sendSPI(forwards);
            printf("Bolden er for langt væk kør tættere på\n");
            usleep(100000);
            count = 0;
      };

      if (x > 250) {
        sendSPI(turn_left);
        usleep(200000);
        sendSPI(stop_);
        printf("X er større end Y, kør mod vestre!\n");
        usleep(100000);
        count = 0;
        return;
      }

      if (x < 70) {
        sendSPI(turn_right);
        usleep(200000);
        sendSPI(stop_);
        printf("Y er større end X, kør mod højre!\n");
        usleep(100000);
        count = 0;
        return;
      }

      // Opsamler mekanisme -- Skal kalibreres
      if (x > 140 && x <215 && hojde>60 && bredde>60) {
        // stop motorer der driver boldbot frem
        // start motor der styre opsamler modul
        printf("Samler bold op\n");
        sendSPI(stop_);
        usleep(100000);
        sendSPI(pickup_);
        usleep(4000000);

        count = 0;
      }
    }
  }

  // ude af if sætning
  usleep(1000000);
  if (!pixy.ccc.numBlocks && count <= 15)
  {
      sendSPI(searchBall);
      usleep(500000);
      sendSPI(stop_);
      printf("Search ball, count er %d\n", count);
      usleep(100000);
      count++;
      return;
  }

  if (count >= 15 && !pixy.ccc.numBlocks)
  {
    sendSPI(forwards);
    usleep(5000000);
    sendSPI(stop_);
    count = 0;
    printf("Kør frem i searchmode\n");
    return;
  }
}

void boldbot::start()
{
  boldbot bot;

  printf ("=============================================================\n");
  printf ("= BoldBot Start!                                   =\n");
  printf ("=============================================================\n");

  printf ("Connecting to Pixy2...");

  // Initialize Pixy2 Connection //
  {
    Result = pixy.init();

    if (Result < 0)
    {
      printf ("Error\n");
      printf ("pixy.init() returned %d\n", Result);
      return Result;
    }

    printf ("Success\n");
  }

  // Get Pixy2 Version information //
  {
    Result = pixy.getVersion();

    if (Result < 0)
    {
      printf ("pixy.getVersion() returned %d\n", Result);
      return Result;
    }
    pixy.setLamp(1,0);
    pixy.version->print();
  }

    // Set Pixy2 to color connected components program //
    pixy.changeProg("color_connected_components");
}

void boldbot::init_sonar()
{
  //opretter objekter til GPIO læsning
  int fd; // sonarinput
  int numread;
  fd = open ("/dev/myDev17", O_RDONLY);
  if (fd == -1) {
    printf("failed to open gpio port with err: %s\n", strerror(errno));

    return -1;
  }
}

int boldbot::read_sonar()
{
  num_read = read(fd, buffer, 1);
  if (num_read == -1) {
    printf("failed to read gpio port with err: %s\n", strerror(errno));
  }
  if (buffer==49) {
    sendSPI(backwards);
    usleep(500000);
    return;
  }
}

int main(){
  boldbot bot;
  bot.init_sonar();
  bot.start();

  while(1)
  {
    bot.get_blocks();
    bot.read_sonar();
    if (run_flag == false)
    {
      break;
    }
  }
printf ("Program slutter\n");
  return 0;
}
