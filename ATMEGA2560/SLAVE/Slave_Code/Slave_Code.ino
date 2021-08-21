#include <SPI.h>
unsigned int buff;
volatile byte indx;
volatile byte  OUTBUFF[5] = {11,45,67,33,22};
volatile int OUTINDX = 0; 
volatile boolean process;

void setup (void) {
   Serial.begin (115200);
   pinMode(MISO, OUTPUT);// have to send on master in so it set as output
  
   SPCR |= _BV(SPE); // turn on SPI in slave mode
  
   process = false;
   SPI.attachInterrupt(); // turn on interrupt
  
   SPDR = 5;
   OUTINDX =1;
   Serial.println(OUTBUFF[0]);
}
ISR (SPI_STC_vect) // SPI interrupt routine 
{ 
  Serial.println("ISR");
  Serial.println(OUTINDX);
   byte c = SPDR; // read byte from SPI Data Register
   buff = c;
   SPDR = OUTBUFF[OUTINDX];
   OUTINDX++;
   process = true;
 
}
void loop (void) {
   if (process) {
      process = false; //reset the process
      Serial.println("MAIN");
      Serial.println (buff);
     
   }
}
