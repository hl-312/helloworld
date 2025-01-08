#include <STC89C5xRC.H>

void main()
{
	unsigned int i = 0;
	unsigned char j = 0x01;
	P2 = 0xff;
	while(1)
	{
		i++;
		if ( i == 33000 ){
			P2 = 0xff^j;
			j <<= 1;
			if( j == 0) j = 0x01;
			i = 0;
		}
	};
}
