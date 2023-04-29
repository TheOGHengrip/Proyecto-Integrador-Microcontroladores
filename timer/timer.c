/*
 * timer.c
 *
 * Created: 23/11/2022 02:04:22 a. m.
 *  Author: Jason Bustos & Marcelo Bazan
 */ 
#include <avr/io.h>

void init_timer(void)
{
	
	//Modo CTC
	TCCR0A &= ~_BV(WGM00);
	TCCR0A |=  _BV(WGM01);
	TCCR0B &= ~_BV(WGM02);
	
	//Prescaler
	TCCR0B |=  _BV(CS02);
	TCCR0B &= ~_BV(CS01);
	TCCR0B |=  _BV(CS00);
	
	//Tope para 0.1s 1s
	OCR0A = 1250000;
	
	//Enable
	TIMSK0 |=  _BV(OCIE0A);
}