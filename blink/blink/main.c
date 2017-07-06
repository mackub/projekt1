/*
 * blink.c
 *
 * Created: 05.07.2017 15:22:20
 * Author : macku
 */ 
<<<<<<< HEAD
 
=======
 #include <stdbool.h>
>>>>>>> gr2
#include <avr/io.h>
#include <util/delay.h>
#include "extrino_portx.h"


void SetGreen(bool on){
	if (on)
	{
		PORTF.OUTSET = PIN1_bm;
	}
	else 
	{
		PORTF.OUTCLR = PIN1_bm;
	}
	
}
void SetRed(bool on)
{
	if (on)
	{
		PORTF.OUTSET = PIN0_bm;
	}
	else
	{
		PORTF.OUTCLR = PIN0_bm;
	}
}

void SetBlue(bool on)
{
	if (on)
	{
		PORTF.OUTSET = PIN2_bm;	// ustaw pin2 jako 1
	}
	else
	{
		PORTF.OUTCLR = PIN2_bm; // ustaw pin2 jako 0
	}
}
int main(void) {
	
<<<<<<< HEAD
	/*PORTE.DIR = 1;                  // caly port E jako wejœcie  bylo 0
	PORTF.DIR = 0b11111111;         // caly port F jako wyjœcie
	
	uint8_t licznik = 0;            // zmienna steruj¹ca mrugaj¹cymi diodami
	int test = 6;

	while(1) {
		licznik++;
		PORTF.OUT = licznik;
		if(PORTE.IN & (1<<5)) {     // jeœli przycisk FLIP zwolniony
			_delay_ms(100);
			} else {                    // jeœli przycisk FLIP wciœniêty
			_delay_ms(50);
		}
	}*/
	PortxInit();                // inicjalizacja PORTX
	
	while(1) {
		PORTX.OUT    =    PORTX.IN;
=======

	PORTF.DIR = 0b11111111;         // caly port F jako wyjœcie
	
	uint8_t licznik = 0;            // zmienna steruj¹ca mrugaj¹cymi diodami
	
	while(1) 
	{
		SetGreen(true);
		_delay_ms(400);
		SetGreen(false);
		_delay_ms(400);

>>>>>>> gr2
	}
}