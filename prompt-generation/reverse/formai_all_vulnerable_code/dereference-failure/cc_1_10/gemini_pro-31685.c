//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_ROOMS 10
#define MAX_DOORS 4

typedef struct {
    int x, y;
} Vec2i;

typedef struct {
    Vec2i pos;
    int type;
} Room;

typedef struct {
    Room *room1, *room2;
} Door;

typedef struct {
    Room *rooms;
    Door *doors;
    int num_rooms, num_doors;
} House;

House *generate_house(int seed) {
    srand(seed);

    House *house = malloc(sizeof(House));
    house->rooms = malloc(sizeof(Room) * MAX_ROOMS);
    house->doors = malloc(sizeof(Door) * MAX_DOORS);

    // Generate rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        house->rooms[i].pos.x = rand() % 100;
        house->rooms[i].pos.y = rand() % 100;
        house->rooms[i].type = rand() % 3;
    }

    // Generate doors
    for (int i = 0; i < MAX_DOORS; i++) {
        int room1 = rand() % MAX_ROOMS;
        int room2 = rand() % MAX_ROOMS;
        while (room1 == room2) {
            room2 = rand() % MAX_ROOMS;
        }
        house->doors[i].room1 = &house->rooms[room1];
        house->doors[i].room2 = &house->rooms[room2];
    }

    house->num_rooms = MAX_ROOMS;
    house->num_doors = MAX_DOORS;

    return house;
}

void free_house(House *house) {
    free(house->rooms);
    free(house->doors);
    free(house);
}

void print_house(House *house) {
    for (int i = 0; i < house->num_rooms; i++) {
        Room *room = &house->rooms[i];
        printf("Room %d: (%d, %d), type %d\n", i, room->pos.x, room->pos.y, room->type);
    }

    for (int i = 0; i < house->num_doors; i++) {
        Door *door = &house->doors[i];
        printf("Door %d: (%d, %d) to (%d, %d)\n", i, door->room1->pos.x, door->room1->pos.y, door->room2->pos.x, door->room2->pos.y);
    }
}

int main() {
    House *house = generate_house(time(NULL));
    print_house(house);
    free_house(house);
    return 0;
}