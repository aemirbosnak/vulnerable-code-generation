//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the room struct
typedef struct room {
    int north;
    int east;
    int south;
    int west;
    int visited;
} room;

// Define the haunted house struct
typedef struct haunted_house {
    int num_rooms;
    room *rooms;
} haunted_house;

// Create a new haunted house
haunted_house *create_haunted_house(int num_rooms) {
    // Allocate memory for the haunted house
    haunted_house *house = malloc(sizeof(haunted_house));
    if (house == NULL) {
        return NULL;
    }

    // Set the number of rooms in the haunted house
    house->num_rooms = num_rooms;

    // Allocate memory for the rooms in the haunted house
    house->rooms = malloc(sizeof(room) * num_rooms);
    if (house->rooms == NULL) {
        free(house);
        return NULL;
    }

    // Initialize the rooms in the haunted house
    for (int i = 0; i < num_rooms; i++) {
        house->rooms[i].north = -1;
        house->rooms[i].east = -1;
        house->rooms[i].south = -1;
        house->rooms[i].west = -1;
        house->rooms[i].visited = 0;
    }

    // Return the haunted house
    return house;
}

// Destroy a haunted house
void destroy_haunted_house(haunted_house *house) {
    // Free the memory allocated for the rooms in the haunted house
    free(house->rooms);

    // Free the memory allocated for the haunted house
    free(house);
}

// Generate a random haunted house
haunted_house *generate_haunted_house(int num_rooms) {
    // Create a new haunted house
    haunted_house *house = create_haunted_house(num_rooms);
    if (house == NULL) {
        return NULL;
    }

    // Set the random seed
    srand(time(NULL));

    // Generate the haunted house
    for (int i = 0; i < num_rooms; i++) {
        // Generate the north door
        if (rand() % 2 == 0) {
            house->rooms[i].north = rand() % num_rooms;
        }

        // Generate the east door
        if (rand() % 2 == 0) {
            house->rooms[i].east = rand() % num_rooms;
        }

        // Generate the south door
        if (rand() % 2 == 0) {
            house->rooms[i].south = rand() % num_rooms;
        }

        // Generate the west door
        if (rand() % 2 == 0) {
            house->rooms[i].west = rand() % num_rooms;
        }
    }

    // Return the haunted house
    return house;
}

// Print a haunted house
void print_haunted_house(haunted_house *house) {
    // Print the number of rooms in the haunted house
    printf("Number of rooms: %d\n", house->num_rooms);

    // Print the rooms in the haunted house
    for (int i = 0; i < house->num_rooms; i++) {
        printf("Room %d:\n", i);
        printf("  North: %d\n", house->rooms[i].north);
        printf("  East: %d\n", house->rooms[i].east);
        printf("  South: %d\n", house->rooms[i].south);
        printf("  West: %d\n", house->rooms[i].west);
        printf("  Visited: %d\n", house->rooms[i].visited);
    }
}

// Simulate a haunted house
void simulate_haunted_house(haunted_house *house) {
    // Start in the first room
    int room = 0;

    // Loop until all rooms have been visited
    while (house->rooms[room].visited == 0) {
        // Mark the room as visited
        house->rooms[room].visited = 1;

        // Get the current time
        time_t t = time(NULL);

        // Print the current room
        printf("You are in room %d at %s\n", room, ctime(&t));

        // Get the user's input
        char input[10];
        printf("What do you want to do? (n/e/s/w/q) ");
        scanf("%s", input);

        // Move to the next room
        switch (input[0]) {
            case 'n':
                room = house->rooms[room].north;
                break;
            case 'e':
                room = house->rooms[room].east;
                break;
            case 's':
                room = house->rooms[room].south;
                break;
            case 'w':
                room = house->rooms[room].west;
                break;
            case 'q':
                return;
        }
    }

    // Print the final message
    printf("You have escaped the haunted house!\n");
}

// Main function
int main() {
    // Generate a random haunted house
    haunted_house *house = generate_haunted_house(10);

    // Print the haunted house
    print_haunted_house(house);

    // Simulate the haunted house
    simulate_haunted_house(house);

    // Destroy the haunted house
    destroy_haunted_house(house);

    return 0;
}