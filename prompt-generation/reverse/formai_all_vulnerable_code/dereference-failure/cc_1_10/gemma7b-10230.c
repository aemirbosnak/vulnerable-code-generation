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
    srand(time(NULL));
    int random_room = rand() % house->rooms;
    printf("You have entered the haunted house of %s.\n", house->name);
    printf("The house has %d rooms.\n", house->rooms);
    printf("You are in room %d.\n", random_room + 1);
    printf("Suddenly, a ghostly figure appears before you.\n");
    printf("What do you do? (Press any key to continue)\n");
    getchar();
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