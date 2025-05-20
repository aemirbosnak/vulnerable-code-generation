//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a macro for a random number between 0 and 9
#define RAND_NUM() ((rand() % 10) )

// Define a structure for a haunted house room
typedef struct Room {
    char name[20];
    struct Room* next;
    int is_visited;
    int has_treasure;
} Room;

// Create a list of haunted house rooms
Room* create_room(char* name, Room* next) {
    Room* new_room = malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->next = next;
    new_room->is_visited = 0;
    new_room->has_treasure = RAND_NUM() % 2;
    return new_room;
}

// Traverse the haunted house
void traverse_house(Room* current_room) {
    // If the room has not been visited, visit it
    if (!current_room->is_visited) {
        current_room->is_visited = 1;

        // Print the room name
        printf("%s\n", current_room->name);

        // If the room has treasure, get the treasure
        if (current_room->has_treasure) {
            printf("You found treasure!\n");
        }

        // Traverse the next room in the house
        traverse_house(current_room->next);
    }
}

int main() {
    // Create the haunted house
    Room* first_room = create_room("The Grand Hall", NULL);
    create_room("The Dining Hall", first_room);
    create_room("The Library", first_room);
    create_room("The Bedroom", create_room("The Secret Room", first_room));

    // Traverse the haunted house
    traverse_house(first_room);

    return 0;
}