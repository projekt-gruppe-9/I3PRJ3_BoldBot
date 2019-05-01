#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "/home/stud/projekt3/src/host/libpixyusb2/include/libpixyusb2.h"
using namespace std;

class boldbot
{

public:
  int handle_ctr_c();
  void get_blocks();
  void start();
  int read_sonar();
  void init_sonar();

private:
  int Block_Index;
  int x;
  int y;
  int hojde;
  int bredde;
  int Result;
  int fd;
  uint8_t buffer[1];
  int num_read;

};
