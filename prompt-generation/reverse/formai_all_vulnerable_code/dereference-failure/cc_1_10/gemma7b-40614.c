//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct room {
    char name[20];
    struct room* next;
} room_t;

room_t* create_room(char* name) {
    room_t* new_room = malloc(sizeof(room_t));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    return new_room;
}

void connect_rooms(room_t* room1, room_t* room2) {
    room1->next = room2;
}

void play_game() {
    room_t* rooms[MAX_ROOM] = {
        create_room("The Grand Hall"),
        create_room("The Library"),
        create_room("The Dining Hall"),
        create_room("The Bedroom"),
        create_room("The Secret Room")
    };

    connect_rooms(rooms[0], rooms[1]);
    connect_rooms(rooms[1], rooms[2]);
    connect_rooms(rooms[2], rooms[3]);
    connect_rooms(rooms[3], rooms[4]);

    // Start at the Grand Hall
    room_t* current_room = rooms[0];

    // Move through the rooms
    while (current_room) {
        printf("%s\n", current_room->name);

        // Get the user input
        char input[20];
        scanf("%s", input);

        // Check if the user input matches the room's name
        if (strcmp(input, current_room->name) == 0) {
            // Move to the next room
            current_room = current_room->next;
        } else {
            // Invalid input
            printf("Invalid input.\n");
        }
    }

    // End of the game
    printf("You have reached the end of the game.\n");
}

int main() {
    play_game();
    return 0;
}