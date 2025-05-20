//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
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
    haunted_house* house = (haunted_house*)malloc(sizeof(haunted_house));
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
    int i;
    for (i = 0; i < house->rooms; i++) {
        printf("You are in room %d of the %s haunted house.\n", i + 1, house->name);
        printf("What do you want to do? (e.g. go north, south, east, west)\n");
        char command[20];
        scanf("%s", command);

        // Implement your logic here to handle the user's command
        // For example, you could check if the user's command is valid,
        // move the user to the next room, or have the user interact with
        // the haunted house
    }
}

int main() {
    // Create a haunted house
    haunted_house* house = create_haunted_house("The Thorn Mansion", 5);

    // Add rooms to the haunted house
    add_room(house, 2);
    add_room(house, 3);
    add_room(house, 4);

    // Simulate the haunted house
    simulate_haunted_house(house);

    return 0;
}