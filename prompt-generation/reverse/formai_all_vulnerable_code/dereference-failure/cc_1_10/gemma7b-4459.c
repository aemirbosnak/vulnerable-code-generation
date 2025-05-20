//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct haunted_house {
    char name[20];
    int rooms;
    struct haunted_house* next;
} haunted_house;

// Function to create a haunted house
haunted_house* create_haunted_house(char* name, int rooms) {
    haunted_house* house = malloc(sizeof(haunted_house));
    strcpy(house->name, name);
    house->rooms = rooms;
    house->next = NULL;
    return house;
}

// Function to add a room to a haunted house
void add_room(haunted_house* house, int rooms) {
    house->rooms += rooms;
}

// Function to simulate the haunted house
void simulate_haunted_house(haunted_house* house) {
    // Generate a random number between 1 and the number of rooms in the house
    int room_number = rand() % house->rooms + 1;

    // Print the room number
    printf("You are in room %d.\n", room_number);

    // Simulate some ghostly activity
    switch (rand() % 3) {
        case 0:
            printf("You hear a shuffling sound.\n");
            break;
        case 1:
            printf("You see a flickering light.\n");
            break;
        case 2:
            printf("You feel a cold hand brush against your skin.\n");
            break;
    }
}

int main() {
    // Create a haunted house
    haunted_house* haunted_house1 = create_haunted_house("The Blackwood Mansion", 10);

    // Add rooms to the haunted house
    add_room(haunted_house1, 5);
    add_room(haunted_house1, 2);
    add_room(haunted_house1, 3);

    // Simulate the haunted house
    simulate_haunted_house(haunted_house1);

    return 0;
}