#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXTERNAL_SOURCE 0

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif

#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

/* Wyœwietlacz LCD */

#define LCD_DDR DDRB		/* DDR wyœwietlacza */
#define LCD_PORT PORTB		/* PORT wyœwietlacza */
#define RS PB0				/* RS wyœwietlacza */
#define EN PB1				/* EN wyœwietlacza */

void LCD_cmd(unsigned char cmd)
{
	LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
	LCD_PORT &= ~ (1<<RS);
	LCD_PORT |= (1<<EN);
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);

	_delay_us(200);

	LCD_PORT = (LCD_PORT & 0x0F) | (cmd << 4);
	LCD_PORT |= (1<<EN);
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_inicjuj()
{
	LCD_DDR=0xFF;
	_delay_ms(20);				/* LCD Power ON delay always >15ms */

	LCD_cmd(0x02);				/* przesylanie bitów  */
	LCD_cmd(0x28);              /* druga linia */
	LCD_cmd(0x0c);              /* wylacz kursor */
	LCD_cmd(0x06);              /* kursor do prawej */
	LCD_cmd(0x01);              /* wyczysc ekran */
	_delay_ms(2);

}

void LCD_wyczysc()
{
	LCD_cmd(0x01);
	_delay_ms(2);
	LCD_cmd(0x80);
}

void LCD_znak(unsigned char znak)
{
	LCD_PORT = (LCD_PORT & 0x0F) | (znak & 0xF0);
	LCD_PORT |= (1<<RS);
	LCD_PORT|= (1<<EN);
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);

	_delay_us(200);

	LCD_PORT = (LCD_PORT & 0x0F) | (znak << 4);
	LCD_PORT |= (1<<EN);
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_ciag(char *ciag)
{
	for(int i=0; ciag[i]!=0;i++ )
	{
		LCD_znak (ciag[i]);
	}
}

/*	RESZTA */

void inicjuj()
{
    ADMUX = 0;

    ADCSRA =
         1 << ADPS0
        | 1 << ADPS1
        | 1 << ADPS2
        | 1 << ADEN;
}

static int16_t wczytaj()
{
    ADCSRA |= (1 << ADSC);
    while(ADCSRA & (1 << ADSC));

    return ADC;
}


int main()
{

	DDRD=255;

	inicjuj();
	LCD_inicjuj();

	while(1)
	{
		auto float voltage = wczytaj();

        char tablica[4];
        double wynik = ( voltage / 1023.0) * 3.3;

        PORTD=wynik*51;

        dtostrf(wynik, 0, 3.3, tablica);

        LCD_wyczysc();
        LCD_ciag(tablica);
        _delay_ms(1000);
	}
}
