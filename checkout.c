#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Here are the initialised room arrays:
char room1[10][16];
char room2[10][16];
char room3[10][16];
char room4[10][16];
char room5[10][16];
char room6[10][16];




int main(void){
    float totalCost = 0, roomCost, boardCost;
    char roomNo;
    //Values of room for TESTING purposes
    room1[0][0] = 'j';
    room1[0][1] = 'o';
    room1[0][2] = 'e';

    room1[1][0] = 'b';
    room1[1][1] = 'l';
    room1[1][2] = 'o';
    room1[1][3] = 'g';
    room1[1][4] = 'g';
    room1[1][5] = 's';

    room1[2][0] = '2';
    room1[2][1] = '7';
    room1[2][2] = '0';
    room1[2][3] = '2';
    room1[2][4] = '1';
    room1[2][5] = '9';
    room1[2][6] = '6';
    room1[2][7] = '0';

    room1[3][0] = 'b';
    room1[3][1] = 'l';
    room1[3][2] = 'o';
    room1[3][3] = 'g';
    room1[3][4] = 'g';
    room1[3][5] = 's';
    room1[3][6] = '5';

    room1[4][0] = 'F';
    room1[4][1] = 'B';

    room1[5][0] = '4';

    room1[6][0] = '2';

    room1[7][0] = '3';

    room1[8][0] = '1';
    room1[8][1] = '2';

    room1[9][0] = 'y';



    //Goes through the whole calculating bill and presenting the bill part depending on the room entered.
    printf("Enter the room you have been staying in: ");
    scanf("%c", &roomNo);
    fflush(stdin);

    //ROOM 1 CHECKOUT
    if (roomNo == '1') {
        //Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
        roomCost = 100 * atoi(room1[8]);

        //Adds the 10% discount to the room rate if the main user is over 65 years old:
        char ss[5];
        if (2025 - atoi(strncpy(ss, room1[2] + 4, 4)) >= 65) {
            roomCost *= 0.9;
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


        totalCost += boardCost;

        //Displays the booking ID, the main guest's name and the final bill:
        printf("Booking ID: %s\n", room1[3]);
        printf("Main guest's name: %s %s\n", room1[0], room1[1]);
        printf("Room cost for %s days: %f POUNDS\n", room1[8], roomCost);
        printf("Board cost for %s days and %s people: %fPOUNDS\n", room1[8], room1[5], boardCost);

        //Adds the price of the daily newspaper:
        if (strcmp(room1[9], "y") == 0) {
            totalCost += 5.5;
            printf("Daily newspaper: 5.50 POUNDS\n");
        }
        printf("===========================================================\n");
        printf("Total cost: %f POUNDS\n", totalCost);

        //Clears the data for the user:
        memset(room1, 0, sizeof(room1));
        room1[0][0] = 'f';

    }

    //ROOM 2 CHECKOUT
    else if (roomNo == '2') {
        //Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
        roomCost = 100 * atoi(room2[8]);

        //Adds the 10% discount to the room rate if the main user is over 65 years old:
        char ss[5];
        if (2025 - atoi(strncpy(ss, room2[2] + 4, 4)) >= 65) {
            roomCost *= 0.9;
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

        totalCost += boardCost;

        //Displays the booking ID, the main guest's name and the final bill:
        printf("Booking ID: %s\n", room2[3]);
        printf("Main guest's name: %s %s\n", room2[0], room2[1]);
        printf("Room cost for %s days: %f POUNDS\n", room2[8], roomCost);
        printf("Board cost for %s days and %s people: %f POUNDS\n", room2[8], room2[5], boardCost);

        //Adds the price of the daily newspaper:
        if (strcmp(room2[9], "y") == 0) {
            totalCost += 5.5;
            printf("Daily newspaper: 5.50 POUNDS\n");
        }
        printf("===========================================================\n");
        printf("Total cost: %f POUNDS\n", totalCost);

        //Clears the data for the user:
        memset(room2, 0, sizeof(room2));
        room2[0][0] = 'f';
    }

    //ROOM 3 CHECKOUT
    else if (roomNo == '3') {
        //Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
        roomCost = 85 * atoi(room3[8]);

        //Adds the 10% discount to the room rate if the main user is over 65 years old:
        char ss[5];
        if (2025 - atoi(strncpy(ss, room3[2] + 4, 4)) >= 65) {
            roomCost *= 0.9;
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

        totalCost += boardCost;

        //Displays the booking ID, the main guest's name and the final bill:
        printf("Booking ID: %s\n", room3[3]);
        printf("Main guest's name: %s %s\n", room3[0], room3[1]);
        printf("Room cost for %s days: %f POUNDS\n", room3[8], roomCost);
        printf("Board cost for %s days and %s people: %f POUNDS\n", room3[8], room3[5], boardCost);

        //Adds the price of the daily newspaper:
        if (strcmp(room3[9], "y") == 0) {
            totalCost += 5.5;
            printf("Daily newspaper: 5.50 POUNDS\n");
        }
        printf("===========================================================\n");
        printf("Total cost: %f POUNDS\n", totalCost);

        //Clears the data for the user:
        memset(room3, 0, sizeof(room3));
        room3[0][0] = 'f';
    }

    //ROOM 4 CHECKOUT
    else if (roomNo == '4') {
        //Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
        roomCost = 75 * atoi(room4[8]);

        //Adds the 10% discount to the room rate if the main user is over 65 years old:
        char ss[5];
        if (2025 - atoi(strncpy(ss, room4[2] + 4, 4)) >= 65) {
            roomCost *= 0.9;
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

        totalCost += boardCost;

        //Displays the booking ID, the main guest's name and the final bill:
        printf("Booking ID: %s\n", room4[3]);
        printf("Main guest's name: %s %s\n", room4[0], room4[1]);
        printf("Room cost for %s days: %f POUNDS\n", room4[8], roomCost);
        printf("Board cost for %s days and %s people: %f POUNDS\n", room4[8], room4[5], boardCost);

        //Adds the price of the daily newspaper:
        if (strcmp(room4[9], "y") == 0) {
            totalCost += 5.5;
            printf("Daily newspaper: 5.50 POUNDS\n");
        }
        printf("===========================================================\n");
        printf("Total cost: %f POUNDS\n", totalCost);

        //Clears the data for the user:
        memset(room4, 0, sizeof(room4));
        room4[0][0] = 'f';
    }

    //ROOM 5 CHECKOUT
    else if (roomNo == '5') {
        //Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
        roomCost = 75 * atoi(room5[8]);

        //Adds the 10% discount to the room rate if the main user is over 65 years old:
        char ss[5];
        if (2025 - atoi(strncpy(ss, room5[2] + 4, 4)) >= 65) {
            roomCost *= 0.9;
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


        totalCost += boardCost;

        //Displays the booking ID, the main guest's name and the final bill:
        printf("Booking ID: %s\n", room5[3]);
        printf("Main guest's name: %s %s\n", room5[0], room5[1]);
        printf("Room cost for %s days: %f POUNDS\n", room5[8], roomCost);
        printf("Board cost for %s days and %s people: %f POUNDS\n", room5[8], room5[5], boardCost);

        //Adds the price of the daily newspaper:
        if (strcmp(room5[9], "y") == 0) {
            totalCost += 5.5;
            printf("Daily newspaper: 5.50 POUNDS\n");
        }
        printf("===========================================================\n");
        printf("Total cost: %f POUNDS\n", totalCost);

        //Clears the data for the user:
        memset(room5, 0, sizeof(room5));
        room5[0][0] = 'f';
    }

    //ROOM 6 CHECKOUT
    else if (roomNo == '6') {
        //Adds the price of the room multiplied by the length of stay (room[8]) to the bill:
        roomCost = 50 * atoi(room6[8]);

        //Adds the 10% discount to the room rate if the main user is over 65 years old:
        char ss[5];
        if (2025 - atoi(strncpy(ss, room6[2] + 4, 4)) >= 65) {
            roomCost *= 0.9;
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
            printf("ERROR - no board value in room6[4].\n");
            boardCost = 0;
        }

        totalCost += boardCost;

        //Displays the booking ID, the main guest's name and the final bill:
        printf("Booking ID: %s\n", room6[3]);
        printf("Main guest's name: %s %s\n", room6[0], room6[1]);
        printf("Room cost for %s days: %f POUNDS\n", room6[8], roomCost);
        printf("Board cost for %s days and %s people: %f POUNDS\n", room6[8], room6[5], boardCost);

        //Adds the price of the daily newspaper:
        if (strcmp(room6[9], "y") == 0) {
            totalCost += 5.5;
            printf("Daily newspaper: 5.50 POUNDS\n");
        }
        printf("===========================================================\n");
        printf("Total cost: %f POUNDS\n", totalCost);

        //Clears the data for the user:
        memset(room6, 0, sizeof(room6));
        room6[0][0] = 'f';
    }

    else {
        printf("Invalid room number.\n");
    }
    //End of checkout
    //mainMenu();
    return 0;
}