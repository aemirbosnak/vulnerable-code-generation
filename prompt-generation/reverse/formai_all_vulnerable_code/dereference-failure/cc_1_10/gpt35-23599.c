//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100

struct Room {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
    int isEndRoom;
};

void printRoomInfo(struct Room* room) {
    printf("CURRENT ROOM: %s\n", room->name);
    printf("DESCRIPTION: %s\n", room->description);
    printf("POSSIBLE DIRECTIONS: ");
    if (room->north != NULL) {
        printf("north ");
    }
    if (room->east != NULL) {
        printf("east ");
    }
    if (room->south != NULL) {
        printf("south ");
    }
    if (room->west != NULL) {
        printf("west ");
    }
    printf("\n");
}

int main() {
    // Initializing rooms
    struct Room* rooms[MAX_ROOMS];
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = malloc(sizeof(struct Room));
        sprintf(rooms[i]->name, "Room %d", i+1);
        sprintf(rooms[i]->description, "This is a room with paranoid vibes...");
        rooms[i]->north = NULL;
        rooms[i]->east = NULL;
        rooms[i]->south = NULL;
        rooms[i]->west = NULL;
        rooms[i]->isEndRoom = 0;
    }
    // Setting room connections
    rooms[0]->north = rooms[1];
    rooms[1]->south = rooms[0];
    rooms[1]->east = rooms[2];
    rooms[2]->west = rooms[1];
    rooms[2]->east = rooms[3];
    rooms[3]->west = rooms[2];
    rooms[3]->north = rooms[4];
    rooms[4]->south = rooms[3];
    rooms[4]->west = rooms[5];
    rooms[5]->east = rooms[4];
    rooms[5]->north = rooms[6];
    rooms[6]->south = rooms[5];
    rooms[6]->east = rooms[7];
    rooms[7]->west = rooms[6];
    rooms[7]->north = rooms[8];
    rooms[8]->south = rooms[7];
    rooms[8]->east = rooms[9];
    rooms[8]->isEndRoom = 1;
    rooms[9]->west = rooms[8];
    
    // Game start
    printf("WELCOME TO THE PARANOID GAME!\n");
    printf("You have entered a strange building and you must find your way out.\n");
    printf("Type 'help' to display the commands available.\n");
    
    struct Room* currentRoom = rooms[0];
    char input[20];
    while (1) {
        printRoomInfo(currentRoom);
        printf("Enter a command: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0';   // removing newline character
        
        if (strcmp(input, "help") == 0) {
            printf("Commands: \n");
            printf("  north/east/south/west - move to the next room in that direction\n");
            printf("  exit - exit the game\n");
        } else if (strcmp(input, "north") == 0 && currentRoom->north != NULL) {
            currentRoom = currentRoom->north;
        } else if (strcmp(input, "east") == 0 && currentRoom->east != NULL) {
            currentRoom = currentRoom->east;
        } else if (strcmp(input, "south") == 0 && currentRoom->south != NULL) {
            currentRoom = currentRoom->south;
        } else if (strcmp(input, "west") == 0 && currentRoom->west != NULL) {
            currentRoom = currentRoom->west;
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command! Type 'help' for a list of commands.\n");
        }
        
        if (currentRoom->isEndRoom) {
            printf("CONGRATULATIONS! YOU HAVE ESCAPED THE PARANOID BUILDING!\n");
            break;
        }
    }
    
    // Freeing memory
    for (i = 0; i < MAX_ROOMS; i++) {
        free(rooms[i]);
    }
    
    return 0;
}