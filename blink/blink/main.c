/*
 * blink.c
 *
 * Created: 05.07.2017 15:22:20
 * Author : macku
 */ 
 #include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>


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
	

	PORTF.DIR = 0b11111111;         // caly port F jako wyjœcie
	
	uint8_t licznik = 0;            // zmienna steruj¹ca mrugaj¹cymi diodami
	
	while(1) 
	{
		SetGreen(true);
		_delay_ms(400);
		SetGreen(false);
		_delay_ms(400);

	}
}