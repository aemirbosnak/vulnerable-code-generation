//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char *name;
    int rooms;
    struct HauntedHouse *next;
} HauntedHouse;

// Create a haunted house
HauntedHouse *createHauntedHouse(char *name, int rooms) {
    HauntedHouse *house = malloc(sizeof(HauntedHouse));
    house->name = name;
    house->rooms = rooms;
    house->next = NULL;

    return house;
}

// Add a room to a haunted house
void addRoom(HauntedHouse *house, int rooms) {
    house->rooms += rooms;
}

// Simulate a haunted house
void simulateHauntedHouse(HauntedHouse *house) {
    // Randomly choose a room
    int room = rand() % house->rooms;

    // Create a spooky sound
    char sound[20];
    sprintf(sound, "sound/%d.wav", room);

    // Play the spooky sound
    system(sound);

    // Display a creepy message
    printf("You are in room %d. The air is thick with the smell of decay. A cold wind blows through the cracks in the walls.\n", room);

    // Simulate other haunted house events
    switch (rand() % 3) {
        case 0:
            printf("You hear a disembodied voice whispering your name.\n");
            break;
        case 1:
            printf("A ghostly figure appears before you.\n");
            break;
        case 2:
            printf("You feel a cold hand brush against your skin.\n");
            break;
    }
}

int main() {
    // Create a haunted house
    HauntedHouse *house = createHauntedHouse("The Thorn Mansion", 10);

    // Add rooms to the haunted house
    addRoom(house, 5);
    addRoom(house, 3);
    addRoom(house, 2);

    // Simulate the haunted house
    simulateHauntedHouse(house);

    return 0;
}