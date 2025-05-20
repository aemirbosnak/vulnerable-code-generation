//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to represent a room
typedef struct {
    char name[50];
    int is_haunted;
    int is_visited;
} Room;

// Function to initialize a room
void init_room(Room* room) {
    room->is_haunted = rand() % 2;
    room->is_visited = 0;
}

// Function to print a room
void print_room(Room* room) {
    if (room->is_haunted) {
        printf("You enter a haunted room.\n");
    } else {
        printf("You enter an empty room.\n");
    }
}

// Function to simulate the haunted house
void haunted_house(int num_rooms) {
    Room rooms[num_rooms];

    // Initialize all rooms
    for (int i = 0; i < num_rooms; i++) {
        init_room(&rooms[i]);
    }

    // Simulate the haunted house
    int current_room = 0;
    while (current_room < num_rooms) {
        print_room(&rooms[current_room]);
        current_room = (current_room + 1) % num_rooms;
    }
}

int main() {
    int num_rooms;

    // Get the number of rooms from the user
    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);

    // Simulate the haunted house
    srand(time(NULL));
    haunted_house(num_rooms);

    return 0;
}