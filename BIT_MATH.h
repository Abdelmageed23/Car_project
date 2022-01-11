#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_
/*Defining some macros of set, clear, toggle and get for reaching bits easily*/
#define SET_BIT(Rej,Bit)	Rej=(Rej|(1<<Bit))

#define CLR_BIT(Rej,Bit)	Rej=(Rej&(~(1<<Bit)))

#define TOG_BIT(Rej,Bit)	Rej=(Rej^(1<<Bit))

#define GET_BIT(Rej,Bit)	((Rej>>Bit)&1)

#endif
