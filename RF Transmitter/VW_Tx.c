#include <VirtualWire.h>
char *controller;
void setup() {
  pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(2000);// speed of data transfer Kbps
}


void loop(){
controller="1"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone

delay(1000);
controller="2"  ;
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); // Wait until the whole message is gone

delay(1000);

}
