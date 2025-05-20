//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_WALLS 20

typedef struct Room {
    int x, y;
    struct Room* next;
} Room;

Room* CreateRoom(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->next = NULL;
    return room;
}

void ConnectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

void GenerateMaze(int width, int height) {
    srand(time(NULL));

    // Create the rooms
    Room* head = CreateRoom(0, 0);
    Room* current = head;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            current = CreateRoom(x, y);
            ConnectRooms(head, current);
            head = current;
        }
    }

    // Connect the walls
    int numWalls = rand() % MAX_WALLS;
    for (int i = 0; i < numWalls; i++) {
        int x1 = rand() % width;
        int y1 = rand() % height;
        int x2 = rand() % width;
        int y2 = rand() % height;

        ConnectRooms(CreateRoom(x1, y1), CreateRoom(x2, y2));
    }
}

int main() {
    GenerateMaze(5, 5);
    return 0;
}