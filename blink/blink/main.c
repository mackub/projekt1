/*
 * blink.c
 *
 * Created: 05.07.2017 15:22:20
 * Author : macku
 */ 
 
#include <avr/io.h>
#include <util/delay.h>
#include "extrino_portx.h"

int main(void) {
	
	/*PORTE.DIR = 1;                  // caly port E jako wej�cie  bylo 0
	PORTF.DIR = 0b11111111;         // caly port F jako wyj�cie
	
	uint8_t licznik = 0;            // zmienna steruj�ca mrugaj�cymi diodami
	int test = 6;

	while(1) {
		licznik++;
		PORTF.OUT = licznik;
		if(PORTE.IN & (1<<5)) {     // je�li przycisk FLIP zwolniony
			_delay_ms(100);
			} else {                    // je�li przycisk FLIP wci�ni�ty
			_delay_ms(50);
		}
	}*/
	PortxInit();                // inicjalizacja PORTX
	
	while(1) {
		PORTX.OUT    =    PORTX.IN;
	}
}