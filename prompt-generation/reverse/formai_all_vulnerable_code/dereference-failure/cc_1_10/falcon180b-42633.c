//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the structure of a room
typedef struct {
    char name[50];
    int is_haunted;
    int has_treasure;
} Room;

// Initialize the rooms
void init_rooms(Room rooms[]) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].is_haunted = rand() % 2;
        rooms[i].has_treasure = rand() % 2;
    }
}

// Print the current room
void print_room(Room room) {
    printf("You are in the %s.\n", room.name);
    if (room.is_haunted) {
        printf("You feel a chill down your spine.\n");
    } else {
        printf("The room is quiet and peaceful.\n");
    }
    if (room.has_treasure) {
        printf("You see a shiny object in the corner.\n");
    } else {
        printf("The room is empty.\n");
    }
}

// Move to a different room
void move(Room rooms[], int num_rooms, int current_room, int direction) {
    int new_room;
    if (direction == 1) {
        new_room = (current_room + 1) % num_rooms;
    } else {
        new_room = (current_room - 1 + num_rooms) % num_rooms;
    }
    print_room(rooms[new_room]);
    current_room = new_room;
}

// Main function
int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOMS];
    init_rooms(rooms);

    int current_room = 0;
    int num_rooms = 0;

    while (1) {
        system("clear");
        print_room(rooms[current_room]);
        printf("What do you want to do? ");
        char action[50];
        scanf("%s", action);

        if (strcmp(action, "move") == 0) {
            int direction;
            printf("Which direction? ");
            scanf("%d", &direction);
            move(rooms, num_rooms, current_room, direction);
        } else if (strcmp(action, "quit") == 0) {
            break;
        }
    }

    return 0;
}