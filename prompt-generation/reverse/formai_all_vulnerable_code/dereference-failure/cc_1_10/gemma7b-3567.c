//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 5
#define GHOST_COUNT 3

typedef struct Room {
    char name[20];
    struct Room* next;
} Room;

typedef struct Ghost {
    char name[20];
    int location;
    struct Ghost* next;
} Ghost;

Room* createRoom(char* name) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

Ghost* createGhost(char* name, int location) {
    Ghost* newGhost = malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->location = location;
    newGhost->next = NULL;
    return newGhost;
}

void haunt(Room* room, Ghost* ghost) {
    if (room && ghost) {
        printf("%s has entered %s!\n", ghost->name, room->name);
    }
}

int main() {
    srand(time(NULL));

    Room* head = createRoom("Entrance");
    Room* currentRoom = head;

    for (int i = 0; i < ROOM_COUNT - 1; i++) {
        currentRoom = createRoom(sprintf("Room %d", i + 1));
        currentRoom->next = head;
        head = currentRoom;
    }

    Ghost* headGhost = createGhost("The Poltergeist", rand() % ROOM_COUNT);
    Ghost* currentGhost = headGhost;

    for (int i = 0; i < GHOST_COUNT - 1; i++) {
        currentGhost = createGhost(sprintf("Ghost %d", i + 1), rand() % ROOM_COUNT);
        currentGhost->next = headGhost;
        headGhost = currentGhost;
    }

    printf("Welcome to the Haunted Mansion!\n");
    printf("Please enter a command: ");

    char command[20];
    scanf("%s", command);

    switch (command[0]) {
        case 'n':
            haunt(currentRoom, currentGhost);
            break;
        case 'q':
            printf("Thank you for visiting the Haunted Mansion!\n");
            break;
        default:
            printf("Invalid command.\n");
    }

    return 0;
}