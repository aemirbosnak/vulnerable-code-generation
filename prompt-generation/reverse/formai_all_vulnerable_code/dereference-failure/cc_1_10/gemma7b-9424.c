//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a linked list of haunted houses
HauntedHouse* head = NULL;

// Function to add a haunted house to the list
void addHauntedHouse(char* name, int rooms) {
    HauntedHouse* newHouse = malloc(sizeof(HauntedHouse));
    strcpy(newHouse->name, name);
    newHouse->rooms = rooms;
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
void simulateHauntedHouse() {
    time_t t;
    t = time(NULL);

    // Randomly select a haunted house
    HauntedHouse* currentHouse = head;
    int randomHouse = rand() % head->rooms;

    // Print the haunted house name and rooms
    printf("You have entered the haunted house of %s.\n", currentHouse->name);
    printf("There are %d rooms in this house.\n", currentHouse->rooms);

    // Simulate events in the haunted house
    switch (randomHouse) {
        case 0:
            printf("You hear a noise in the hallway.\n");
            break;
        case 1:
            printf("You see a ghostly figure wandering through the living room.\n");
            break;
        case 2:
            printf("You find a hidden secret room.\n");
            break;
        default:
            printf("You hear a disembodied voice calling your name.\n");
            break;
    }

    // Print the time since the last event
    printf("Time since last event: %d seconds.\n", (int)time(NULL) - t);
}

int main() {
    // Add haunted houses to the list
    addHauntedHouse("The Thorn Mansion", 10);
    addHauntedHouse("The Blackwood Manor", 12);
    addHauntedHouse("The Briarcliff Hall", 14);

    // Simulate the haunted house
    simulateHauntedHouse();

    return 0;
}