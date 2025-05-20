//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct Room {
    struct Room* next;
    int num;
    char* description;
} Room;

Room* generateMaze(int numRooms) {
    srand(time(NULL));
    Room* head = malloc(sizeof(Room));
    head->num = 1;
    head->description = malloc(100);
    sprintf(head->description, "You are in a small room. There is a door to the north and a door to the east.");

    Room* tail = head;
    for (int i = 1; i < numRooms; i++) {
        tail->next = malloc(sizeof(Room));
        tail = tail->next;
        tail->num = i + 1;
        tail->description = malloc(100);
        sprintf(tail->description, "You are in a room. There are doors to the north, south, and east.");
    }

    return head;
}

void traverseMaze(Room* room) {
    printf("%s\n", room->description);

    if (room->next) {
        printf("There is a door to the north. Press n to go north.\n");
        printf("There is a door to the east. Press e to go east.\n");
    }

    int choice = getchar();

    switch (choice) {
        case 'n':
            traverseMaze(room->next);
            break;
        case 'e':
            // Implement east direction
            break;
    }
}

int main() {
    Room* maze = generateMaze(MAX_ROOMS);
    traverseMaze(maze);

    return 0;
}