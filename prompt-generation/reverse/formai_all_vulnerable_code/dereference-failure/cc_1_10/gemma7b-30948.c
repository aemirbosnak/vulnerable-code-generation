//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Room* prev;
    int num;
} Room;

Room* createRoom(char* name, int num) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->num = num;
    newRoom->next = NULL;
    newRoom->prev = NULL;
    return newRoom;
}

void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
    room2->prev = room1;
}

int main() {
    Room* room1 = createRoom("The Hallway", 1);
    Room* room2 = createRoom("The Kitchen", 2);
    Room* room3 = createRoom("The Living Room", 3);
    Room* room4 = createRoom("The Bedroom", 4);
    Room* room5 = createRoom("The Bathroom", 5);

    connectRooms(room1, room2);
    connectRooms(room2, room3);
    connectRooms(room3, room4);
    connectRooms(room4, room5);

    // Game Loop
    int currentRoom = 1;
    char input[20];

    while (currentRoom) {
        // Display the current room information
        printf("You are in %s.\n", room1->name);

        // Get the user input
        printf("Enter a command: ");
        scanf("%s", input);

        // Check if the user input is valid
        if (strcmp(input, "go north") == 0) {
            currentRoom = room1->next->num;
        } else if (strcmp(input, "go south") == 0) {
            currentRoom = room1->prev->num;
        } else if (strcmp(input, "look") == 0) {
            // Display the room description
            printf("The room is %s.\n", room1->name);
        } else {
            // Invalid input
            printf("Invalid command.\n");
        }
    }

    return 0;
}