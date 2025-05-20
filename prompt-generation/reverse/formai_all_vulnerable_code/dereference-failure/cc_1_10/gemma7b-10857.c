//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

#define MAX_ROOM_COUNT 5

typedef struct Room {
    int x;
    int y;
    struct Room* next;
} Room;

Room* generateRooms(int roomCount) {
    srand(time(NULL));
    Room* head = malloc(sizeof(Room));
    head->x = rand() % MAZE_WIDTH;
    head->y = rand() % MAZE_HEIGHT;
    head->next = NULL;

    for (int i = 1; i < roomCount; i++) {
        Room* newRoom = malloc(sizeof(Room));
        newRoom->x = rand() % MAZE_WIDTH;
        newRoom->y = rand() % MAZE_HEIGHT;
        newRoom->next = head;
        head = newRoom;
    }

    return head;
}

void drawMaze(Room* room) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (x == room->x && y == room->y) {
                printf("%c ", PLAYER_CHAR);
            } else if (room->next) {
                printf("%c ", EMPTY_CHAR);
            } else {
                printf("%c ", WALL_CHAR);
            }
        }
        printf("\n");
    }
}

int main() {
    int roomCount = rand() % MAX_ROOM_COUNT + 1;
    Room* room = generateRooms(roomCount);
    drawMaze(room);

    return 0;
}