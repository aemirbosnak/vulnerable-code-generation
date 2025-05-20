//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 80

// Define colors
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define MAGENTA 6
#define CYAN 7

// Define structures
typedef struct {
    int x;
    int y;
    char symbol;
    int color;
} Cell;

typedef struct {
    int width;
    int height;
    Cell **cells;
} Map;

void generateMap(Map *map) {
    // Initialize map
    map->width = COLS;
    map->height = ROWS;
    map->cells = (Cell **) malloc(map->height * sizeof(Cell *));
    for (int i = 0; i < map->height; i++) {
        map->cells[i] = (Cell *) malloc(map->width * sizeof(Cell));
    }

    // Fill map with random symbols
    srand(time(NULL));
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            map->cells[i][j].symbol = rand() % 10 + '0';
            map->cells[i][j].color = rand() % 7;
        }
    }
}

void printMap(Map *map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%c", map->cells[i][j].symbol);
        }
        printf("\n");
    }
}

int main() {
    Map map;
    generateMap(&map);
    printMap(&map);

    return 0;
}