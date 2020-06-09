#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/sfr_defs.h>

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif

#ifndef inb
#define	inb(addr)			(addr)
#endif

#ifndef outb
#define	outb(addr, data)	addr = (data)
#endif

#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

#ifndef tbi
#define tbi(reg,bit)		reg ^= (_BV(bit))
#endif

/*
#define bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))
#define loop_until_bit_is_set(sfr, bit)   do { } while (bit_is_clear(sfr, bit))
#define loop_until_bit_is_clear(sfr, bit)   do { } while (bit_is_set(sfr, bit))
*/

#define MIN(a,b)			((a<b)?(a):(b))
#define MAX(a,b)			((a>b)?(a):(b))
#define ABS(x)				((x>0)?(x):(-x))


#endif /* GLOBAL_H_ */
