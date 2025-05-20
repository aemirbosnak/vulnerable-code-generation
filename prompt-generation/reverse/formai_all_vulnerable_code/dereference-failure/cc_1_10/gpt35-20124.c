//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct room {
    int x;
    int y;
    int width;
    int height;
};

void printMap(char **map, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void generateMap(char **map, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            map[i][j] = '#';
        }
    }

    srand(time(NULL));

    int numRooms = rand() % 5 + 4;
    struct room *rooms = malloc(sizeof(struct room) * numRooms);

    for (int i = 0; i < numRooms; i++) {
        struct room r = {rand() % (size - 6) + 3, rand() % (size - 6) + 3,
                         rand() % 4 + 5, rand() % 4 + 5};
        int intersects = 0;
        for (int j = 0; j < i; j++) {
            if (r.x + r.width >= rooms[j].x && r.x <= rooms[j].x + rooms[j].width &&
                r.y + r.height >= rooms[j].y && r.y <= rooms[j].y + rooms[j].height) {
                intersects = 1;
                break;
            }
        }
        if (!intersects) {
            for (int j = r.y; j < r.y + r.height; j++) {
                for (int k = r.x; k < r.x + r.width; k++) {
                    map[j][k] = '.';
                }
            }
            rooms[i] = r;
        } else {
            i--;
        }
    }

    for (int i = 0; i < numRooms - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;

        int x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].height / 2;

        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
                map[y1][x1] = '.';
            } else if (x1 > x2) {
                x1--;
                map[y1][x1] = '.';
            }

            if (y1 < y2) {
                y1++;
                map[y1][x1] = '.';
            } else if (y1 > y2) {
                y1--;
                map[y1][x1] = '.';
            }
        }
    }

    free(rooms);
}

int main() {
    int size = 20;
    char **map = malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(char) * size);
    }

    generateMap(map, size);
    printMap(map, size);

    for (int i = 0; i < size; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}