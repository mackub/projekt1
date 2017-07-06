#include "extrino_portx.h"

volatile struct PORTX_t PORTX; 

void PortxInit(void) {
	// sygna³y SS dla wszystkich peryferów na eXtrino XL
	PORTA.OUTSET		=	PIN3_bm | PIN4_bm;					// SPI MEM, OP AMP
	PORTA.DIRSET		=	PIN3_bm | PIN4_bm;					// SPI MEM, OP AMP
	PORTE.OUTSET		=	PIN3_bm | PIN6_bm | PIN7_bm;		// SD, PORTX, DIGPOT
	PORTE.DIRSET		=	PIN3_bm | PIN6_bm | PIN7_bm;		// SD, PORTX, DIGPOT
	
	PORTC.DIRSET		=	PIN4_bm | PIN5_bm | PIN7_bm;
	PORTC.DIRCLR		=	PIN6_bm;
	PORTC.OUTCLR		=	PIN7_bm | PIN6_bm | PIN5_bm | PIN4_bm;
	PORTC.REMAP			=	PORT_SPI_bm;						// zamiana miejscami SCK i MOSI
	SPIC.CTRL			=	SPI_ENABLE_bm|
							SPI_MASTER_bm|
							SPI_MODE_3_gc|
							//SPI_CLK2X_bm|
							SPI_PRESCALER_DIV128_gc;
	
	#if PORTX_AUTOREFRESH
		// przerwania
		SPIC.INTCTRL	=	SPI_INTLVL_LO_gc;
		PMIC.CTRL       =   PMIC_HILVLEN_bm|					// w³¹czenie przerwañ o priorytecie HI
							PMIC_MEDLVLEN_bm|					// w³¹czenie przerwañ o priorytecie MED
							PMIC_LOLVLEN_bm;					// w³¹czenie przerwañ o priorytecie LO
		sei();
		SPIC.DATA		=	0;									// pierwsza transmisja, zerowanie
	#else
		PortxRefresh();
	#endif
	
	
}

#if PORTX_AUTOREFRESH == 0
void PortxRefresh(void) {
	PORTE.OUTCLR	=	PIN6_bm;
	
	//for(uint8_t i = 255; i; i--);								// opóŸnienie
	PORTX.OUT	   |=	PORTX.OUTSET;
	PORTX.OUT	   &=  ~PORTX.OUTCLR;
	PORTX.OUT	   ^=	PORTX.OUTTGL;
	PORTX.OUTSET	=	0;
	PORTX.OUTCLR	=	0;
	PORTX.OUTTGL	=	0;

	SPIC.DATA	=	PORTX.OUT;
	while(SPIC.STATUS == 0);
	PORTX.IN = SPIC.DATA;
	for(uint8_t i = 255; i; i--);								// opóŸnienie
	PORTE.OUTSET	=	PIN6_bm;
}
#endif

ISR(SPIC_INT_vect) {
	PORTE.OUTSET	=	PIN6_bm;								// chip deselect
	PORTX.OUT	   |=	PORTX.OUTSET;
	PORTX.OUT	   &=  ~PORTX.OUTCLR;
	PORTX.OUT	   ^=	PORTX.OUTTGL;
	PORTX.OUTSET	=	0;
	PORTX.OUTCLR	=	0;
	PORTX.OUTTGL	=	0;
	PORTE.OUTCLR	=	PIN6_bm;								// chip select
	PORTX.IN		=	SPIC.DATA;
	SPIC.DATA		=	PORTX.OUT;
}