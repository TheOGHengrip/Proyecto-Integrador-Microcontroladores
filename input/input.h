/*
 * input.h
 *
 * Created: 22/11/2022 03:35:05 p. m.
 *  Author: Jason Bustos & Marcelo Bazan
 */ 


#ifndef INPUT_H_
#define INPUT_H_

#define BUTTONS PINC
#define MODO PINC0
#define MODO_PRESS bit_is_set(BUTTONS,MODO)
#define ASC PINC1
#define ASC_PRESS bit_is_set(BUTTONS,ASC)
#define DES PINC2
#define DES_PRESS bit_is_set(BUTTONS,DES)

//Macros
#define _BV(bit) (1 << (bit))

//Definicion
void init_ports(void);




#endif /* INPUT_H_ */