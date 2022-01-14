#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


#define LED_PORTA	0
#define LED_PORTB	1
#define LED_PORTC	2
#define LED_PORTD	3

#define LED_PIN0	0
#define LED_PIN1	1
#define LED_PIN2	2
#define LED_PIN3	3
#define LED_PIN4	4
#define LED_PIN5	5
#define LED_PIN6	6
#define LED_PIN7	7

void LED_init(uint8_t port , uint8_t Pin);
void LED_ON(uint8_t port , uint8_t Pin);
void LED_OFF(uint8_t port , uint8_t Pin);

#endif
