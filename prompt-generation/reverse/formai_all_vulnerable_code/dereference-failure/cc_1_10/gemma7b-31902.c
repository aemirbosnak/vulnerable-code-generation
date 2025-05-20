//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
    char name[20];
    struct Room** connections;
    int numConnections;
} Room;

Room** createMaze(int numRooms) {
    Room** maze = malloc(numRooms * sizeof(Room));
    for (int i = 0; i < numRooms; i++) {
        maze[i] = malloc(sizeof(Room));
        maze[i]->connections = malloc((MAX_PATHS) * sizeof(struct Room*));
        maze[i]->numConnections = 0;
    }
    return maze;
}

void generatePaths(Room** maze) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int numPaths = rand() % MAX_PATHS;
        for (int j = 0; j < numPaths; j++) {
            int destination = rand() % MAX_ROOMS;
            while (destination == i) {
                destination = rand() % MAX_ROOMS;
            }
            maze[i]->connections[maze[i]->numConnections++] = maze[destination];
        }
    }
}

void printMaze(Room** maze) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%s: ", maze[i]->name);
        for (int j = 0; j < maze[i]->numConnections; j++) {
            printf("%s, ", maze[i]->connections[j]->name);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int numRooms = 5;
    Room** maze = createMaze(numRooms);
    generatePaths(maze);
    printMaze(maze);

    return 0;
}