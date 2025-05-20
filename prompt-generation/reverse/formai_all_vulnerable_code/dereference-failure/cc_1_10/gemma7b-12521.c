//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_PATH_NUM 20

typedef struct room {
    int num;
    struct room* north;
    struct room* south;
    struct room* east;
    struct room* west;
} room;

room* generateMaze(int seed) {
    srand(seed);
    room* head = malloc(sizeof(room));
    head->num = 1;
    head->north = NULL;
    head->south = NULL;
    head->east = NULL;
    head->west = NULL;

    room* current = head;
    for (int i = 2; i <= MAX_ROOM_NUM; i++) {
        current->north = malloc(sizeof(room));
        current->north->num = i;
        current->south = malloc(sizeof(room));
        current->south->num = i + 1;
        current->east = malloc(sizeof(room));
        current->east->num = i + 2;
        current->west = malloc(sizeof(room));
        current->west->num = i + 3;

        int direction = rand() % MAX_PATH_NUM;
        switch (direction) {
            case 0:
                current->north->south = current;
                current->south = current->north;
                break;
            case 1:
                current->east->west = current;
                current->west = current->east;
                break;
            case 2:
                current->south->north = current;
                current->north = current->south;
                break;
            case 3:
                current->west->east = current;
                current->east = current->west;
                break;
        }

        current = current->south;
    }

    return head;
}

int main() {
    room* maze = generateMaze(time(NULL));
    // Do something with the maze
    return 0;
}