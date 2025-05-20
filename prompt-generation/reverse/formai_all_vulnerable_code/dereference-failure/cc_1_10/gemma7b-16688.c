//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NUM 5

typedef struct room_t {
    char name[20];
    struct room_t* next;
    struct room_t* prev;
    int num;
    char description[100];
} room_t;

room_t* create_room(char* name, int num, char* description) {
    room_t* new_room = malloc(sizeof(room_t));
    strcpy(new_room->name, name);
    new_room->num = num;
    strcpy(new_room->description, description);
    new_room->next = NULL;
    new_room->prev = NULL;
    return new_room;
}

void connect_rooms(room_t* room1, room_t* room2) {
    room1->next = room2;
    room2->prev = room1;
}

void play_game() {
    room_t* start_room = create_room("The Hallway", 1, "You find yourself in a long, dark hallway.");
    room_t* end_room = create_room("The Treasure Chamber", 5, "You have reached the treasure chamber!");

    connect_rooms(start_room, end_room);

    // Game loop
    room_t* current_room = start_room;
    while (current_room->next) {
        printf("You are in %s. What do you want to do? (north, south, east, west): ", current_room->name);
        char input[20];
        scanf("%s", input);

        // Move in the direction specified
        if (strcmp(input, "north") == 0) {
            current_room = current_room->next;
        } else if (strcmp(input, "south") == 0) {
            current_room = current_room->prev;
        } else if (strcmp(input, "east") == 0) {
            // Code for moving east
        } else if (strcmp(input, "west") == 0) {
            // Code for moving west
        } else {
            printf("Invalid input.\n");
        }
    }

    // You have reached the end room
    printf("You have reached the treasure chamber! Congratulations!\n");
}

int main() {
    play_game();
    return 0;
}