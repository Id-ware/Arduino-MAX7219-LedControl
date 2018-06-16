
#include "LedControl.h"

/*
  Now we need a LedControl to work with.
  on max7219's chip pin-1-[DIN] >> is connected to arduino digital pin 12
  on max7219's chip pin-13-[CLK] >> is connected to arduino digital pin 11
  on max7219's chip pin-12-[LOAD(CS)] >> is connected to arduino digital pin 10
  I'm using only a single MAX7219.
  
  NOTICE:
  If you not using a module, but a bare chip
  don't forget to jumper max7219's chip pin-19(V+) and pin-18(ISET)
  cause otherwise the driver won't work!
  datasheet requires to use 9.53K ohm resistor minimum
  but, since i'm using 1 inch digit and runnig it as common anode, 
  the max7219 resistens keep everything ok

  my wiring setup is like this:
  http://i0.wp.com/www.plingboot.com/wp-content/uploads/2017/01/reverse.jpg?resize=955%2C482
  (it might not be working or understendable, this is still WIP)
  source:
  http://www.plingboot.com/2017/01/max7219-and-common-anode-displays/
  (i used the wiring example, not the code, cause its not working)
  
*/
LedControl lc = LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 2000;

void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,15);
  /* and clear the display */
  lc.clearDisplay(0);
}

void clearingall() {
  lc.setRow(0,0,0B00000000);  // turns off -a- digits
  lc.setRow(0,1,0B00000000);  // turns off -b- digits 
  lc.setRow(0,2,0B00000000);  // turns off -c- digits
  lc.setRow(0,3,0B00000000);  // turns off -d- digits
  lc.setRow(0,4,0B00000000);  // turns off -e- digits
  lc.setRow(0,5,0B00000000);  // turns off -f- digits
  lc.setRow(0,6,0B00000000);  // turns off -g- digits
  lc.setRow(0,7,0B00000000);  // turns off -DP- digits
}

void write0() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
  lc.setRow(0,3,0B01110000);  // turns on -d- digits
  lc.setRow(0,4,0B01110000);  // turns on -e- digits
  lc.setRow(0,5,0B01110000);  // turns on -f- digits
//  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write1() {
//  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
//  lc.setRow(0,3,0B01110000);  // turns on -d- digits
//  lc.setRow(0,4,0B01110000);  // turns on -e- digits
//  lc.setRow(0,5,0B01110000);  // turns on -f- digits
//  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write2() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
//  lc.setRow(0,2,0B01110000);  // turns on -c- digits
  lc.setRow(0,3,0B01110000);  // turns on -d- digits
  lc.setRow(0,4,0B01110000);  // turns on -e- digits
//  lc.setRow(0,5,0B01110000);  // turns on -f- digits
  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write3() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
  lc.setRow(0,3,0B01110000);  // turns on -d- digits
//  lc.setRow(0,4,0B01110000);  // turns on -e- digits
//  lc.setRow(0,5,0B01110000);  // turns on -f- digits
  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write4() {
//  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
//  lc.setRow(0,3,0B01110000);  // turns on -d- digits
//  lc.setRow(0,4,0B01110000);  // turns on -e- digits
  lc.setRow(0,5,0B01110000);  // turns on -f- digits
  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write5() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
//  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
  lc.setRow(0,3,0B01110000);  // turns on -d- digits
//  lc.setRow(0,4,0B01110000);  // turns on -e- digits
  lc.setRow(0,5,0B01110000);  // turns on -f- digits
  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write6() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
//  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
  lc.setRow(0,3,0B01110000);  // turns on -d- digits
  lc.setRow(0,4,0B01110000);  // turns on -e- digits
  lc.setRow(0,5,0B01110000);  // turns on -f- digits
  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write7() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
//  lc.setRow(0,3,0B01110000);  // turns on -d- digits
//  lc.setRow(0,4,0B01110000);  // turns on -e- digits
//  lc.setRow(0,5,0B01110000);  // turns on -f- digits
//  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write8() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
  lc.setRow(0,3,0B01110000);  // turns on -d- digits
  lc.setRow(0,4,0B01110000);  // turns on -e- digits
  lc.setRow(0,5,0B01110000);  // turns on -f- digits
  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}
void write9() {
  lc.setRow(0,0,0B01110000);  // turns on -a- digits
  lc.setRow(0,1,0B01110000);  // turns on -b- digits 
  lc.setRow(0,2,0B01110000);  // turns on -c- digits
  lc.setRow(0,3,0B01110000);  // turns on -d- digits
//  lc.setRow(0,4,0B01110000);  // turns on -e- digits
  lc.setRow(0,5,0B01110000);  // turns on -f- digits
  lc.setRow(0,6,0B01110000);  // turns on -g- digits
//  lc.setRow(0,7,0B01110000);  // turns on -DP- digits
}

void loop() {
  clearingall();
  write0();
  delay(delaytime);
  clearingall();
  write1();
  delay(delaytime);
  clearingall();
  write2();
  delay(delaytime);
  clearingall();
  write3();
  delay(delaytime);
  clearingall();
  write4();
  delay(delaytime);
  clearingall();
  write5();
  delay(delaytime);
  clearingall();
  write6();
  delay(delaytime);
  clearingall();
  write7();
  delay(delaytime);
  clearingall();
  write8();
  delay(delaytime);
  clearingall();
  write9();
  delay(delaytime);
}
