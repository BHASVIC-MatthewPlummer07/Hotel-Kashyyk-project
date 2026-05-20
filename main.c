#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//declare global variables
char room1[10][16];
char room2[10][16];
char room3[10][16];
char room4[10][16];
char room5[10][16];
char room6[10][16];

char tableNaboo[2];
char tableEndor[2];
char tableTatooine[2];

//declare void subroutines
void mainMenu();
void checkIn();
void bookATable();
void tableAvailability();
void checkOut();
void encryption();

//main
int main(void) {
	//Initialises each table as free to book for
	tableEndor[0] = '0';
	tableEndor[1] = '0';
	tableNaboo[0] = '0';
	tableNaboo[1] = '0';
	tableTatooine[0] = '0';
	tableTatooine[1] = '0';

	//sets the room states to free
	room1[0][0] = 'f';
	room2[0][0] = 'f';
	room3[0][0] = 'f';
	room4[0][0] = 'f';
	room5[0][0] = 'f';
	room6[0][0] = 'f';

	printf("Welcome to Hotel Kashyyyk!\n");
	//initialises the main menu for the first time
    mainMenu();
    return 0;
}

//mainMenu
void mainMenu(void) {
	//local variables for mainMenu()
    int selection=0;

    //prints menu options
    printf("\n");
    printf("========================");
    printf("\nMain Menu");
    printf("\n========================");
    printf("\n[1] Check In [1]");
    printf("\n[2] Book A Table [2]");
    printf("\n[3] Check Out [3]");
    printf("\n========================");
    //inputs user choice and forwards to correct subroutine
    printf("\nEnter option: ");
    scanf(" %s", &selection);
	fflush(stdin);
	printf("\n");
    switch (selection) {
        case('1'):
            checkIn();
        break;
        case('2'):
            bookATable();
        break;
        case('3'):
            checkOut();
        break;
        default:
            printf("Error! Invalid Operation!\n");
        fflush(stdin);
        mainMenu();
        break;
    }
}
//checkIn

void checkIn(void){
//initialise local variables
	int availability_check=0;
	int room_selection=0;
	int room_selection_confirmed=0;
	int child_conversion=0;
	int adult_conversion=0;
	int valid = 0;
	int spaceCheck = 0;
	char dateCheck[3];
	char monthCheck[3];
	char yearCheck[5];
	int digitCheck = 0;

	//set up random function to work
	int random_number = rand() % 10;;
	srand(time(NULL));

	//available room check
	printf("========================");
	printf("\nCheck In");
	printf("\n========================\n");
	encryption();
	printf("\nAvailable Rooms (max room capacity: 4):");
	if (room1[0][0] == 'f') {
		printf("\nRoom 1: 100GBP per room, per day");
		availability_check=1;
	}
	if (room2[0][0] == 'f') {
		printf("\nRoom 2: 100GBP per room, per day");
		availability_check=1;
	}
	if (room3[0][0] == 'f') {
		printf("\nRoom 3: 85GBP per room, per day");
		availability_check=1;
	}
	if (room4[0][0] == 'f') {
		printf("\nRoom 4: 75GBP per room, per day");
		availability_check=1;
	}
	if (room5[0][0] == 'f') {
		printf("\nRoom 5: 75GBP per room, per day");
		availability_check=1;
	}
	if (room6[0][0] == 'f') {
		printf("\nRoom 6: 50GBP per room, per day");
		availability_check=1;
	}
	if (availability_check==0) {
		printf("\nNo rooms available, please check back later.\n");
		fflush(stdin);
		mainMenu();
	}
	fflush(stdin);

	//user room selection
	printf("\n");
	printf("Choose room number: ");
	scanf("%d", &room_selection);
	printf("\n");
	if (room_selection == 1 && room1[0][0] == 'f') {
		printf("Room selection confirmed.\n");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 2 && room2[0][0] == 'f'){
		printf("Room selection confirmed.\n");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 3 && room3[0][0] == 'f'){
		printf("Room selection confirmed.\n");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 4 && room4[0][0] == 'f'){
		printf("Room selection confirmed.\n");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 5 && room5[0][0] == 'f'){
		printf("Room selection confirmed.\n");
		room_selection_confirmed = room_selection;
	}
	else if (room_selection == 6 && room6[0][0] == 'f'){
		printf("Room selection confirmed.\n");
		room_selection_confirmed = room_selection;
	}
	else {
		printf("Either a room number was not entered correctly or the room number entered was not available.\n");
		fflush(stdin);
		mainMenu();
	}
	fflush(stdin);

	//enter personal details
	//room1
	if (room_selection_confirmed == 1) {
		//First name with validation
		while (valid == 0) {
			spaceCheck = 0;
			printf("\nEnter first name: ");
			gets(room1[0]);
			for (int i = 0; room1[0][i] != '\0'; i++) {
				if (strchr(room1[0], ' ') != NULL){
					spaceCheck = 1;
					break;
				}
			}
			if (spaceCheck == 1) {
				printf("\nInvalid first name (contains a space). Try again.");
			}
			else if (strlen(room1[0]) == 0) {
				printf("\nNo first name detected. Try again.");
			}
			else {
				valid = 1;
			}
		}
		valid = 0;

		//Last name with validation
		while (valid == 0) {
			spaceCheck = 0;
			printf("\nEnter last name: ");
			gets(room1[1]);
			for (int i = 0; room1[1][i] != '\0'; i++) {
				if (strchr(room1[1], ' ') != NULL){
					spaceCheck = 1;
					break;
				}
			}
			if (spaceCheck == 1) {
				printf("\nInvalid last name (contains a space). Try again.");
			}
			else if (strlen(room1[1]) == 0) {
				printf("\nNo last name detected. Try again.");
			}
			else {
				valid = 1;
			}
		}
		valid = 0;

		//DOB with validation
		while (valid == 0) {
			printf("\nEnter date of birth [DDMMYYYY]: ");
			gets(room1[2]);
			digitCheck = 0;
			sprintf(dateCheck, "%.2s", room1[2]);
			sprintf(monthCheck, "%.2s", room1[2] + 2);
			sprintf(yearCheck, "%.4s", room1[2] + 4);
			for (int i = 0; room1[2][i] != '\0'; i++){
				if (!isdigit(room1[2][i])) {
					digitCheck = 1;
				}
			}
			if (digitCheck == 1) {
				printf("\nInvalid DOB - only digits allowed - please try again in the format specified.");
			}
			else if (strlen(room1[2]) == 0) {
				printf("\nNo DOB detected. Try again.");
			}
			else if (strlen(room1[2]) > 8) {
				printf("\nToo many digits entered for DOB - please try again in the format specified.");
			}
			else if (strlen(room1[2]) < 8) {
				printf("\nToo few digits entered for DOB - please try again in the format specified.");
			}
			else if (atoi(yearCheck) > 2009) {
				printf("\nChildren can't book hotel rooms.");
			}
			else if (atoi(yearCheck) < 1900) {
				printf("\nInvalid age - too old.");
			}
			else if (atoi(monthCheck) > 12 || atoi(monthCheck) < 1){
				printf("\nInvalid month.");
			}
			else if (atoi(dateCheck) > 31 || atoi(dateCheck) < 1) {
				printf("\nInvalid date");
			}
			else {
				valid = 1;
			}

		}

		sprintf(room1[3], "%s%d", room1[1], random_number);
		printf("\nHere is your Booking ID: %s", room1[3]);

		printf("\n\nEnter board type (costs per day, per person)| Full Board 20GBP [f] | Half Board 15GBP [h] | Bed & Breakfast 5GBP [b]: ");
		scanf(" %c", &room1[4][0]);

		printf("\nEnter number of children (under 16): ");
		scanf(" %d", &child_conversion);

		printf("\nEnter number of adults: ");
		scanf(" %d", &adult_conversion);

		if (child_conversion + adult_conversion > 4) {
			printf("Error! Maximum room capacity exceeded (Maximum of 4 per room)!\n");
			room1[0][0] = 'f';
			mainMenu();
		} else {
			room1[5][0] = (child_conversion+adult_conversion) + 48;
		}
		room1[6][0] = child_conversion+48;
		room1[7][0] = adult_conversion+48;
		fflush(stdin);

		printf("\nEnter length of stay (in days): ");
		scanf(" %s", &room1[8]);

		valid = 0;

		while(valid == 0) {
			printf("\nWould you like to receive the daily newspaper (+5.50 GBP to bill)? [y/n]: ");
			scanf(" %s", room1[9]);
			fflush(stdin);
			if(strcmp(room1[9], "y") != 0 && strcmp(room1[9], "n") != 0) {
				printf("Enter either 'y' or 'n' ");
			}
			else {
				valid = 1;
			}
		}
		mainMenu();
		}

	//room2
	else if (room_selection_confirmed == 2) {
		printf("\nEnter first name: ");
		scanf(" %s", &room2[0]);

		printf("\nEnter last name: ");
		scanf(" %s", &room2[1]);

		printf("\nEnter date of birth [DDMMYYYY]: ");
		scanf(" %s", &room2[2]);

		sprintf(room2[3], "%s%d", room2[1], random_number);
		printf("\nHere is your Booking ID: %s", room2[3]);

		printf("\n\nEnter board type (costs per day, per person)| Full Board 20GBP [f] | Half Board 15GBP [h] | Bed & Breakfast 5GBP [b]: ");
		scanf(" %c", &room2[4][0]);

		printf("\nEnter number of children (under 16): ");
		scanf(" %d", &child_conversion);

		printf("\nEnter number of adults: ");
		scanf(" %d", &adult_conversion);

		if (child_conversion + adult_conversion > 4) {
			printf("Error! Maximum room capacity exceeded (Maximum of 4 per room)!\n");
			room2[0][0] = 'f';
			mainMenu();
		}
		else {
			room2[5][0] = (child_conversion+adult_conversion) + 48;
		}
		room2[6][0] = child_conversion+48;
		room2[7][0] = adult_conversion+48;

		fflush(stdin);

		printf("\nEnter length of stay (in days): ");
		scanf(" %s", &room2[8]);

		valid = 0;

		while(valid == 0) {
			printf("\nWould you like to receive the daily newspaper (+5.50 GBP to bill)? [y/n]: ");
			scanf(" %s", room2[9]);
			fflush(stdin);
			if(strcmp(room2[9], "y") != 0 && strcmp(room2[9], "n") != 0) {
				printf("Enter either 'y' or 'n' ");
			}
			else {
				valid = 1;
			}
		}
		mainMenu();
	}
	//room3
	else if (room_selection_confirmed == 3) {
		printf("\nEnter first name: ");
		scanf(" %s", &room3[0]);

		printf("\nEnter last name: ");
		scanf(" %s", &room3[1]);

		printf("\nEnter date of birth [DDMMYYYY]: ");
		scanf(" %s", &room3[2]);

		sprintf(room3[3], "%s%d", room3[1], random_number);
		printf("\nHere is your Booking ID: %s", room3[3]);

		printf("\n\nEnter board type (costs per day, per person)| Full Board 20GBP [f] | Half Board 15GBP [h] | Bed & Breakfast 5GBP [b]: ");
		scanf(" %c", &room3[4][0]);

		printf("\nEnter number of children (under 16): ");
		scanf(" %d", &child_conversion);

		printf("\nEnter number of adults: ");
		scanf(" %d", &adult_conversion);

		if (child_conversion + adult_conversion > 4) {
			printf("Error! Maximum room capacity exceeded (Maximum of 4 per room)!\n");
			room3[0][0] = 'f';
			mainMenu();
		} else {
			room3[5][0] = (child_conversion+adult_conversion) + 48;
		}
		room3[6][0] = child_conversion+48;
		room3[7][0] = adult_conversion+48;

		fflush(stdin);

		printf("\nEnter length of stay (in days): ");
		scanf(" %s", &room3[8]);

		valid = 0;

		while(valid == 0) {
			printf("\nWould you like to receive the daily newspaper (+5.50 GBP to bill)? [y/n]: ");
			scanf(" %s", room3[9]);
			fflush(stdin);
			if(strcmp(room3[9], "y") != 0 && strcmp(room3[9], "n") != 0) {
				printf("Enter either 'y' or 'n' ");
			}
			else {
				valid = 1;
			}
		}
		mainMenu();
	}
	//room4
	else if (room_selection_confirmed == 4) {
		printf("\nEnter first name: ");
		scanf(" %s", &room4[0]);

		printf("\nEnter last name: ");
		scanf(" %s", &room4[1]);

		printf("\nEnter date of birth [DDMMYYYY]: ");
		scanf(" %s", &room4[2]);

		sprintf(room4[3], "%s%d", room4[1], random_number);
		printf("\nHere is your Booking ID: %s", room4[3]);

		printf("\n\nEnter board type (costs per day, per person)| Full Board 20GBP [f] | Half Board 15GBP [h] | Bed & Breakfast 5GBP [b]: ");
		scanf(" %c", &room4[4][0]);

		printf("\nEnter number of children (under 16): ");
		scanf(" %d", &child_conversion);

		printf("\nEnter number of adults: ");
		scanf(" %d", &adult_conversion);

		if (child_conversion + adult_conversion > 4) {
			printf("Error! Maximum room capacity exceeded (Maximum of 4 per room)!\n");
			room4[0][0] = 'f';
			mainMenu();
		} else {
			room4[5][0] = (child_conversion+adult_conversion) + 48;
		}
		room4[6][0] = child_conversion+48;
		room4[7][0] = adult_conversion+48;

		fflush(stdin);

		printf("\nEnter length of stay (in days): ");
		scanf(" %s", &room4[8]);

		valid = 0;

		while(valid == 0) {
			printf("\nWould you like to receive the daily newspaper (+5.50 GBP to bill)? [y/n]: ");
			scanf(" %s", room4[9]);
			fflush(stdin);
			if(strcmp(room4[9], "y") != 0 && strcmp(room4[9], "n") != 0) {
				printf("Enter either 'y' or 'n' ");
			}
			else {
				valid = 1;
			}
		}
		mainMenu();
	}
	//room5
	else if (room_selection_confirmed == 5) {
		printf("\nEnter first name: ");
		scanf(" %s", &room5[0]);

		printf("\nEnter last name: ");
		scanf(" %s", &room5[1]);

		printf("\nEnter date of birth [DDMMYYYY]: ");
		scanf(" %s", &room5[2]);

		sprintf(room5[3], "%s%d", room5[1], random_number);
		printf("\nHere is your Booking ID: %s", room5[3]);

		printf("\n\nEnter board type (costs per day, per person)| Full Board 20GBP [f] | Half Board 15GBP [h] | Bed & Breakfast 5GBP [b]: ");
		scanf(" %c", &room5[4][0]);

		printf("\nEnter number of children (under 16): ");
		scanf(" %d", &child_conversion);

		printf("\nEnter number of adults: ");
		scanf(" %d", &adult_conversion);

		if (child_conversion + adult_conversion > 4) {
			printf("Error! Maximum room capacity exceeded (Maximum of 4 per room)!\n");
			room5[0][0] = 'f';
			mainMenu();
		} else {
			room5[5][0] = (child_conversion+adult_conversion) + 48;
		}
		room5[6][0] = child_conversion+48;
		room5[7][0] = adult_conversion+48;

		fflush(stdin);

		printf("\nEnter length of stay (in days): ");
		scanf(" %s", &room5[8]);

		valid = 0;

		while(valid == 0) {
			printf("\nWould you like to receive the daily newspaper (+5.50 GBP to bill)? [y/n]: ");
			scanf(" %s", room5[9]);
			fflush(stdin);
			if(strcmp(room5[9], "y") != 0 && strcmp(room5[9], "n") != 0) {
				printf("Enter either 'y' or 'n' ");
			}
			else {
				valid = 1;
			}
		}
		mainMenu();
	}
	//room6
	else if (room_selection_confirmed == 6) {
		printf("\nEnter first name: ");
		scanf(" %s", &room6[0]);

		printf("\nEnter last name: ");
		scanf(" %s", &room6[1]);

		printf("\nEnter date of birth [DDMMYYYY]: ");
		scanf(" %s", &room6[2]);

		sprintf(room6[3], "%s%d", room6[1], random_number);
		printf("\nHere is your Booking ID: %s", room6[3]);

		printf("\n\nEnter board type (costs per day, per person)| Full Board 20GBP [f] | Half Board 15GBP [h] | Bed & Breakfast 5GBP [b]: ");
		scanf(" %c", &room6[4][0]);

		printf("\nEnter number of children (under 16): ");
		scanf(" %d", &child_conversion);

		printf("\nEnter number of adults: ");
		scanf(" %d", &adult_conversion);

		if (child_conversion + adult_conversion > 4) {
			printf("Error! Maximum room capacity exceeded (Maximum of 4 per room)!\n");
			room6[0][0] = 'f';
			mainMenu();
		} else {
			room6[5][0] = (child_conversion+adult_conversion) + 48;
		}
		room6[6][0] = child_conversion+48;
		room6[7][0] = adult_conversion+48;

		fflush(stdin);

		printf("\nEnter length of stay (in days): ");
		scanf(" %s", &room6[8]);

		valid = 0;

		while(valid == 0) {
			printf("\nWould you like to receive the daily newspaper (+5.50 GBP to bill)? [y/n]: ");
			scanf(" %s", room6[9]);
			fflush(stdin);
			if(strcmp(room6[9], "y") != 0 && strcmp(room6[9], "n") != 0) {
				printf("Enter either 'y' or 'n' ");
			}
			else {
				valid = 1;
			}
		}
		mainMenu();
	}

	//else statement - should never have been seen by user
	else {
		printf("A non-user error has occurred.");
		printf("\nError Description:");
		printf("\n room_selection did not transferred correctly to room_selection_confirmed");
		fflush(stdin);
		mainMenu();
	}
}

void encryption(void) {
	printf("L");
	Sleep(200);
	printf("o");
	Sleep(200);
	printf("a");
	Sleep(200);
	printf("d");
	Sleep(200);
	printf("i");
	Sleep(200);
	printf("n");
	Sleep(200);
	printf("g ");
	Sleep(200);
	printf("e");
	Sleep(200);
	printf("n");
	Sleep(200);
	printf("c");
	Sleep(200);
	printf("r");
	Sleep(200);
	printf("y");
	Sleep(200);
	printf("p");
	Sleep(200);
	printf("t");
	Sleep(200);
	printf("i");
	Sleep(200);
	printf("o");
	Sleep(200);
	printf("n ");
	Sleep(200);
	printf("s");
	Sleep(200);
	printf("o");
	Sleep(200);
	printf("f");
	Sleep(200);
	printf("t");
	Sleep(200);
	printf("w");
	Sleep(200);
	printf("a");
	Sleep(200);
	printf("r");
	Sleep(200);
	printf("e");
	Sleep(200);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".\n");
	Sleep(400);
	printf("ERROR PLEASE CONTACT OUR CUSTOMER SUPPORT!\n");
	Sleep(2000);
	printf("LOL only joking.");
}
void bookATable(void) {
	printf("========================");
	printf("\nBook A Table\n");
	printf("========================\n");

	encryption();

    // Define user input booking number
    char Num[15];
    printf("\nEnter your booking ID: ");
    scanf("%s", &Num);

    // ROOM 1
    // Define existing booking number as single string
    char bookingNum1[15];
    for (int i = 0; i < 15; i++) {
        bookingNum1[i] = room1[3][i];
    }
    // Define existing guest numbers
    int guestNum1 = room1[5][0] - '0';

    // ROOM 2
    // Define existing booking number as single string
    char bookingNum2[15];
    for (int i = 0; i < 15; i++) {
        bookingNum2[i] = room2[3][i];
    }
    // Define existing guest numbers
    int guestNum2 = room2[5][0] - '0';

    // ROOM 3
    // Define existing booking number as single string
    char bookingNum3[15];
    for (int i = 0; i < 15; i++) {
        bookingNum3[i] = room3[3][i];
    }
    // Define existing guest numbers
    int guestNum3 = room3[5][0] - '0';

    // ROOM 4
    // Define existing booking number as single string
    char bookingNum4[15];
    for (int i = 0; i < 15; i++) {
        bookingNum4[i] = room4[3][i];
    }
    // Define existing guest numbers
    int guestNum4 = room4[5][0] - '0';

    // ROOM 5
    // Define existing booking number as single string
    char bookingNum5[15];
    for (int i = 0; i < 15; i++) {
        bookingNum5[i] = room5[3][i];
    }
    // Define existing guest numbers
    int guestNum5 = room5[5][0] - '0';

    // ROOM 6
    // Define existing booking number as single string
    char bookingNum6[15];
    for (int i = 0; i < 15; i++) {
        bookingNum6[i] = room6[3][i];
    }
    // Define existing guest numbers
    int guestNum6 = room6[5][0] - '0';
    // Variable to store if details are successful
    int success = 0;
    // Check booking number validity for room 1
    if (strcmp(Num, bookingNum1) == 0) {
        // Check board type validity for room1
        if (room1[4][0] != 'b') {
            // Check less than or 4 people in group
            if (guestNum1 > 4) {
                printf("Too many people in your group.\n");
                mainMenu();
            }
            else {
                // Print table availability
                success = 1;
                tableAvailability();
            }
        }
        else {
            printf("Invalid board type (only Half Board and Full Board can book a table).\n");
            mainMenu();
        }
    }
    // Check booking number validity for room 2
    else if (strcmp(Num, bookingNum2) == 0) {
        // Check board type validity for room 2
        if (room2[4][0] != 'b') {
            // Check less than or 4 people in group
            if (guestNum2 > 4) {
                printf("Too many people in your group.\n");
                mainMenu();
            }
            else {
                // Print table availability
                success = 1;
                tableAvailability();
            }
        }
        else {
            printf("Invalid board type (only Half Board and Full Board can book a table).\n");
            mainMenu();
        }
    }
    // Check booking number validity for room 3
    else if (strcmp(Num, bookingNum3) == 0) {
        // Check board type validity for room 3
        if (room3[4][0] != 'b') {
            // Check less than or 4 people in group
            if (guestNum3 > 4) {
                printf("Too many people in your group.\n");
                mainMenu();
            }
            else {
                // Print table availability
                success = 1;
                tableAvailability();
            }
        }
        else {
            printf("Invalid board type (only Half Board and Full Board can book a table).\n");
            mainMenu();
        }
    }
    // Check booking number validity for room 4
    else if (strcmp(Num, bookingNum4) == 0) {
        // Check board type validity for room 4
        if (room4[4][0] != 'b') {
            // Check less than or 4 people in group
            if (guestNum4 > 4) {
                printf("Too many people in your group.\n");
                mainMenu();
            }
            else {
                // Print table availability
                success = 1;
                tableAvailability();
            }
        }
        else {
            printf("Invalid board type (only Half Board and Full Board can book a table).\n");
            mainMenu();
        }
    }
    // Check booking number validity for room 5
    else if (strcmp(Num, bookingNum5) == 0) {
        // Check board type validity for room 5
        if (room5[4][0] != 'b') {
            // Check less than or 4 people in group
            if (guestNum5 > 4) {
                printf("Too many people in your group.\n");
                mainMenu();
            }
            else {
                // Print table availability
                success = 1;
                tableAvailability();
            }
        }
        else {
            printf("Invalid board type (only Half Board and Full Board can book a table).\n");
            mainMenu();
        }
    }
    // Check booking number validity for room 6
    else if (strcmp(Num, bookingNum6) == 0) {
        // Check board type validity for room 6
        if (room6[4][0] != 'b') {
            // Check less than or 4 people in group
            if (guestNum6 > 4) {
                printf("Too many people in your group.\n");
                mainMenu();
            }
            else {
                // Print table availability
                success = 1;
                tableAvailability();
            }
        }
        else {
            printf("Invalid board type (only Half Board and Full Board can book a table).\n");
            mainMenu();
        }
    }
    // Check if booking id was never valid
    else {
        printf("Invalid booking ID.\n");
        mainMenu();
    }

    // Ask what table the user wants and input
    if (success == 1) {
        int table;
        printf("\nWhich table? (1 for Naboo, 2 for Endor, 3 for Tatooine): ");
        scanf(" %d", &table);
    	fflush(stdin);
    	if(table <1 || table > 3) {
    		printf("Invalid table selected!");
    		mainMenu();
    	}
        // Ask what time the user wants and input
        int time;
        printf("\nWhich time do you want to book for? (1 for 19:00, 2 for 21:00) ");
        scanf(" %d", &time);
    	fflush(stdin);
    	time -= 1;
        // Check which table the user entered
    	if(time != 0 && time != 1) {
    		printf("Invalid time selected!\n");
    	}
        else if (table == 1) {
        	if(tableNaboo[time] == '1') {
        		printf("Table already booked for this time\n");
        	}
        	else {
        		tableNaboo[time] = '1';
        		printf("\nYour table has been booked.\n");
        	}
        }
        else if (table == 2) {
        	if(tableEndor[time] == '1') {
        		printf("Table already booked for this time.\n");
        	}
        	else {
        		tableEndor[time] = '1';
        		printf("\nYour table has been booked.\n");
        	}
        }
        else {
        	if(tableTatooine[time] == '1') {
        		printf("Table already booked for this time.\n");
        	}
        	else {
        		tableTatooine[time] = '1';
        		printf("\nYour table has been booked.\n");
        	}
        }
    	mainMenu();
    }
}

void tableAvailability() {
	int count = 0;
<<<<<<< HEAD
	printf("\n");
	printf("For 7pm:\n");
	if (tableNaboo[0] == '0') {
		printf("NABOO \n");
		printf("----------------- \n");
		printf("|               | \n");
		printf("|   AVAILABLE   | \n");
		printf("|               | \n");
		printf("----------------- \n");
		count += 1;
	}
	if (tableEndor[0] == '0') {
		printf("ENDOR \n");
		printf("----------------- \n");
		printf("|               | \n");
		printf("|   AVAILABLE   | \n");
		printf("|               | \n");
		printf("----------------- \n");
		count += 1;
	}
	if (tableTatooine[0] == '0') {
		printf("TATOOINE \n");
		printf("----------------- \n");
		printf("|               | \n");
		printf("|   AVAILABLE   | \n");
		printf("|               | \n");
		printf("----------------- \n");
		count += 1;
	}
	printf("For 9pm:\n");
	if (tableNaboo[1] == '0') {
		printf("NABOO \n");
		printf("----------------- \n");
		printf("|               | \n");
		printf("|   AVAILABLE   | \n");
		printf("|               | \n");
		printf("----------------- \n");
		count += 1;
	}
	if (tableEndor[1] == '0') {
		printf("ENDOR \n");
		printf("----------------- \n");
		printf("|               | \n");
		printf("|   AVAILABLE   | \n");
		printf("|               | \n");
		printf("----------------- \n");
		count += 1;
	}
	if (tableTatooine[1] == '0') {
		printf("TATOOINE \n");
		printf("----------------- \n");
		printf("|               | \n");
		printf("|   AVAILABLE   | \n");
		printf("|               | \n");
		printf("----------------- \n");
=======
	printf("========================\n");
	if (tableNaboo[0] == '0') {
		printf("Table Naboo is available for 19:00.\n");
		count += 1;
	}
	if (tableNaboo[1] == '0') {
		printf("Table Naboo is available for 21:00.\n");
		count += 1;
	}
	if (tableEndor[0] == '0') {
		printf("Table Endor is available for 19:00.\n");
		count += 1;
	}
	if (tableEndor[1] == '0') {
		printf("Table Endor is available for 21:00.\n");
		count += 1;
	}
	if (tableTatooine[0] == '0') {
		printf("Table Tatooine is available for 19:00.\n");
		count += 1;
	}
	if (tableTatooine[1] == '0') {
		printf("Table Tatooine is available for 21:00.\n");
>>>>>>> c7d52e23df4c13ab2d5ac8d7aae7508b56031580
		count += 1;
	}
	if (count==0) {
		printf("No tables available, check again later.\n");
		mainMenu();
	}
	printf("========================");
}

void checkOut() {
	printf("========================");
	printf("\nCheck Out");
	printf("\n========================");
	float totalCost = 0, roomCost, boardCost;
	char roomNo[1];
	//Goes through the whole calculating bill and presenting the bill part depending on the room entered.
	printf("\nEnter the room you have been staying in: ");
	scanf(" %s", &roomNo);
	fflush(stdin);
	//ROOM 1 CHECKOUT
	if (strcmp(roomNo, "1") == 0) {
		if (room1[0][0] == 'f') {
			printf("Unused room number\n");
			mainMenu();
		}
		//Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
		roomCost = 100 * atoi(room1[8]);
		//Adds the 10% discount to the room rate if the main user is over 65 years old:
		char ss[5];
		if (2025 - atoi(strncpy(ss, room1[2] + 4, 4)) >= 65) {
			roomCost *= 0.9;
			printf("\nMain user is 65 or more years old - 10%% discount applied to room rate");
		}
		totalCost += roomCost;
		//Adds the price of the board multiplied by the number of people and number of days stayed, and gives every child a 50% discount:
		if (strcmp(room1[4], "f") == 0) {
			boardCost = (20 * atoi(room1[8]) * atoi(room1[6]) / 2) + (20 * atoi(room1[8]) * atoi(room1[7]));
			//For reference - (20 * length of stay * no. of children / 2) + (20 * length of stay * no. of adults)
		}
		else if (strcmp(room1[4], "h") == 0) {
			boardCost = (15 * atoi(room1[8]) * atoi(room1[6]) / 2) + (15 * atoi(room1[8]) * atoi(room1[7]));
		}
		else if (strcmp(room1[4], "b") == 0) {
			boardCost = (5 * atoi(room1[8]) * atoi(room1[6]) / 2) + (5 * atoi(room1[8]) * atoi(room1[7]));
		}
		else {
			printf("ERROR - no board value in room1[4].\n");
			boardCost = 0;
		}
		if (atoi(room1[6]) > 0) {
			printf("\nThere are %d children (under 16) - 50%% discount applied to the board rate for each child", atoi(room1[6]));
		}
		totalCost += boardCost;
		//Displays the booking ID, the main guest's name and the final bill:
		printf("========================\n");
		printf("\nBooking ID: %s\n", room1[3]);
		printf("Main guest's name: %s %s\n", room1[0], room1[1]);
		printf("Room cost for %s days: %f GBP\n", room1[8], roomCost);
		printf("Board cost for %s days and %s people: %f GBP\n", room1[8], room1[5], boardCost);
		//Adds the price of the daily newspaper:
		if (strcmp(room1[9], "y") == 0) {
			totalCost += 5.5;
			printf("Daily newspaper: 5.50 GBP\n");
		}
		printf("========================\n");
		printf("Total cost: %f GBP\n", totalCost);
		printf("========================\n");
		//Clears the data for the user:
		memset(room1, 0, sizeof(room1));
		room1[0][0] = 'f';
		mainMenu();
	}
	//ROOM 2 CHECKOUT
	else if (strcmp(roomNo, "2") == 0) {
		if (room2[0][0] == 'f') {
			printf("Unused room number\n");
			mainMenu();
		}
		//Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
		roomCost = 100 * atoi(room2[8]);
		//Adds the 10% discount to the room rate if the main user is over 65 years old:
		char ss[5];
		if (2025 - atoi(strncpy(ss, room2[2] + 4, 4)) >= 65) {
			roomCost *= 0.9;
			printf("\nMain user is 65 or more years old - 10%% discount applied to room rate");
		}
		totalCost += roomCost;
		//Adds the price of the board multiplied by the number of people and number of days stayed, and gives every child a 50% discount:
		if (strcmp(room2[4], "f") == 0) {
			boardCost = (20 * atoi(room2[8]) * atoi(room2[6]) / 2) + (20 * atoi(room2[8]) * atoi(room2[7]));
			//For reference - (20 * length of stay * no. of children / 2) + (20 * length of stay * no. of adults)
		}
		else if (strcmp(room2[4], "h") == 0) {
			boardCost = (15 * atoi(room2[8]) * atoi(room2[6]) / 2) + (15 * atoi(room2[8]) * atoi(room2[7]));
		}
		else if (strcmp(room2[4], "b") == 0) {
			boardCost = (5 * atoi(room2[8]) * atoi(room2[6]) / 2) + (5 * atoi(room2[8]) * atoi(room2[7]));
		}
		else {
			printf("ERROR - no board value in room2[4].\n");
			boardCost = 0;
		}
		if (atoi(room2[6]) > 0) {
			printf("\nThere are %d children (under 16) - 50%% discount applied to the board rate for each child\n", atoi(room2[6]));
		}
		totalCost += boardCost;
		//Displays the booking ID, the main guest's name and the final bill:
		printf("\n");
		printf("Booking ID: %s\n", room2[3]);
		printf("Main guest's name: %s %s\n", room2[0], room2[1]);
		printf("Room cost for %s days: %f GBP\n", room2[8], roomCost);
		printf("Board cost for %s days and %s people: %f GBP\n", room2[8], room2[5], boardCost);
		//Adds the price of the daily newspaper:
		if (strcmp(room2[9], "y") == 0) {
			totalCost += 5.5;
			printf("Daily newspaper: 5.50 GBP\n");
		}
		printf("____________________________________________\n");
		printf("Total cost: %f POUNDS\n", totalCost);
		//Clears the data for the user:
		memset(room2, 0, sizeof(room2));
		room2[0][0] = 'f';
		mainMenu();
	}
	//ROOM 3 CHECKOUT
	else if (strcmp(roomNo, "3") == 0) {
		if (room3[0][0] == 'f') {
			printf("Unused room number\n");
			mainMenu();
		}
		//Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
		roomCost = 85 * atoi(room3[8]);
		//Adds the 10% discount to the room rate if the main user is over 65 years old:
		char ss[5];
		if (2025 - atoi(strncpy(ss, room3[2] + 4, 4)) >= 65) {
			roomCost *= 0.9;
			printf("\nMain user is 65 or more years old - 10%% discount applied to room rate");
		}
		totalCost += roomCost;
		//Adds the price of the board multiplied by the number of people and number of days stayed, and gives every child a 50% discount:
		if (strcmp(room3[4], "f") == 0) {
			boardCost = (20 * atoi(room3[8]) * atoi(room3[6]) / 2) + (20 * atoi(room3[8]) * atoi(room3[7]));
			//For reference - (20 * length of stay * no. of children / 2) + (20 * length of stay * no. of adults)
		}
		else if (strcmp(room3[4], "h") == 0) {
			boardCost = (15 * atoi(room3[8]) * atoi(room3[6]) / 2) + (15 * atoi(room3[8]) * atoi(room3[7]));
		}
		else if (strcmp(room3[4], "b") == 0) {
			boardCost = (5 * atoi(room3[8]) * atoi(room3[6]) / 2) + (5 * atoi(room3[8]) * atoi(room3[7]));
		}
		else {
			printf("ERROR - no board value in room3[4].\n");
			boardCost = 0;
		}
		if (atoi(room3[6]) > 0) {
			printf("\nThere are %d children (under 16) - 50%% discount applied to the board rate for each child\n", atoi(room3[6]));
		}
		totalCost += boardCost;
		//Displays the booking ID, the main guest's name and the final bill:
		printf("\n");
		printf("Booking ID: %s\n", room3[3]);
		printf("Main guest's name: %s %s\n", room3[0], room3[1]);
		printf("Room cost for %s days: %f GBP\n", room3[8], roomCost);
		printf("Board cost for %s days and %s people: %f GBP\n", room3[8], room3[5], boardCost);
		//Adds the price of the daily newspaper:
		if (strcmp(room3[9], "y") == 0) {
			totalCost += 5.5;
			printf("Daily newspaper: 5.50 GBP\n");
		}
		printf("____________________________________________\n");
		printf("Total cost: %f GBP\n", totalCost);
		//Clears the data for the user:
		memset(room3, 0, sizeof(room3));
		room3[0][0] = 'f';
		mainMenu();
	}
	//ROOM 4 CHECKOUT
	else if (strcmp(roomNo, "4") == 0) {
		if (room4[0][0] == 'f') {
			printf("Unused room number\n");
			mainMenu();
		}
		//Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
		roomCost = 75 * atoi(room4[8]);
		//Adds the 10% discount to the room rate if the main user is over 65 years old:
		char ss[5];
		if (2025 - atoi(strncpy(ss, room4[2] + 4, 4)) >= 65) {
			roomCost *= 0.9;
			printf("\nMain user is 65 or more years old - 10%% discount applied to room rate");
		}
		totalCost += roomCost;
		//Adds the price of the board multiplied by the number of people and number of days stayed, and gives every child a 50% discount:
		if (strcmp(room4[4], "f") == 0) {
			boardCost = (20 * atoi(room4[8]) * atoi(room4[6]) / 2) + (20 * atoi(room4[8]) * atoi(room4[7]));
			//For reference - (20 * length of stay * no. of children / 2) + (20 * length of stay * no. of adults)
		}
		else if (strcmp(room4[4], "h") == 0) {
			boardCost = (15 * atoi(room4[8]) * atoi(room4[6]) / 2) + (15 * atoi(room4[8]) * atoi(room4[7]));
		}
		else if (strcmp(room4[4], "b") == 0) {
			boardCost = (5 * atoi(room4[8]) * atoi(room4[6]) / 2) + (5 * atoi(room4[8]) * atoi(room4[7]));
		}
		else {
			printf("ERROR - no board value in room4[4].\n");
			boardCost = 0;
		}
		if (atoi(room4[6]) > 0) {
			printf("\nThere are %d children (under 16) - 50%% discount applied to the board rate for each child\n", atoi(room4[6]));
		}
		totalCost += boardCost;
		//Displays the booking ID, the main guest's name and the final bill:
		printf("\n");
		printf("Booking ID: %s\n", room4[3]);
		printf("Main guest's name: %s %s\n", room4[0], room4[1]);
		printf("Room cost for %s days: %f GBP\n", room4[8], roomCost);
		printf("Board cost for %s days and %s people: %f GBP\n", room4[8], room4[5], boardCost);
		//Adds the price of the daily newspaper:
		if (strcmp(room4[9], "y") == 0) {
			totalCost += 5.5;
			printf("Daily newspaper: 5.50 GBP\n");
		}
		printf("____________________________________________\n");
		printf("Total cost: %f GBP\n", totalCost);
		//Clears the data for the user:
		memset(room4, 0, sizeof(room4));
		room4[0][0] = 'f';
		mainMenu();
	}
	//ROOM 5 CHECKOUT
	else if (strcmp(roomNo, "5") == 0) {
		if (room5[0][0] == 'f') {
			printf("Unused room number\n");
			mainMenu();
		}
		//Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
		roomCost = 75 * atoi(room5[8]);
		//Adds the 10% discount to the room rate if the main user is over 65 years old:
		char ss[5];
		if (2025 - atoi(strncpy(ss, room5[2] + 4, 4)) >= 65) {
			roomCost *= 0.9;
			printf("\nMain user is 65 or more years old - 10%% discount applied to room rate");
		}
		totalCost += roomCost;
		//Adds the price of the board multiplied by the number of people and number of days stayed, and gives every child a 50% discount:
		if (strcmp(room5[4], "f") == 0) {
			boardCost = (20 * atoi(room5[8]) * atoi(room5[6]) / 2) + (20 * atoi(room5[8]) * atoi(room5[7]));
			//For reference - (20 * length of stay * no. of children / 2) + (20 * length of stay * no. of adults)
		}
		else if (strcmp(room5[4], "h") == 0) {
			boardCost = (15 * atoi(room5[8]) * atoi(room5[6]) / 2) + (15 * atoi(room5[8]) * atoi(room5[7]));
		}
		else if (strcmp(room5[4], "b") == 0) {
			boardCost = (5 * atoi(room5[8]) * atoi(room5[6]) / 2) + (5 * atoi(room5[8]) * atoi(room5[7]));
		}
		else {
			printf("ERROR - no board value in room5[4].\n");
			boardCost = 0;
		}
		//Shows the user that there is a 50% discount to board cost for any children
		if (atoi(room5[6]) > 0) {
			printf("\nThere are %d children (under 16) - 50%% discount applied to the board rate for each child\n", atoi(room5[6]));
		}
		totalCost += boardCost;
		//Displays the booking ID, the main guest's name and the final bill:
		printf("\n");
		printf("Booking ID: %s\n", room5[3]);
		printf("Main guest's name: %s %s\n", room5[0], room5[1]);
		printf("Room cost for %s days: %f GBP\n", room5[8], roomCost);
		printf("Board cost for %s days and %s people: %f GBP\n", room5[8], room5[5], boardCost);
		//Adds the price of the daily newspaper:
		if (strcmp(room5[9], "y") == 0) {
			totalCost += 5.5;
			printf("Daily newspaper: 5.50 GBP\n");
		}
		printf("____________________________________________\n");
		printf("Total cost: %f POUNDS\n", totalCost);
		//Clears the data for the user:
		memset(room5, 0, sizeof(room5));
		room5[0][0] = 'f';
		mainMenu();
	}
	//ROOM 6 CHECKOUT
	else if (strcmp(roomNo, "6") == 0) {
		if (room6[0][0] == 'f') {
			printf("Unused room number\n");
			mainMenu();
		}
		//Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
		roomCost = 50 * atoi(room6[8]);
		//Adds the 10% discount to the room rate if the main user is over 65 years old:
		char ss[5];
		if (2025 - atoi(strncpy(ss, room6[2] + 4, 4)) >= 65) {
			roomCost *= 0.9;
			printf("\nMain user is 65 or more years old - 10%% discount applied to room rate");
		}
		totalCost += roomCost;
		//Adds the price of the board multiplied by the number of people and number of days stayed, and gives every child a 50% discount:
		if (strcmp(room6[4], "f") == 0) {
			boardCost = (20 * atoi(room6[8]) * atoi(room6[6]) / 2) + (20 * atoi(room6[8]) * atoi(room6[7]));
			//For reference - (20 * length of stay * no. of children / 2) + (20 * length of stay * no. of adults)
		}
		else if (strcmp(room6[4], "h") == 0) {
			boardCost = (15 * atoi(room6[8]) * atoi(room6[6]) / 2) + (15 * atoi(room6[8]) * atoi(room6[7]));
		}
		else if (strcmp(room6[4], "b") == 0) {
			boardCost = (5 * atoi(room6[8]) * atoi(room6[6]) / 2) + (5 * atoi(room6[8]) * atoi(room6[7]));
		}
		else {
			printf("\nERROR - no board value in room6[4].");
			boardCost = 0;
		}
		//Shows the user that there is a 50% discount to board cost for any children
		if (atoi(room6[6]) > 0) {
			printf("\nThere are %d children (under 16) - 50%% discount applied to the board rate for each child\n", atoi(room6[6]));
		}
		totalCost += boardCost;
		//Displays the booking ID, the main guest's name and the final bill:
		printf("\n");
		printf("Booking ID: %s\n", room6[3]);
		printf("Main guest's name: %s %s\n", room6[0], room6[1]);
		printf("Room cost for %s days: %f GBP\n", room6[8], roomCost);
		printf("Board cost for %s days and %s people: %f GBP\n", room6[8], room6[5], boardCost);
		//Adds the price of the daily newspaper:
		if (strcmp(room6[9], "y") == 0) {
			totalCost += 5.5;
			printf("Daily newspaper: 5.50 GBP\n");
		}
		printf("____________________________________________\n");
		printf("Total cost: %f GBP\n", totalCost);
		//Clears the data for the user:
		memset(room6, 0, sizeof(room6));
		room6[0][0] = 'f';
		mainMenu();
	}
	else {
		printf("Invalid room number.\n");
	}
	//End of checkout
	mainMenu();

}