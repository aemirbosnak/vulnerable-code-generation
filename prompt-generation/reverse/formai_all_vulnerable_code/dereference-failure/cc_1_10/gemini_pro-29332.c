//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point pos;
    bool is_alive;
} Ghost;

typedef struct {
    Point pos;
    bool is_open;
} Door;

typedef struct {
    Point pos;
    int num_doors;
    Door* doors;
} Room;

typedef struct {
    int num_rooms;
    Room* rooms;
    int num_ghosts;
    Ghost* ghosts;
} HauntedHouse;

HauntedHouse* create_haunted_house(int num_rooms, int num_doors, int num_ghosts) {
    HauntedHouse* house = malloc(sizeof(HauntedHouse));
    house->num_rooms = num_rooms;
    house->rooms = malloc(sizeof(Room) * num_rooms);
    for (int i = 0; i < num_rooms; i++) {
        house->rooms[i].pos.x = rand() % 100;
        house->rooms[i].pos.y = rand() % 100;
        house->rooms[i].num_doors = rand() % 4;
        house->rooms[i].doors = malloc(sizeof(Door) * house->rooms[i].num_doors);
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            house->rooms[i].doors[j].pos.x = rand() % 100;
            house->rooms[i].doors[j].pos.y = rand() % 100;
            house->rooms[i].doors[j].is_open = false;
        }
    }

    house->num_ghosts = num_ghosts;
    house->ghosts = malloc(sizeof(Ghost) * num_ghosts);
    for (int i = 0; i < num_ghosts; i++) {
        house->ghosts[i].pos.x = rand() % 100;
        house->ghosts[i].pos.y = rand() % 100;
        house->ghosts[i].is_alive = true;
    }

    return house;
}

void destroy_haunted_house(HauntedHouse* house) {
    for (int i = 0; i < house->num_rooms; i++) {
        free(house->rooms[i].doors);
    }
    free(house->rooms);
    free(house->ghosts);
    free(house);
}

void print_haunted_house(HauntedHouse* house) {
    for (int i = 0; i < house->num_rooms; i++) {
        printf("Room %d:\n", i);
        printf("  Position: (%d, %d)\n", house->rooms[i].pos.x, house->rooms[i].pos.y);
        printf("  Number of doors: %d\n", house->rooms[i].num_doors);
        for (int j = 0; j < house->rooms[i].num_doors; j++) {
            printf("    Door %d:\n", j);
            printf("      Position: (%d, %d)\n", house->rooms[i].doors[j].pos.x, house->rooms[i].doors[j].pos.y);
            printf("      Is open: %s\n", house->rooms[i].doors[j].is_open ? "true" : "false");
        }
    }

    for (int i = 0; i < house->num_ghosts; i++) {
        printf("Ghost %d:\n", i);
        printf("  Position: (%d, %d)\n", house->ghosts[i].pos.x, house->ghosts[i].pos.y);
        printf("  Is alive: %s\n", house->ghosts[i].is_alive ? "true" : "false");
    }
}

int main() {
    srand(time(NULL));

    HauntedHouse* house = create_haunted_house(10, 20, 5);

    print_haunted_house(house);

    destroy_haunted_house(house);

    return 0;
}