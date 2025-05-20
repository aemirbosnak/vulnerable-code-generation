//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 50
#define MAX_ROOMS 10
#define MAX_DESCRIPTION 200

// Room struct for holding room information
typedef struct Room {
    int id;
    char name[MAX_INPUT];
    char description[MAX_DESCRIPTION];
    struct Room *north;
    struct Room *east;
    struct Room *south;
    struct Room *west;
} Room;

// Function declarations
Room* create_rooms();
void link_rooms(Room *rooms);
void play_game(Room *start_room);
void print_room_description(Room *current_room);
int get_input(Room *current_room, char *input);
bool is_direction(char *input);
bool check_direction(Room *current_room, char *input);
Room* move_direction(Room *current_room, char *input);

int main() {
    srand(time(NULL)); // Seed the random number generator
    Room *start_room = create_rooms(); // Create the rooms
    link_rooms(start_room); // Link the rooms together
    play_game(start_room); // Start the game
}

Room* create_rooms() {
    // Initialize the rooms
    Room *rooms = malloc(MAX_ROOMS * sizeof(Room));
    for(int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].id = i;
        sprintf(rooms[i].name, "Room %d", i + 1);
        sprintf(rooms[i].description, "You are in %s. It's dark, cold, and damp. You can hear strange noises in the distance.", rooms[i].name);
        rooms[i].north = NULL;
        rooms[i].east = NULL;
        rooms[i].south = NULL;
        rooms[i].west = NULL;
    }
    return rooms;
}

void link_rooms(Room *rooms) {
    // Link the rooms together randomly
    int directions[MAX_ROOMS] = {0}; // Directions already assigned
    for(int i = 0; i < MAX_ROOMS; i++) {
        int room_id = i;
        while(directions[room_id] < 4) {
            int rand_dir = rand() % 4; // Randomly assign direction
            if(directions[room_id] == 0 && rooms[room_id].north == NULL) {
                // Assign north
                int next_room_id = room_id - 1;
                if(next_room_id >= 0 && rooms[next_room_id].south == NULL) {
                    rooms[room_id].north = &rooms[next_room_id];
                    rooms[next_room_id].south = &rooms[room_id];
                    directions[room_id]++;
                    directions[next_room_id]++;
                }
            } else if(directions[room_id] == 1 && rooms[room_id].east == NULL) {
                // Assign east
                int next_room_id = room_id + 3;
                if(next_room_id < MAX_ROOMS && rooms[next_room_id].west == NULL) {
                    rooms[room_id].east = &rooms[next_room_id];
                    rooms[next_room_id].west = &rooms[room_id];
                    directions[room_id]++;
                    directions[next_room_id]++;
                }
            } else if(directions[room_id] == 2 && rooms[room_id].south == NULL) {
                // Assign south
                int next_room_id = room_id + 1;
                if(next_room_id < MAX_ROOMS && rooms[next_room_id].north == NULL) {
                    rooms[room_id].south = &rooms[next_room_id];
                    rooms[next_room_id].north = &rooms[room_id];
                    directions[room_id]++;
                    directions[next_room_id]++;
                }
            } else if(directions[room_id] == 3 && rooms[room_id].west == NULL) {
                // Assign west
                int next_room_id = room_id - 3;
                if(next_room_id >= 0 && rooms[next_room_id].east == NULL) {
                    rooms[room_id].west = &rooms[next_room_id];
                    rooms[next_room_id].east = &rooms[room_id];
                    directions[room_id]++;
                    directions[next_room_id]++;
                }
            }
        }
    }
}

void play_game(Room *start_room) {
    Room *current_room = start_room;
    char input[MAX_INPUT] = "";
    printf("Welcome to the Haunted House Simulator! Your goal is to escape the house.\n\n");
    do {
        print_room_description(current_room);
        if(get_input(current_room, input)) {
            if(is_direction(input)) {
                if(check_direction(current_room, input)) {
                    current_room = move_direction(current_room, input);
                } else {
                    printf("You can't go that way.\n\n");
                }
            } else {
                printf("Invalid input.\n\n");
            }
        }
    } while(current_room->id != 0); // Escape condition
    printf("Congratulations! You escaped the haunted house.\n");
}

void print_room_description(Room *current_room) {
    printf("%s\n", current_room->description);
    if(current_room->north != NULL) printf("There is a door to the north.\n");
    if(current_room->east != NULL) printf("There is a door to the east.\n");
    if(current_room->south != NULL) printf("There is a door to the south.\n");
    if(current_room->west != NULL) printf("There is a door to the west.\n");
    printf("\n");
}

int get_input(Room *current_room, char *input) {
    printf("> ");
    fflush(stdout);
    fgets(input, MAX_INPUT, stdin);
    // Replace newline character with null character
    if(input[strlen(input)-1] == '\n') input[strlen(input)-1] = '\0';
    // Check if user wants to quit
    if(strcmp(input, "quit") == 0) exit(0);
    return strlen(input) > 0;
}

bool is_direction(char *input) {
    if(strcmp(input, "north") == 0 || strcmp(input, "east") == 0 || strcmp(input, "south") == 0 || strcmp(input, "west") == 0) {
        return true;
    }
    return false;
}

bool check_direction(Room *current_room, char *input) {
    if(strcmp(input, "north") == 0 && current_room->north != NULL) {
        return true;
    } else if(strcmp(input, "east") == 0 && current_room->east != NULL) {
        return true;
    } else if(strcmp(input, "south") == 0 && current_room->south != NULL) {
        return true;
    } else if(strcmp(input, "west") == 0 && current_room->west != NULL) {
        return true;
    }
    return false;
}

Room* move_direction(Room *current_room, char *input) {
    if(strcmp(input, "north") == 0) {
        return current_room->north;
    } else if(strcmp(input, "east") == 0) {
        return current_room->east;
    } else if(strcmp(input, "south") == 0) {
        return current_room->south;
    } else if(strcmp(input, "west") == 0) {
        return current_room->west;
    }
    return current_room;
}