//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the different types of ghosts
typedef enum {
    GHOST_TYPE_POLTERGEIST,
    GHOST_TYPE_SPECTRE,
    GHOST_TYPE_DEMON
} ghost_type_t;

// Define the different types of rooms
typedef enum {
    ROOM_TYPE_LIVING_ROOM,
    ROOM_TYPE_KITCHEN,
    ROOM_TYPE_BEDROOM,
    ROOM_TYPE_BATHROOM,
    ROOM_TYPE_ATTIC
} room_type_t;

// Define the different types of events
typedef enum {
    EVENT_TYPE_DOOR_CREAKS_OPEN,
    EVENT_TYPE_LIGHT_FLICKERS,
    EVENT_TYPE_FOOTSTEPS_HEARD,
    EVENT_TYPE_SHADOW_SEEN,
    EVENT_TYPE_GHOST_APPEARS
} event_type_t;

// Define the struct for a ghost
typedef struct {
    ghost_type_t type;
    int power;
} ghost_t;

// Define the struct for a room
typedef struct {
    room_type_t type;
    int size;
    int haunted;
} room_t;

// Define the struct for an event
typedef struct {
    event_type_t type;
    int time;
} event_t;

// Create a new ghost
ghost_t *create_ghost(ghost_type_t type, int power) {
    ghost_t *ghost = malloc(sizeof(ghost_t));
    ghost->type = type;
    ghost->power = power;
    return ghost;
}

// Create a new room
room_t *create_room(room_type_t type, int size, int haunted) {
    room_t *room = malloc(sizeof(room_t));
    room->type = type;
    room->size = size;
    room->haunted = haunted;
    return room;
}

// Create a new event
event_t *create_event(event_type_t type, int time) {
    event_t *event = malloc(sizeof(event_t));
    event->type = type;
    event->time = time;
    return event;
}

// Get a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random ghost
ghost_t *generate_random_ghost() {
    ghost_type_t type = get_random_number(GHOST_TYPE_POLTERGEIST, GHOST_TYPE_DEMON);
    int power = get_random_number(1, 10);
    return create_ghost(type, power);
}

// Generate a random room
room_t *generate_random_room() {
    room_type_t type = get_random_number(ROOM_TYPE_LIVING_ROOM, ROOM_TYPE_ATTIC);
    int size = get_random_number(10, 20);
    int haunted = get_random_number(0, 1);
    return create_room(type, size, haunted);
}

// Generate a random event
event_t *generate_random_event() {
    event_type_t type = get_random_number(EVENT_TYPE_DOOR_CREAKS_OPEN, EVENT_TYPE_GHOST_APPEARS);
    int time = get_random_number(1, 10);
    return create_event(type, time);
}

// Print the ghost
void print_ghost(ghost_t *ghost) {
    printf("Ghost: ");
    switch (ghost->type) {
        case GHOST_TYPE_POLTERGEIST:
            printf("Poltergeist");
            break;
        case GHOST_TYPE_SPECTRE:
            printf("Spectre");
            break;
        case GHOST_TYPE_DEMON:
            printf("Demon");
            break;
    }
    printf(" (Power: %d)\n", ghost->power);
}

// Print the room
void print_room(room_t *room) {
    printf("Room: ");
    switch (room->type) {
        case ROOM_TYPE_LIVING_ROOM:
            printf("Living Room");
            break;
        case ROOM_TYPE_KITCHEN:
            printf("Kitchen");
            break;
        case ROOM_TYPE_BEDROOM:
            printf("Bedroom");
            break;
        case ROOM_TYPE_BATHROOM:
            printf("Bathroom");
            break;
        case ROOM_TYPE_ATTIC:
            printf("Attic");
            break;
    }
    printf(" (Size: %d, Haunted: %d)\n", room->size, room->haunted);
}

// Print the event
void print_event(event_t *event) {
    printf("Event: ");
    switch (event->type) {
        case EVENT_TYPE_DOOR_CREAKS_OPEN:
            printf("Door Creaks Open");
            break;
        case EVENT_TYPE_LIGHT_FLICKERS:
            printf("Light Flickers");
            break;
        case EVENT_TYPE_FOOTSTEPS_HEARD:
            printf("Footsteps Heard");
            break;
        case EVENT_TYPE_SHADOW_SEEN:
            printf("Shadow Seen");
            break;
        case EVENT_TYPE_GHOST_APPEARS:
            printf("Ghost Appears");
            break;
    }
    printf(" (Time: %d)\n", event->time);
}

void run_haunted_house_simulator() {
    // Create a haunted house
    room_t *rooms[5];
    for (int i = 0; i < 5; i++) {
        rooms[i] = generate_random_room();
    }

    int time = 0;
    while (1) {
		// A day in the life of a haunted house!
        printf("Time: %d\n", time);
        for (int i = 0; i < 5; i++) {
			// Check if any events happen in this room
            event_t *event = generate_random_event();
            if (event->type == EVENT_TYPE_GHOST_APPEARS && rooms[i]->haunted) {
                ghost_t *ghost = generate_random_ghost();
                printf("A ghost appears in the ");
                print_room(rooms[i]);
                printf("!");
                print_ghost(ghost);
            } else {
                printf("Nothing happens in the ");
                print_room(rooms[i]);
                printf(".");
            }
            free(event);
        }
        printf("\n");
        time++;
    }
}

int main() {
    srand(time(NULL));
    run_haunted_house_simulator();
    return 0;
}