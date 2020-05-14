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
	int a,b=0;

	 for(int z=0; z<10;z++)
		{
			for(int x=0; x<10;x++)
			{
				for(int j=0; j<10;j++)
				{
					for(int i=0; i<10;i++)
					{

						wyswietl(i,3);
						_delay_ms(50);
						if (a!=0) wyswietl(j,2);
						_delay_ms(50);
						if (b!=0)wyswietl(x,1);
						_delay_ms(50);
						if (z!=0)wyswietl(z,0);
						_delay_ms(50);

					}
					a++;
				}
				b++;
			}
		}

	while(1)
	{
		wyswietl(9,3);
		_delay_ms(50);
		wyswietl(9,2);
		_delay_ms(50);
		wyswietl(9,1);
		_delay_ms(50);
		wyswietl(9,0);
		_delay_ms(50);
	}

	}
	return 0;
}
