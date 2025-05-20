//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: genius
#include <stdlib.h>
#include <stdio.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
    int num;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

Room** createMaze(int size) {
    Room** maze = malloc(size * sizeof(Room*));
    for (int i = 0; i < size; i++) {
        maze[i] = malloc(sizeof(Room));
        maze[i]->num = i;
        maze[i]->north = NULL;
        maze[i]->south = NULL;
        maze[i]->east = NULL;
        maze[i]->west = NULL;
    }

    return maze;
}

void generatePaths(Room** maze, int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        int r = rand() % MAX_PATHS;
        switch (r) {
            case 0:
                maze[i]->north = maze[rand() % MAX_ROOMS];
                break;
            case 1:
                maze[i]->south = maze[rand() % MAX_ROOMS];
                break;
            case 2:
                maze[i]->east = maze[rand() % MAX_ROOMS];
                break;
            case 3:
                maze[i]->west = maze[rand() % MAX_ROOMS];
                break;
            default:
                break;
        }
    }
}

void traverseMaze(Room** maze, int currentRoom) {
    printf("You are in room %d.\n", currentRoom);
    if (maze[currentRoom]->north) {
        printf("You can go north to room %d.\n", maze[currentRoom]->north->num);
    }
    if (maze[currentRoom]->south) {
        printf("You can go south to room %d.\n", maze[currentRoom]->south->num);
    }
    if (maze[currentRoom]->east) {
        printf("You can go east to room %d.\n", maze[currentRoom]->east->num);
    }
    if (maze[currentRoom]->west) {
        printf("You can go west to room %d.\n", maze[currentRoom]->west->num);
    }
    printf("\n");
}

int main() {
    int size = 10;
    Room** maze = createMaze(size);
    generatePaths(maze, size);
    traverseMaze(maze, 0);

    return 0;
}