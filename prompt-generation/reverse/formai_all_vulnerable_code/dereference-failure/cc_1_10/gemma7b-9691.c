//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int hasKey;
    int hasSecret;
} Room;

Room* createRoom(char* name, int hasKey, int hasSecret) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->hasKey = hasKey;
    newRoom->hasSecret = hasSecret;
    return newRoom;
}

void explore(Room* currentRoom) {
    printf("You are in the %s.\n", currentRoom->name);

    if (currentRoom->hasKey) {
        printf("There is a key on the table.\n");
    }

    if (currentRoom->hasSecret) {
        printf("There is a secret hidden in this room.\n");
    }

    printf("Please enter the direction you want to go (north, south, east, west): ");
    char direction;
    scanf("%c", &direction);

    switch (direction) {
        case 'n':
            explore(currentRoom->next);
            break;
        case 's':
            // Implement south direction
            break;
        case 'e':
            // Implement east direction
            break;
        case 'w':
            // Implement west direction
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

int main() {
    Room* room1 = createRoom("The Hallway", 1, 0);
    Room* room2 = createRoom("The Library", 0, 1);
    Room* room3 = createRoom("The Bedroom", 0, 0);

    room1->next = room2;
    room2->next = room3;

    explore(room1);

    return 0;
}