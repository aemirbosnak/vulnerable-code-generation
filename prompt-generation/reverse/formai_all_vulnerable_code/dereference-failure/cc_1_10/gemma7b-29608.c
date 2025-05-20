//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Haunted House structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a list of haunted houses
HauntedHouse* hauntedHouseHead = NULL;

// Function to add a haunted house to the list
void addHauntedHouse(char* name, int rooms) {
    HauntedHouse* newHouse = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    strcpy(newHouse->name, name);
    newHouse->rooms = rooms;
    newHouse->next = NULL;

    if (hauntedHouseHead == NULL) {
        hauntedHouseHead = newHouse;
    } else {
        HauntedHouse* currentHouse = hauntedHouseHead;
        while (currentHouse->next != NULL) {
            currentHouse = currentHouse->next;
        }
        currentHouse->next = newHouse;
    }
}

// Function to simulate a haunted house
void simulateHauntedHouse() {
    HauntedHouse* currentHouse = hauntedHouseHead;

    // Loop over the haunted houses
    while (currentHouse) {
        // Generate a random event for the house
        int event = rand() % 3;

        // Handle the event
        switch (event) {
            case 0:
                printf("You hear a disembodied voice calling your name.\n");
                break;
            case 1:
                printf("You see a ghostly figure roaming the halls.\n");
                break;
            case 2:
                printf("You feel a cold wind blowing through the house.\n");
                break;
        }

        // Move to the next haunted house
        currentHouse = currentHouse->next;
    }
}

// Main function
int main() {
    // Add some haunted houses to the list
    addHauntedHouse("The Blackwood Mansion", 10);
    addHauntedHouse("The Thornfield Hall", 12);
    addHauntedHouse("The Greystone Manor", 14);

    // Simulate the haunted house
    simulateHauntedHouse();

    return 0;
}