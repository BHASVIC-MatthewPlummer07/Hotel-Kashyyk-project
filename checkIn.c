#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//delcare variables
char room1[10][16];
char room2[10][16];
char room3[10][16];
char room4[10][16];
char room5[10][16];
char room6[10][16];

 void checkIn();
//void checkIn() {};

int main(void) {
	room1[0][0] ='f';
	room2[0][0] ='f';
	room3[0][0] ='f';
	room4[0][0] ='f';
	room5[0][0] ='f';
	room6[0][0] ='f';
	checkIn();
	return 0;
}

void checkIn() {
	//initalise local variables
	int availablity_check=0;
	int room_selection=0;
	int room_selection_confirmed=0;
	int child_conversion=0;
	int adult_conversion=0;
	char bookingID_temp='0';

	//set up random function to work
	int random_number;
	srand(time(NULL));
	random_number = rand() % 10;

	//available room check
	printf("\n");
	printf("========================");
	printf("\nCheck In");
	printf("\n========================");
	printf("\nAvailable Rooms");
	if (room1[0][0] == 'f') {
		printf("\nRoom 1: £100");
		availablity_check=1;
	}
	if (room2[0][0] == 'f') {
		printf("\nRoom 2: £100");
		availablity_check=1;
	}
	if (room3[0][0] == 'f') {
		printf("\nRoom 3: £85");
		availablity_check=1;
	}
	if (room4[0][0] == 'f') {
		printf("\nRoom 4: £75");
		availablity_check=1;
	}
	if (room5[0][0] == 'f') {
		printf("\nRoom 5: £75");
		availablity_check=1;
	}
	if (room6[0][0] == 'f') {
		printf("\nRoom 6: £50");
		availablity_check=1;
	}
	if (availablity_check==0) {
		printf("\nNo rooms available, please check back later.");
		//mainMenu();
	}

	//user room selection
	printf("\n");
	printf("Enter room number: ");
	scanf("%d", &room_selection);
	if (room_selection == 1 && room1[0][0] == 'f'){
		printf("Room selection confirmed.");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 2 && room2[0][0] == 'f'){
		printf("Room selection confirmed.");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 3 && room3[0][0] == 'f'){
		printf("Room selection confirmed.");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 4 && room4[0][0] == 'f'){
		printf("Room selection confirmed.");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 5 && room5[0][0] == 'f'){
		printf("Room selection confirmed.");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 6 && room6[0][0] == 'f'){
		printf("Room selection confirmed.");
		room_selection_confirmed = room_selection;
	}
	else {
		printf("Either a room number was not entered correctly or the room number entered was not available.");
		//mainMenu();
	}

		//enter personal details
		//room1
		if (room_selection_confirmed == 1) {
			printf("\n Enter first name: ");
			scanf(" %s", room1[0]);

			printf("\n Enter last name: ");
			scanf(" %s", room1[1]);

			printf("\n Enter date of birth: ");
			scanf(" %s", room1[2]);

			sprintf(room1[3], "%s%d", room1[1], random_number);
			printf("\n Booking ID: %s", room1[3]);

			printf("\n Enter board type | Full Board £20 [f] | Half Board £15 [h] | Bed & Breakfast £5 [b]: ");
			scanf(" %c", &room1[4][0]);

			printf("Enter number of under 16s: ");
			scanf(" %d", &child_conversion);

			printf("Enter number of adults: ");
			scanf(" %d", &adult_conversion);

			if (child_conversion + adult_conversion > 4) {
				printf("Error! Maximum room capacity exceeded!");
				//mainMenu();
			} else {
				room1[5][0] = (child_conversion+adult_conversion) + 48;
			}
			room1[6][0] = child_conversion+48;
			room1[7][0] = adult_conversion+48;

			printf("Enter length of stay: ");
			scanf(" %c", &room1[8]);

			printf("Would you like to recieve the daily newspaper?: ");
			scanf(" %c", room1[9]);
			}

		//room2
		else if (room_selection_confirmed == 2) {
			printf("\n Enter first name: ");
			scanf(" %s", &room2[0]);

			printf("\n Enter last name: ");
			scanf(" %s", &room2[1]);

			printf("\n Enter date of birth: ");
			scanf(" %s", &room2[2]);

			sprintf(room2[3], "%s%d", room2[1], random_number);
			printf("\n Booking ID: %s", room2[3]);

			printf("\n Enter board type | Full Board £20 [f] | Half Board £15 [h] | Bed & Breakfast £5 [b]: ");
			scanf(" %c", &room2[4][0]);

			printf("Enter number of under 16s: ");
			scanf(" %d", &child_conversion);

			printf("Enter number of adults: ");
			scanf(" %d", &adult_conversion);

			if (child_conversion + adult_conversion > 4) {
				printf("Error! Maximum room capacity exceeded!");
				//mainMenu();
			}
			else {
				room2[5][0] = (child_conversion+adult_conversion) + 48;
			}
			room2[6][0] = child_conversion+48;
			room2[7][0] = adult_conversion+48;

			printf("Enter length of stay: ");
			scanf(" %c", &room2[8]);

			printf("Would you like to recieve the daily newspaper?: ");
			scanf(" %c", &room2[9]);
		}
		//room3
		else if (room_selection_confirmed == 3) {
			printf("\n Enter first name: ");
			scanf(" %s", &room3[0]);

			printf("\n Enter last name: ");
			scanf(" %s", &room3[1]);

			printf("\n Enter date of birth: ");
			scanf(" %s", &room3[2]);

			sprintf(room3[3], "%s%d", room3[1], random_number);
			printf("\n Booking ID: %s", room3[3]);

			printf("\n Enter board type | Full Board £20 [f] | Half Board £15 [h] | Bed & Breakfast £5 [b]: ");
			scanf(" %c", &room3[4][0]);

			printf("Enter number of under 16s: ");
			scanf(" %d", &child_conversion);

			printf("Enter number of adults: ");
			scanf(" %d", &adult_conversion);

			if (child_conversion + adult_conversion > 4) {
				printf("Error! Maximum room capacity exceeded!");
				//mainMenu();
			} else {
				room3[5][0] = (child_conversion+adult_conversion) + 48;
			}
			room3[6][0] = child_conversion+48;
			room3[7][0] = adult_conversion+48;

			printf("Enter length of stay: ");
			scanf(" %c", &room3[8]);

			printf("Would you like to recieve the daily newspaper?: ");
			scanf(" %c", &room3[9]);
		}
		//room4
		else if (room_selection_confirmed == 4) {
			printf("\n Enter first name: ");
			scanf(" %s", &room4[0]);

			printf("\n Enter last name: ");
			scanf(" %s", &room4[1]);

			printf("\n Enter date of birth: ");
			scanf(" %s", &room4[2]);

			sprintf(room4[3], "%s%d", room4[1], random_number);
			printf("\n Booking ID: %s", room4[3]);

			printf("\n Enter board type | Full Board £20 [f] | Half Board £15 [h] | Bed & Breakfast £5 [b]: ");
			scanf(" %c", &room4[4][0]);

			printf("Enter number of under 16s: ");
			scanf(" %d", &child_conversion);

			printf("Enter number of adults: ");
			scanf(" %d", &adult_conversion);

			if (child_conversion + adult_conversion > 4) {
				printf("Error! Maximum room capacity exceeded!");
				//mainMenu();
			} else {
				room4[5][0] = (child_conversion+adult_conversion) + 48;
			}
			room4[6][0] = child_conversion+48;
			room4[7][0] = adult_conversion+48;

			printf("Enter length of stay: ");
			scanf(" %c", &room4[8]);

			printf("Would you like to recieve the daily newspaper?: ");
			scanf(" %c", &room4[9]);
		}
		//room5
		else if (room_selection_confirmed == 5) {
			printf("\n Enter first name: ");
			scanf(" %s", &room5[0]);

			printf("\n Enter last name: ");
			scanf(" %s", &room5[1]);

			printf("\n Enter date of birth: ");
			scanf(" %s", &room5[2]);

			sprintf(room5[3], "%s%d", room5[1], random_number);
			printf("\n Booking ID: %s", room5[3]);

			printf("\n Enter board type | Full Board £20 [f] | Half Board £15 [h] | Bed & Breakfast £5 [b]: ");
			scanf(" %c", &room5[4][0]);

			printf("Enter number of under 16s: ");
			scanf(" %d", &child_conversion);

			printf("Enter number of adults: ");
			scanf(" %d", &adult_conversion);

			if (child_conversion + adult_conversion > 4) {
				printf("Error! Maximum room capacity exceeded!");
				//mainMenu();
			} else {
				room5[5][0] = (child_conversion+adult_conversion) + 48;
			}
			room5[6][0] = child_conversion+48;
			room5[7][0] = adult_conversion+48;

			printf("Enter length of stay: ");
			scanf(" %c", &room5[8]);

			printf("Would you like to recieve the daily newspaper?: ");
			scanf(" %c", &room5[9]);
		}
		//room6
		else if (room_selection_confirmed == 6) {
			printf("\n Enter first name: ");
			scanf(" %s", &room6[0]);

			printf("\n Enter last name: ");
			scanf(" %s", &room6[1]);

			printf("\n Enter date of birth: ");
			scanf(" %s", &room6[2]);

			sprintf(room6[3], "%s%d", room6[1], random_number);
			printf("\n Booking ID: %s", room6[3]);

			printf("\n Enter board type | Full Board £20 [f] | Half Board £15 [h] | Bed & Breakfast £5 [b]: ");
			scanf(" %c", &room6[4][0]);

			printf("Enter number of under 16s: ");
			scanf(" %d", &child_conversion);

			printf("Enter number of adults: ");
			scanf(" %d", &adult_conversion);

			if (child_conversion + adult_conversion > 4) {
				printf("Error! Maximum room capacity exceeded!");
				//mainMenu();
			} else {
				room6[5][0] = (child_conversion+adult_conversion) + 48;
			}
			room6[6][0] = child_conversion+48;
			room6[7][0] = adult_conversion+48;

			printf("Enter length of stay: ");
			scanf(" %c", &room6[8]);

			printf("Would you like to recieve the daily newspaper?: ");
			scanf(" %c", &room6[9]);
				//return to mainMenu
				//mainMenu();
			}
		//else statement - should never been seen by user
		else {
			printf("A non-user error has occured.");
			printf("\nError Description:");
			printf("\nroom_selection did not transferred correctly to room_selection_confirmed");
			//mainMenu();
		}
	}
