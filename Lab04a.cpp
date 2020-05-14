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

void wyswietl(int liczba, int wyswietlacz){
	PORTD=255;
	switch(liczba)
	{
		case 0:
			PORTA=0b00111111;
		break;

		case 1:
			PORTA=0b00000110;
		break;

		case 2:
			PORTA=0b01011011;
		break;

		case 3:
			PORTA=0b01001111;
		break;

		case 4:
			PORTA=0b01100110;
		break;

		case 5:
			PORTA=0b01101101;
		break;

		case 6:
			PORTA=0b01111101;
		break;

		case 7:
			PORTA=0b00000111;
		break;

		case 8:
			PORTA=0b01111111;
		break;

		case 9:
			PORTA=0b01101111;
		break;

		default:
			PORTA=255;
		break;
	}
	PORTD=~(0b00010000<<wyswietlacz);
}

int main() {

	PORTA=255;
	DDRA=255;

	PORTD=255;
	DDRD=0b11110000;

	while(1)
	{
		for (int i=0; i<6;i++)
		{
			for(int j=0;j<10;j++)
			{
				for(int k=0;k<6;k++)
				{
					for(int l=0;l<10;l++)
					{

						wyswietl(l,3);
						_delay_ms(20);
						wyswietl(k,2);
						_delay_ms(20);
						wyswietl(j,1);
						_delay_ms(20);
						wyswietl(i,0);
						_delay_ms(20);

					}
				}
			}
		}

		while(1)
		{
			wyswietl(9,3);
			_delay_ms(20);
			wyswietl(5,2);
			_delay_ms(20);
			wyswietl(9,1);
			_delay_ms(20);
			wyswietl(5,0);
			_delay_ms(20);
		}
	}

	return 0;
}
