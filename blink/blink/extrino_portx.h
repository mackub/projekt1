#ifndef EXTRINO_PORTX_H_
#define EXTRINO_PORTX_H_

#include <avr/io.h>
#include <avr/interrupt.h>

// AUTOMATYCZNE OD�WIE�ANIE PORTU X
// PORTX nale�y od�wie�a� r�cznie, gdy SPI jest wykorzystywane jeszcze do innych cel�w
// 1 - w��czone
// 0 - wy��czone
#define PORTX_AUTOREFRESH		1

struct PORTX_t {
	uint8_t volatile IN;
	uint8_t volatile OUT;
	uint8_t volatile OUTSET;
	uint8_t volatile OUTCLR;
	uint8_t volatile OUTTGL;
};
volatile struct PORTX_t PORTX; 

// inicjalizacja PORTX
void PortxInit(void);

// od�wierzenie rejestr�w PORTX
#if PORTX_AUTOREFRESH == 0
void PortxRefresh(void);
#endif

#endif /* EXTRINO_PORTX_H_ */