//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Function to create a haunted house
HauntedHouse* createHauntedHouse() {
    HauntedHouse* hh = malloc(sizeof(HauntedHouse));
    hh->name[0] = '\0';
    hh->rooms = 0;
    hh->next = NULL;
    return hh;
}

// Function to add a room to a haunted house
void addRoom(HauntedHouse* hh, int rooms) {
    hh->rooms += rooms;
}

// Function to simulate the haunted house
void simulateHauntedHouse(HauntedHouse* hh) {
    printf("Welcome to the haunted house of %s!\n", hh->name);
    printf("There are a total of %d rooms in this house.\n", hh->rooms);
    printf("Please enter the room number you want to visit:\n");

    int roomNumber;
    scanf("%d", &roomNumber);

    // Check if the room number is valid
    if (roomNumber < 1 || roomNumber > hh->rooms) {
        printf("Invalid room number.\n");
    } else {
        // Simulate the haunted room
        printf("You have entered room number %d.\n", roomNumber);
        printf("The room is dark and dusty. You hear a strange noise.\n");
        printf("Do you want to leave the room? (Y/N)\n");

        char leaveRoom;
        scanf("%c", &leaveRoom);

        // If the user wants to leave the room, they will be transported to the next room
        if (leaveRoom == 'Y') {
            simulateHauntedHouse(hh->next);
        } else {
            printf("You have decided to stay in the room.\n");
        }
    }
}

int main() {
    // Create a haunted house
    HauntedHouse* hh = createHauntedHouse();

    // Add some rooms to the haunted house
    addRoom(hh, 5);

    // Simulate the haunted house
    simulateHauntedHouse(hh);

    return 0;
}