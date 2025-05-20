//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room {
    char name[20];
    struct Room* next;
} Room;

Room* CreateRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void ConnectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

void PlayGame() {
    Room* startRoom = CreateRoom("The Grand Hall");
    Room* bedroom = CreateRoom("The Bedroom");
    Room* library = CreateRoom("The Library");

    ConnectRooms(startRoom, bedroom);
    ConnectRooms(startRoom, library);

    // The player's current room
    Room* currentRoom = startRoom;

    // Game loop
    while (1) {
        // Display the room's description
        printf("%s\n", currentRoom->name);

        // Get the player's input
        char input[20];
        printf("What do you want to do? ");
        scanf("%s", input);

        // Check if the player's input is valid
        if (strcmp(input, "go north") == 0) {
            currentRoom = currentRoom->next;
        } else if (strcmp(input, "go south") == 0) {
            // Implement south direction code
        } else if (strcmp(input, "go east") == 0) {
            // Implement east direction code
        } else if (strcmp(input, "go west") == 0) {
            // Implement west direction code
        } else {
            printf("Invalid input.\n");
        }

        // Check if the player has won the game
        if (currentRoom->name == "The Library") {
            printf("You have won the game!\n");
            break;
        }
    }
}

int main() {
    PlayGame();
    return 0;
}