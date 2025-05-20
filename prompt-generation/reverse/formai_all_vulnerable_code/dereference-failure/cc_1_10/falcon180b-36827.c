//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_ROOM_SIZE 10
#define MAX_ENEMIES 50
#define MAX_ITEMS 50

typedef struct {
    int x, y;
} Point;

typedef struct {
    char symbol;
    int color;
} Tile;

typedef struct {
    Tile *tiles;
    int width, height;
} Room;

typedef struct {
    char name[20];
    int attack, defense;
} Enemy;

typedef struct {
    char name[20];
    int value;
} Item;

Room rooms[MAX_ROOMS];
Enemy enemies[MAX_ENEMIES];
Item items[MAX_ITEMS];

void generate_room(int room_index) {
    int i, j;
    rooms[room_index].tiles = malloc(MAX_ROOM_SIZE * MAX_ROOM_SIZE * sizeof(Tile));
    rooms[room_index].width = rand() % MAX_ROOM_SIZE + 5;
    rooms[room_index].height = rand() % MAX_ROOM_SIZE + 5;

    for (i = 0; i < rooms[room_index].width; i++) {
        for (j = 0; j < rooms[room_index].height; j++) {
            rooms[room_index].tiles[i * rooms[room_index].height + j].symbol = rand() % 26 + 'A';
            rooms[room_index].tiles[i * rooms[room_index].height + j].color = rand() % 8;
        }
    }
}

void generate_enemies() {
    int i;
    for (i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].name[0] = '\0';
        enemies[i].attack = rand() % 10 + 1;
        enemies[i].defense = rand() % 10 + 1;
    }
}

void generate_items() {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].value = rand() % 100;
    }
}

int main() {
    srand(time(NULL));

    generate_room(0);
    generate_enemies();
    generate_items();

    return 0;
}