//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: genius
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
HauntedHouse* createHauntedHouse() {
    HauntedHouse* house = malloc(sizeof(HauntedHouse));
    house->name[0] = '\0';
    house->rooms = 0;
    house->next = NULL;
    return house;
}

// Add a room to a haunted house
void addRoom(HauntedHouse* house, int rooms) {
    house->rooms += rooms;
}

// Simulate a haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    time_t t = time(NULL);
    int i = 0;

    // Generate random events
    for (i = 0; i < house->rooms; i++) {
        switch (rand() % 3) {
            case 0:
                printf("You hear a loud bang.\n");
                break;
            case 1:
                printf("You see a ghostly figure moving through the hallway.\n");
                break;
            case 2:
                printf("You smell a strong scent of decay.\n");
                break;
        }
    }

    // Move the ghostly figure
    printf("The ghostly figure moves towards you.\n");

    // You flee from the haunted house
    printf("You flee from the haunted house.\n");
}

int main() {
    HauntedHouse* house = createHauntedHouse();
    addRoom(house, 10);
    simulateHauntedHouse(house);

    return 0;
}