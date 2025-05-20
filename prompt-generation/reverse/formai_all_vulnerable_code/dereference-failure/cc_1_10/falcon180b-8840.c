//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int** create_map(int width, int height) {
    int** map = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            map[i][j] = rand_range(0, 1);
        }
    }
    return map;
}

void print_map(int** map, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int width = 50;
    int height = 25;

    int** map = create_map(width, height);

    print_map(map, width, height);

    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}