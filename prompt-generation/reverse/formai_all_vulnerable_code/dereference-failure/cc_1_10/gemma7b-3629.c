//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 10

typedef struct Room {
    char name[20];
    struct Room* next;
} Room;

Room* createRoom(char* name) {
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, name);
    room->next = NULL;
    return room;
}

void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

int main() {
    // Create rooms
    Room* room1 = createRoom("The Grand Hall");
    Room* room2 = createRoom("The Dining Hall");
    Room* room3 = createRoom("The Library");

    // Connect rooms
    connectRooms(room1, room2);
    connectRooms(room2, room3);

    // Start the adventure
    printf("You wake up in %s. What do you do?", room1->name);
    char command[20];
    scanf("%s", command);

    // Check if the command is valid
    if (strcmp(command, "go") == 0) {
        // Get the direction
        char direction[20];
        printf("In which direction do you want to go?");
        scanf("%s", direction);

        // Check if the direction is valid
        if (strcmp(direction, "north") == 0) {
            printf("You travel north to %s.", room2->name);
        } else if (strcmp(direction, "south") == 0) {
            printf("You travel south to %s.", room3->name);
        } else {
            printf("Invalid direction.");
        }
    } else {
        printf("Invalid command.");
    }

    return 0;
}