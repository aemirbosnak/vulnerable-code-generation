//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 20

typedef struct Room {
    int x, y;
    struct Room* next;
} Room;

Room* generateMaze(int numRooms) {
    srand(time(NULL));
    Room* head = malloc(sizeof(Room));
    head->x = 0;
    head->y = 0;
    head->next = NULL;

    for (int i = 0; i < numRooms; i++) {
        Room* newRoom = malloc(sizeof(Room));
        newRoom->x = rand() % 10;
        newRoom->y = rand() % 10;
        newRoom->next = NULL;

        if (head) {
            head->next = newRoom;
            head = newRoom;
        } else {
            head = newRoom;
        }
    }

    return head;
}

void printMaze(Room* room) {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            Room* currentRoom = room;
            while (currentRoom) {
                if (currentRoom->x == x && currentRoom->y == y) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Room* maze = generateMaze(MAX_ROOMS);
    printMaze(maze);

    return 0;
}