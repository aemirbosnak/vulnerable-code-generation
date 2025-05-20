//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a haunted house
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Function to create a haunted house
HauntedHouse* createHauntedHouse() {
    HauntedHouse* house = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    house->name[0] = '\0';
    house->rooms = 0;
    house->next = NULL;
    return house;
}

// Function to add a room to a haunted house
void addRoom(HauntedHouse* house, int rooms) {
    house->rooms += rooms;
}

// Function to simulate the haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    // Randomly select a room in the house
    int room = rand() % house->rooms;

    // Create a list of ghostly encounters
    switch (room) {
        case 0:
            printf("You hear a scratching sound coming from the hallway.\n");
            break;
        case 1:
            printf("You see a ghostly figure standing in the doorway of your room.\n");
            break;
        case 2:
            printf("You hear a disembodied voice whispering your name.\n");
            break;
        case 3:
            printf("You feel a cold hand brush against your skin.\n");
            break;
        case 4:
            printf("You hear the sound of footsteps running down the stairs.\n");
            break;
    }
}

int main() {
    // Create a haunted house
    HauntedHouse* house = createHauntedHouse();

    // Add rooms to the haunted house
    addRoom(house, 5);

    // Simulate the haunted house
    simulateHauntedHouse(house);

    return 0;
}