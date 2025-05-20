//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_ROOMS 10
#define MAX_LINES 80

typedef struct {
    int x, y;
} Coord;

typedef struct {
    char *name;
    Coord pos;
} Room;

Room rooms[MAX_ROOMS];
char map[ROWS][COLS];
int num_rooms;

void init_map() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '#';
        }
    }
}

void create_room(int x, int y) {
    if (num_rooms >= MAX_ROOMS) {
        printf("Too many rooms!\n");
        exit(1);
    }

    rooms[num_rooms].pos.x = x;
    rooms[num_rooms].pos.y = y;
    rooms[num_rooms].name = malloc(32);
    sprintf(rooms[num_rooms].name, "Room %d", num_rooms + 1);

    num_rooms++;
}

void generate_map() {
    srand(time(NULL));

    for (int i = 0; i < num_rooms; i++) {
        int attempts = 0;

        while (attempts < 100) {
            Coord pos = {rand() % ROWS, rand() % COLS};

            if (map[pos.x][pos.y] == '#' &&!is_occupied(pos)) {
                map[pos.x][pos.y] = 'R' + i;
                rooms[i].pos = pos;
                break;
            }

            attempts++;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == '#') {
                create_room(i, j);
            }
        }
    }
}

int is_occupied(Coord pos) {
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].pos.x == pos.x && rooms[i].pos.y == pos.y) {
            return 1;
        }
    }

    return 0;
}

void print_map() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    init_map();
    generate_map();
    print_map();

    return 0;
}