#include <stdio.h>
#include <string.h>

// MOCK DATA FOR TESTING

char room1[10][16] = {"joe", "bloggs", "18061990", "bloggs5", "f", "4", "2", "2", "12", "y"};
char room2[10][16] = {"ben", "smith", "09051962", "smith2", "b", "2", "1", "1", "4", "n"};
char room3[10][16] = {"jane", "wilson", "18021986", "wilson1", "h", "8", "6", "2", "10", "y"};
char room4[10][16] = {"michael", "stevens", "02072001", "stevens6", "f", "3", "2", "1", "4", "n"};
char room5[10][16] = {"sally", "davies", "09081934", "davies5", "b", "1", "0", "1", "14", "y"};
char room6[10][16] = {"jim", "kitchen", "18071997", "kitchen5", "f", "7", "3", "4", "1", "n"};
char tableNaboo[2] = {'0','0'};
char tableEndor[2]  = {'0','0'};
char tableTatooine[2] = {'0', '0'};

// CODE FOR TESTING
void mainMenu() {
    printf("YOU ARE AT THE MAIN MENU\n");
}

// END OF CODE FOR TESTING

// function to show available tables
void tableAvailabilty() {
    int count = 0;
    if (tableNaboo[0] == '0') {
        printf("Table naboo is available for 7\n");
        count += 1;
    }
    if (tableNaboo[1] == '0') {
        printf("Table naboo is available for 9\n");
        count += 1;
    }
    if (tableEndor[0] == '0') {
        printf("Table endor is available for 7\n");
        count += 1;
    }
    if (tableEndor[1] == '0') {
        printf("Table endor is available for 9\n");
        count += 1;
    }
    if (tableTatooine[0] == '0') {
        printf("Table tatooine is available for 7\n");
        count += 1;
    }
    if (tableTatooine[1] == '0') {
        printf("Table tatooine is available for 9\n");
        count += 1;
    }
    if (count==1) {
        printf("No tables available");
        mainMenu();
    }
}

void bookATable() {
    // Define user input booking number
    char Num[15];
    printf("Enter a booking number: ");
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
                tableAvailabilty();
            }
        }
        else {
            printf("Invalid board type.\n");
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
                tableAvailabilty();
            }
        }
        else {
            printf("Invalid board type.\n");
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
                tableAvailabilty();
            }
        }
        else {
            printf("Invalid board type.\n");
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
                tableAvailabilty();
            }
        }
        else {
            printf("Invalid board type.\n");
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
                tableAvailabilty();
            }
        }
        else {
            printf("Invalid board type.\n");
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
                tableAvailabilty();
            }
        }
        else {
            printf("Invalid board type.\n");
            mainMenu();
        }
    }
    // Check if booking id was never valid
    else {
        printf("Invalid booking number.\n");
        mainMenu();
    }

    // Ask what table the user wants and input
    if (success == 1) {
        int table;
        printf("Which table? (1 for Naboo, 2 for Endor, 3 for Tatooine) ");
        scanf("%d", &table);
        // Ask what time the user wants and input
        int time;
        printf("Which time do you want to book for? (0 for 19:00, 1 for 21:00) ");
        scanf("%d", &time);
        // Check which table the user entered
        if (table == 1) {
            tableNaboo[time] = '1';
        }
        else if (table == 2) {
            tableEndor[time] = '1';
        }
        else {
            tableTatooine[time] = '1';
        }
        printf("Your table has been booked");
    }
}