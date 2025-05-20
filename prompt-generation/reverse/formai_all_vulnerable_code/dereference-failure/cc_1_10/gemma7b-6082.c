//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a haunted house node
HauntedHouse* createHauntedHouse(char* name, int rooms) {
    HauntedHouse* house = malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->rooms = rooms;
    house->next = NULL;
    return house;
}

// Add a room to a haunted house
void addRoom(HauntedHouse* house, int rooms) {
    house->rooms += rooms;
}

// Traverse the haunted house
void traverseHauntedHouse(HauntedHouse* house) {
    printf("Exploring the Haunted House of %s...\n", house->name);
    printf("Number of rooms: %d\n", house->rooms);
    printf("----------------------------------------\n");
    HauntedHouse* current = house;
    while (current) {
        printf("Room: %s\n", current->name);
        current = current->next;
    }
}

int main() {
    // Create a haunted house
    HauntedHouse* hauntedHouse = createHauntedHouse("The Thorn Mansion", 5);

    // Add rooms to the haunted house
    addRoom(hauntedHouse, 3);
    addRoom(hauntedHouse, 2);
    addRoom(hauntedHouse, 4);

    // Traverse the haunted house
    traverseHauntedHouse(hauntedHouse);

    return 0;
}