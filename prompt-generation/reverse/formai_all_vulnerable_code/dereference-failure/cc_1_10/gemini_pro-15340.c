//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a room in the haunted house
typedef struct Room {
    char* name;             // Name of the room
    char* description;      // Description of the room
    struct Room* exits[4];  // Pointers to the exits from the room (north, east, south, west)
} Room;

// Array of rooms in the haunted house
Room rooms[] = {
    { "Entrance Hall", "You are standing in the entrance hall of a large, dark house. The air is cold and damp, and you can hear the sound of wind whistling through the cracks in the walls.", NULL, NULL, NULL, NULL },
    { "Living Room", "You enter a large, dimly lit living room. The furniture is covered in dust and cobwebs, and there is a large fireplace in the center of the room. You can hear the sound of something moving in the shadows.", NULL, NULL, NULL, NULL },
    { "Dining Room", "You enter a large, formal dining room. The table is set for a feast, but the food is long gone. There is a large chandelier hanging from the ceiling, and you can see the shadows of creatures moving in the darkness.", NULL, NULL, NULL, NULL },
    { "Kitchen", "You enter a small, dark kitchen. The counters are covered in grime and grease, and there is a large stove in the center of the room. You can hear the sound of something cooking in the oven.", NULL, NULL, NULL, NULL },
    { "Master Bedroom", "You enter a large, luxurious master bedroom. The bed is covered in silk sheets, and there is a large mirror on the wall. You can see the reflection of something moving in the mirror.", NULL, NULL, NULL, NULL },
    { "Guest Bedroom", "You enter a small, cozy guest bedroom. The bed is covered in a quilt, and there is a small dresser in the corner of the room. You can hear the sound of someone breathing in the closet.", NULL, NULL, NULL, NULL },
    { "Bathroom", "You enter a small, dark bathroom. The sink is covered in grime, and there is a large bathtub in the corner of the room. You can hear the sound of water dripping from the faucet.", NULL, NULL, NULL, NULL },
    { "Basement", "You enter a large, dark basement. The floor is covered in dirt and cobwebs, and there is a large furnace in the center of the room. You can hear the sound of something crawling in the darkness.", NULL, NULL, NULL, NULL },
    { "Attic", "You enter a large, dusty attic. The floor is covered in boxes and old furniture, and there is a large window in the corner of the room. You can see the shadows of creatures moving in the darkness.", NULL, NULL, NULL, NULL }
};

// Function to choose a random room from the array of rooms
Room* choose_room() {
    return &rooms[rand() % 9];
}

// Function to print the description of a room
void print_room(Room* room) {
    printf("%s\n%s\n", room->name, room->description);
}

// Function to get the user's input
char* get_input() {
    char* input = malloc(100);
    scanf("%s", input);
    return input;
}

// Function to play the game
void play_game() {
    // Set the current room to the entrance hall
    Room* current_room = &rooms[0];

    // Loop until the user quits the game
    while (1) {
        // Print the description of the current room
        print_room(current_room);

        // Get the user's input
        char* input = get_input();

        // Check if the user wants to quit the game
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Check if the user wants to move to a different room
        else if (strcmp(input, "north") == 0) {
            current_room = current_room->exits[0];
        } else if (strcmp(input, "east") == 0) {
            current_room = current_room->exits[1];
        } else if (strcmp(input, "south") == 0) {
            current_room = current_room->exits[2];
        } else if (strcmp(input, "west") == 0) {
            current_room = current_room->exits[3];
        }

        // Check if the user wants to interact with an object in the room
        else {
            printf("You can't do that.\n");
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