//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 10

typedef struct Room {
    char name[20];
    struct Room* next;
} Room;

void createRoom(char* name) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
}

void connectRooms(Room* room1, Room* room2) {
    room1->next = room2;
}

int main() {
    Room* rooms = NULL;

    createRoom("The Foyer");
    createRoom("The Kitchen");
    createRoom("The Living Room");
    createRoom("The Bedroom");

    connectRooms(rooms, rooms->next);
    connectRooms(rooms->next, rooms->next->next);
    connectRooms(rooms->next->next, rooms->next->next->next);

    printf("You are in the %s.\n", rooms->name);

    // Game loop
    int choice;
    while (1) {
        printf("What do you want to do? (1) Go north, (2) Go south, (3) Go east, (4) Go west\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rooms->next) {
                    printf("You are now in the %s.\n", rooms->next->name);
                    rooms = rooms->next;
                } else {
                    printf("There is no room to the north.\n");
                }
                break;
            case 2:
                if (rooms->next->next) {
                    printf("You are now in the %s.\n", rooms->next->next->name);
                    rooms = rooms->next->next;
                } else {
                    printf("There is no room to the south.\n");
                }
                break;
            case 3:
                if (rooms->next->next->next) {
                    printf("You are now in the %s.\n", rooms->next->next->next->name);
                    rooms = rooms->next->next->next;
                } else {
                    printf("There is no room to the east.\n");
                }
                break;
            case 4:
                if (rooms->next->next) {
                    printf("You are now in the %s.\n", rooms->next->next->name);
                    rooms = rooms->next->next;
                } else {
                    printf("There is no room to the west.\n");
                }
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}