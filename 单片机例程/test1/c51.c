#include <reg52.h>
#include <intrins.h>

void delay();
char my_crol_(unsigned char P,unsigned int i);
unsigned int LEFT;
sbit beep = P1^5;

void main()
{
 	
	P2 = 0xfe;
	LEFT = 1;
 	while(1)
	{	
		delay();
		
		if (LEFT)
		{
			P2 = (P2<<1) ^ 1;
		}else{
			P2 = (P2>>1) ^ 0X80;
		}	 

		if(P2 == 0xff && LEFT)
		{
			delay();
			LEFT = 0;
			P2 = P2>>1;
		}else if(P2 == 0xff){
			delay();
			LEFT = 1;
			P2 = P2<<1;
		}

		if(P2==0xfe || P2 == 0x7f){
			beep = 0;
		}
		else{
			beep = 1;
		}					  	  

	}
	
 }


 void delay()
 {
 	unsigned int x,y;
 	for(x=0;x<100;x++)
		for(y=0;y<400;y++);
 }

 char my_crol_(unsigned char P,unsigned int i)
 {
 		P = (P<<i) ^ 1;
		if(P == 0xff)
		{
			delay();
			P = 0xfe;
		}
		return P;
 }