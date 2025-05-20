//MISTRAL-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 10
#define ROOM_MIN_SIZE 5
#define ROOM_MAX_SIZE 15

typedef struct {
    int x, y;
} pos_t;

typedef struct {
    int w, h;
    int **map;
} level_t;

void generate_room(level_t *level, pos_t pos, int size) {
    int i, j;
    for (i = pos.y; i < pos.y + size; ++i) {
        for (j = pos.x; j < pos.x + size; ++j) {
            if (i >= 0 && i < level->h && j >= 0 && j < level->w) {
                level->map[i][j] = 1;
            }
        }
    }
}

void generate_level(level_t *level) {
    int i, j, rooms = 3;
    pos_t pos;
    int room_size;

    srand(time(NULL));

    level->w = WIDTH;
    level->h = HEIGHT;
    level->map = malloc(sizeof(int *) * level->h);
    for (i = 0; i < level->h; ++i) {
        level->map[i] = calloc(level->w, sizeof(int));
    }

    for (i = 0; i < level->h; ++i) {
        for (j = 0; j < level->w; ++j) {
            level->map[i][j] = 0;
        }
    }

    while (rooms--) {
        do {
            pos.x = rand() % (level->w - ROOM_MAX_SIZE) + 1;
            pos.y = rand() % (level->h - ROOM_MIN_SIZE) + 1;
        } while (isValidRoom(level, pos, ROOM_MIN_SIZE, ROOM_MAX_SIZE));

        room_size = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;

        generate_room(level, pos, room_size);
    }
}

int isValidRoom(level_t *level, pos_t pos, int min_size, int max_size) {
    int i, j, room_w, room_h;

    room_w = pos.x + max_size;
    room_h = pos.y + min_size;

    for (i = pos.y; i < room_h; ++i) {
        for (j = pos.x; j < room_w; ++j) {
            if (i >= 0 && i < level->h && j >= 0 && j < level->w && level->map[i][j] != 0) {
                return 0;
            }
        }
    }

    return 1;
}

void print_level(level_t *level) {
    int i, j;
    for (i = 0; i < level->h; ++i) {
        for (j = 0; j < level->w; ++j) {
            putchar(level->map[i][j] == 1 ? '#' : '.');
        }
        putchar('\n');
    }
}

int main() {
    level_t level;

    generate_level(&level);
    print_level(&level);

    free(level.map);
    return 0;
}