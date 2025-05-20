//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Struct to represent a room in the haunted house
typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

// Array of room names
char* room_names[] = {
    "Foyer",
    "Living Room",
    "Dining Room",
    "Kitchen",
    "Study",
    "Master Bedroom",
    "Guest Bedroom",
    "Bathroom",
    "Attic",
    "Basement"
};

// Array of room descriptions
char* room_descriptions[] = {
    "A large, open room with a high ceiling and a grand staircase leading to the upper floors.",
    "A cozy room with a fireplace and a couch. A large window overlooks the front yard.",
    "A formal room with a long table and chairs. A chandelier hangs from the ceiling.",
    "A large room with a stove, oven, and refrigerator. A door leads to the backyard.",
    "A small room with a desk and a bookcase. A window overlooks the side yard.",
    "A large room with a bed, dresser, and nightstands. A door leads to a balcony.",
    "A small room with a bed and a dresser. A window overlooks the backyard.",
    "A small room with a toilet, sink, and bathtub. A window overlooks the side yard.",
    "A large, open space with a dusty floor and cobwebs hanging from the rafters.",
    "A large, dark space with a dirt floor and a musty smell."
};

// Function to create a new room
room* create_room(char* name, char* description) {
    room* new_room = malloc(sizeof(room));
    new_room->name = name;
    new_room->description = description;
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

// Function to connect two rooms
void connect_rooms(room* room1, room* room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            break;
        case 'e':
            room1->east = room2;
            break;
        case 's':
            room1->south = room2;
            break;
        case 'w':
            room1->west = room2;
            break;
    }
}

// Function to generate a random haunted house
room* generate_haunted_house() {
    // Create the rooms
    room* foyer = create_room(room_names[0], room_descriptions[0]);
    room* living_room = create_room(room_names[1], room_descriptions[1]);
    room* dining_room = create_room(room_names[2], room_descriptions[2]);
    room* kitchen = create_room(room_names[3], room_descriptions[3]);
    room* study = create_room(room_names[4], room_descriptions[4]);
    room* master_bedroom = create_room(room_names[5], room_descriptions[5]);
    room* guest_bedroom = create_room(room_names[6], room_descriptions[6]);
    room* bathroom = create_room(room_names[7], room_descriptions[7]);
    room* attic = create_room(room_names[8], room_descriptions[8]);
    room* basement = create_room(room_names[9], room_descriptions[9]);

    // Connect the rooms
    connect_rooms(foyer, living_room, 'n');
    connect_rooms(foyer, dining_room, 'e');
    connect_rooms(foyer, kitchen, 's');
    connect_rooms(foyer, study, 'w');
    connect_rooms(living_room, master_bedroom, 'n');
    connect_rooms(living_room, guest_bedroom, 'e');
    connect_rooms(living_room, bathroom, 's');
    connect_rooms(dining_room, kitchen, 'n');
    connect_rooms(dining_room, study, 'e');
    connect_rooms(kitchen, basement, 's');
    connect_rooms(study, attic, 'n');

    // Return the starting room
    return foyer;
}

// Function to print a room's description
void print_room_description(room* room) {
    printf("%s\n", room->description);
}

// Function to get a random direction
char get_random_direction() {
    int random_number = rand() % 4;
    switch (random_number) {
        case 0:
            return 'n';
        case 1:
            return 'e';
        case 2:
            return 's';
        case 3:
            return 'w';
    }
    return 'n'; // Default to north
}

// Function to simulate the haunted house
void simulate_haunted_house(room* current_room) {
    // Print the room's description
    print_room_description(current_room);

    // Get a random direction
    char direction = get_random_direction();

    // Move to the next room
    switch (direction) {
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
    }

    // If the current room is null, then we have reached the end of the house
    if (current_room == NULL) {
        printf("You have escaped the haunted house!\n");
        return;
    }

    // Simulate the next room
    simulate_haunted_house(current_room);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a haunted house
    room* haunted_house = generate_haunted_house();

    // Simulate the haunted house
    simulate_haunted_house(haunted_house);

    return 0;
}