//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_DOORS 4

typedef struct room {
    int id;
    int num_doors;
    struct room *doors[MAX_DOORS];
    int visited;
} room;

room *create_room(int id) {
    room *r = malloc(sizeof(room));
    r->id = id;
    r->num_doors = 0;
    for (int i = 0; i < MAX_DOORS; i++) {
        r->doors[i] = NULL;
    }
    r->visited = 0;
    return r;
}

void connect_rooms(room *r1, room *r2) {
    r1->doors[r1->num_doors++] = r2;
    r2->doors[r2->num_doors++] = r1;
}

void print_room(room *r) {
    printf("You are in room %d.\n", r->id);
    if (r->num_doors == 0) {
        printf("There are no doors in this room.\n");
    } else {
        printf("There are %d doors in this room:\n", r->num_doors);
        for (int i = 0; i < r->num_doors; i++) {
            printf("Door %d: %d\n", i + 1, r->doors[i]->id);
        }
    }
}

int choose_door(room *r) {
    if (r->num_doors == 0) {
        return -1;
    } else {
        return rand() % r->num_doors;
    }
}

void explore_room(room *r) {
    if (r->visited) {
        return;
    }

    r->visited = 1;
    print_room(r);

    int door = choose_door(r);
    if (door != -1) {
        explore_room(r->doors[door]);
    }
}

void haunted_house_simulator() {
    // Create the rooms
    room *rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = create_room(i);
    }

    // Connect the rooms
    connect_rooms(rooms[0], rooms[1]);
    connect_rooms(rooms[0], rooms[2]);
    connect_rooms(rooms[1], rooms[3]);
    connect_rooms(rooms[1], rooms[4]);
    connect_rooms(rooms[2], rooms[5]);
    connect_rooms(rooms[2], rooms[6]);
    connect_rooms(rooms[3], rooms[7]);
    connect_rooms(rooms[3], rooms[8]);
    connect_rooms(rooms[4], rooms[9]);

    // Explore the haunted house
    explore_room(rooms[0]);
}

int main() {
    srand(time(NULL));
    haunted_house_simulator();
    return 0;
}