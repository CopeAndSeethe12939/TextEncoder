/* 34 Encoder/decoder method & routine by The_Original_Sin */

#include <stdio.h>

typedef unsigned char BYTE;

BYTE o1,o2,o3,o4 = 0;
BYTE v1,v2,v3,v4 = 0;

void encode(BYTE v1,BYTE v2,BYTE v3,BYTE v4)
{
	o1 = ((v1 & 0x3f) | ((v4 & 0x30) << 2));
	o2 = ((v2 & 0x3f) | ((v4 & 0xc0) << 4));
	o3 = ((v3 & 0x3f) | ((v4 & 0x03) << 6));
}

void decode(BYTE v1,BYTE v2,BYTE v3)
{
	o1 = (v1 & 0x3f);
	o2 = (v2 & 0x3f);
	o3 = (v3 & 0x3f);
	o4 = ((v1 & 0xc0) >> 2) | ((v2 & 0xc0) >> 4) |((v3 & 0xc0) >> 6);
}

int main ()
{

encode (0x08,0x05,0x20,0x21);
printf ("%02x %02x %02x\n",o1,o2,o3);
decode (o1,o2,o3);
printf ("%02x %02x %02x %02x\n",o1,o2,o3,o4);

return 0;
}
