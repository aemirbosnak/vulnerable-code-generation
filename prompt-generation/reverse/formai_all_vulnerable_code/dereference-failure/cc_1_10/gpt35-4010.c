//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

typedef struct Room {
    char name[MAX_INPUT_SIZE];
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

void create_rooms(Room **start_room, Room **end_room) {
    // Create the rooms
    Room *room1, *room2, *room3, *room4, *room5;
    room1 = (Room *) malloc(sizeof(Room));
    room2 = (Room *) malloc(sizeof(Room));
    room3 = (Room *) malloc(sizeof(Room));
    room4 = (Room *) malloc(sizeof(Room));
    room5 = (Room *) malloc(sizeof(Room));

    // Set the names of the rooms
    strcpy(room1->name, "Room 1");
    strcpy(room2->name, "Room 2");
    strcpy(room3->name, "Room 3");
    strcpy(room4->name, "Room 4");
    strcpy(room5->name, "Room 5");

    // Set the connections between the rooms
    room1->north = room2;
    room2->south = room1;

    room2->north = room3;
    room3->south = room2;

    room3->east = room4;
    room4->west = room3;

    room3->north = room5;
    room5->south = room3;

    // Set the starting and ending room
    *start_room = room1;
    *end_room = room4;
}

void play_game(Room *current_room, Room *end_room) {
    char input[MAX_INPUT_SIZE];

    printf("You are in %s.\n", current_room->name);

    // If the current room is the end room, the player has won
    if (current_room == end_room) {
        printf("Congratulations, you have won the game!\n");
        return;
    }

    printf("What do you want to do?\n");
    scanf("%s", input);

    // Move north
    if (strcmp(input, "north") == 0 && current_room->north != NULL) {
        play_game(current_room->north, end_room);
    }
    
    // Move south
    else if (strcmp(input, "south") == 0 && current_room->south != NULL) {
        play_game(current_room->south, end_room);
    }

    // Move east
    else if (strcmp(input, "east") == 0 && current_room->east != NULL) {
        play_game(current_room->east, end_room);
    }

    // Move west
    else if (strcmp(input, "west") == 0 && current_room->west != NULL) {
        play_game(current_room->west, end_room);
    }

    // Invalid input
    else {
        printf("Invalid input. Try again.\n");
        play_game(current_room, end_room);
    }
}

int main() {
    Room *start_room, *end_room;
    create_rooms(&start_room, &end_room);
    play_game(start_room, end_room);
    return 0;
}