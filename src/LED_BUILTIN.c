#define F_CPU 16000000UL //Definiert die Taktfrequenz für die Zeitrechnung (delay_ms)
#include <avr/io.h> //internes Headerfile, stellt Symbolnamen wie PORTB, PIN etc. bereit
#include <util/delay.h> //internes Headerfile, stell avr-gcc (Compiler später bereit) --> richtige Mikrocontroller Programmierung
#include <stdint.h> //HeaderDatei für uint usw. 


#define LEDON (PORTB |= (1<<PB5))
#define LEDOFF (PORTB &= ~(1 <<PB5))


typedef enum {
    MODE1 = 0,
    MODE2 = 1
} led_mode_t;



void led_modes (led_mode_t MODUS){
	switch(MODUS)
	{
		case MODE1:
			LEDON; _delay_ms(1100);
			LEDOFF; _delay_ms(1100);
			break;

		case MODE2:
			for (uint8_t i=0; i<3; i++) {
					LEDON;  _delay_ms(100);
					LEDOFF; _delay_ms(100);
			}
			_delay_ms(1000);
			break;
	}
}

int main(void)
{
	DDRB |= (1 << DDB5); //Das hier definiert Pin13 als Ausgabe
	while(1){
		led_modes(MODE1);
	}
	
}
