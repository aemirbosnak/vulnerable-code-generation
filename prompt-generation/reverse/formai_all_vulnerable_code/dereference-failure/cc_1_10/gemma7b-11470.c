//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 20

typedef struct Room {
    int x, y;
    struct Room* north, *south, *east, *west;
} Room;

Room* generateMaze(int size) {
    srand(time(NULL));

    Room* rooms = malloc(size * sizeof(Room));

    for (int i = 0; i < size; i++) {
        rooms[i].x = rand() % size;
        rooms[i].y = rand() % size;

        rooms[i].north = NULL;
        rooms[i].south = NULL;
        rooms[i].east = NULL;
        rooms[i].west = NULL;
    }

    for (int i = 0; i < size; i++) {
        int r1 = rand() % size;
        int r2 = rand() % size;

        if (r1 != r2) {
            rooms[i].north = &rooms[r1];
            rooms[r2].south = &rooms[i];
        }
    }

    return rooms;
}

int main() {
    Room* maze = generateMaze(MAX_Rooms);

    // Print the maze
    for (int i = 0; i < MAX_Rooms; i++) {
        printf("(%d, %d) ", maze[i].x, maze[i].y);
        if (maze[i].north) {
            printf("N ");
        }
        if (maze[i].south) {
            printf("S ");
        }
        if (maze[i].east) {
            printf("E ");
        }
        if (maze[i].west) {
            printf("W ");
        }
        printf("\n");
    }

    return 0;
}