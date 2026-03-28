#include <reg51.h>
#define LCD P2
//lcd = P2;
sbit rs = P3^0;
sbit e = P3^1;
sbit swi = P3^3;
bit flag = 0;
void delay(unsigned char x){
	unsigned int i,j;
	for(i =0 ; i<x; i++){
		for( j = 0; j<1275; j++);
	}
}
void lcd_cmd(unsigned char cmd){
	LCD = cmd;
	rs = 0;
	e = 1;
	delay(2);
	e = 0;
}

void lcd_data (unsigned char a){
	LCD = a;
	rs = 1;
	e = 1;
	delay(2);
	e = 0;
}
void lcd_string(char *str){
	while (*str){
		lcd_data(*str++);
	}
}
void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
}
void external(void) interrupt 2{
   flag = 1;
}
void main(){
	lcd_init();
	lcd_string("RESTARTING");
	delay(1000);
	lcd_cmd(0x01);
	IE = 0x84;
	IT1 = 1;
	while(1){
		if (flag == 1){
				lcd_cmd(0x01);
				lcd_string("SWITCH PRESSED");
				delay(1000);
				flag = 0;
		}
		else {
			lcd_cmd(0x01);
			lcd_string("NOT PRESSED");
			delay(1000);
	}
}
}
			
	
