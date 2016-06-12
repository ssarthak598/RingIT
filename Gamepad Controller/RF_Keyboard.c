#include <VirtualWire.h>

void setup()
{
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(12);
    vw_setup(2000);  // Bits per sec
Serial.begin(9600);
    vw_rx_start();  
      Keyboard.begin();
     
    
}
    void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      int a = buf[0];
      int b=map(a,48,49,0,1);
   if(b==3)
   {
    Keyboard.write(0xD7); 
   }
      
}
}
