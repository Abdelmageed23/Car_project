/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 6 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "Interrupt_interface.h"
#include "Interrupt_private.h"
#include "Interrupt_config.h"

void GlobalInerruptEnable(void)
{
	SET_BIT(SREG,7);
}
