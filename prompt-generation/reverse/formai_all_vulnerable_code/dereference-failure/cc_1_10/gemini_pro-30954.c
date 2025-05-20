//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the data structure for a room
typedef struct room {
    int number;  // The room number
    int north;   // The room number to the north
    int east;    // The room number to the east
    int south;   // The room number to the south
    int west;    // The room number to the west
    int haunted; // Boolean flag indicating if the room is haunted
} room;

// Define the data structure for the haunted house
typedef struct haunted_house {
    room rooms[MAX_ROOMS];  // The array of rooms
    int num_rooms;          // The number of rooms in the house
} haunted_house;

// Function to create a new haunted house
haunted_house* create_haunted_house() {
    // Allocate memory for the haunted house
    haunted_house* house = malloc(sizeof(haunted_house));

    // Initialize the haunted house
    house->num_rooms = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        house->rooms[i].number = -1;
        house->rooms[i].north = -1;
        house->rooms[i].east = -1;
        house->rooms[i].south = -1;
        house->rooms[i].west = -1;
        house->rooms[i].haunted = 0;
    }

    // Return the haunted house
    return house;
}

// Function to add a room to the haunted house
void add_room(haunted_house* house, int number, int north, int east, int south, int west, int haunted) {
    // Check if the room number is valid
    if (number < 0 || number >= MAX_ROOMS) {
        printf("Error: Invalid room number %d\n", number);
        return;
    }

    // Check if the room already exists
    if (house->rooms[number].number != -1) {
        printf("Error: Room %d already exists\n", number);
        return;
    }

    // Add the room to the haunted house
    house->rooms[number].number = number;
    house->rooms[number].north = north;
    house->rooms[number].east = east;
    house->rooms[number].south = south;
    house->rooms[number].west = west;
    house->rooms[number].haunted = haunted;

    // Increment the number of rooms in the house
    house->num_rooms++;
}

// Function to print the haunted house
void print_haunted_house(haunted_house* house) {
    // Print the header
    printf("Haunted House:\n");
    printf("Number  North  East  South  West  Haunted\n");

    // Print the rooms
    for (int i = 0; i < house->num_rooms; i++) {
        printf("%d  ", house->rooms[i].number);
        printf("%d  ", house->rooms[i].north);
        printf("%d  ", house->rooms[i].east);
        printf("%d  ", house->rooms[i].south);
        printf("%d  ", house->rooms[i].west);
        printf("%d\n", house->rooms[i].haunted);
    }
}

// Function to destroy the haunted house
void destroy_haunted_house(haunted_house* house) {
    // Free the memory for the haunted house
    free(house);
}

// Function to generate a random haunted house
haunted_house* generate_random_haunted_house(int num_rooms) {
    // Check if the number of rooms is valid
    if (num_rooms < 0 || num_rooms > MAX_ROOMS) {
        printf("Error: Invalid number of rooms %d\n", num_rooms);
        return NULL;
    }

    // Create a new haunted house
    haunted_house* house = create_haunted_house();

    // Add rooms to the haunted house
    for (int i = 0; i < num_rooms; i++) {
        // Generate a random room number
        int number = rand() % MAX_ROOMS;

        // Generate random connections to other rooms
        int north = rand() % MAX_ROOMS;
        int east = rand() % MAX_ROOMS;
        int south = rand() % MAX_ROOMS;
        int west = rand() % MAX_ROOMS;

        // Generate a random boolean flag indicating if the room is haunted
        int haunted = rand() % 2;

        // Add the room to the haunted house
        add_room(house, number, north, east, south, west, haunted);
    }

    // Return the haunted house
    return house;
}

// Function to play the haunted house game
void play_haunted_house_game(haunted_house* house) {
    // Initialize the player's current room
    int current_room = 0;

    // Print the welcome message
    printf("Welcome to the Haunted House Game!\n");
    printf("Your goal is to find the exit room without being scared by the ghosts.\n");

    // Loop until the player finds the exit room or is scared by a ghost
    while (current_room != -1) {
        // Print the current room
        printf("You are in room %d.\n", current_room);

        // Print the room's connections
        printf("The room has connections to the following rooms:\n");
        if (house->rooms[current_room].north != -1) {
            printf("North: %d\n", house->rooms[current_room].north);
        }
        if (house->rooms[current_room].east != -1) {
            printf("East: %d\n", house->rooms[current_room].east);
        }
        if (house->rooms[current_room].south != -1) {
            printf("South: %d\n", house->rooms[current_room].south);
        }
        if (house->rooms[current_room].west != -1) {
            printf("West: %d\n", house->rooms[current_room].west);
        }

        // Get the player's input
        printf("Enter the number of the room you want to go to next, or -1 to exit: ");
        int next_room;
        scanf("%d", &next_room);

        // Check if the player entered a valid room number
        if (next_room < -1 || next_room >= MAX_ROOMS) {
            printf("Error: Invalid room number %d\n", next_room);
            continue;
        }

        // Check if the player is trying to exit the haunted house
        if (next_room == -1) {
            printf("Exiting the haunted house.\n");
            break;
        }

        // Check if the player is trying to go to a room that is not connected to the current room
        if (house->rooms[current_room].north != next_room &&
            house->rooms[current_room].east != next_room &&
            house->rooms[current_room].south != next_room &&
            house->rooms[current_room].west != next_room) {
            printf("Error: Room %d is not connected to the current room.\n", next_room);
            continue;
        }

        // Check if the player is trying to go to a room that is haunted
        if (house->rooms[next_room].haunted) {
            printf("You are scared by a ghost in room %d!\n", next_room);
            break;
        }

        // Move the player to the next room
        current_room = next_room;
    }

    // Print the game over message
    printf("Game over!\n");
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random haunted house with 10 rooms
    haunted_house* house = generate_random_haunted_house(10);

    // Print the haunted house
    print_haunted_house(house);

    // Play the haunted house game
    play_haunted_house_game(house);

    // Destroy the haunted house
    destroy_haunted_house(house);

    return 0;
}