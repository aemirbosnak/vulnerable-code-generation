//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAP_SIZE (WIDTH * HEIGHT)

enum tile_type {
    TILE_EMPTY = 0,
    TILE_GRASS = 1,
    TILE_DIRT = 2,
    TILE_STONE = 3,
    TILE_WATER = 4
};

void generate_map(int map[MAP_SIZE], int seed) {
    srand(seed);

    for (int i = 0; i < MAP_SIZE; ++i) {
        map[i] = rand() % 5;
    }
}

void print_map(const int map[MAP_SIZE]) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            switch (map[y * WIDTH + x]) {
                case TILE_EMPTY:
                    printf(" ");
                    break;
                case TILE_GRASS:
                    printf("#");
                    break;
                case TILE_DIRT:
                    printf(".");
                    break;
                case TILE_STONE:
                    printf("*");
                    break;
                case TILE_WATER:
                    printf("~");
                    break;
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    int map[MAP_SIZE];

    generate_map(map, seed);
    print_map(map);

    return 0;
}