/*
 * disp.c
 *
 * Created: 18/11/2022 02:50:32 p. m.
 *  Author: Jason Bustos & Marcelo Bazan
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "disp.h"

#define TIME 10

void init_display(void)
{
	DDRD |= (_BV(SEGA) | _BV(SEGB) | _BV(SEGC) | _BV(SEGD) | _BV(SEGE) | _BV(SEGF));
	DDRB |= _BV(SEGG);
	COMMON_DDRX |= (_BV(COMMON_LED1) | _BV(COMMON_LED2) | _BV(COMMON_LED3) | _BV(COMMON_LED4));
}

void show_numbers(uint16_t num)
{
	
	switch (num)
	{
		case 0:
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_ON;
		SEGE_ON;
		SEGF_ON;
		SEGG_OFF;
		break;
		case 1:
		SEGA_OFF;
		SEGB_ON;
		SEGC_ON;
		SEGD_OFF;
		SEGE_OFF;
		SEGF_OFF;
		SEGG_OFF;
		break;
		case 2:
		SEGA_ON;
		SEGB_ON;
		SEGC_OFF;
		SEGD_ON;
		SEGE_ON;
		SEGF_OFF;
		SEGG_ON;
		
		break;
		case 3:
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_ON;
		SEGE_OFF;
		SEGF_OFF;
		SEGG_ON;
		break;
		case 4:
		SEGA_OFF;
		SEGB_ON;
		SEGC_ON;
		SEGD_OFF;
		SEGE_OFF;
		SEGF_ON;
		SEGG_ON;
		break;
		case 5:
		SEGA_ON;
		SEGB_OFF;
		SEGC_ON;
		SEGD_ON;
		SEGE_OFF;
		SEGF_ON;
		SEGG_ON;
		break;
		case 6:
		SEGA_OFF;
		SEGB_OFF;
		SEGC_ON;
		SEGD_ON;
		SEGE_ON;
		SEGF_ON;
		SEGG_ON;
		break;
		case 7:
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_OFF;
		SEGE_OFF;
		SEGF_OFF;
		SEGG_ON;
		break;
		case 8:
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_ON;
		SEGE_ON;
		SEGF_ON;
		SEGG_ON;
		break;
		case 9:
		SEGA_ON;
		SEGB_ON;
		SEGC_ON;
		SEGD_OFF;
		SEGE_OFF;
		SEGF_ON;
		SEGG_ON;
		break;
	}
}
