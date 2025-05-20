//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NUM 10

typedef struct ROOM {
    char name[20];
    struct ROOM* next_room;
    struct ROOM* prev_room;
    int x, y;
} ROOM;

ROOM* create_room(char* name, int x, int y) {
    ROOM* new_room = (ROOM*)malloc(sizeof(ROOM));
    strcpy(new_room->name, name);
    new_room->x = x;
    new_room->y = y;
    new_room->next_room = NULL;
    new_room->prev_room = NULL;
    return new_room;
}

void connect_rooms(ROOM* room1, ROOM* room2) {
    room1->next_room = room2;
    room2->prev_room = room1;
}

int main() {
    ROOM* rooms[MAX_ROOM_NUM];
    for (int i = 0; i < MAX_ROOM_NUM; i++) {
        rooms[i] = NULL;
    }

    rooms[0] = create_room("The Kitchen", 0, 0);
    rooms[1] = create_room("The Living Room", 1, 0);
    rooms[2] = create_room("The Bedroom", 2, 0);
    rooms[3] = create_room("The Bathroom", 3, 0);

    connect_rooms(rooms[0], rooms[1]);
    connect_rooms(rooms[1], rooms[2]);
    connect_rooms(rooms[2], rooms[3]);

    // Paranoia begins...

    ROOM* current_room = rooms[0];
    char* goal_room_name = "The Bathroom";

    while (current_room) {
        if (strcmp(current_room->name, goal_room_name) == 0) {
            printf("You have reached the goal room!\n");
            break;
        } else if (current_room->next_room) {
            current_room = current_room->next_room;
        } else if (current_room->prev_room) {
            current_room = current_room->prev_room;
        } else {
            printf("Error: path not found.\n");
            return 1;
        }
    }

    return 0;
}