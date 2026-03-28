#include <reg51.h>

sbit led1 = P2^0;
sbit led2 = P2^4;
sbit swi = P3^2;
void delay(void);
void urgent(void) interrupt 0{
	int i;
	led1 = 1;
	led2 = 0;
	for(i = 0; i<20 ; i++){
	delay();
	}
	led1 = 0;
	led2 = 1;
	for(i = 0; i<20 ; i++){
	delay();
	}
}

void main(){
	
	IT0 = 0;
	IE = 0x81;
	while (1){
	led1 = 0;
	led2 = 0;
	}
}

void delay(){
	TMOD = 0x01;
	TH0 = 0x4B;
	TL0 = 0x26;
	TR0 = 1;
	while (TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}