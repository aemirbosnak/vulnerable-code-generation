//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct Room {
    char name[20];
    struct Room* next;
} Room;

Room* createRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

int main() {
    Room* room1 = createRoom("The Grand Hall");
    Room* room2 = createRoom("The Dining Hall");
    Room* room3 = createRoom("The Library");
    Room* room4 = createRoom("The Bedroom");
    Room* room5 = createRoom("The Garden");

    connectRooms(room1, room2);
    connectRooms(room2, room3);
    connectRooms(room3, room4);
    connectRooms(room4, room5);

    // Start the game
    printf("You wake up in %s.\n", room1->name);

    // Get the user's input
    char input[20];
    printf("What do you want to do? ");
    scanf("%s", input);

    // Check if the user's input is valid
    if (strcmp(input, "go") == 0) {
        // Get the user's destination
        char destination[20];
        printf("Where do you want to go? ");
        scanf("%s", destination);

        // Find the destination room
        Room* currentRoom = room1;
        while (currentRoom && strcmp(currentRoom->name, destination) != 0) {
            currentRoom = currentRoom->next;
        }

        // If the destination room is found, go there
        if (currentRoom) {
            printf("You are now in %s.\n", currentRoom->name);
        } else {
            printf("Error: destination not found.\n");
        }
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}