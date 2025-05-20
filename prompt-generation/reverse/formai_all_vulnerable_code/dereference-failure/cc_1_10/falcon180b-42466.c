//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generateMap(int width, int height, char map[height][width]) {
    int startX = 0;
    int startY = 0;
    map[startY][startX] = '.';

    int dirX = 0;
    int dirY = 1;

    while (1) {
        map[startY][startX] = '.';
        startX += dirX;
        startY += dirY;

        if (startX >= width || startX < 0 || startY >= height || startY < 0) {
            dirX = -dirX;
            dirY = -dirY;
        }

        if (map[startY][startX] == '#') {
            dirX = -dirX;
        }
    }
}

int main() {
    srand(time(NULL));

    int width = 50;
    int height = 50;
    char map[height][width];

    generateMap(width, height, map);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}