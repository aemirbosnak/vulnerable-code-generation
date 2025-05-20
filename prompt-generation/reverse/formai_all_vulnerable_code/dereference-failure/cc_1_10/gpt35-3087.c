//FormAI DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of rooms
#define MAX_ROOMS 50

// Define struct for each hotel room
typedef struct {
    int roomNumber;
    char guestName[50];
    int numOccupants;
    double rate;
} Room;

// Array to hold all hotel rooms
Room rooms[MAX_ROOMS];

// Function to print all currently occupied rooms
void printOccupiedRooms() {
    printf("Occupied Rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].numOccupants > 0) { // if room is occupied
            printf("Room %d: %s\n", rooms[i].roomNumber, rooms[i].guestName);
        }
    }
    printf("\n");
}

// Function to add a guest to a room
void addGuest(int roomNum, char name[], int numOcc, double rate) {
    rooms[roomNum-1].roomNumber = roomNum;
    strcpy(rooms[roomNum-1].guestName, name);
    rooms[roomNum-1].numOccupants = numOcc;
    rooms[roomNum-1].rate = rate;
    printf("%s added to Room %d.\n", name, roomNum);
}

// Function to remove a guest from a room
void removeGuest(int roomNum) {
    strcpy(rooms[roomNum-1].guestName, "");
    rooms[roomNum-1].numOccupants = 0;
    rooms[roomNum-1].rate = 0;
    printf("Guest removed from Room %d.\n", roomNum);
}

// Function to calculate total revenue for hotel
double calculateRevenue() {
    double revenue = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        revenue += rooms[i].numOccupants * rooms[i].rate; // multiply numOccupants by rate for each room
    }
    return revenue;
}

int main() {
    int input = 0;
    int roomNum = 0;
    char name[50] = "";
    int numOcc = 0;
    double rate = 0.0;

    while (input != 5) { // loop until user chooses to exit
        printf("Please choose an option (1-5):\n");
        printf("1. Print Occupied Rooms.\n");
        printf("2. Add Guest to Room.\n");
        printf("3. Remove Guest from Room.\n");
        printf("4. Calculate Revenue.\n");
        printf("5. Exit.\n");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printOccupiedRooms();
                break;
            case 2:
                printf("Enter room number (1-%d): ", MAX_ROOMS);
                scanf("%d", &roomNum);
                printf("Enter guest name: ");
                scanf("%s", name);
                printf("Enter number of occupants: ");
                scanf("%d", &numOcc);
                printf("Enter nightly rate: ");
                scanf("%lf", &rate);
                addGuest(roomNum, name, numOcc, rate);
                break;
            case 3:
                printf("Enter room number to remove guest from (1-%d): ", MAX_ROOMS);
                scanf("%d", &roomNum);
                removeGuest(roomNum);
                break;
            case 4:
                printf("Total revenue: $%.2lf\n", calculateRevenue());
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid input. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}