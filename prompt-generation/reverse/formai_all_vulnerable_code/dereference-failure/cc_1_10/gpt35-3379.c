//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    char* description;
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
};

struct Room* createRoom(char* description) {
    struct Room* room = malloc(sizeof(struct Room));
    room->description = description;
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

void connectRooms(struct Room* room1, struct Room* room2, char* direction1, char* direction2) {
    if (strcmp(direction1, "north") == 0) {
        room1->north = room2;
    } else if (strcmp(direction1, "east") == 0) {
        room1->east = room2;
    } else if (strcmp(direction1, "south") == 0) {
        room1->south = room2;
    } else if (strcmp(direction1, "west") == 0) {
        room1->west = room2;
    }
    if (strcmp(direction2, "north") == 0) {
        room2->north = room1;
    } else if (strcmp(direction2, "east") == 0) {
        room2->east = room1;
    } else if (strcmp(direction2, "south") == 0) {
        room2->south = room1;
    } else if (strcmp(direction2, "west") == 0) {
        room2->west = room1;
    }
}

int main() {
    struct Room* entryway = createRoom("You find yourself in a dusty entryway with tall ceilings.");
    struct Room* livingRoom = createRoom("The living room is dark and appears abandoned, old furniture is strewn about the room.");
    struct Room* kitchen = createRoom("The kitchen has been left in a state of disarray, pots and pans litter the counter.");
    struct Room* diningRoom = createRoom("The dining room table is set, but looks as if it has not been used in years.");
    struct Room* hallway = createRoom("The hallway is dark and ominous, you feel as if you are being watched.");
    struct Room* bedroom = createRoom("The bedroom is small and cramped, the bed appears untouched.");
    struct Room* bathroom = createRoom("The bathroom is old and rusty, you feel a chill run down your spine.");
    struct Room* attic = createRoom("The attic is musty and damp, it appears as if no one has been there in years.");

    connectRooms(entryway, livingRoom, "north", "south");
    connectRooms(livingRoom, kitchen, "east", "west");
    connectRooms(livingRoom, diningRoom, "north", "south");
    connectRooms(diningRoom, hallway, "east", "west");
    connectRooms(hallway, bedroom, "north", "south");
    connectRooms(hallway, bathroom, "east", "west");
    connectRooms(hallway, attic, "north", "south");

    struct Room* currentRoom = entryway;
    printf("%s\n", currentRoom->description);
    while (1) {
        char input[100];
        scanf("%s", input);
        if (strcmp(input, "north") == 0 && currentRoom->north != NULL) {
            printf("%s\n", currentRoom->north->description);
            currentRoom = currentRoom->north;
        } else if (strcmp(input, "east") == 0 && currentRoom->east != NULL) {
            printf("%s\n", currentRoom->east->description);
            currentRoom = currentRoom->east;
        } else if (strcmp(input, "south") == 0 && currentRoom->south != NULL) {
            printf("%s\n", currentRoom->south->description);
            currentRoom = currentRoom->south;
        } else if (strcmp(input, "west") == 0 && currentRoom->west != NULL) {
            printf("%s\n", currentRoom->west->description);
            currentRoom = currentRoom->west;
        } else {
            printf("You cannot go that way. Try going north, east, south, or west.\n");
        }
    }
    return 0;
}