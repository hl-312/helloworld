#include <STC89C5xRC.H>

typedef enum { RIGHT, LEFT } Direction;

void delay_s( char num );			//delay for num seconds.
void FlowLedP2( Direction dirt, char num, unsigned char drt );		// led lighting to flow to Direction in P2, fluence at num, duration of drt.


void main()
{
    P2 = 0xff;
	FlowLedP2( LEFT, 1, 16);
    while (1);
}

//这个数据是实验模糊测的，不是计算的
void delay_s( char num )
{
	if( num > 0 && num < 120 ){
		for ( ; num > 0; num-- ){
			unsigned int i;
			for ( i = 0; i < 32800; i++ ){};
		}
		return ;
	}
	return ;
}

void FlowLedP2( Direction dirt, char num, unsigned char drt )
{
	unsigned char set = 0x01;
	for ( ; drt > 0 ; drt-- ){
		P2 = 0xff^set;
		if ( dirt == RIGHT ) {
			set <<= 1;
			if ( set == 0 ) set = 0x01;
		} else if (dirt == LEFT) {
			set >>= 1;
			if ( set == 0 ) set = 0x80;
		}
		delay_s( num );
	}
	P2 = 0xff;
	return ;
}
