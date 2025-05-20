//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_EXITS 5

typedef struct Room {
    char description[256];
    struct Room* exits[MAX_EXITS];
} Room;

Room* createRoom(const char* description) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->description, description);
    for (int i = 0; i < MAX_EXITS; i++) {
        newRoom->exits[i] = NULL;
    }
    return newRoom;
}

void connectRooms(Room* room1, Room* room2, int exitIndex) {
    if (exitIndex >= 0 && exitIndex < MAX_EXITS) {
        room1->exits[exitIndex] = room2;
    }
}

void exploreRoom(Room* currentRoom) {
    if (currentRoom == NULL) return;

    printf("%s\n", currentRoom->description);
    
    printf("Exits:\n");
    for (int i = 0; i < MAX_EXITS; i++) {
        if (currentRoom->exits[i] != NULL) {
            printf("Exit %d: %s\n", i + 1, currentRoom->exits[i]->description);
        }
    }

    int choice = 0;
    printf("Choose an exit (1 - %d, or 0 to exit): ", MAX_EXITS);
    scanf("%d", &choice);

    if (choice == 0) {
        printf("Exiting the adventure. Goodbye!\n");
        return;
    } else if (choice > 0 && choice <= MAX_EXITS) {
        exploreRoom(currentRoom->exits[choice - 1]);
    } else {
        printf("Invalid choice. Please try again.\n");
        exploreRoom(currentRoom);
    }
}

void freeRooms(Room* room) {
    if (room == NULL) return;
    
    for (int i = 0; i < MAX_EXITS; i++) {
        freeRooms(room->exits[i]);
    }
    
    free(room);
}

int main() {
    Room* kitchen = createRoom("You are in the kitchen. There is a delicious smell coming from the oven.");
    Room* livingRoom = createRoom("You are in the living room. There's a cozy fireplace here.");
    Room* bedroom = createRoom("You are in the bedroom. It's quiet and peaceful.");
    Room* bathroom = createRoom("You are in the bathroom. It's clean and bright.");
    
    connectRooms(kitchen, livingRoom, 0);
    connectRooms(kitchen, bedroom, 1);
    
    connectRooms(livingRoom, kitchen, 0);
    connectRooms(livingRoom, bathroom, 1);
    
    connectRooms(bedroom, kitchen, 0);
    
    connectRooms(bathroom, livingRoom, 0);
    
    printf("Welcome to the Adventure Game!\n");
    exploreRoom(kitchen);
    
    freeRooms(kitchen);
    freeRooms(livingRoom);
    freeRooms(bedroom);
    freeRooms(bathroom);

    return 0;
}