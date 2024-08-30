#include <avr/io.h>
#include "lcd.h"
#include "keypad.h"
typedef struct {
	char id[5];
	char pass[5];
	char name[9];
} user;
user users[4] = {
	{"0001", "1111", "john"},
	{"0002", "2222", "Rito"},
	{"0003", "3333", "rahaf"},
	{"0004", "4444", "tifa"}
};
char enter(char get[]){
	char i=0;
	while(1){
		char ch=keypad_scan();
		get[i]=ch;
		i++;
		if (i>=4){
			get[i] = '\0';
			break;
		}
	}
}

char check_id(char getid[]) {
	char i=0;
	for (; i < 4; i++) {
		int match = 1;
		for (int j = 0;j<4; j++) {
			if (getid[j] != users[i].id[j]) {
				match = 0;
				break;
			}
		}
		if (match==1){
			return i ;
		}
	}
			lcd_cmd(0xC0);
			lcd_str("wrong ID");
			return 'w';
}
char check_pass(char getpass[],char usernum) {
		char match = '1';
		for (int i = 0;i<4; i++) {
			if (getpass[i] != users[usernum].pass[i]) {
				match = '0';
				break;
			}
		}
			return match ;
	}
void toggle(char pin){
	PORTB^=1<<pin;
	_delay_ms(200);
	PORTB^=1<<pin;
	_delay_ms(200);
	PORTB^=1<<pin;
	_delay_ms(200);
	PORTB^=1<<pin;
	_delay_ms(200);
	PORTB^=1<<pin;
	_delay_ms(200);
	PORTB^=1<<pin;
	_delay_ms(200);
}
int main(void){
	lcd_init();
	DDRB=0xff;
	while (1){
		PORTB|=1<<2;
		PORTB&=~(1<<3);
		PORTB&=~(1<<0);
		PORTB&=~(1<<1);
		char getid[5];
		lcd_cmd(0x80);
		lcd_str("ID :");
		enter(getid);
		char usernum= check_id(getid);
		if (usernum != 'w'){
			_delay_ms(1000);
			lcd_cmd(0x01);
			char getpass[5];
			lcd_cmd(0x80);
			lcd_str("password :");
			enter(getpass);
			char checkpass = check_pass(getpass,usernum);
				if (checkpass == '0'){
					lcd_cmd(0xC0);
					lcd_str("wrong password");
					toggle(2);
					lcd_cmd(0x01);
				}else{
					lcd_cmd(0xC0);
					lcd_str("welcome !");
					_delay_ms(250);
					lcd_cmd(0x01);
					lcd_cmd(0x80);
					lcd_str("Hello ");
					lcd_str(users[usernum].name);
					PORTB^=1<<2;
					PORTB^=1<<3;
					
					PORTB^=1<<0;
					toggle(3);
					_delay_ms(2500);
					PORTB^=1<<0;
					PORTB^=1<<1;
					_delay_ms(2500);
					PORTB^=1<<1;
					lcd_cmd(0x01);
				}
		}else{
			toggle(2);
			lcd_cmd(0x01);
		}
    }
}