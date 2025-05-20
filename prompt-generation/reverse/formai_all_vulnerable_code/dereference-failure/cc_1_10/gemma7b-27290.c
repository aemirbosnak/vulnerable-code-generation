//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

typedef struct Room {
    char name[20];
    struct Room* nextRoom;
    int hasKey;
} Room;

Room* createRoom(char* name, int hasKey) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->nextRoom = NULL;
    newRoom->hasKey = hasKey;
    return newRoom;
}

void playGame() {
    Room* currentRoom = createRoom("The Hallway", 1);
    Room* secondRoom = createRoom("The Kitchen", 0);
    currentRoom->nextRoom = secondRoom;
    secondRoom->nextRoom = currentRoom;

    int choice;
    printf("You are in %s. You have a key if you need it.\n", currentRoom->name);

    printf("What do you want to do? (1) Go to the kitchen, (2) Search the room, (3) Use the key?\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            currentRoom = secondRoom;
            printf("You have entered the kitchen.\n");
            break;
        case 2:
            // Search the room code
            break;
        case 3:
            // Use the key code
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    playGame();
}

int main() {
    playGame();

    return 0;
}