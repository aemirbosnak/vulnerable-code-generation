//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a haunted house
typedef struct HauntedHouse {
    char name[20];
    int yearBuilt;
    char owner[20];
    int numRooms;
    int numGhosts;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a linked list of haunted houses
HauntedHouse* head = NULL;

// Function to add a haunted house to the list
void addHauntedHouse(char* name, int yearBuilt, char* owner, int numRooms, int numGhosts) {
    HauntedHouse* newHouse = malloc(sizeof(HauntedHouse));
    strcpy(newHouse->name, name);
    newHouse->yearBuilt = yearBuilt;
    strcpy(newHouse->owner, owner);
    newHouse->numRooms = numRooms;
    newHouse->numGhosts = numGhosts;
    newHouse->next = NULL;

    if (head == NULL) {
        head = newHouse;
    } else {
        HauntedHouse* currentHouse = head;
        while (currentHouse->next != NULL) {
            currentHouse = currentHouse->next;
        }
        currentHouse->next = newHouse;
    }
}

// Function to simulate a haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    printf("Welcome to the haunted house of %s!\n", house->name);
    printf("The house was built in %d.\n", house->yearBuilt);
    printf("The owner is %s.\n", house->owner);
    printf("The house has %d rooms and %d ghosts.\n", house->numRooms, house->numGhosts);

    // Simulate the ghosts' activities
    for (int i = 0; i < house->numGhosts; i++) {
        printf("The ghost of %s is lurking about...\n", house->name);
    }

    // Ask the visitor to leave the house
    printf("Please leave the haunted house.\n");
}

int main() {
    // Add some haunted houses to the list
    addHauntedHouse("The Thorn Mansion", 1890, "Mr. Thorn", 10, 5);
    addHauntedHouse("The Blackwood Manor", 1910, "Mr. Blackwood", 12, 3);
    addHauntedHouse("The Greystone Inn", 1860, "Mr. Greystone", 8, 2);

    // Simulate the haunted house
    simulateHauntedHouse(head);

    return 0;
}