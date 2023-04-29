/*
 * Codigo.c
 *
 * Created: 18/11/2022 02:49:50 p. m.
 * Author : Jason Bustos, Marcelo Bazan
 * Equipo: #16
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "input/input.h"
#include "disp/disp.h"
#include "adc/adc.h"
#include "timer/timer.h"
#define TIME 100

//Variables y definicion de contador automatico
void contadorFun(uint16_t numero);
uint8_t millares = 0;
uint8_t centenas = 0;
uint8_t decenas = 0;
uint8_t unidades = 0;
uint8_t contador = 0000;
//contador ascendente
uint8_t contador_asc = 0000;
//contador descendente
uint8_t contador_des = 159;
//Seleccion de modo
uint8_t modoReg = 0;
//valor de potenciometro
uint8_t potValue = 0;
//valor potenciometro convertido a formato requerido 0-999
uint16_t format = 0;

//TODO: uint8_t no es suficente para el modo descendente al ser unsigned, cambiar contador_des a int_16t
//TODO: opciones, pasar todo a int_16t | crear dos contadores para contador_des que sigan el mismo decenso, tomar encuenta para el if el contador con int16t
//y mostrar el contadro con uint_8t | crear una nueva funcion para contador y en ella pasar valores uint16 | Crear funciones variadicas en show_number y contadorAutomatico.


int main(void)
{
	cli();
	init_display();
	init_ports();
    init_timer();
	init_adc();
	sei();
	ADC_on();
	
    while (1) 
    {
		uint16_t conversor = 0;
		if(modoReg == 0)
		{
			conversor = (uint16_t) contador; //Convierte los contadores de uint8 a uint16
			contadorFun(conversor);
			_delay_us(10);
		}
		else if (modoReg == 1)
		{
			conversor = (uint16_t) contador_asc;
			contadorFun(conversor);
			_delay_us(10);
		}
		else if (modoReg == 2)
		{
			conversor = (uint16_t) contador_des;
			contadorFun(conversor);
			_delay_us(10);
		}
		else if (modoReg == 3)
		{
			contadorFun(format);
		}
    }
}

void contadorFun(uint16_t numero)
{
	millares = numero / 1000;
	COMMON_LED1_ON;
	COMMON_LED2_OFF;
	COMMON_LED3_OFF;
	COMMON_LED4_OFF;
	show_numbers(millares);
	_delay_us(TIME);
	COMMON_LED1_OFF;
	COMMON_LED2_ON;
	COMMON_LED3_OFF;
	COMMON_LED4_OFF;
	centenas = (numero%1000)/100;
	show_numbers(centenas);
	_delay_us(TIME);
	COMMON_LED1_OFF;
	COMMON_LED2_OFF;
	COMMON_LED3_ON;
	COMMON_LED4_OFF;
	decenas = (numero%100)/10;
	show_numbers(decenas);
	_delay_us(TIME);
	COMMON_LED1_OFF;
	COMMON_LED2_OFF;
	COMMON_LED3_OFF;
	COMMON_LED4_ON;
	unidades = numero%10;
	show_numbers(unidades);
	_delay_us(TIME);
	COMMON_LED1_OFF;
	COMMON_LED2_OFF;
	COMMON_LED3_OFF;
	COMMON_LED4_OFF;
	_delay_us(TIME);
}

ISR(TIMER0_COMPA_vect)
{
	if (MODO_PRESS && !ASC_PRESS && !DES_PRESS)
	{
		modoReg++;
	}
	else if(modoReg == 0)
	{
		if(contador < 159)
		{
			contador++;
			_delay_us(TIME);
		}
		else
		{
			contador = 0;
		}
	}
	else if (modoReg == 1)
	{
		if (!MODO_PRESS && ASC_PRESS && !DES_PRESS)
		{
			contador_asc++;
			_delay_us(TIME);
			if (contador_asc > 159)
			{
				contador_asc = 0;
			}
		}
	}
	else if (modoReg == 2)
	{
		if (!MODO_PRESS && !ASC_PRESS && DES_PRESS)
		{
			contador_des--;
			_delay_us(TIME);
			
			if (contador_des == 255)
			{
				contador_des = 159;
			}
		}
	}
	else if (modoReg == 3)
	{
		double aux = 3.91764;
		format = (uint16_t)ceil(potValue*aux);
	}
	else if(modoReg > 3)
	{
		modoReg = 0;
	}
	
}

ISR(ADC_vect)
{
	potValue = ADCH;
}
