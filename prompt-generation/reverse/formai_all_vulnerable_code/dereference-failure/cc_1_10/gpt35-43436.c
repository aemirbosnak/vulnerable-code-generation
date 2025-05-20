//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
// C Hotel Management System
// Written by Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for Guest and Room Information
typedef struct {
    int guestID;
    char guestName[50];
    int roomNumber;
} Guest;

typedef struct {
    int roomNumber;
    int roomType;
    int roomStatus;
} Room;

// Function prototypes
void checkIn(Guest*, Room*);
void checkOut(Guest*, Room*);
void printGuestList(Guest*);
void printRoomList(Room*);

// Main function
int main() {
    int numRooms = 100; // Total number of rooms in the hotel
    Guest* guestList = malloc(numRooms * sizeof(Guest));
    Room* roomList = malloc(numRooms * sizeof(Room));
    int choice;

    // Initialize room information
    for (int i = 0; i < numRooms; i++) {
        roomList[i].roomNumber = i + 1;
        roomList[i].roomType = 1; // Default room type is standard
        roomList[i].roomStatus = 0; // Room is empty
    }

    do {
        // Display menu and get user's choice
        printf("\n==========\n");
        printf("MENU\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. Print guest list\n");
        printf("4. Print room list\n");
        printf("5. Exit\n");
        printf("==========\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn(guestList, roomList);
                break;
            case 2:
                checkOut(guestList, roomList);
                break;
            case 3:
                printGuestList(guestList);
                break;
            case 4:
                printRoomList(roomList);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    free(guestList);
    free(roomList);
    return 0;
}

// Function for checking in a guest
void checkIn(Guest* guestList, Room* roomList) {
    int guestID, roomNumber, roomType;
    char guestName[50];
    int i;

    // Get guest information
    printf("Enter guest ID: ");
    scanf("%d", &guestID);
    printf("Enter guest name: ");
    scanf("%s", guestName);

    // Check if guest is already checked in
    for (i = 0; i < 100; i++) {
        if (guestList[i].guestID == guestID) {
            printf("Guest is already checked in.\n");
            return;
        }
    }

    // Get room information
    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    // Check if room is available
    if (roomList[roomNumber - 1].roomStatus == 1) {
        printf("Room is already occupied.\n");
        return;
    }

    // Get room type
    printf("Enter room type (1 = Standard, 2 = Deluxe): ");
    scanf("%d", &roomType);
    if (roomType < 1 || roomType > 2) {
        printf("Invalid room type.\n");
        return;
    }

    // Update guest and room information
    guestList[i].guestID = guestID;
    strcpy(guestList[i].guestName, guestName);
    guestList[i].roomNumber = roomNumber;

    roomList[roomNumber - 1].roomType = roomType;
    roomList[roomNumber - 1].roomStatus = 1;

    printf("Guest checked in successfully.\n");
}

// Function for checking out a guest
void checkOut(Guest* guestList, Room* roomList) {
    int guestID, roomNumber, i;

    // Get guest and room information
    printf("Enter guest ID: ");
    scanf("%d", &guestID);

    for (i = 0; i < 100; i++) {
        if (guestList[i].guestID == guestID) {
            roomNumber = guestList[i].roomNumber;
            break;
        }
    }

    if (i == 100) {
        printf("Guest not found.\n");
        return;
    }

    // Update guest and room information
    guestList[i].guestID = 0;
    strcpy(guestList[i].guestName, "");
    guestList[i].roomNumber = 0;

    roomList[roomNumber - 1].roomType = 1;
    roomList[roomNumber - 1].roomStatus = 0;

    printf("Guest checked out successfully.\n");
}

// Function for printing list of checked in guests
void printGuestList(Guest* guestList) {
    printf("\nLIST OF GUESTS CHECKED IN\n");
    printf("Guest ID\tGuest Name\tRoom Number\n");
    for (int i = 0; i < 100; i++) {
        if (guestList[i].guestID != 0) {
            printf("%d\t\t%s\t\t%d\n", guestList[i].guestID, guestList[i].guestName, guestList[i].roomNumber);
        }
    }
}

// Function for printing list of rooms
void printRoomList(Room* roomList) {
    printf("\nLIST OF ROOMS\n");
    printf("Room Number\tRoom Type\tRoom Status\n");
    for (int i = 0; i < 100; i++) {
        printf("%d\t\t%d\t\t%d\n", roomList[i].roomNumber, roomList[i].roomType, roomList[i].roomStatus);
    }
}