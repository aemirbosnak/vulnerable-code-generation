//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a haunted house list
HauntedHouse* createHauntedHouseList(int numHouses) {
    HauntedHouse* head = NULL;
    for (int i = 0; i < numHouses; i++) {
        HauntedHouse* newHouse = malloc(sizeof(HauntedHouse));
        newHouse->name[0] = '\0';
        newHouse->rooms = 0;
        newHouse->next = head;
        head = newHouse;
    }
    return head;
}

// Simulate a haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    printf("Welcome to the haunted house of %s!\n", house->name);
    printf("There are %d rooms in this house.\n", house->rooms);

    // Generate a random room number
    int roomNum = rand() % house->rooms;

    // Simulate a ghostly encounter
    printf("You have entered room %d. A ghostly figure is lurking within...\n", roomNum);

    // Play a spooky sound effect
    system("play spooky.wav");

    // Give the player a chance to escape
    printf("Do you want to flee? (Y/N): ");
    char escape = getchar();

    // If the player escapes, they are safe
    if (escape == 'Y' || escape == 'y') {
        printf("You have escaped the haunted house.\n");
    } else {
        // The player is trapped in the haunted house
        printf("You are trapped in the haunted house. Game over.\n");
    }
}

int main() {
    // Create a haunted house list
    HauntedHouse* hauntedHouseList = createHauntedHouseList(5);

    // Simulate the haunted house
    simulateHauntedHouse(hauntedHouseList);

    return 0;
}