
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

void LED_init(uint8_t port , uint8_t Pin)
{
	DIO_SETpinDir(port,Pin,1);
}


void LED_ON(uint8_t port , uint8_t Pin)
{
	DIO_SETpinVal(port,Pin,1);
}



void LED_OFF(uint8_t port , uint8_t Pin)
{
	DIO_SETpinVal(port,Pin,0);
}
