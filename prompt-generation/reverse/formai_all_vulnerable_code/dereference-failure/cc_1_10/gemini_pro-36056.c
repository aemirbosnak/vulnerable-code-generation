//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the possible events that can occur in a room
typedef enum {
    EVENT_NONE,
    EVENT_CREAK,
    EVENT_GROAN,
    EVENT_BANG,
    EVENT_SCREAM
} event_t;

// Define the structure of a room in the haunted house
typedef struct {
    int number;          // The room number
    event_t event;       // The event that occurs in the room
    struct room *next;    // The next room in the house
} room_t;

// Define the structure of the haunted house
typedef struct {
    room_t *first;       // The first room in the house
    room_t *last;        // The last room in the house
    int num_rooms;       // The number of rooms in the house
} haunted_house_t;

// Create a new haunted house
haunted_house_t *create_haunted_house(int num_rooms) {
    // Allocate memory for the haunted house
    haunted_house_t *house = malloc(sizeof(haunted_house_t));

    // Initialize the haunted house
    house->first = NULL;
    house->last = NULL;
    house->num_rooms = num_rooms;

    // Create the rooms in the haunted house
    for (int i = 0; i < num_rooms; i++) {
        // Allocate memory for the room
        room_t *room = malloc(sizeof(room_t));

        // Initialize the room
        room->number = i + 1;
        room->event = EVENT_NONE;
        room->next = NULL;

        // Add the room to the haunted house
        if (house->first == NULL) {
            house->first = room;
        } else {
            house->last->next = room;
        }
        house->last = room;
    }

    // Return the haunted house
    return house;
}

// Destroy a haunted house
void destroy_haunted_house(haunted_house_t *house) {
    // Free the rooms in the haunted house
    room_t *room = house->first;
    while (room != NULL) {
        room_t *next = room->next;
        free(room);
        room = next;
    }

    // Free the haunted house
    free(house);
}

// Get a random event
event_t get_random_event() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 0 and 4
    int random_number = rand() % 5;

    // Return the corresponding event
    switch (random_number) {
        case 0:
            return EVENT_CREAK;
        case 1:
            return EVENT_GROAN;
        case 2:
            return EVENT_BANG;
        case 3:
            return EVENT_SCREAM;
        default:
            return EVENT_NONE;
    }
}

// Simulate a haunted house
void simulate_haunted_house(haunted_house_t *house) {
    // Get the first room in the haunted house
    room_t *room = house->first;

    // Loop through the rooms in the haunted house
    while (room != NULL) {
        // Get a random event for the room
        room->event = get_random_event();

        // Print the event that occurred in the room
        switch (room->event) {
            case EVENT_CREAK:
                printf("You hear a creak in room %d.\n", room->number);
                break;
            case EVENT_GROAN:
                printf("You hear a groan in room %d.\n", room->number);
                break;
            case EVENT_BANG:
                printf("You hear a bang in room %d.\n", room->number);
                break;
            case EVENT_SCREAM:
                printf("You hear a scream in room %d.\n", room->number);
                break;
            default:
                printf("Nothing happens in room %d.\n", room->number);
                break;
        }

        // Get the next room in the haunted house
        room = room->next;
    }
}

// Main function
int main() {
    // Create a new haunted house with 10 rooms
    haunted_house_t *house = create_haunted_house(10);

    // Simulate the haunted house
    simulate_haunted_house(house);

    // Destroy the haunted house
    destroy_haunted_house(house);

    return 0;
}