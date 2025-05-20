//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_DOORS 4

// Structure to represent a room in the house
typedef struct Room {
    int num_doors;
    int doors[MAX_DOORS];
    int visited;
} Room;

// Structure to represent the haunted house
typedef struct House {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} House;

// Function to create a new house
House* create_house() {
    House* house = malloc(sizeof(House));
    house->num_rooms = 0;
    return house;
}

// Function to add a new room to the house
void add_room(House* house, Room room) {
    house->rooms[house->num_rooms] = room;
    house->num_rooms++;
}

// Function to generate a random house
House* generate_house() {
    House* house = create_house();

    // Create the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room room;
        room.num_doors = rand() % MAX_DOORS + 1;
        for (int j = 0; j < room.num_doors; j++) {
            room.doors[j] = rand() % MAX_ROOMS;
        }
        room.visited = 0;
        add_room(house, room);
    }

    // Connect the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            int door = house->rooms[i].doors[j];
            if (door != i && house->rooms[door].visited == 0) {
                house->rooms[i].doors[j] = door;
                house->rooms[door].doors[house->rooms[door].num_doors++] = i;
                house->rooms[door].visited = 1;
            }
        }
    }

    return house;
}

// Function to print the house
void print_house(House* house) {
    for (int i = 0; i < house->num_rooms; i++) {
        printf("Room %d:\n", i);
        printf("  Number of doors: %d\n", house->rooms[i].num_doors);
        printf("  Doors: ");
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            printf("%d ", house->rooms[i].doors[j]);
        }
        printf("\n");
    }
}

// Function to simulate walking through the house
void walk_through_house(House* house) {
    int current_room = 0;

    while (current_room != -1) {
        // Print the current room
        printf("You are in room %d.\n", current_room);

        // Get the user's input
        int next_room;
        printf("Which room would you like to go to? (-1 to quit): ");
        scanf("%d", &next_room);

        // Check if the user wants to quit
        if (next_room == -1) {
            break;
        }

        // Check if the user's input is valid
        if (next_room < 0 || next_room >= house->num_rooms) {
            printf("Invalid room number.\n");
            continue;
        }

        // Check if the door to the next room is locked
        int door_locked = 0;
        for (int i = 0; i < house->rooms[current_room].num_doors; i++) {
            if (house->rooms[current_room].doors[i] == next_room) {
                door_locked = 0;
                break;
            }
        }

        if (door_locked) {
            printf("The door to that room is locked.\n");
            continue;
        }

        // Move to the next room
        current_room = next_room;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random house
    House* house = generate_house();

    // Print the house
    print_house(house);

    // Simulate walking through the house
    walk_through_house(house);

    return 0;
}