#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
for (int i = 0; i < 10; i++) {
	switch (i) {
		case 0:
			printf("room1[%d] (First Name): %s\n", i, room1[i]);
			break;
		case 1:
			printf("room1[%d] (Last Name):  %s\n", i, room1[i]);
			break;
		case 2:
			printf("room1[%d] (DOB):        %s\n", i, room1[i]);
			break;
		case 3:
			printf("room1[%d] (Booking ID): %s\n", i, room1[i]);
			break;
		case 4:
			printf("room1[%d] (Board Type): %s\n", i, room1[i]);
			break;
		case 5:
			printf("room1[%d] (Total Guests): %s\n", i, room1[i]);
			break;
		case 6:
			printf("room1[%d] (Under 16s): %s\n", i, room1[i]);
			break;
		case 7:
			printf("room1[%d] (Adults):    %s\n", i, room1[i]);
			break;
		case 8:
			printf("room1[%d] (Length of Stay): %s\n", i, room1[i]);
			break;
		case 9:
			printf("room1[%d] (Newspaper): %s\n", i, room1[i]);
			break;
		default:
			printf("room1[%d]: %s\n", i, room1[i]);
			break;
	}