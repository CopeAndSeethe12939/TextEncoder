/* 34 Encoder/decoder method & routine by The_Original_Sin */

#include <stdio.h>

typedef unsigned char BYTE;

BYTE o1,o2,o3,o4,o5,o6,o7,o8 = 0;
BYTE v1,v2,v3,v4,v5,v6,v7,v8 = 0;

void encode(BYTE v1,BYTE v2,BYTE v3,BYTE v4,BYTE v5,BYTE v6,BYTE v7,BYTE v8)
{
	o1 = ((v1 & 0x7f) | ((v8 & 0x40) << 1));
	o2 = ((v2 & 0x7f) | ((v8 & 0x20) << 2));
	o3 = ((v3 & 0x7f) | ((v8 & 0x10) << 3));
	o4 = ((v4 & 0x7f) | ((v8 & 0x08) << 4));
	o5 = ((v5 & 0x7f) | ((v8 & 0x04) << 5));
	o6 = ((v6 & 0x7f) | ((v8 & 0x02) << 6));
	o7 = ((v7 & 0x7f) | ((v8 & 0x01) << 7));
}

void decode(BYTE v1,BYTE v2,BYTE v3,BYTE v4,BYTE v5,BYTE v6,BYTE v7)
{
	o1 = (v1 & 0x7f);
	o2 = (v2 & 0x7f);
	o3 = (v3 & 0x7f);
	o4 = (v4 & 0x7f);
	o5 = (v5 & 0x7f);
	o6 = (v6 & 0x7f);
	o7 = (v7 & 0x7f);
	o8 = 	((v1 & 0x80) >> 1) | 
		((v2 & 0x80) >> 2) |
		((v3 & 0x80) >> 3) |
		((v4 & 0x80) >> 4) |
		((v5 & 0x80) >> 5) |
		((v6 & 0x80) >> 6) |
		((v7 & 0x80) >> 7);

}

int main ()
{

printf ("%02x %02x %02x %02x %02x %02x %02x %02x\n",0x08,0x05,0x20,0x21,0x08,0x05,0x20,0x21);

encode (0x08,0x05,0x20,0x21,0x08,0x05,0x20,0x21);
printf ("%02x %02x %02x %02x %02x %02x %02x\n",o1,o2,o3,o4,o5,o6,o7);
decode (o1,o2,o3,o4,o5,o6,o7);
printf ("%02x %02x %02x %02x %02x %02x %02x %02x\n",o1,o2,o3,o4,o5,o6,o7,o8);

return 0;
}
