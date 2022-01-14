/**********************************************************************/
/**********************************************************************/
/*****************		Author: Eagles (Team2)*************************/
/*****************		SWC:	Build your own car	*******************/
/*****************		Version:1.00			***********************/
/**********************************************************************/
/**********************************************************************/

/*include some header files we need*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "Interrupt_interface.h"
#include "KEYPAD_interface.h"
#include "Motor.h"
#include "LED_interface.h"



#define SPEED_BUTTON	8 //A button to control speed, Farward or Reverse
#define	MOVE_BUTTON		2 //A button to move the car.
#define RIGHT_BUTTON	6 //Abutton to turn right
#define LEFT_BUTTON		4 //Abutton to turn right

#define PRESSED			1 //Pressed state
#define NOT_PRESSED		0 //Not Pressed state

#define NO_SPEED		0 //No Speed
#define Speed_30		30 //Speed 30% of the max speed
#define Speed_60		60 //Speed 60% of the max speed
#define Speed_90		90 //Speed 90% of the max speed

#define First_SPEED_LEVEL	1 //define the press that reach the first option
#define Second_SPEED_LEVEL	2 //define the press that reach the second option
#define Third_SPEED_LEVEL	3 //define the press that reach the Third option
#define REVERSE_SPEED_LEVEL		4 //define the press that reach the reverse option

/*Declaration of functions that control the motors*/
void MOVE_REV(void); //Move Reverse
void MOVE_FWD(void); //Move Forward
void MOVE_LEFT(void); //Turn left
void MOVE_RIGHT(void); //Turn right
void MOTORS_OFF(); //Stop the car
void LEDS_INIT(void); //Initalizing Leds

void main()
{
	GlobalInerruptEnable(); //Call a function that enable the global interrupt
	 KPD_init(); //call initialization of keypad
	 MOTOR_init(MOTOR_1); //call initialization of Motor1
	 MOTOR_init(MOTOR_2); //call initialization of Motor2
	
	/*Some local variables to control speed by buttons*/
	 uint8_t Speed_level =NO_SPEED;
	 uint8_t key=0;

	/*Initializing LEDs*/
	 LEDS_INIT();

	while(1)
	{
		/*Check if the speed button pressed or not*/
		if( SPEED_BUTTON == KPD_u8GetPressedKey())
		{
			Speed_level++; //increse the speed level options
			/*check of speed level options reach max ot not*/
			if(Speed_level >REVERSE_SPEED_LEVEL)
			{
				Speed_level =First_SPEED_LEVEL;//if yes, start from the first
			}
			switch (Speed_level)
			{
				/*check if the speed level options in the first option*/
			case  First_SPEED_LEVEL:
				LED_ON(LED_PORTB,4);
				LED_OFF(LED_PORTB,5);
				LED_OFF(LED_PORTB,6);
				LED_OFF(LED_PORTB,7);
			break;
			/*check if the speed level options in the second option*/
			case  Second_SPEED_LEVEL:
				LED_OFF(LED_PORTB,4);
				 LED_ON(LED_PORTB,5);
				LED_OFF(LED_PORTB,6);
				LED_OFF(LED_PORTB,7);
			break;
			/*check if the speed level options in the third option*/
			case Third_SPEED_LEVEL:
				LED_OFF(LED_PORTB,4);
				LED_OFF(LED_PORTB,5);
				 LED_ON(LED_PORTB,6);
				LED_OFF(LED_PORTB,7);
			break;
			/*check if the speed level options in the reverse option*/
			case  REVERSE_SPEED_LEVEL:
				LED_OFF(LED_PORTB,4);
				LED_OFF(LED_PORTB,5);
				LED_OFF(LED_PORTB,6);
				 LED_ON(LED_PORTB,7);
			break;
			}
			/*Pooling to control button long press and bouncing*/
			while(SPEED_BUTTON == KPD_u8GetPressedKey())
			{

			}
		}
		
		while(MOVE_BUTTON == KPD_u8GetPressedKey() )
		{
			/*check if the speed level options in the first option*/
			if(Speed_level ==First_SPEED_LEVEL)
			{
				MOTOR_speed(Speed_30);//Set motor speed by 30% of the max speed
				MOVE_FWD();//Move motor forward
			}
			/*check if the speed level options in the second option*/
			else if (Speed_level == Second_SPEED_LEVEL )
			{
				MOTOR_speed(Speed_60);//Set motor speed by 60% of the max speed
				MOVE_FWD();//Move motor forward
			}
			/*check if the speed level options in the third option*/
			else if (Speed_level == Third_SPEED_LEVEL )
			{
				MOTOR_speed(Speed_90);//Set motor speed by 90% of the max speed
				MOVE_FWD();//Move motor forward
			}
			/*check if the speed level options in the reverse option*/
			else if (Speed_level == REVERSE_SPEED_LEVEL )
			{
				MOTOR_speed(Speed_30);//Set motor speed by 30% of the max speed
				MOVE_REV();//Move motor reverse
			}
		}
		MOTORS_OFF();//Stop the motors
		/*if the pressed key is move right*/
		while(RIGHT_BUTTON == KPD_u8GetPressedKey() )
		{
			MOTOR_speed(Speed_30);//Set speed as 30 % of the max speed
			MOVE_RIGHT();//Turn right
		}
		MOTORS_OFF();//Stop the motors
		/*if the pressed key is move left*/
		while(LEFT_BUTTON == KPD_u8GetPressedKey() )
		{
			MOTOR_speed(Speed_30);//Set speed as 30 % of the max speed
			MOVE_LEFT();//Turn left
		}
		MOTORS_OFF();//Stop the motors


	}
}

/*Implementation of move motors reverse*/
void MOVE_REV(void)
{
	MOTOR_direction(MOTOR_1, REV);
	MOTOR_direction(MOTOR_2, REV);
}

/*Implementation of move motors forward*/
void MOVE_FWD(void)
{
	MOTOR_direction(MOTOR_1, FWD);
	MOTOR_direction(MOTOR_2, FWD);
}

/*Implementation of turm motors right*/
void MOVE_RIGHT(void)
{
	MOTOR_direction(MOTOR_1, FWD);
	MOTOR_direction(MOTOR_2, REV);
}

/*Implementation of turm motors left*/
void MOVE_LEFT(void)
{
	MOTOR_direction(MOTOR_1, REV);
	MOTOR_direction(MOTOR_2, FWD);
}

/*Implementation of stop motors*/
void MOTORS_OFF()
{
	MOTOR_off(MOTOR_1);
	MOTOR_off(MOTOR_2);
}


void LEDS_INIT(void)
{
	LED_init(LED_PORTB,4);
	LED_init(LED_PORTB,5);
	LED_init(LED_PORTB,6);
	LED_init(LED_PORTB,7);

}
