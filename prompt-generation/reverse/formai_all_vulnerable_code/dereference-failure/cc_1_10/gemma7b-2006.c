//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
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
HauntedHouse* createHauntedHouse(char* name, int rooms) {
    HauntedHouse* house = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->rooms = rooms;
    house->next = NULL;
    return house;
}

// Function to add a room to a haunted house
void addRoom(HauntedHouse* house, char* roomName) {
    // Create a new room
    HauntedHouse* newRoom = createHauntedHouse(roomName, 0);

    // If the house is not null, add the new room to the end
    if (house) {
        house->next = newRoom;
    }
}

// Function to simulate a haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    // Randomly choose a room in the house
    HauntedHouse* currentRoom = house;
    while (currentRoom) {
        int roomNumber = rand() % currentRoom->rooms;
        currentRoom = currentRoom->next;
    }

    // Display the room name
    printf("You are in the %s.\n", currentRoom->name);
}

int main() {
    // Create a haunted house
    HauntedHouse* hauntedHouse = createHauntedHouse("The Thornfield Hall", 5);

    // Add rooms to the haunted house
    addRoom(hauntedHouse, "The Grand Hall");
    addRoom(hauntedHouse, "The Dining Hall");
    addRoom(hauntedHouse, "The Library");
    addRoom(hauntedHouse, "The Bedroom");
    addRoom(hauntedHouse, "The Cellar");

    // Simulate the haunted house
    simulateHauntedHouse(hauntedHouse);

    return 0;
}