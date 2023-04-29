/*
 * disp.h
 *
 * Created: 18/11/2022 02:50:20 p. m.
 *  Author: Jason Bustos & Marcelo Bazan
 */ 


#ifndef DISP_H_
#define DISP_H_

//#define _BV(bit) (1<<(bit))
//Display
#define DISPLAY_PORTD PORTD //Definicion de puertos a usar
#define DISPLAY_PORTB PORTB
//Segmento A
#define SEGA PORTD2 //PORTD2
#define SEGA_ON DISPLAY_PORTD |= _BV(SEGA)
#define SEGA_OFF DISPLAY_PORTD &= ~_BV(SEGA)
//Segmento B
#define SEGB PORTD3
#define SEGB_ON DISPLAY_PORTD |= _BV(SEGB)
#define SEGB_OFF DISPLAY_PORTD &= ~_BV(SEGB)
//Segmento C
#define SEGC PORTD4
#define SEGC_ON DISPLAY_PORTD |= _BV(SEGC)
#define SEGC_OFF DISPLAY_PORTD &= ~_BV(SEGC)
//Segmento D
#define SEGD PORTD5
#define SEGD_ON DISPLAY_PORTD |= _BV(SEGD)
#define SEGD_OFF DISPLAY_PORTD &= ~_BV(SEGD)
//Segmento E
#define SEGE PORTD6
#define SEGE_ON DISPLAY_PORTD |= _BV(SEGE)
#define SEGE_OFF DISPLAY_PORTD &= ~_BV(SEGE)
//Segmento F
#define SEGF PORTD7
#define SEGF_ON DISPLAY_PORTD |= _BV(SEGF)
#define SEGF_OFF DISPLAY_PORTD &= ~_BV(SEGF)
//Segmento G
#define SEGG PORTB0
#define SEGG_ON DISPLAY_PORTB |= _BV(SEGG)
#define SEGG_OFF DISPLAY_PORTB &= ~_BV(SEGG)

//Definir el LED (digitos)
#define COMMON_DDRX DDRB
#define COMMON_PORTX PORTB
//primer LED
#define COMMON_LED1 PORTB4
#define COMMON_LED1_ON COMMON_PORTX &= ~_BV(COMMON_LED1)
#define COMMON_LED1_OFF COMMON_PORTX |= _BV(COMMON_LED1)
//segundo LED
#define COMMON_LED2 PORTB3
#define COMMON_LED2_ON COMMON_PORTX &= ~_BV(COMMON_LED2)
#define COMMON_LED2_OFF COMMON_PORTX |= _BV(COMMON_LED2)
//tercer LED
#define COMMON_LED3 PORTB2
#define COMMON_LED3_ON COMMON_PORTX &= ~_BV(COMMON_LED3)
#define COMMON_LED3_OFF COMMON_PORTX |= _BV(COMMON_LED3)
//cuarto LED
#define COMMON_LED4 PORTB1
#define COMMON_LED4_ON COMMON_PORTX &= ~_BV(COMMON_LED4)
#define COMMON_LED4_OFF COMMON_PORTX |= _BV(COMMON_LED4)


void init_display(void);
void show_numbers(uint16_t num);

#endif /* DISP_H_ */