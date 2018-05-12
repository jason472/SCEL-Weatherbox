/*routine.cpp*/

/*Libraries*/

#include "routine.h"
//#include "transmit.h"

void routine(int *count)
{
  /*Variable Initialization*/
  long wait_ms=1000;
  unsigned long transmit_timer = millis();

  /*Poll sensors and construct packet*/
  make_packet(*count);

  /*Increment the poll count */
  (*count)++;

  /*Transmit after 3 polls*/
  if((*count)>=5)
  {
    send_packet();
    clear_packet();
    (*count)=0;
    
  }
  while((millis() - transmit_timer) <= wait_ms);
}

