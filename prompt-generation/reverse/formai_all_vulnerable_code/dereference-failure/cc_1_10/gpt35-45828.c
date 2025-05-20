//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define room and door structs
struct Room {
    char name[50];
    char description[100];
    struct Door* doors[4];
};

struct Door {
    char name[50];
    struct Room* room1;
    struct Room* room2;
    bool locked;
};

// create rooms and doors
struct Room* createRoom(char name[], char description[]) {
    struct Room* room = (struct Room*) malloc(sizeof(struct Room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    return room;
}

struct Door* createDoor(char name[], struct Room* room1, struct Room* room2, bool locked) {
    struct Door* door = (struct Door*) malloc(sizeof(struct Door));
    strcpy(door->name, name);
    door->room1 = room1;
    door->room2 = room2;
    door->locked = locked;
    return door;
}

int main() {
    // create rooms
    struct Room* room1 = createRoom("Room 1", "This is room 1");
    struct Room* room2 = createRoom("Room 2", "This is room 2");
    struct Room* room3 = createRoom("Room 3", "This is room 3");
    struct Room* room4 = createRoom("Room 4", "This is room 4");

    // create doors
    struct Door* door1 = createDoor("Door 1", room1, room2, false);
    struct Door* door2 = createDoor("Door 2", room2, room3, true);
    struct Door* door3 = createDoor("Door 3", room2, room4, false);

    // link doors and rooms
    room1->doors[0] = door1;
    room2->doors[0] = door1;
    room2->doors[1] = door2;
    room2->doors[2] = door3;
    room3->doors[0] = door2;
    room4->doors[0] = door3;

    // set current room
    struct Room* currentRoom = room1;

    // game loop
    while (true) {
        // print current room
        printf("%s\n\n%s\n\n", currentRoom->name, currentRoom->description);

        // print available doors
        printf("Doors:\n");
        for (int i = 0; i < 4; i++) {
            if (currentRoom->doors[i] != NULL) {
                printf("%s\n", currentRoom->doors[i]->name);
            }
        }

        // get user input
        printf("Enter a door name or 'quit' to exit: ");
        char input[50];
        scanf("%s", input);

        // handle user input
        if (strcmp(input, "quit") == 0) {
            break;
        }

        bool doorFound = false;
        for (int i = 0; i < 4; i++) {
            if (currentRoom->doors[i] != NULL && strcmp(currentRoom->doors[i]->name, input) == 0) {
                if (currentRoom->doors[i]->locked) {
                    printf("The door is locked.\n");
                } else {
                    if (currentRoom == currentRoom->doors[i]->room1) {
                        currentRoom = currentRoom->doors[i]->room2;
                    } else {
                        currentRoom = currentRoom->doors[i]->room1;
                    }
                    doorFound = true;
                    break;
                }
            }
        }
        if (!doorFound) {
            printf("Invalid input.\n");
        }
    }

    return 0;
}