//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the different types of rooms in the haunted house
typedef enum {
    ENTRANCE,
    HALLWAY,
    BEDROOM,
    BATHROOM,
    KITCHEN,
    LIBRARY,
    DINING_ROOM,
    LIVING_ROOM,
    ATTIC,
    BASEMENT
} room_type;

// Define the different types of events that can occur in the haunted house
typedef enum {
    NO_EVENT,
    CREAK,
    GROAN,
    WHISPER,
    FOOTSTEPS,
    DOOR_CREAK,
    WINDOW_RATTLE,
    SHADOW,
    GHOST
} event_type;

// Define the structure of a room in the haunted house
typedef struct {
    room_type type;
    char *description;
    event_type event;
} room;

// Define the structure of the haunted house
typedef struct {
    room rooms[MAX_ROOMS];
    int num_rooms;
} haunted_house;

// Create a new haunted house
haunted_house *create_haunted_house() {
    haunted_house *house = malloc(sizeof(haunted_house));
    house->num_rooms = 0;
    return house;
}

// Add a new room to the haunted house
void add_room(haunted_house *house, room_type type, char *description) {
    if (house->num_rooms < MAX_ROOMS) {
        house->rooms[house->num_rooms].type = type;
        house->rooms[house->num_rooms].description = description;
        house->num_rooms++;
    }
}

// Generate a random event for a room
event_type generate_event() {
    int event = rand() % 10;
    switch (event) {
        case 0:
            return CREAK;
        case 1:
            return GROAN;
        case 2:
            return WHISPER;
        case 3:
            return FOOTSTEPS;
        case 4:
            return DOOR_CREAK;
        case 5:
            return WINDOW_RATTLE;
        case 6:
            return SHADOW;
        case 7:
            return GHOST;
        default:
            return NO_EVENT;
    }
}

// Print the description of a room
void print_room(room *room) {
    printf("%s\n", room->description);
}

// Print the event that occurs in a room
void print_event(event_type event) {
    switch (event) {
        case CREAK:
            printf("You hear a creak.\n");
            break;
        case GROAN:
            printf("You hear a groan.\n");
            break;
        case WHISPER:
            printf("You hear a whisper.\n");
            break;
        case FOOTSTEPS:
            printf("You hear footsteps.\n");
            break;
        case DOOR_CREAK:
            printf("You hear a door creak.\n");
            break;
        case WINDOW_RATTLE:
            printf("You hear a window rattle.\n");
            break;
        case SHADOW:
            printf("You see a shadow.\n");
            break;
        case GHOST:
            printf("You see a ghost!\n");
            break;
        default:
            printf("Nothing happens.\n");
            break;
    }
}

// Simulate the haunted house
void simulate_haunted_house(haunted_house *house) {
    // Loop through each room in the haunted house
    for (int i = 0; i < house->num_rooms; i++) {
        // Print the description of the room
        print_room(&house->rooms[i]);

        // Generate a random event for the room
        event_type event = generate_event();

        // Print the event that occurs in the room
        print_event(event);
    }
}

// Free the memory allocated for the haunted house
void free_haunted_house(haunted_house *house) {
    free(house);
}

// Main function
int main() {
    // Create a new haunted house
    haunted_house *house = create_haunted_house();

    // Add rooms to the haunted house
    add_room(house, ENTRANCE, "You enter the haunted house through a creaky wooden door.");
    add_room(house, HALLWAY, "You walk down a long, dark hallway.");
    add_room(house, BEDROOM, "You enter a bedroom with a large, four-poster bed.");
    add_room(house, BATHROOM, "You enter a bathroom with a claw-foot bathtub.");
    add_room(house, KITCHEN, "You enter a kitchen with a large, old-fashioned stove.");
    add_room(house, LIBRARY, "You enter a library with shelves full of dusty books.");
    add_room(house, DINING_ROOM, "You enter a dining room with a long, wooden table.");
    add_room(house, LIVING_ROOM, "You enter a living room with a large, leather couch.");
    add_room(house, ATTIC, "You climb a ladder to the attic.");
    add_room(house, BASEMENT, "You descend into the basement.");

    // Simulate the haunted house
    simulate_haunted_house(house);

    // Free the memory allocated for the haunted house
    free_haunted_house(house);

    return 0;
}