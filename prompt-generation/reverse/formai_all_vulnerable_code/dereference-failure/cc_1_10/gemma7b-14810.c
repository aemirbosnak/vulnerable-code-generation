//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

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
        newRoom->x = rand() % WIDTH;
        newRoom->y = rand() % HEIGHT;
        newRoom->next = NULL;

        if (!head) {
            head = newRoom;
        } else {
            head->next = newRoom;
            head = newRoom;
        }
    }

    return head;
}

void printMaze(Room* room) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (room->x == x && room->y == y) {
                printf("O ");
            } else {
                printf(". ");
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