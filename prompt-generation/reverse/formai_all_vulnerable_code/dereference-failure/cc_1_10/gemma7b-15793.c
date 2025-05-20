//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 10

typedef struct Room {
    char name[20];
    struct Room *next;
} Room;

Room *createRoom(char *name) {
    Room *newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void connectRooms(Room *room1, Room *room2) {
    room1->next = room2;
}

int main() {
    Room *start = createRoom("The Entrance");
    Room *hallway = createRoom("The Hallway");
    Room *kitchen = createRoom("The Kitchen");
    Room *bedroom = createRoom("The Bedroom");

    connectRooms(start, hallway);
    connectRooms(hallway, kitchen);
    connectRooms(hallway, bedroom);

    printf("Welcome to the labyrinth of mystery!\n");
    printf("You are in %s.\n", start->name);

    // Game loop
    int choice;
    while (1) {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You went north and entered the hallway.\n");
                start = hallway;
                break;
            case 2:
                printf("You went east and entered the kitchen.\n");
                start = kitchen;
                break;
            case 3:
                printf("You went south and entered the bedroom.\n");
                start = bedroom;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        if (start->next == NULL) {
            printf("You have reached the end of the labyrinth.\n");
            break;
        }
    }

    return 0;
}