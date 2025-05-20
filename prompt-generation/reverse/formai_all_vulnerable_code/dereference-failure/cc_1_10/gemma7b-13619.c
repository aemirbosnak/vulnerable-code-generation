//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int is_visited;
} Room;

Room* create_room(char* name) {
    Room* new_room = malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    new_room->is_visited = 0;
    return new_room;
}

void connect_rooms(Room* room1, Room* room2) {
    room1->next = room2;
}

int main() {
    Room* rooms[MAX_ROOM_NUM] = { NULL };
    rooms[0] = create_room("The Grand Hall");
    rooms[1] = create_room("The Dining Hall");
    rooms[2] = create_room("The Library");
    rooms[3] = create_room("The Bedroom");
    rooms[4] = create_room("The Secret Room");

    connect_rooms(rooms[0], rooms[1]);
    connect_rooms(rooms[0], rooms[2]);
    connect_rooms(rooms[1], rooms[3]);
    connect_rooms(rooms[2], rooms[4]);

    int current_room = 0;
    char input[20];

    printf("You are in %s. Please enter the name of the direction you want to go:", rooms[current_room]->name);
    scanf("%s", input);

    switch (input[0]) {
        case 'n':
            if (rooms[current_room]->next != NULL) {
                current_room++;
                printf("You are now in %s.", rooms[current_room]->name);
            } else {
                printf("There is no direction in that  of.");
            }
            break;
        case 's':
            if (rooms[current_room]->next != NULL) {
                current_room--;
                printf("You are now in %s.", rooms[current_room]->name);
            } else {
                printf("There is no direction in that  of.");
            }
            break;
        case 'e':
            printf("You have exited the game.");
            break;
        default:
            printf("Invalid input.");
            break;
    }

    return 0;
}