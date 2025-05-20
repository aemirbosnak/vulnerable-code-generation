//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Create a struct to represent a room in the haunted house
typedef struct room {
    char *name;             // The name of the room
    char *description;      // A description of the room
    struct room *north;     // The room to the north
    struct room *east;      // The room to the east
    struct room *south;     // The room to the south
    struct room *west;      // The room to the west
    int has_ghost;          // Whether or not the room has a ghost
} room;

// Create a function to create a new room
room *create_room(char *name, char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->name = name;
    new_room->description = description;
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    new_room->has_ghost = 0;
    return new_room;
}

// Create a function to add a ghost to a room
void add_ghost(room *room) {
    room->has_ghost = 1;
}

// Create a function to print the description of a room
void print_room_description(room *room) {
    printf("%s\n", room->description);
}

// Create a function to move the player to a new room
room *move_player(room *current_room, char direction) {
    switch (direction) {
        case 'n':
            return current_room->north;
        case 'e':
            return current_room->east;
        case 's':
            return current_room->south;
        case 'w':
            return current_room->west;
        default:
            return current_room;
    }
}

// Create a function to check if the player has won the game
int player_has_won(room *current_room) {
    return current_room->name == "Exit";
}

// Create a function to play the game
void play_game() {
    // Create the rooms in the haunted house
    room *living_room = create_room("Living Room", "A large, dimly lit room with a fireplace and a couch.");
    room *kitchen = create_room("Kitchen", "A small, cluttered room with a stove, a refrigerator, and a sink.");
    room *dining_room = create_room("Dining Room", "A large, formal room with a long table and chairs.");
    room *library = create_room("Library", "A large, well-lit room with bookshelves lining the walls.");
    room *master_bedroom = create_room("Master Bedroom", "A large, luxurious room with a king-sized bed and a walk-in closet.");
    room *guest_bedroom = create_room("Guest Bedroom", "A small, cozy room with a twin bed and a dresser.");
    room *bathroom = create_room("Bathroom", "A small, tiled room with a toilet, a sink, and a bathtub.");
    room *attic = create_room("Attic", "A large, dusty room with boxes and old furniture.");
    room *basement = create_room("Basement", "A dark, damp room with a dirt floor and a few cobwebs.");
    room *exit = create_room("Exit", "A small, dark room with a single door leading outside.");

    // Set the exits for each room
    living_room->north = kitchen;
    living_room->east = dining_room;
    living_room->south = library;
    living_room->west = master_bedroom;
    kitchen->north = living_room;
    kitchen->east = dining_room;
    dining_room->west = kitchen;
    dining_room->south = living_room;
    library->north = living_room;
    library->south = attic;
    library->east = guest_bedroom;
    master_bedroom->east = living_room;
    master_bedroom->south = bathroom;
    guest_bedroom->west = library;
    guest_bedroom->south = bathroom;
    bathroom->north = master_bedroom;
    bathroom->west = guest_bedroom;
    attic->north = library;
    attic->south = basement;
    basement->north = attic;
    exit->south = basement;

    // Add ghosts to some of the rooms
    add_ghost(kitchen);
    add_ghost(library);
    add_ghost(guest_bedroom);
    add_ghost(basement);

    // Set the current room to the living room
    room *current_room = living_room;

    // Play the game until the player wins
    while (!player_has_won(current_room)) {
        // Print the description of the current room
        print_room_description(current_room);

        // Get the player's input
        char direction;
        printf("Which direction would you like to go? (n/e/s/w)\n");
        scanf(" %c", &direction);

        // Move the player to the new room
        current_room = move_player(current_room, direction);
    }

    // Print a message to the player indicating that they have won the game
    printf("Congratulations! You have escaped the haunted house!\n");
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}