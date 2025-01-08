#include <STC89C5xRC.H>

void main()
{
    unsigned char i = 0;
    unsigned char j = 0;
    while(1) {
        if ( i == 0 ) P2 = 0x03;    //P2 ^= 0x01;   //与 1 异或就是给该位取反,与 0 异或不变，full 亮度只能在开头这里设置
//      if ( i == 1 ) P2 ^= 0x02;                   //P21 1% 亮度
        if ( i == 90 ) P2 ^= 0x04;                  //P22 90%亮度
        if ( i == 10 ) P2 ^= 0x08;
        if ( i == 10 ) P2 ^= 0x10;
        if ( i == 10 ) P2 ^= 0x20;
        if ( i == 80 ) P2 ^= 0x40;
        if ( i == 50 ) P2 ^= 0x80;
		for ( j = 0; j < 10; j++ ){};
        i++;
        if ( i >= 100) i -= 100;                    //相当于取模运算或者说取余了。一般的取模运算可能会用触发，这里只用减法，也许能加快速度
	};
}