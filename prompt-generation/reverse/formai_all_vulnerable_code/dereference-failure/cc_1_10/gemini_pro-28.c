//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the types of rooms and the possible events that can occur in each room.
typedef enum {
    ROOM_TYPE_ENTRANCE,
    ROOM_TYPE_LIVING_ROOM,
    ROOM_TYPE_LIBRARY,
    ROOM_TYPE_KITCHEN,
    ROOM_TYPE_BEDROOM,
    ROOM_TYPE_BATHROOM,
    ROOM_TYPE_ATTIC,
    ROOM_TYPE_BASEMENT
} room_type_t;

typedef enum {
    EVENT_TYPE_NONE,
    EVENT_TYPE_CREAKING_FLOORBOARDS,
    EVENT_TYPE_FLICKERING_LIGHTS,
    EVENT_TYPE_HOWLING_WIND,
    EVENT_TYPE_WHISPERING_VOICES,
    EVENT_TYPE_SCREAMING,
    EVENT_TYPE_GHOST_APPEARANCE
} event_type_t;

// Define the structure of a room.
typedef struct {
    room_type_t type;
    char *description;
    event_type_t event;
} room_t;

// Define the structure of a house.
typedef struct {
    room_t *rooms;
    int num_rooms;
} house_t;

// Create a new house.
house_t *create_house() {
    // Allocate memory for the house.
    house_t *house = malloc(sizeof(house_t));

    // Create the rooms.
    house->num_rooms = 8;
    house->rooms = malloc(sizeof(room_t) * house->num_rooms);

    // Set the type and description of each room.
    house->rooms[0].type = ROOM_TYPE_ENTRANCE;
    house->rooms[0].description = "You enter the house through a creaky old door. The air is cold and damp, and the walls are lined with dusty portraits.";
    house->rooms[1].type = ROOM_TYPE_LIVING_ROOM;
    house->rooms[1].description = "The living room is spacious and dimly lit. There is a large fireplace in the center of the room, and the walls are adorned with antique furniture.";
    house->rooms[2].type = ROOM_TYPE_LIBRARY;
    house->rooms[2].description = "The library is filled with shelves of books from floor to ceiling. The air is heavy with the smell of old paper.";
    house->rooms[3].type = ROOM_TYPE_KITCHEN;
    house->rooms[3].description = "The kitchen is small and cramped. The stove is old and rusty, and the sink is filled with dirty dishes.";
    house->rooms[4].type = ROOM_TYPE_BEDROOM;
    house->rooms[4].description = "The bedroom is sparsely furnished. There is a bed, a dresser, and a nightstand. The curtains are drawn, and the room is dark and gloomy.";
    house->rooms[5].type = ROOM_TYPE_BATHROOM;
    house->rooms[5].description = "The bathroom is small and tiled. The mirror is cracked, and the sink is stained with rust.";
    house->rooms[6].type = ROOM_TYPE_ATTIC;
    house->rooms[6].description = "The attic is dark and dusty. There are boxes and furniture piled up everywhere. The air is thick with the smell of mothballs.";
    house->rooms[7].type = ROOM_TYPE_BASEMENT;
    house->rooms[7].description = "The basement is cold and damp. The walls are made of stone, and the floor is covered in dirt. There is a single light bulb hanging from the ceiling, and it casts a dim glow over the room.";

    // Set the event for each room.
    srand(time(NULL));
    for (int i = 0; i < house->num_rooms; i++) {
        house->rooms[i].event = rand() % 7;
    }

    return house;
}

// Destroy a house.
void destroy_house(house_t *house) {
    // Free the memory allocated for the house.
    free(house->rooms);
    free(house);
}

// Print the description of a room.
void print_room_description(room_t *room) {
    printf("%s\n", room->description);
}

// Print the event that occurs in a room.
void print_room_event(room_t *room) {
    switch (room->event) {
        case EVENT_TYPE_NONE:
            printf("Nothing happens.\n");
            break;
        case EVENT_TYPE_CREAKING_FLOORBOARDS:
            printf("You hear creaking floorboards behind you.\n");
            break;
        case EVENT_TYPE_FLICKERING_LIGHTS:
            printf("The lights flicker and go out.\n");
            break;
        case EVENT_TYPE_HOWLING_WIND:
            printf("You hear the wind howling outside.\n");
            break;
        case EVENT_TYPE_WHISPERING_VOICES:
            printf("You hear whispering voices coming from the darkness.\n");
            break;
        case EVENT_TYPE_SCREAMING:
            printf("You hear screaming coming from the next room.\n");
            break;
        case EVENT_TYPE_GHOST_APPEARANCE:
            printf("You see a ghost appear in front of you.\n");
            break;
    }
}

// Play the haunted house simulator.
void play_game(house_t *house) {
    // Start in the entrance.
    room_t *current_room = &house->rooms[0];

    // While the player is still alive, keep playing the game.
    bool player_alive = true;
    while (player_alive) {
        // Print the description of the current room.
        print_room_description(current_room);

        // Print the event that occurs in the current room.
        print_room_event(current_room);

        // Get the player's input.
        char input[100];
        printf("What do you want to do? ");
        scanf("%s", input);

        // If the player wants to quit, exit the game.
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // If the player wants to move to another room, change the current room.
        if (strcmp(input, "north") == 0) {
            current_room = &house->rooms[(current_room - house->rooms + 1) % house->num_rooms];
        } else if (strcmp(input, "south") == 0) {
            current_room = &house->rooms[(current_room - house->rooms - 1 + house->num_rooms) % house->num_rooms];
        } else if (strcmp(input, "east") == 0) {
            current_room = &house->rooms[(current_room - house->rooms + 2) % house->num_rooms];
        } else if (strcmp(input, "west") == 0) {
            current_room = &house->rooms[(current_room - house->rooms - 2 + house->num_rooms) % house->num_rooms];
        }

        // If the player encounters a ghost, they die.
        if (current_room->event == EVENT_TYPE_GHOST_APPEARANCE) {
            printf("You have been killed by a ghost.\n");
            player_alive = false;
        }
    }
}

// Main function.
int main() {
    // Create a new house.
    house_t *house = create_house();

    // Play the game.
    play_game(house);

    // Destroy the house.
    destroy_house(house);

    return 0;
}