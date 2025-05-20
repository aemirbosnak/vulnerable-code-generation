//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Room types
enum room_type {
    EMPTY,
    DOOR,
    WINDOW,
    STAIRS_UP,
    STAIRS_DOWN,
    TRAP,
    GHOST
};

// Room structure
struct room {
    enum room_type type;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
};

// Function to create a new room
struct room *create_room(enum room_type type) {
    struct room *room = malloc(sizeof(struct room));
    room->type = type;
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Function to generate a random room
struct room *generate_room() {
    int type = rand() % 7;
    return create_room(type);
}

// Function to print a room
void print_room(struct room *room) {
    switch (room->type) {
        case EMPTY:
            printf("You are in an empty room.\n");
            break;
        case DOOR:
            printf("You are in a room with a door to the north.\n");
            break;
        case WINDOW:
            printf("You are in a room with a window to the east.\n");
            break;
        case STAIRS_UP:
            printf("You are in a room with stairs leading up to the north.\n");
            break;
        case STAIRS_DOWN:
            printf("You are in a room with stairs leading down to the south.\n");
            break;
        case TRAP:
            printf("You are in a room with a trap door in the floor.\n");
            break;
        case GHOST:
            printf("You are in a room with a ghost!\n");
            break;
    }
}

// Function to play the game
void play_game() {
    // Create the first room
    struct room *current_room = generate_room();
    
    // Play the game until the player quits
    while (1) {
        // Print the current room
        print_room(current_room);
        
        // Get the player's input
        char input;
        printf("Enter a command (n, e, s, w, q): ");
        scanf(" %c", &input);
        
        // Move the player to the next room
        switch (input) {
            case 'n':
                current_room = current_room->north;
                break;
            case 'e':
                current_room = current_room->east;
                break;
            case 's':
                current_room = current_room->south;
                break;
            case 'w':
                current_room = current_room->west;
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Play the game
    play_game();
    
    return 0;
}