//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a list of haunted houses
HauntedHouse* head = NULL;

// Function to add a haunted house to the list
void addHouse(char* name, int rooms) {
    HauntedHouse* newHouse = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    strcpy(newHouse->name, name);
    newHouse->rooms = rooms;
    newHouse->next = NULL;

    if (head == NULL) {
        head = newHouse;
    } else {
        head->next = newHouse;
    }
}

// Function to simulate the haunted house
void simulateHouse(HauntedHouse* house) {
    printf("You are in the haunted house of %s.\n", house->name);
    printf("There are %d rooms in this house.\n", house->rooms);

    // Simulate the haunted house events
    srand(time(NULL));
    int event = rand() % 3;

    switch (event) {
        case 0:
            printf("You hear a loud noise.\n");
            break;
        case 1:
            printf("You see a ghostly figure.\n");
            break;
        case 2:
            printf("You smell a pungent odor.\n");
            break;
    }
}

int main() {
    // Add some haunted houses to the list
    addHouse("The Blackwood Mansion", 10);
    addHouse("The Amityville Horror", 5);
    addHouse("The Winchester Mystery House", 15);

    // Simulate the haunted house
    simulateHouse(head);

    return 0;
}