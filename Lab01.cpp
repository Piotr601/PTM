
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include <math.h>



#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif

#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif


int main() {

	DDRD=255;

/*	while(1){
		for(int j=0;j<8;j++){
			PORTD=0b00000000;
			_delay_ms(50);
			PORTD=0b11111111;
			_delay_ms(50);
		}
	}
*/

	while(1){
		for(int i=0;i<8;i++){
			PORTD = 1 << i;
			_delay_ms(50);
			if (i==7) {
				for(int i=7;i>0;i--){
							PORTD = 1 << i;
							if (i==7) {_delay_ms(0);}
							else _delay_ms(50);

				}
			}
		}

	}
}
