#include <STC89C5xRC.H>

void delay_ms( char num );			//delay for num ms.

void main()
{
    unsigned char i = 0;
    while(1) {
        if ( i % 8 == 0 ) {
            P2 = 0xff;
            P2 = P2^0x01;    //与 1 异或就是给该位取反
        }
        if ( i % 8 == 1 ) P2 = P2^0x02;
        if ( i % 8 == 2 ) P2 = P2^0x04;
        if ( i % 8 == 3 ) P2 = P2^0x08;
        if ( i % 8 == 4 ) P2 = P2^0x10;
        if ( i % 8 == 5 ) P2 = P2^0x20;
        if ( i % 8 == 6 ) P2 = P2^0x40;
        if ( i % 8 == 7 ) P2 = P2^0x80;
        if ( i == 240) i = 0;
        delay_ms(1);
        i++;
	};
}



void delay_ms( char num )
{
	if( num > 0 && num < 120 ){
		for ( ; num > 0; num-- ){
			unsigned int i;
			for ( i = 0; i < 33; i++ ){};
		}
		return ;
	}
	return ;
}