//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

struct Guest {
    char name[50];
    int roomNumber;
    int daysStayed;
};

void checkIn(struct Guest *hotelGuests, int numRooms);
void checkOut(struct Guest *hotelGuests, int numRooms);
void displayGuests(struct Guest *hotelGuests, int numRooms);
void displayOptions();

int main() {
    int numRooms;
    printf("Enter the number of available rooms in the hotel: ");
    scanf("%d", &numRooms);

    struct Guest hotelGuests[numRooms];

    while(1) {
        displayOptions();

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                checkIn(hotelGuests, numRooms);
                break;
            case 2:
                checkOut(hotelGuests, numRooms);
                break;
            case 3:
                displayGuests(hotelGuests, numRooms);
                break;
            case 4:
                printf("Thank you for using the hotel management system!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}

void displayOptions() {
    printf("\n1. Check In\n");
    printf("2. Check Out\n");
    printf("3. Display Guests\n");
    printf("4. Exit\n");
    printf("\nPlease select an option: ");
}

void checkIn(struct Guest *hotelGuests, int numRooms) {
    printf("\nCHECK IN:\n");
    for(int i=0; i<numRooms; i++) {
        if(hotelGuests[i].roomNumber == 0) {
            printf("Guest %d:\n", i+1);
            printf("Name: ");
            scanf("%s", hotelGuests[i].name);
            printf("Room Number: ");
            scanf("%d", &hotelGuests[i].roomNumber);
            printf("Days Stayed: ");
            scanf("%d", &hotelGuests[i].daysStayed);
            printf("Guest checked in successfully.\n");
            return;
        }
    }
    printf("No available rooms!\n");
}

void checkOut(struct Guest *hotelGuests, int numRooms) {
    printf("\nCHECK OUT:\n");
    int roomNum;
    printf("Enter room number: ");
    scanf("%d", &roomNum);

    for(int i=0; i<numRooms; i++) {
        if(hotelGuests[i].roomNumber == roomNum) {
            printf("Guest %d:\nName: %s\nRoom Number: %d\nDays Stayed: %d\n", i+1, hotelGuests[i].name, hotelGuests[i].roomNumber, hotelGuests[i].daysStayed);
            printf("Check out successful.\n");
            hotelGuests[i].roomNumber = 0;
            hotelGuests[i].daysStayed = 0;
            hotelGuests[i].name[0] = '\0';
            return;
        }
    }
    printf("Invalid room number!\n");
}

void displayGuests(struct Guest *hotelGuests, int numRooms) {
    printf("\nGUESTS:\n");
    for(int i=0; i<numRooms; i++) {
        if(hotelGuests[i].roomNumber != 0) {
            printf("Guest %d:\nName: %s\nRoom Number: %d\nDays Stayed: %d\n", i+1, hotelGuests[i].name, hotelGuests[i].roomNumber, hotelGuests[i].daysStayed);
        }
    }
}