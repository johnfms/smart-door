/*
 * keypad.h
 *
 * Created: 10/8/2024 6:34:14 PM
 *  Author: john
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>        // Include AVR input/output library for I/O operations
#include <util/delay.h>    // Include delay utility for timing functions

// Define the port, pin, and data direction register for the keypad
#define KEYPAD_PORT     PORTA
#define KEYPAD_PIN      PINA
#define KEYPAD_DDR      DDRA

// Define masks for rows and columns of the keypad
#define KEYPAD_ROW_MASK 0x0F    // Mask for rows (lower 4 bits)
#define KEYPAD_COL_MASK 0xF0    // Mask for columns (upper 4 bits)

// Define the keypad layout in a 4x4 matrix
/*char keypad[4][4] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};*/
char keypad[4][4] = {
	{'+', '-', '*', '/'},
	{'=', '3', '6','9'},
	{'0', '2', '5','8'},
	{'c', '1', '4','7'}
};
// Function to read the pressed key on the keypad
char readKeypad()
{
	while(1)
	{
		// Loop through the columns
		
		for (int col = 0; col < 4; col++)
		{
			// Set data direction for columns and activate a single column
			KEYPAD_DDR = KEYPAD_COL_MASK;
			KEYPAD_PORT = ~(1 << (col + 4));  // Shift to the correct column position
			
			// Check each row for a pressed key
			for (int row = 0; row < 4; row++)
			{
				// If a key is pressed in the current row
				if (!(KEYPAD_PIN & (1 << row)))
				{
					// Wait for key release
					while (!(KEYPAD_PIN & (1 << row)));
					// Return the corresponding character from the keypad matrix
					return keypad[row][col];
				}
			}
		}
		
	}
	return 0;  // This line should technically never be reached
}

// Function to scan the keypad and return the pressed key
char keypad_scan()
{
	char key = readKeypad();  // Read the pressed key
	if (key != 0)
	{
		// Display the pressed key on the LCD (assuming LCD_DISPLAY_CHAR is defined elsewhere)
		lcd_char(key);
	}
	
	return key;  // Return the pressed key
}

#endif /* KEYPAD_H_ */