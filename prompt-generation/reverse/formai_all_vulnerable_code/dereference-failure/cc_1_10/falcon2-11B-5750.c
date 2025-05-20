//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct Room {
    char* name;
    char* description;
    struct Room* next;
};

struct Room* roomList = NULL;

void addRoom(struct Room* newRoom) {
    if (roomList == NULL) {
        roomList = newRoom;
    } else {
        struct Room* current = roomList;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newRoom;
    }
}

void printRoomList() {
    struct Room* current = roomList;
    while (current!= NULL) {
        printf("Room: %s\n", current->name);
        printf("Description: %s\n", current->description);
        printf("Exits: ");
        struct Room* next = current->next;
        while (next!= NULL) {
            printf("(%s) ", next->name);
            next = next->next;
        }
        printf("\n");
        current = current->next;
    }
}

void goToRoom(char* roomName) {
    struct Room* current = roomList;
    while (current!= NULL) {
        if (strcmp(current->name, roomName) == 0) {
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid room name.\n");
        return;
    }
    printf("You enter the %s.\n", current->name);
    printf("Description: %s\n", current->description);
    printf("Exits: ");
    struct Room* next = current->next;
    while (next!= NULL) {
        printf("(%s) ", next->name);
        next = next->next;
    }
    printf("\n");
}

int main() {
    struct Room* hallway = (struct Room*)malloc(sizeof(struct Room));
    hallway->name = "Hallway";
    hallway->description = "You are standing in a dimly lit hallway.";
    hallway->next = NULL;

    struct Room* kitchen = (struct Room*)malloc(sizeof(struct Room));
    kitchen->name = "Kitchen";
    kitchen->description = "You are in the kitchen. There's a door to the north.";
    kitchen->next = NULL;

    struct Room* diningRoom = (struct Room*)malloc(sizeof(struct Room));
    diningRoom->name = "Dining Room";
    diningRoom->description = "You are in the dining room. There's a door to the south.";
    diningRoom->next = NULL;

    struct Room* bedroom = (struct Room*)malloc(sizeof(struct Room));
    bedroom->name = "Bedroom";
    bedroom->description = "You are in the bedroom. There's a door to the west.";
    bedroom->next = NULL;

    hallway->next = kitchen;
    kitchen->next = diningRoom;
    diningRoom->next = bedroom;

    addRoom(hallway);
    addRoom(kitchen);
    addRoom(diningRoom);
    addRoom(bedroom);

    char command[100];
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove the newline character

        if (strcmp(command, "go north") == 0) {
            goToRoom("Kitchen");
        } else if (strcmp(command, "go south") == 0) {
            goToRoom("Dining Room");
        } else if (strcmp(command, "go west") == 0) {
            goToRoom("Bedroom");
        } else if (strcmp(command, "go east") == 0) {
            goToRoom("Hallway");
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}