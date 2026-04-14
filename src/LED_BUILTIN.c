#include <avr/io.h> //internes Headerfile, stellt Symbolnamen wie PORTB, PIN etc. bereit
#include <util/delay.h> //internes Headerfile, stell avr-gcc (Compiler später bereit) --> richtige Mikrocontroller Programmierung
#include <stdint.h> //HeaderDatei für uint usw. 
#define F_CPU 16000000UL //Definiert die Taktfrequenz für die Zeitrechnung (delay_ms)

#define LEDON (PORTB |= (1<<PB5))
#define LEDOFF (PORTB &= ~(1 <<PB5))

int main(void)
{
	DDRB |= (1 << DDB5); //Das hier definiert Pin13 als Ausgabe

	LEDON; _delay_ms(800);
	LEDOFF; _delay_ms(800); 
}
