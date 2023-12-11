#include <TI_SN76489.h>

TI_SN76489 sn(2, 3, 4, 5, 6, 7, 8, 10, 13, 9, _1MHz);

void setup()
{
  Serial.begin(115200);
  sn.begin();
  sn.attenuation(0, 0);
  sn.frequency(0, 200);
}

void loop()
{ 
  while (Serial.available() > 0) {
    int red = Serial.parseInt(); 
    
    if (Serial.read() == '\n') 
      sn.frequency(0, red);
      
  }  
}
