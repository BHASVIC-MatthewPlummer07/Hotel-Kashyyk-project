#include <stdio.h>

char room1[10][16];
char room2[10][16];
char room3[10][16];
char room4[10][16];
char room5[10][16];
char room6[10][16];

void mainMenu();
void checkIn();
void checkOut();
void bookAtable();

int main(void){
	mainMenu();
	return 0;
}

void checkIn(void){
	printf("checkIn");
}

void checkOut(void){
	printf("checkOut");
}
void bookAtable(void){
	printf("bookAtable");
}

void mainMenu(void) {
	//local variables for mainMenu()
	int selection=0;

	//prints menu options
	printf("\n");
	printf("========================");
	printf("\nMain Menu");
	printf("\n========================");
	printf("\n[1] Check In [1]");
	printf("\n[2] Check Out [2]");
	printf("\n[3] Book A Room [3]");
	printf("\n========================");
	//inputs user choice and forwards to correct subroutine
	printf("\nEnter option: ");
	scanf(" %d", &selection);
	switch (selection) {
		case(1):
			checkIn();
			break;
		case(2):
			checkOut();
			break;
		case(3):
			bookAtable();
			break;
		default:
			printf("Error! Invalid Operation!");
			mainMenu();
			break;
	}
}

