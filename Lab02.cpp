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

	DDRD=0xFF;

	DDRB=0x0F;
	PORTB=0xF0;


// Zadanie 1 - wlaczanie przyciskiem
/*
	while(1){

		 sbi(PORTB,0);
		 sbi(PORTB,1);
		 sbi(PORTB,2);
		 sbi(PORTB,3);

		 	if(bit_is_set(PINB,4)){
				PORTD = 255;
				_delay_ms(20);
		 		cbi(PORTB,0);
		 	}

			if(bit_is_set(PINB,5)){
				PORTD = 255;
				_delay_ms(20);
				cbi(PORTB,1);
			}
			if(bit_is_set(PINB,6)){
				PORTD = 255;
				_delay_ms(20);
				cbi(PORTB,2);
			}
			if(bit_is_set(PINB,7)){
				PORTD = 255;
				_delay_ms(20);
				cbi(PORTB,3);
			}

		 PORTD=0;

		 cbi(PORTB,0);
		 cbi(PORTB,1);
		 cbi(PORTB,2);
		 cbi(PORTB,3);

	}

*/


// Zadanie 2 - Cofaj¹ca sie szlaczek po nacisnieciu



		int p;
	    uint8_t diody[]={1, 2 , 4 , 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2, 1} ;
	    uint8_t zmiana[]={1, 2 , 4 , 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2, 1} ;

	    while (1) {

	    	 sbi(PORTB,0);
	    	 sbi(PORTB,1);
	    	 sbi(PORTB,2);
	    	 sbi(PORTB,3);

	    	for(int i=0; i<15; i++){
	            if (  bit_is_set(PINB,4)	|| bit_is_set(PINB,5)	|| bit_is_set(PINB,6)	|| bit_is_set(PINB,7)	){
	            	while(p!=1){
						switch(i){

						case 0:
							p=1;
							i=0;
							break;

						case 1:
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;
						case 2:
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;
						case 3:
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;
						case 4:
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;
						case 5:
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;
						case 6:
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;
						case 7:
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;

						case 8:
							PORTD = ~zmiana[7];
							_delay_ms(10);
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;

						case 9:
							PORTD = ~zmiana[8];
							_delay_ms(10);
							PORTD = ~zmiana[7];
							_delay_ms(10);
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;

						case 10:
							PORTD = ~zmiana[9];
							_delay_ms(10);
							PORTD = ~zmiana[8];
							_delay_ms(10);
							PORTD = ~zmiana[7];
							_delay_ms(10);
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;

						case 11:
							PORTD = ~zmiana[10];
							_delay_ms(10);
							PORTD = ~zmiana[9];
							_delay_ms(10);
							PORTD = ~zmiana[8];
							_delay_ms(10);
							PORTD = ~zmiana[7];
							_delay_ms(10);
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;

						case 12:
							PORTD = ~zmiana[11];
							_delay_ms(10);
							PORTD = ~zmiana[10];
							_delay_ms(10);
							PORTD = ~zmiana[9];
							_delay_ms(10);
							PORTD = ~zmiana[8];
							_delay_ms(10);
							PORTD = ~zmiana[7];
							_delay_ms(10);
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;

						case 13:
							PORTD = ~zmiana[12];
							_delay_ms(10);
							PORTD = ~zmiana[11];
							_delay_ms(10);
							PORTD = ~zmiana[10];
							_delay_ms(10);
							PORTD = ~zmiana[9];
							_delay_ms(10);
							PORTD = ~zmiana[8];
							_delay_ms(10);
							PORTD = ~zmiana[7];
							_delay_ms(10);
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
							break;

						case 14:
							PORTD = ~zmiana[13];
							_delay_ms(10);
							PORTD = ~zmiana[12];
							_delay_ms(10);
							PORTD = ~zmiana[11];
							_delay_ms(10);
							PORTD = ~zmiana[10];
							_delay_ms(10);
							PORTD = ~zmiana[9];
							_delay_ms(10);
							PORTD = ~zmiana[8];
							_delay_ms(10);
							PORTD = ~zmiana[7];
							_delay_ms(10);
							PORTD = ~zmiana[6];
							_delay_ms(10);
							PORTD = ~zmiana[5];
							_delay_ms(10);
							PORTD = ~zmiana[4];
							_delay_ms(10);
							PORTD = ~zmiana[3];
							_delay_ms(10);
							PORTD = ~zmiana[2];
							_delay_ms(10);
							PORTD = ~zmiana[1];
							_delay_ms(10);
							PORTD = ~zmiana[0];
								p=1;
								i=0;
						break;

						default:
							p=0;
							break;
						}
	            	 }
	            	}
	            else
	            	PORTD = ~diody[i];
	            	_delay_ms(10);
	            	p=0;

	        }

	    	 cbi(PORTB,0);
	    	 cbi(PORTB,1);
	   		 cbi(PORTB,2);
 			 cbi(PORTB,3);

	  }



// Zadanie 3 - Wyswietla liczbe przez przycisk. Uwaga tylko jeden przycisk nalezy kliknac i przytrzymac!

/*
	while(1){
		for(int i=0;i<4;i++){
					sbi(PORTB,i);
					if(bit_is_set(PINB,4)){
						if(i==0){
							PORTD=1;
							_delay_ms(50);
						}
						if(i==1){
							PORTD=2;
							_delay_ms(50);
						}
						if(i==2){
							PORTD=3;
							_delay_ms(50);
						}
						if(i==3){
							PORTD=4;
							_delay_ms(50);
						}

						cbi(PORTB,i);

					}
					if(bit_is_set(PINB,5)){
						if(i==0){
							PORTD=5;
							_delay_ms(50);
						}
						if(i==1){
							PORTD=6;
							_delay_ms(50);
						}
						if(i==2){
							PORTD=7;
							_delay_ms(50);
						}
						if(i==3){
							PORTD=8;
							_delay_ms(50);
						}
						cbi(PORTB,i);

					}
					if(bit_is_set(PINB,6)){
						if(i==0){
							PORTD=9;
							_delay_ms(50);
						}
						if(i==1){
							PORTD=10;
							_delay_ms(50);
						}
						if(i==2){
							PORTD=11;
							_delay_ms(50);
						}
						if(i==3){
							PORTD=12;
							_delay_ms(50);
						}
						cbi(PORTB,i);

					}
					if(bit_is_set(PINB,7)){
						if(i==0){
							PORTD=13;
							_delay_ms(50);
						}
						if(i==1){
							PORTD=14;
							_delay_ms(50);
						}
						if(i==2){
							PORTD=15;
							_delay_ms(50);
						}
						if(i==3){
							PORTD=16;
							_delay_ms(50);
						}

						cbi(PORTB,i);

					}
					cbi(PORTB,i);
					PORTD=0;
			}
	}


	// FUNKCJA GETKEY
/*
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
	 */
}
