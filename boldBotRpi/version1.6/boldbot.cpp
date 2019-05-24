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
#include "/home/stud/projekt3/pixy2/src/host/libpixyusb2/include/libpixyusb2.h"
using namespace std;
static bool run_flag = true;
#define searchBall_ 0b00000001  //1
#define forwards    0b00000010  //2
#define backwards   0b00000011  //3
#define stop_       0b00000100  //4
#define turn_right  0b00000101  //5
#define turn_left   0b00000110  //6
#define stop_f      0b00000111  //7
#define pickup_down 0b00001000  //8
#define pickup_up   0b00001001  //9
#define pickup_stop 0b00001010  //10
int count = 0;

Pixy2 pixy;

//Funktion til at sende signal
void sendSPI(int sendbyte){
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
int receiveSPI(void) {
  int fd = open("/dev/spi_drv0", O_RDWR);

  char ubuf[8];

  read(fd,ubuf,strlen(ubuf));

  int return_val = 0;

  sscanf(ubuf,"%i", return_val);

  close(fd);

  return return_val;
}

// håndtere afslutning af program via ctrl_c
int boldbot::handle_ctr_c(){
  run_flag = false;
  return 0;
}
//
void boldbot::get_blocks(int sig){
  pixy.ccc.getBlocks(false, sig);

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

      if (hojde<80 && bredde<80 && x > 116 && x < 184) {

          cout << "x koordinat" << x << "brede: " << bredde << "hojde: " << hojde << endl;
          sendSPI(forwards);
          printf("Bolden er for langt væk kør tættere på\n");
          usleep(900000);

          count = 0;

      }
      if (hojde<125 && bredde< 135 && x>120 && x < 180) {
        usleep(300000);
        cout << "x koordinat" << x << "brede: " << bredde << "hojde: " << hojde << endl;
        sendSPI(forwards);
        printf("Bolden er for langt væk kør tættere på\n");
        usleep(400000);
        sendSPI(stop_);
        count = 0;
        usleep(300000);
      }

      if (hojde>200 && bredde>200) {
        sendSPI(backwards);
        usleep(300000);
      }

      if (x > 185) {
        sendSPI(turn_left);
        cout << "x koordinat" << x << "brede: " << bredde << "hojde: " << hojde << endl;


        printf("X er større end Y, kør mod ventre!\n");
        usleep(300000);
        sendSPI(stop_);
        usleep(300000);
        count = 0;
        return;
      }

      if (x < 115) {
        sendSPI(turn_right);
        cout << "x koordinat" << x << "brede: " << bredde << "hojde: " << hojde << endl;

        usleep(300000);
        sendSPI(stop_);
        usleep(300000);
        printf("Y er større end X, kør mod højre!\n");

        count = 0;
        return;
      }

      // Opsamler mekanisme -- Skal kalibreres
      atom
      if (x > 120 && x <180 && hojde>125 && bredde>135){
        // stop motorer der driver boldbot frem
        // start motor der styre opsamler modul
        cout << "x koordinat" << x << "brede: " << bredde << "hojde: " << hojde << endl;
        printf("Samler bold op\n");
        sendSPI(stop_);
        usleep(300000);
        sendSPI(pickup_stop);
        usleep(500000);
        sendSPI(pickup_down);
        usleep(800000);
        sendSPI(pickup_stop);
        usleep(300000);
        sendSPI(pickup_down);
        usleep(800000);
        sendSPI(pickup_stop);
        usleep(2000000);
        sendSPI(pickup_up);
        usleep(600000);
        sendSPI(pickup_stop);
        usleep(300000);
        sendSPI(backwards);
        usleep(2000000);
        count = 0;
      }
    }



  }

  // ude af if sætning
  usleep(1000000);
  if (!pixy.ccc.numBlocks && count <= 15)
  {
    if (count==0) {
      sendSPI(backwards);
      usleep(300000);
      sendSPI(stop_);
      usleep(300000);
    }
      sendSPI(turn_left);
      usleep(300000);
      sendSPI(stop_);
      usleep(300000);
      printf("Search ball, count er %d\n", count);

      count++;
      return;

  }

  if (count >= 15 && !pixy.ccc.numBlocks)
  {
    sendSPI(forwards);
    usleep(12000000);
    sendSPI(stop_);
    usleep(300000);
    count = 0;
    printf("Kør frem i searchmode\n");
    return;
  }

}

void boldbot::start(){
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
    pixy.setLamp(0,0);
    pixy.version->print();
  }

    // Set Pixy2 to color connected components program //
    pixy.changeProg("color_connected_components");
}

void boldbot::init_sonar(){
  //opretter objekter til GPIO læsning
  fd = open ("/dev/gpio17", O_RDONLY);
  if (fd == -1) {
    printf("failed to open gpio port with err: %s\n", strerror(errno));
    return -1;
  }
}

void boldbot::read_sonar(){

  num_read = read(fd, buffer, 1);
  if (num_read == -1) {
    printf("failed to read gpio port with err: %s\n", strerror(errno));
    return;
  }

  if (buffer[0]=='1') {
      usleep(300000);
      sendSPI(backwards);
      usleep(2000000);
      sendSPI(stop_);
      printf("buffer er: %c\n", buffer[0]);
      printf("Bakker væk \n");
      usleep(300000);
    }

    //return buffer[0];
}
//Main
int main(){
  boldbot bot;
  //bot.init_sonar();
  bot.start();
  while(1)
  {
    bot.get_blocks(1);
    //bot.read_sonar();

    if (run_flag == false)
    {
      break;
    }
  }
  printf ("Program slutter\n");
  return 0;
}
