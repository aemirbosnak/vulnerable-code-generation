//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a haunted house
HauntedHouse* createHauntedHouse(char* name, int rooms) {
    HauntedHouse* house = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->rooms = rooms;
    house->next = NULL;
    return house;
}

// Add a room to a haunted house
void addRoom(HauntedHouse* house, int rooms) {
    house->rooms += rooms;
}

// Simulate a haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    printf("Welcome to the haunted house of %s!\n", house->name);
    printf("There are a total of %d rooms in this house.\n", house->rooms);

    // Simulate the rooms
    for (int i = 0; i < house->rooms; i++) {
        printf("You are in room %d.\n", i);
        // Randomly generate a paranormal event
        int event = rand() % 3;
        switch (event) {
            case 0:
                printf("You hear a strange noise.\n");
                break;
            case 1:
                printf("You see a ghostly figure.\n");
                break;
            case 2:
                printf("You feel a cold hand on your shoulder.\n");
                break;
        }
    }

    // Simulate the exit
    printf("You have escaped the haunted house of %s.\n", house->name);
}

int main() {
    // Create a haunted house
    HauntedHouse* house = createHauntedHouse("The Blackwood Mansion", 10);

    // Add rooms to the haunted house
    addRoom(house, 5);

    // Simulate the haunted house
    simulateHauntedHouse(house);

    return 0;
}