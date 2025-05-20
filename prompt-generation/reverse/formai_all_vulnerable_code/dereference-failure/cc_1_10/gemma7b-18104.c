//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_PATH_LENGTH 20

typedef struct Room {
    int num;
    char **walls;
    struct Room *next;
} Room;

void generateMaze(int seed) {
    srand(seed);
    int numRooms = rand() % MAX_ROOM_NUM + 1;
    Room **rooms = malloc(numRooms * sizeof(Room));

    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->num = i + 1;
        rooms[i]->walls = malloc(4 * sizeof(char *));
        for (int j = 0; j < 4; j++) {
            rooms[i]->walls[j] = malloc(MAX_PATH_LENGTH * sizeof(char));
        }
        rooms[i]->next = NULL;
    }

    // Connect rooms
    for (int i = 0; i < numRooms - 1; i++) {
        int numConnections = rand() % MAX_PATH_LENGTH + 1;
        for (int j = 0; j < numConnections; j++) {
            int targetRoom = rand() % numRooms;
            rooms[i]->walls[j] = rooms[targetRoom];
        }
    }

    // Print the maze
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d:\n", rooms[i]->num);
        for (int j = 0; j < 4; j++) {
            printf("Walls: ");
            for (int k = 0; k < MAX_PATH_LENGTH; k++) {
                if (rooms[i]->walls[j][k] != NULL) {
                    printf("%p ", rooms[i]->walls[j][k]);
                } else {
                    printf("NULL ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    generateMaze(time(NULL));
    return 0;
}