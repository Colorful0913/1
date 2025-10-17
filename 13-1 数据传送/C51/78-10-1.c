#include <reg52.h>
//#include <absace.h>
#define XBYTE ((unsigned char volatile xdata *) 0)
#define DBYTE ((unsigned char volatile data *) 0)
int i=0;
void main(){
XBYTE[0x4000]=0x34;
i=XBYTE[0x4000];
DBYTE[0x30]=i ;
}