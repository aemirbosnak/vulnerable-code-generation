//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MIN_ROOMS 5
#define MAX_GHOSTS 5

struct room {
    int id;
    int num_ghosts;
    struct room* north;
    struct room* south;
    struct room* east;
    struct room* west;
};

struct room* current_room;
struct room* all_rooms[MAX_ROOMS];

void generate_rooms(int num_rooms) {
    int i;
    srand(time(NULL)); // seed random number generator
    for (i = 0; i < num_rooms; i++) {
        all_rooms[i] = (struct room*)malloc(sizeof(struct room));
        all_rooms[i]->id = i;
        all_rooms[i]->num_ghosts = rand() % MAX_GHOSTS; // generate random number of ghosts
        all_rooms[i]->north = NULL;
        all_rooms[i]->south = NULL;
        all_rooms[i]->east = NULL;
        all_rooms[i]->west = NULL;
    }
    // connect rooms randomly
    for (i = 0; i < num_rooms; i++) {
        int north = rand() % num_rooms;
        int south = rand() % num_rooms;
        int east = rand() % num_rooms;
        int west = rand() % num_rooms;
        all_rooms[i]->north = all_rooms[north];
        all_rooms[i]->south = all_rooms[south];
        all_rooms[i]->east = all_rooms[east];
        all_rooms[i]->west = all_rooms[west];
    }
}

void print_room(int id) {
    printf("You are in room %d.\n", id);
    printf("There are %d ghosts in this room.\n", current_room->num_ghosts);
    printf("You can go: ");
    if (current_room->north != NULL) printf("north ");
    if (current_room->south != NULL) printf("south ");
    if (current_room->east != NULL) printf("east ");
    if (current_room->west != NULL) printf("west ");
    printf("\n");
}

void move(char direction) {
    struct room* next_room = NULL;
    switch (direction) {
        case 'n': next_room = current_room->north; break;
        case 's': next_room = current_room->south; break;
        case 'e': next_room = current_room->east; break;
        case 'w': next_room = current_room->west; break;
        default: printf("Invalid direction.\n"); return;
    }
    if (next_room != NULL) {
        current_room = next_room;
    } else {
        printf("You cannot go that way.\n");
    }
}

int main() {
    int num_rooms = rand() % (MAX_ROOMS - MIN_ROOMS) + MIN_ROOMS;
    generate_rooms(num_rooms);
    current_room = all_rooms[0];
    char direction;
    while (1) {
        print_room(current_room->id);
        printf("Which direction do you want to go? (n/s/e/w): ");
        scanf("%c", &direction);
        move(direction);
    }
    return 0;
}