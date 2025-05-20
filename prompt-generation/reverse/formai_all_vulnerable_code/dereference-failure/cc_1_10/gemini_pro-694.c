//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_ROOMS_PER_FLOOR 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point location;
    int num_doors;
    Point* doors;
} Room;

typedef struct {
    int num_floors;
    int num_rooms;
    Room* rooms;
} House;

House* create_house() {
    House* house = malloc(sizeof(House));
    house->num_floors = rand() % MAX_FLOORS + 1;
    house->num_rooms = rand() % MAX_ROOMS_PER_FLOOR + 1;
    house->rooms = malloc(sizeof(Room) * house->num_rooms);

    for (int i = 0; i < house->num_rooms; i++) {
        Room* room = &house->rooms[i];
        room->location.x = rand() % 100;
        room->location.y = rand() % 100;
        room->num_doors = rand() % 4 + 1;
        room->doors = malloc(sizeof(Point) * room->num_doors);

        for (int j = 0; j < room->num_doors; j++) {
            room->doors[j].x = rand() % 100;
            room->doors[j].y = rand() % 100;
        }
    }

    return house;
}

void print_house(House* house) {
    printf("House with %d floors and %d rooms:\n", house->num_floors, house->num_rooms);

    for (int i = 0; i < house->num_rooms; i++) {
        Room* room = &house->rooms[i];
        printf("Room %d at (%d, %d) with %d doors:\n", i, room->location.x, room->location.y, room->num_doors);

        for (int j = 0; j < room->num_doors; j++) {
            printf("Door %d at (%d, %d)\n", j, room->doors[j].x, room->doors[j].y);
        }
    }
}

int main() {
    srand(time(NULL));

    House* house = create_house();
    print_house(house);

    free(house);

    return 0;
}