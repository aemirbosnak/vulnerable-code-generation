//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Connections 5

typedef struct Room {
    int num;
    struct Room **connections;
    char name[20];
} Room;

Room **generateMaze(int numRooms) {
    srand(time(NULL));

    Room **rooms = malloc(numRooms * sizeof(Room));

    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->num = i;
        rooms[i]->connections = NULL;
        rooms[i]->name[0] = '\0';
    }

    for (int i = 0; i < numRooms; i++) {
        int numConnections = rand() % MAX_Connections;
        rooms[i]->connections = malloc(numConnections * sizeof(Room));

        for (int j = 0; j < numConnections; j++) {
            rooms[i]->connections[j] = rooms[rand() % numRooms];
        }
    }

    return rooms;
}

int main() {
    Room **maze = generateMaze(MAX_Rooms);

    for (int i = 0; i < MAX_Rooms; i++) {
        printf("Room %d: %s\n", maze[i]->num, maze[i]->name);
        for (int j = 0; j < MAX_Connections; j++) {
            if (maze[i]->connections[j]) {
                printf("  Connection to Room %d\n", maze[i]->connections[j]->num);
            }
        }
    }

    return 0;
}