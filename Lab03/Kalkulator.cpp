#include "GLOBAL.h"
#include "LCD_HD44780.h"


#define WIELKOSC 15

/* GETKEY */

int getKey(){
	for(int i=0;i<4;i++){
			sbi(PORTC,i);
			if(bit_is_set(PINC,4)){
				cbi(PORTC,i);
				return 1+4*i;
			}
			if(bit_is_set(PINC,5)){
				cbi(PORTC,i);
				return 2+4*i;
			}
			if(bit_is_set(PINC,6)){
				cbi(PORTC,i);
				return 3+4*i;
			}
			if(bit_is_set(PINC,7)){
				cbi(PORTC,i);
				return 4+4*i;
			}
			cbi(PORTC,i);
	}
	return 0;
}
/*
 *  KLAWIATURA
 *  7 8 9 /
 *  6 5 4 *
 *  3 2 1 -
 *  C 0	= +
 */

int main()
{
	DDRD=0xFF;

	DDRC=0x0F;
	PORTC=0xF0;

	// ZMIENNE
	char tekst[WIELKOSC];
	char znak;
	char operacja;

	int wynik = 0;
	int liczba1 = 0;
	int liczba2 = 0;
	int index = 0;

	bool pierwsza = true;
	//

	LCD_HD44780::init();
	LCD_HD44780::writeText("KALKULATOR");
	_delay_ms(2000);
	LCD_HD44780::clear();


	while(1)
	{
		switch(getKey())
		{
			case 1:
				znak = '7';
			break;
			case 2:
				znak = '4';
			break;
			case 3:
				znak = '1';
			break;
			// Wyczysc
			case 4:
				znak = 'C';
			break;
			case 5:
				znak = '8';
			break;
			case 6:
				znak = '5';
			break;
			case 7:
				znak = '2';
			break;
			case 8:
				znak = '0';
			break;
			case 9:
				znak = '9';
			break;
			case 10:
				znak = '6';
			break;
			case 11:
				znak = '3';
			break;
			// Wyswietlanie wyniku
			case 12:
				znak = '=';
			break;
			// Dzielenie
			case 13:
				znak = '/';
			break;
			// Mnozenie
			case 14:
				znak = '*';
			break;
			// Odejmowanie
			case 15:
				znak = '-';
			break;
			// Dodawanie
			case 16:
				znak = '+';
			break;

			default:
				znak = 'x';
			break;
		}

		if(pierwsza == true)
		{
			if(getKey()!=0)
			{
				// zapis liczb
				if(znak == '1' || znak == '2' || znak == '3' || znak == '4' || znak == '5' || znak == '6' || znak == '7' || znak == '8' || znak == '9' || znak == '0')
				{
					tekst[index] = znak;
					liczba1 = atoi(tekst);
					index++;
					_delay_ms(70);
				}

				// czyszczenie po dzialaniu
				else if(znak == '+' || znak == '-' || znak == '/' || znak == '*' || znak == '=')
				{
					for(int i=0; i<WIELKOSC; i++)
					{
						tekst[i]=' ';
					}
					//LCD_HD44780::clear();

					index =0;
					operacja=znak;

					pierwsza = false;
				}

				// czyszczenie po clearze
				else
				{
					for(int i=0; i<WIELKOSC; i++)
					{
						tekst[i]=' ';
					}
					//LCD_HD44780::clear();

					index = 0;
					liczba1 = 0; liczba2 = 0;
				}
			}
		}
		else
		{
			if(getKey()!=0)
			{
				// zapis liczb
				if(znak == '1' || znak == '2' || znak == '3' || znak == '4' || znak == '5' || znak == '6' || znak == '7' || znak == '8' || znak == '9' || znak == '0')
				{
					tekst[index] = znak;
					liczba2 = atoi(tekst);
					index++;
					_delay_ms(70);
				}

				// czyszczenie po clearze
				else if(znak == 'C')
				{
					for(int i=0; i<WIELKOSC; i++)
					{
						tekst[i]=' ';
					}
					//LCD_HD44780::clear();

					index = 0;
					liczba1 = 0; liczba2 = 0;
					pierwsza = true;
				}

				else if(znak != '=')
				{
					for(int i=0; i<WIELKOSC; i++)
					{
						tekst[i]=' ';
					}
					//LCD_HD44780::clear();

					operacja = znak;
					index = 0;
					pierwsza = false;

				}

				else if(operacja == '+')
				{
					wynik = liczba1+liczba2;
					itoa(wynik, tekst, 10);
				}

				else if(operacja == '-')
				{
					wynik = liczba1-liczba2;
					itoa(wynik, tekst, 10);
				}

				else if(operacja == '*')
				{
					wynik = liczba1*liczba2;
					itoa(wynik, tekst, 10);
				}
				// operacja = '/'
				else
				{
					wynik = liczba1/liczba2;
					itoa(wynik, tekst, 10);
				}
			}
		}

		LCD_HD44780::clear();
		LCD_HD44780::writeText(tekst);
		_delay_ms(750);
	  }

}
