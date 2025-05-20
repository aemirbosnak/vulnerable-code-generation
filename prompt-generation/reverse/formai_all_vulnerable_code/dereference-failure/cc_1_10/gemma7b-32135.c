//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Function to create a haunted house
HauntedHouse* createHauntedHouse(char* name, int rooms) {
    HauntedHouse* house = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->rooms = rooms;
    house->next = NULL;
    return house;
}

// Function to add a room to a haunted house
void addRoom(HauntedHouse* house, int rooms) {
    for (int i = 0; i < rooms; i++) {
        house->rooms++;
        house = house->next = createHauntedHouse(NULL, 0);
    }
}

// Function to simulate the haunted house
void simulateHauntedHouse(HauntedHouse* house) {
    srand(time(NULL));
    int room = rand() % house->rooms;
    switch (room) {
        case 0:
            printf("You are in the living room.\n");
            break;
        case 1:
            printf("You are in the dining room.\n");
            break;
        case 2:
            printf("You are in the bedroom.\n");
            break;
        case 3:
            printf("You are in the kitchen.\n");
            break;
        default:
            printf("You are in an unknown room.\n");
            break;
    }

    printf("Suddenly, you hear a noise.\n");
    pause();
    printf("You feel a cold hand on your shoulder.\n");
    pause();
    printf("You flee from the haunted house.\n");
}

int main() {
    HauntedHouse* hauntedHouse = createHauntedHouse("The Haunted Thorn Mansion", 5);
    addRoom(hauntedHouse, 10);
    simulateHauntedHouse(hauntedHouse);
    return 0;
}