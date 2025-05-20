//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 20
#define MAX_ROOMS 100

enum {
    WALL = '#',
    FLOOR = '.',
    DOOR = '+',
    PLAYER = '@'
};

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point top_left;
    Point bottom_right;
} Rectangle;

void generate_map(char map[HEIGHT][WIDTH]) {
    int num_rooms = rand() % MAX_ROOMS + 1;
    Rectangle rooms[num_rooms];
    int i;

    for (i = 0; i < num_rooms; i++) {
        rooms[i].top_left.x = rand() % (HEIGHT - 5) + 2;
        rooms[i].top_left.y = rand() % (WIDTH - 5) + 2;
        rooms[i].bottom_right.x = rooms[i].top_left.x + 4;
        rooms[i].bottom_right.y = rooms[i].top_left.y + 4;

        int door_x = rand() % (rooms[i].bottom_right.x - rooms[i].top_left.x + 1) + rooms[i].top_left.x;
        int door_y = rand() % (rooms[i].bottom_right.y - rooms[i].top_left.y + 1) + rooms[i].top_left.y;

        map[rooms[i].top_left.y][rooms[i].top_left.x] = DOOR;
        map[door_y][door_x] = DOOR;
    }

    int start_x = rand() % (HEIGHT - 5) + 2;
    int start_y = rand() % (WIDTH - 5) + 2;
    map[start_y][start_x] = PLAYER;

    for (i = 0; i < HEIGHT; i++) {
        map[i][0] = WALL;
        map[i][WIDTH - 1] = WALL;
    }

    for (i = 0; i < WIDTH; i++) {
        map[0][i] = WALL;
        map[HEIGHT - 1][i] = WALL;
    }
}

void print_map(char map[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char map[HEIGHT][WIDTH];

    generate_map(map);
    print_map(map);

    return 0;
}