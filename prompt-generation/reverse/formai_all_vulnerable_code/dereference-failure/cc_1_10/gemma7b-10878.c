//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a room
typedef struct Room {
    int x, y;
    struct Room *next;
} Room;

// Function to generate a random room
Room *generate_room() {
    int x, y;
    Room *room = malloc(sizeof(Room));
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    room->x = x;
    room->y = y;
    room->next = NULL;
    return room;
}

// Function to connect rooms
void connect_rooms(Room *room1, Room *room2) {
    room1->next = room2;
}

// Function to print the map
void print_map(Room *room) {
    while (room) {
        printf("(%d, %d) ", room->x, room->y);
        room = room->next;
    }
    printf("\n");
}

int main() {
    // Generate a list of rooms
    Room *head = generate_room();
    Room *current = head;
    for (int i = 1; i < 10; i++) {
        current->next = generate_room();
        connect_rooms(current, current->next);
        current = current->next;
    }

    // Print the map
    print_map(head);

    return 0;
}