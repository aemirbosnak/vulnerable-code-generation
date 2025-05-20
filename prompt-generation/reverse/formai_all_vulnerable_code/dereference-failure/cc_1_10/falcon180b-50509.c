//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 50
#define MAX_ROOMS 100
#define MAX_MONSTERS 100
#define MAX_ITEMS 100
#define TILE_SIZE 16

typedef struct {
    int x;
    int y;
    char symbol;
    char color;
} Tile;

typedef struct {
    int x, y;
    char symbol;
    char color;
} Entity;

typedef struct {
    int x, y;
    int w, h;
} Rect;

Tile *tiles;
Entity *entities;
Rect *rooms;
int num_tiles, num_entities, num_rooms;

void init() {
    srand(time(NULL));
    tiles = malloc(WIDTH * HEIGHT * sizeof(Tile));
    entities = malloc(MAX_MONSTERS * sizeof(Entity));
    rooms = malloc(MAX_ROOMS * sizeof(Rect));
    num_tiles = 0;
    num_entities = 0;
    num_rooms = 0;
}

void generate_map() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            tiles[num_tiles].x = i;
            tiles[num_tiles].y = j;
            tiles[num_tiles].symbol = rand() % 2? '#' : '.';
            tiles[num_tiles].color = rand() % 8;
            num_tiles++;
        }
    }
}

void generate_entities() {
    int i;
    for (i = 0; i < MAX_MONSTERS; i++) {
        entities[i].x = rand() % WIDTH;
        entities[i].y = rand() % HEIGHT;
        entities[i].symbol = 'M';
        entities[i].color = rand() % 8;
    }
}

void generate_rooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].x = rand() % WIDTH;
        rooms[i].y = rand() % HEIGHT;
        rooms[i].w = rand() % 10 + 5;
        rooms[i].h = rand() % 10 + 5;
    }
}

void draw_tile(int x, int y) {
    printf("%c", tiles[y * WIDTH + x].symbol);
}

void draw_room(int i) {
    int x, y, w, h;
    x = rooms[i].x * TILE_SIZE;
    y = rooms[i].y * TILE_SIZE;
    w = rooms[i].w * TILE_SIZE;
    h = rooms[i].h * TILE_SIZE;
    for (int j = 0; j < w; j++) {
        for (int k = 0; k < h; k++) {
            draw_tile(x + j, y + k);
        }
    }
}

void draw_entities() {
    int i;
    for (i = 0; i < num_entities; i++) {
        draw_tile(entities[i].x, entities[i].y);
    }
}

int main() {
    init();
    generate_map();
    generate_entities();
    generate_rooms();
    while (1) {
        system("clear");
        int player_x = 0;
        int player_y = 0;
        draw_entities();
        draw_tile(player_x, player_y);
        int i;
        for (i = 0; i < num_rooms; i++) {
            draw_room(i);
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}