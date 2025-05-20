//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int visited;
} Room;

Room* createRoom(char* name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->visited = 0;
    return newRoom;
}

void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

int main() {
    Room* rooms[MAX_ROOMS] = {NULL};

    // Create rooms
    rooms[0] = createRoom("The Hallway");
    rooms[1] = createRoom("The Kitchen");
    rooms[2] = createRoom("The Living Room");
    rooms[3] = createRoom("The Bedroom");
    rooms[4] = createRoom("The Bathroom");

    // Connect rooms
    connectRooms(rooms[0], rooms[1]);
    connectRooms(rooms[0], rooms[2]);
    connectRooms(rooms[1], rooms[3]);
    connectRooms(rooms[2], rooms[4]);

    // Play the game
    printf("You are in %s. What do you want to do?", rooms[0]->name);

    // Get the player's input
    char input[20];
    scanf("%s", input);

    // Check if the player has already visited the room
    if (rooms[0]->visited == 0) {
        // Mark the room as visited
        rooms[0]->visited = 1;

        // Go to the next room
        if (strcmp(input, "go north") == 0) {
            printf("You have gone north to %s.\n", rooms[1]->name);
            main();
        } else if (strcmp(input, "go south") == 0) {
            printf("You have gone south to %s.\n", rooms[2]->name);
            main();
        } else {
            printf("Invalid input.\n");
            main();
        }
    } else {
        printf("You have already visited this room.\n");
        main();
    }

    return 0;
}