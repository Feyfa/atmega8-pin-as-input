#include <avr/io.h>

int main(void)
{
	// Make PB0 And PB1 As Output
	DDRB |= 1 << 0 | 1 << 1;
	
	// Make PC0 And PC1 As Input
	DDRC &= ~(1 << 0 | 1 << 1);
	
	// Write Logic High To PC0 And PC1, This Aims To Make PC0 And PC1 As Pull Up Mode Inputs
	PORTC |= 1 << 0 | 1 << 1;
	
    while (1)
    {
		/*
		- When PC0 Is 0 Or When The Switch Is Pressed
		- !(PINC & (1 << 0))
		- !(11111110 & 00000001)
		- !(00000000)
		- !(0)
		- 1
		*/
		if(!(PINC & (1 << 0)))
		{
			// PB0 HIGH
			PORTB |= 1 << 0;
		}
		
		/*
		- When PC0 Is 1 Or When The Switch Has Not Been Pressed
		- !(PINC & (1 << 0))
		- !(11111111 & 00000001)
		- !(00000001)
		- !(1)
		- 0
		- There Is No Need To Write This Condition Again, Because It Has Been Resolved Using else, This Is Just To Know How It Works
		*/
		else
		{
			// PB0 LOW
			PORTB &= ~(1 << 0);
		}
		
		
		
		
		
		/*
		- When PC1 Is 0 Or When The Switch Is Pressed
		- !(PINC & (1 << 1))
		- !(11111101 & 00000010)
		- !(00000000)
		- !(0)
		- 1
		*/
		if(!(PINC & (1 << 1))) 
		{
			// PB1 HIGH
			PORTB |= 1 << 1;	
		}
		
		/*
		- When PC1 Is 1 Or When The Switch Has Not Been Pressed
		- !(PINC & (1 << 0))
		- !(11111111 & 00000010)
		- !(00000010)
		- !(2)
		- 0
		- There Is No Need To Write This Condition Again, Because It Has Been Resolved Using else, This Is Just To Know How It Works
		*/
		else
		{
			// PB1 LOW
			PORTB &= ~(1 << 1);	
		}
			
    }
}

