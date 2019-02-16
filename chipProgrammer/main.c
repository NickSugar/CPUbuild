/*
 * main.c
 * 
 * Copyright 2019  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char **argv)
{
	wiringPiSetupGpio();
	
	int pins[8];
	pins[0] = 4;
	pins[1] = 14;
	pins[2] = 15;
	pins[3] = 17;
	pins[4] = 18;
	pins[5] = 27;
	pins[6] = 22;
	pins[7] = 23;

	int k;
	for(k = 0; k < 8; k++){
		pinMode(pins[k], OUTPUT);
	}

	for(int i = 0; i < 8; i++){
		digitalWrite(pins[i], 0);	
	}

	int inputBits[8];
	
	printf("\nInput 8 bits one at a time and hit enter\nLeast significant bit first\n");

	for(int i = 0; i < 8; i++){
		scanf("%d", &inputBits[i]);
		digitalWrite(pins[i], inputBits[i]);	
	}

	printf("You have entered: ");
	for (int i = 7; i >= 0; i--){
		printf("%d", inputBits[i]);	
	}
	printf("\n");
	
	return 0;
}

