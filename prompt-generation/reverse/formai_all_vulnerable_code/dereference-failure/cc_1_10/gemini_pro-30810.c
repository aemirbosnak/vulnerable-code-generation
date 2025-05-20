//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the maximum number of exits per room
#define MAX_EXITS 4

// Define the data structure for a room
typedef struct room {
    int num_exits;
    int exits[MAX_EXITS];
    int visited;
} room;

// Define the data structure for the haunted house
typedef struct haunted_house {
    int num_rooms;
    room rooms[MAX_ROOMS];
} haunted_house;

// Create a new haunted house
haunted_house* create_haunted_house(int num_rooms) {
    // Allocate memory for the haunted house
    haunted_house* house = malloc(sizeof(haunted_house));

    // Set the number of rooms in the haunted house
    house->num_rooms = num_rooms;

    // Create each room in the haunted house
    for (int i = 0; i < num_rooms; i++) {
        // Set the number of exits for the room
        house->rooms[i].num_exits = rand() % MAX_EXITS + 1;

        // Set the exits for the room
        for (int j = 0; j < house->rooms[i].num_exits; j++) {
            house->rooms[i].exits[j] = rand() % num_rooms;
        }

        // Set the visited flag for the room to false
        house->rooms[i].visited = 0;
    }

    // Return the haunted house
    return house;
}

// Print the haunted house
void print_haunted_house(haunted_house* house) {
    // Print the number of rooms in the haunted house
    printf("The haunted house has %d rooms.\n", house->num_rooms);

    // Print each room in the haunted house
    for (int i = 0; i < house->num_rooms; i++) {
        // Print the room number
        printf("Room %d:\n", i);

        // Print the number of exits for the room
        printf("    Number of exits: %d\n", house->rooms[i].num_exits);

        // Print the exits for the room
        printf("    Exits: ");
        for (int j = 0; j < house->rooms[i].num_exits; j++) {
            printf("%d ", house->rooms[i].exits[j]);
        }
        printf("\n");

        // Print the visited flag for the room
        printf("    Visited: %d\n", house->rooms[i].visited);
    }
}

// Free the memory allocated for the haunted house
void free_haunted_house(haunted_house* house) {
    // Free the memory allocated for each room in the haunted house
    for (int i = 0; i < house->num_rooms; i++) {
        free(house->rooms[i].exits);
    }

    // Free the memory allocated for the haunted house
    free(house);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Create a new haunted house with 10 rooms
    haunted_house* house = create_haunted_house(10);

    // Print the haunted house
    print_haunted_house(house);

    // Free the memory allocated for the haunted house
    free_haunted_house(house);

    return 0;
}