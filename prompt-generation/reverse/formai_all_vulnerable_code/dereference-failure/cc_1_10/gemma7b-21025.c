//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
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
    house->rooms += rooms;
}

// Function to haunt a house
void hauntHouse(HauntedHouse* house) {
    srand(time(NULL));
    int haunt_room = rand() % house->rooms + 1;
    printf("You are in the %s room of the %s haunted house.\n", haunt_room, house->name);
    printf("Suddenly, you hear a noise... \n");
    pause();
    printf("The noise fades away... \n");
    printf("You feel a presence... \n");
    pause();
    printf("The presence disappears... \n");
    printf("You are alone again... \n");
}

int main() {
    // Create a haunted house
    HauntedHouse* myHouse = createHauntedHouse("The Blackwood Mansion", 10);

    // Add rooms to the house
    addRoom(myHouse, 5);

    // Haunt the house
    hauntHouse(myHouse);

    return 0;
}