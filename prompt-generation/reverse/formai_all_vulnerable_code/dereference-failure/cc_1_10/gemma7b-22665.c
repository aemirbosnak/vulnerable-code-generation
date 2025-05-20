//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
    char name[20];
    struct Room *next;
} Room;

Room *createRoom(char *name) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

void connectRooms(Room *room1, Room *room2) {
    room1->next = room2;
}

int main() {
    Room *rooms = NULL;
    rooms = createRoom("The Hall");
    connectRooms(rooms, createRoom("The Kitchen"));
    connectRooms(rooms, createRoom("The Living Room"));
    connectRooms(rooms, createRoom("The Bedroom"));
    connectRooms(rooms, createRoom("The Bathroom"));

    printf("You are in %s. What do you want to do? (go, search, interact): ", rooms->name);
    char input[20];
    scanf("%s", input);

    if (strcmp(input, "go") == 0) {
        printf("Please enter the direction you want to go: ");
        char direction[20];
        scanf("%s", direction);

        Room *currentRoom = rooms;
        while (currentRoom->next) {
            if (strcmp(direction, currentRoom->next->name) == 0) {
                currentRoom = currentRoom->next;
                printf("You are now in %s. What do you want to do? (go, search, interact): ", currentRoom->name);
                break;
            }
            currentRoom = currentRoom->next;
        }

        if (currentRoom->next == NULL) {
            printf("There is no room in that direction.");
        }
    } else if (strcmp(input, "search") == 0) {
        printf("Please enter what you want to search for: ");
        char searchTerm[20];
        scanf("%s", searchTerm);

        Room *currentRoom = rooms;
        while (currentRoom) {
            if (strstr(currentRoom->name, searchTerm) != NULL) {
                printf("You found %s in %s.\n", searchTerm, currentRoom->name);
            }
            currentRoom = currentRoom->next;
        }

        if (currentRoom == NULL) {
            printf("No results found.");
        }
    } else if (strcmp(input, "interact") == 0) {
        printf("Please enter what you want to interact with: ");
        char interactTerm[20];
        scanf("%s", interactTerm);

        Room *currentRoom = rooms;
        while (currentRoom) {
            if (strstr(currentRoom->name, interactTerm) != NULL) {
                printf("You interacted with %s in %s.\n", interactTerm, currentRoom->name);
            }
            currentRoom = currentRoom->next;
        }

        if (currentRoom == NULL) {
            printf("No results found.");
        }
    } else {
        printf("Invalid input. Please try again.");
    }

    return 0;
}