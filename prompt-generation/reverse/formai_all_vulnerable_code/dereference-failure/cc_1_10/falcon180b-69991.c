//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 50
#define MAX_ROOMS 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    char *name;
    int health;
    int attack;
} Creature;

typedef struct {
    Point pos;
    Creature *creature;
} Room;

Room *rooms;
int num_rooms;

void generate_map() {
    srand(time(NULL));
    rooms = malloc(MAX_ROOMS * sizeof(Room));
    num_rooms = 0;

    Room *start_room = &rooms[0];
    start_room->pos.x = 0;
    start_room->pos.y = 0;
    start_room->creature = NULL;

    int dx = 0, dy = 1;
    int count = 0;

    while (count < MAX_ROOMS) {
        Room *room = &rooms[num_rooms];
        room->pos.x = dx;
        room->pos.y = dy;

        if (count == 0) {
            room->creature = malloc(sizeof(Creature));
            room->creature->name = "Goblin";
            room->creature->health = 10;
            room->creature->attack = 3;
        }

        if (dx == 0 && dy == HEIGHT - 1) {
            room->creature = malloc(sizeof(Creature));
            room->creature->name = "Dragon";
            room->creature->health = 100;
            room->creature->attack = 20;
        }

        if (dx == WIDTH - 1 && dy == 0) {
            room->creature = malloc(sizeof(Creature));
            room->creature->name = "Orc";
            room->creature->health = 20;
            room->creature->attack = 5;
        }

        num_rooms++;
        count++;

        if (dy == 0) {
            dx++;
        } else if (dx == WIDTH - 1) {
            dy++;
        } else if (dy == HEIGHT - 1) {
            dx--;
        } else {
            dy--;
        }
    }
}

int main() {
    generate_map();

    return 0;
}