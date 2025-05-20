//FormAI DATASET v1.0 Category: Hotel Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roomNumber;
    char roomType[10];
    int price;
    char isOccupied[4];
    char name[30];
} Room;

void displayMenu() {
    printf("\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. Display Rooms\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void checkIn(Room *rooms) {
    int roomNumber;
    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);
    getchar();
    strcpy(rooms[roomNumber - 1].isOccupied, "Yes");
    printf("\nEnter name of guest: ");
    fgets(rooms[roomNumber - 1].name, 30, stdin);
    printf("\nCheck in successful!\n");
}

void checkOut(Room *rooms) {
    int roomNumber;
    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);
    getchar();
    strcpy(rooms[roomNumber - 1].isOccupied, "No");
    printf("\nCheck out successful!\n");
}

void displayRooms(Room *rooms, int numRooms) {
    printf("\nRoom   Type     Price     Occupancy     Name\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%-5d%-10s%-10d%-10s%-30s\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].price, rooms[i].isOccupied, rooms[i].name);
    }
}

int main() {
    int numRooms = 5;
    Room *rooms = malloc(numRooms * sizeof(Room));
    
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].roomType, "Single");
        rooms[i].price = 1000;
        strcpy(rooms[i].isOccupied, "No");
        strcpy(rooms[i].name, "N/A");
    }
    
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkIn(rooms);
                break;
            case 2:
                checkOut(rooms);
                break;
            case 3:
                displayRooms(rooms, numRooms);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    free(rooms);
    return 0;
}