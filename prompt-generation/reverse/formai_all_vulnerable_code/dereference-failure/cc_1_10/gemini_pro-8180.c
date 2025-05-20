//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a struct to represent a room in the haunted house
typedef struct Room {
    char* name;         // The name of the room
    char* description;  // A description of the room
    struct Room* north;  // The room to the north
    struct Room* east;   // The room to the east
    struct Room* south;  // The room to the south
    struct Room* west;   // The room to the west
} Room;

// Create a struct to represent the player
typedef struct Player {
    char* name;         // The name of the player
    Room* current_room;  // The room the player is currently in
} Player;

// Create a function to generate a random number between two values
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Create a function to create a new room
Room* create_room(char* name, char* description) {
    Room* room = (Room*) malloc(sizeof(Room));
    room->name = name;
    room->description = description;
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Create a function to create a new player
Player* create_player(char* name, Room* starting_room) {
    Player* player = (Player*) malloc(sizeof(Player));
    player->name = name;
    player->current_room = starting_room;
    return player;
}

// Create a function to add a room to the haunted house
void add_room(Room* room, Room* north, Room* east, Room* south, Room* west) {
    room->north = north;
    room->east = east;
    room->south = south;
    room->west = west;
}

// Create a function to print the description of a room
void print_room_description(Room* room) {
    printf("%s\n", room->description);
}

// Create a function to move the player to a new room
void move_player(Player* player, Room* new_room) {
    player->current_room = new_room;
}

// Create a function to play the game
void play_game(Player* player) {
    // Print the description of the player's current room
    print_room_description(player->current_room);

    // Get the player's input
    char input[100];
    printf("What do you want to do? ");
    scanf("%s", input);

    // Check the player's input
    if (strcmp(input, "north") == 0) {
        // Move the player to the room to the north
        move_player(player, player->current_room->north);
    } else if (strcmp(input, "east") == 0) {
        // Move the player to the room to the east
        move_player(player, player->current_room->east);
    } else if (strcmp(input, "south") == 0) {
        // Move the player to the room to the south
        move_player(player, player->current_room->south);
    } else if (strcmp(input, "west") == 0) {
        // Move the player to the room to the west
        move_player(player, player->current_room->west);
    } else {
        // Print an error message
        printf("Invalid input\n");
    }
}

// Create a function to main
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the rooms of the haunted house
    Room* foyer = create_room("Foyer", "You are standing in the foyer of the haunted house. The air is thick with dust and cobwebs. You can hear the sound of wind whistling through the cracks in the walls.");
    Room* living_room = create_room("Living Room", "You are standing in the living room of the haunted house. The furniture is covered in sheets and the air is heavy with the smell of decay.");
    Room* dining_room = create_room("Dining Room", "You are standing in the dining room of the haunted house. The table is set for a feast, but the food is rotten and crawling with maggots.");
    Room* kitchen = create_room("Kitchen", "You are standing in the kitchen of the haunted house. The stove is cold and the sink is filled with dirty dishes.");
    Room* master_bedroom = create_room("Master Bedroom", "You are standing in the master bedroom of the haunted house. The bed is unmade and the curtains are drawn. You can hear the sound of someone crying in the next room.");
    Room* guest_bedroom = create_room("Guest Bedroom", "You are standing in the guest bedroom of the haunted house. The bed is made and the room is tidy. You can hear the sound of someone snoring in the next room.");
    Room* bathroom = create_room("Bathroom", "You are standing in the bathroom of the haunted house. The mirror is cracked and the sink is stained with blood.");
    Room* attic = create_room("Attic", "You are standing in the attic of the haunted house. The air is filled with the smell of mothballs and there are cobwebs everywhere. You can see a rocking chair in the corner of the room.");
    Room* basement = create_room("Basement", "You are standing in the basement of the haunted house. The air is cold and damp and you can hear the sound of dripping water. You can see a furnace in the corner of the room.");

    // Add the rooms to the haunted house
    add_room(foyer, living_room, dining_room, kitchen, NULL);
    add_room(living_room, foyer, dining_room, master_bedroom, guest_bedroom);
    add_room(dining_room, foyer, living_room, kitchen, NULL);
    add_room(kitchen, dining_room, foyer, NULL, NULL);
    add_room(master_bedroom, living_room, bathroom, attic, basement);
    add_room(guest_bedroom, living_room, bathroom, NULL, NULL);
    add_room(bathroom, master_bedroom, guest_bedroom, NULL, NULL);
    add_room(attic, master_bedroom, NULL, NULL, NULL);
    add_room(basement, master_bedroom, NULL, NULL, NULL);

    // Create the player
    Player* player = create_player("Player", foyer);

    // Play the game
    play_game(player);

    return 0;
}