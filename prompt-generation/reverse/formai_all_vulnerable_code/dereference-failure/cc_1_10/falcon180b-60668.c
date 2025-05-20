//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point top_left;
    Point bottom_right;
} Rectangle;

void generate_dungeon(char map[HEIGHT][WIDTH], Point player_pos) {
    srand(time(0));

    int num_rooms = rand() % MAX_ROOMS + 1;

    for (int i = 0; i < num_rooms; i++) {
        int room_x = rand() % (HEIGHT - 5) + 1;
        int room_y = rand() % (WIDTH - 5) + 1;
        int room_w = rand() % 5 + 3;
        int room_h = rand() % 5 + 3;

        Rectangle room = {
            {room_x, room_y},
            {room_x + room_w - 1, room_y + room_h - 1}
        };

        if (room_x == player_pos.x && room_y == player_pos.y) {
            room_x += 1;
            room_y += 1;
        }

        for (int j = room.top_left.y; j <= room.bottom_right.y; j++) {
            for (int k = room.top_left.x; k <= room.bottom_right.x; k++) {
                map[j][k] = '#';
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] == '#') {
                map[i][j] = '.';
            }
        }
    }

    map[player_pos.y][player_pos.x] = '@';
}

void print_map(char map[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char map[HEIGHT][WIDTH];
    Point player_pos = {0, 0};

    generate_dungeon(map, player_pos);

    print_map(map);

    return 0;
}