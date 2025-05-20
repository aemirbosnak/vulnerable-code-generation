//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct room {
    int x, y, w, h;
};

struct level {
    int width, height;
    int **tiles;
    struct room *rooms;
    int num_rooms;
};

struct level *generate_level(int width, int height, int num_rooms) {
    struct level *lvl = malloc(sizeof(struct level));
    lvl->width = width;
    lvl->height = height;
    lvl->tiles = calloc(height, sizeof(int *));
    for (int i = 0; i < height; i++) {
        lvl->tiles[i] = calloc(width, sizeof(int));
    }
    lvl->rooms = malloc(num_rooms * sizeof(struct room));
    lvl->num_rooms = num_rooms;

    /* Generate rooms */
    for (int i = 0; i < num_rooms; i++) {
        struct room r;
        r.x = rand() % (width - 10) + 1;
        r.y = rand() % (height - 10) + 1;
        r.w = rand() % 7 + 4;
        r.h = rand() % 7 + 4;
        for (int y = r.y; y < r.y + r.h; y++) {
            for (int x = r.x; x < r.x + r.w; x++) {
                lvl->tiles[y][x] = 1;
            }
        }
        lvl->rooms[i] = r;
    }

    /* Connect rooms */
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = lvl->rooms[i].x + lvl->rooms[i].w/2;
        int y1 = lvl->rooms[i].y + lvl->rooms[i].h/2;
        int x2 = lvl->rooms[i+1].x + lvl->rooms[i+1].w/2;
        int y2 = lvl->rooms[i+1].y + lvl->rooms[i+1].h/2;
        while (x1 != x2) {
            lvl->tiles[y1][x1] = 1;
            if (x1 < x2) {
                x1++;
            }
            else {
                x1--;
            }
        }
        while (y1 != y2) {
            lvl->tiles[y1][x1] = 1;
            if (y1 < y2) {
                y1++;
            }
            else {
                y1--;
            }
        }
    }

    /* Add some walls and decorations */
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (lvl->tiles[y][x] == 0) {
                if ((x == 0 || x == width-1 || y == 0 || y == height-1) ||
                    (rand()%10 == 0)) {
                    lvl->tiles[y][x] = 2;
                }
            }
        }
    }

    return lvl;
}

void print_level(struct level *lvl) {
    for (int y = 0; y < lvl->height; y++) {
        for (int x = 0; x < lvl->width; x++) {
            if (lvl->tiles[y][x] == 0) {
                printf(".");
            }
            else if (lvl->tiles[y][x] == 1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    struct level *lvl = generate_level(50, 30, 7);
    print_level(lvl);
    return 0;
}