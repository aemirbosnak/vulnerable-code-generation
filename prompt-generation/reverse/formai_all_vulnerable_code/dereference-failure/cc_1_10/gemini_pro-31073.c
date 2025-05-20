//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_SIZE 10
#define MAX_ROOMS 10

typedef struct room {
    int x;
    int y;
    int width;
    int height;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
} room;

room *generate_room(int x, int y, int width, int height) {
    room *r = malloc(sizeof(room));
    r->x = x;
    r->y = y;
    r->width = width;
    r->height = height;
    r->north = NULL;
    r->south = NULL;
    r->east = NULL;
    r->west = NULL;
    return r;
}

void generate_doors(room *r) {
    int num_doors = rand() % 4;
    for (int i = 0; i < num_doors; i++) {
        int door_dir = rand() % 4;
        switch (door_dir) {
            case 0: // north
                if (r->north == NULL) {
                    r->north = generate_room(r->x, r->y + r->height, r->width, rand() % MAX_ROOM_SIZE);
                }
                break;
            case 1: // south
                if (r->south == NULL) {
                    r->south = generate_room(r->x, r->y - r->height, r->width, rand() % MAX_ROOM_SIZE);
                }
                break;
            case 2: // east
                if (r->east == NULL) {
                    r->east = generate_room(r->x + r->width, r->y, rand() % MAX_ROOM_SIZE, r->height);
                }
                break;
            case 3: // west
                if (r->west == NULL) {
                    r->west = generate_room(r->x - r->width, r->y, rand() % MAX_ROOM_SIZE, r->height);
                }
                break;
        }
    }
}

void print_room(room *r) {
    for (int i = 0; i < r->height; i++) {
        for (int j = 0; j < r->width; j++) {
            printf(".");
        }
        printf("\n");
    }
}

void print_map(room *r) {
    if (r == NULL) {
        return;
    }
    print_room(r);
    if (r->north != NULL) {
        printf("N");
    } else {
        printf(" ");
    }
    if (r->south != NULL) {
        printf("S");
    } else {
        printf(" ");
    }
    if (r->east != NULL) {
        printf("E");
    } else {
        printf(" ");
    }
    if (r->west != NULL) {
        printf("W");
    } else {
        printf(" ");
    }
    printf("\n");
    print_map(r->north);
    print_map(r->south);
    print_map(r->east);
    print_map(r->west);
}

int main() {
    srand(time(NULL));
    room *start_room = generate_room(0, 0, 5, 5);
    generate_doors(start_room);
    print_map(start_room);
    return 0;
}