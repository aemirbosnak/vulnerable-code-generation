//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int hasKey;
    int isVisited;
} Room;

Room* createRoom(char* name, int hasKey) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->hasKey = hasKey;
    newRoom->isVisited = 0;
    return newRoom;
}

void playGame() {
    Room* currentRoom = createRoom("The Living Room", 1);
    currentRoom = createRoom("The Kitchen", 0);
    currentRoom = createRoom("The Bedroom", 1);
    currentRoom = createRoom("The Office", 0);
    currentRoom = createRoom("The Basement", 1);

    currentRoom = currentRoom->next;

    while (!currentRoom->isVisited) {
        printf("You are in the %s. What do you want to do? (go/search/take/leave)\n", currentRoom->name);
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "go") == 0) {
            currentRoom = currentRoom->next;
        } else if (strcmp(input, "search") == 0) {
            printf("There is nothing here.\n");
        } else if (strcmp(input, "take") == 0) {
            if (currentRoom->hasKey) {
                printf("You took the key.\n");
                currentRoom->hasKey = 0;
            } else {
                printf("There is no key here.\n");
            }
        } else if (strcmp(input, "leave") == 0) {
            printf("You left the room.\n");
            currentRoom->isVisited = 1;
        } else {
            printf("Invalid input.\n");
        }
    }

    printf("You have won the game!\n");
}

int main() {
    playGame();
    return 0;
}