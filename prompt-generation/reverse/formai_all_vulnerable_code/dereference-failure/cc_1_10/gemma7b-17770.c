//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_ROOM 20

typedef struct Room {
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
    int num;
} Room;

Room** generateMaze(int size) {
    Room** maze = malloc(size * sizeof(Room*));
    for (int i = 0; i < size; i++) {
        maze[i] = malloc(sizeof(Room));
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
        maze[i]->num = i + 1;
    }

    return maze;
}

void printMaze(Room** maze) {
    for (int i = 0; i < MAX_ROOM; i++) {
        printf("Room %d: ", maze[i]->num);
        if (maze[i]->north) {
            printf("North to Room %d ", maze[i]->north->num);
        } else {
            printf("No north exit");
        }
        printf(", ");
        if (maze[i]->south) {
            printf("South to Room %d ", maze[i]->south->num);
        } else {
            printf("No south exit");
        }
        printf(", ");
        if (maze[i]->east) {
            printf("East to Room %d ", maze[i]->east->num);
        } else {
            printf("No east exit");
        }
        printf(", ");
        if (maze[i]->west) {
            printf("West to Room %d ", maze[i]->west->num);
        } else {
            printf("No west exit");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_ROOM + 5;
    Room** maze = generateMaze(size);
    printMaze(maze);

    return 0;
}