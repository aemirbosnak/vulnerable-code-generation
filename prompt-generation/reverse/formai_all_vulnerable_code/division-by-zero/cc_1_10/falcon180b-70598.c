//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    WALL = '#',
    FLOOR = '.',
    DOOR = '+',
    PLAYER = '@'
};

void generate_map(char **map, int width, int height) {
    int x, y;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            map[y][x] = FLOOR;
        }
    }

    srand(time(NULL));
    int doors = rand() % 10 + 1;
    int placed_doors = 0;

    while(placed_doors < doors) {
        int dx = rand() % width;
        int dy = rand() % height;

        if(map[dy][dx] == FLOOR) {
            map[dy][dx] = DOOR;
            placed_doors++;
        }
    }
}

void print_map(char **map, int width, int height) {
    int x, y;
    for(y = 0; y < height; y++) {
        for(x = 0; x < width; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width and height of the map: ");
    scanf("%d %d", &width, &height);

    char **map = (char **)malloc(sizeof(char *) * height);
    for(int i = 0; i < height; i++) {
        map[i] = (char *)malloc(sizeof(char) * width);
    }

    generate_map(map, width, height);
    print_map(map, width, height);

    return 0;
}