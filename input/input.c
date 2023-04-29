/*
 * input.c
 *
 * Created: 29/11/2022 04:08:07 p. m.
 *  Author: Jason Bustos & Marcelo Bazan
 */ 
#include <avr/io.h>
#include "input.h"

void init_ports(void)
{
	DDRC &=	~_BV(MODO);
	DDRC &= ~_BV(ASC);
	DDRC &= ~_BV(DES);
}