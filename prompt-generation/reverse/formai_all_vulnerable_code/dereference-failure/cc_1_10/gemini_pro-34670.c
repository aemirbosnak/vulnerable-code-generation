//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the structure of a room
typedef struct room {
    int north;  // The index of the room to the north, or -1 if there is no room to the north
    int east;   // The index of the room to the east, or -1 if there is no room to the east
    int south;  // The index of the room to the south, or -1 if there is no room to the south
    int west;   // The index of the room to the west, or -1 if there is no room to the west
    int visited;// Flag indicating whether the room has been visited
} room;

// Define the structure of the haunted house
typedef struct haunted_house {
    room rooms[MAX_ROOMS];  // The array of rooms
    int num_rooms;          // The number of rooms in the house
} haunted_house;

// Function to create a new haunted house
haunted_house* create_haunted_house() {
    // Allocate memory for the haunted house
    haunted_house* house = malloc(sizeof(haunted_house));

    // Set the number of rooms in the house to 0
    house->num_rooms = 0;

    // Return the haunted house
    return house;
}

// Function to add a room to the haunted house
void add_room(haunted_house* house, int north, int east, int south, int west) {
    // Check if the haunted house is full
    if (house->num_rooms >= MAX_ROOMS) {
        return;
    }

    // Get the index of the new room
    int index = house->num_rooms;

    // Set the values of the new room
    house->rooms[index].north = north;
    house->rooms[index].east = east;
    house->rooms[index].south = south;
    house->rooms[index].west = west;
    house->rooms[index].visited=0;

    // Increment the number of rooms in the house
    house->num_rooms++;
}

// Function to print the haunted house
void print_haunted_house(haunted_house* house) {
    // Loop through the rooms in the house
    for (int i = 0; i < house->num_rooms; i++) {
        // Print the room number
        printf("Room %d:\n", i);

        // Print the room's exits
        printf("  North: %d\n", house->rooms[i].north);
        printf("  East: %d\n", house->rooms[i].east);
        printf("  South: %d\n", house->rooms[i].south);
        printf("  West: %d\n", house->rooms[i].west);
        printf("  Visited: %d\n", house->rooms[i].visited);
    }
}

// Function to play the haunted house game
void play_haunted_house(haunted_house* house) {
    // Set the current room to the first room
    int current_room = 0;

    // Loop until the player has visited all of the rooms
    // Increment till visited is set to true
    while (house->rooms[current_room].visited == 0) {
  
        // Print the current room
        printf("You are in room %d.\n", current_room);
    
        // Get the player's input
        char input;
        printf("Enter a direction to move (n/e/s/w): ");
        scanf(" %c", &input);
    
        // Move the player to the next room
        switch (input) {
            case 'n':
                current_room = house->rooms[current_room].north;
                break;
            case 'e':
                current_room = house->rooms[current_room].east;
                break;
            case 's':
                current_room = house->rooms[current_room].south;
                break;
            case 'w':
                current_room = house->rooms[current_room].west;
                break;
        }
      house->rooms[current_room].visited = 1;

    }

    // Print a message indicating that the player has won the game
    printf("Congratulations! You have escaped the haunted house.\n");
}

// Main function
int main() {
    // Create a new haunted house
    haunted_house* house = create_haunted_house();

    // Add rooms to the haunted house
    add_room(house, 1, 2, -1, -1);
    add_room(house, 0, 3, -1, -1);
    add_room(house, 1, 4, -1, -1);
    add_room(house, 2, -1, 5, -1);
    add_room(house, 3, -1, -1, 6);
    add_room(house, 4, -1, -1, -1);

    // Print the haunted house
    print_haunted_house(house);

    // Play the haunted house game
    play_haunted_house(house);

    // Free the memory allocated for the haunted house
    free(house);

    return 0;
}