#include <avr/io.h>
#include <avr/interrupt.h>


int main(void){
	DDRB=0xFF;                //PORTB la output PORT
	PORTB=0x00;	
	
	
    DDRD=0x00; //khai bao PORTD la input de ket noi Button kich vao chan T1 
	PORTD=0xFF; //su dung dien tro keo len cho PORTD
    
	TCCR1B=(1<<CS12)|(1<<CS11); // CS12=1, CS11=1, CS00=0: xung nhip tu //chan T1, canh xuong

	while (1){           //vòng l?p vô t?n	
		if (TCNT1==10) TCNT1=0;
        PORTB=TCNT1;   //xuat gia tri dem ra led 7 doan
        if (bit_is_clear(PIND,7)) TCNT1=0;  //Reset bo dem neu chan PD7=0
	}
}
