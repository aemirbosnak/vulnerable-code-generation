//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Room struct
typedef struct room {
    int number;
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
    int visited;
    int monster;
    int treasure;
} Room;

// Function to create a new room
Room* new_room(int number) {
    // Allocate memory for room struct
    Room* room = malloc(sizeof(Room));
    
    // Set room properties based on room number
    switch(number) {
        case 0:
            room->name = "Entrance Hall";
            room->description = "You are in a large entrance hall. The room is dark and damp.";
            room->north = NULL;
            room->east = new_room(1);
            room->south = NULL;
            room->west = NULL;
            room->monster = 0;
            room->treasure = 0;
            break;
        case 1:
            room->name = "Kitchen";
            room->description = "The kitchen is full of cobwebs. You can barely see anything.";
            room->north = NULL;
            room->east = new_room(2);
            room->south = NULL;
            room->west = new_room(0);
            room->monster = 1;
            room->treasure = 0;
            break;
        case 2:
            room->name = "Living Room";
            room->description = "The living room is filled with old furniture and strange artifacts.";
            room->north = new_room(5);
            room->east = NULL;
            room->south = new_room(3);
            room->west = new_room(1);
            room->monster = 0;
            room->treasure = 0;
            break;
        case 3:
            room->name = "Bedroom";
            room->description = "There is a large bed in the center of the room. It looks like someone was just sleeping in it.";
            room->north = new_room(2);
            room->east = NULL;
            room->south = new_room(4);
            room->west = NULL;
            room->monster = 0;
            room->treasure = 1;
            break;
        case 4:
            room->name = "Dining Room";
            room->description = "The dining room is set for a feast. But there is no food in sight.";
            room->north = new_room(3);
            room->east = new_room(6);
            room->south = NULL;
            room->west = NULL;
            room->monster = 1;
            room->treasure = 0;
            break;
        case 5:
            room->name = "Library";
            room->description = "The library is lined with bookshelves from floor to ceiling. Many of the books are missing their covers.";
            room->north = NULL;
            room->east = NULL;
            room->south = new_room(2);
            room->west = new_room(7);
            room->monster = 0;
            room->treasure = 1;
            break;
        case 6:
            room->name = "Ballroom";
            room->description = "The ballroom is massive and empty. But there is a strange feeling in the air.";
            room->north = NULL;
            room->east = NULL;
            room->south = NULL;
            room->west = new_room(4);
            room->monster = 0;
            room->treasure = 0;
            break;
        case 7:
            room->name = "Study";
            room->description = "The study is full of old papers and strange diagrams. It looks like someone was studying the occult.";
            room->north = NULL;
            room->east = new_room(5);
            room->south = NULL;
            room->west = NULL;
            room->monster = 1;
            room->treasure = 0;
            break;
    }
    
    // Set room number and visited flag
    room->number = number;
    room->visited = 0;
    
    // Return newly created room
    return room;
}

// Function to print the current room
void print_room(Room* room) {
    printf("%s\n", room->name);
    printf("%s\n", room->description);
    if(room->monster == 1) {
        printf("There is a monster in the room!\n");
    }
    if(room->treasure == 1) {
        printf("There is treasure in the room!\n");
    }
}

// Function to move the player to another room
int move_player(Room** current_room, char* direction) {
    // Check if the player can move in the specified direction
    if(direction == "north" && (*current_room)->north != NULL) {
        *current_room = (*current_room)->north;
        return 1;
    } else if(direction == "east" && (*current_room)->east != NULL) {
        *current_room = (*current_room)->east;
        return 1;
    } else if(direction == "south" && (*current_room)->south != NULL) {
        *current_room = (*current_room)->south;
        return 1;
    } else if(direction == "west" && (*current_room)->west != NULL) {
        *current_room = (*current_room)->west;
        return 1;
    } else {
        printf("You cannot move in that direction.\n");
        return 0;
    }
}

// Function to generate a random number between min and max (inclusive)
int random_num(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Main function
int main() {
    // Generate haunted house by creating each room
    Room* entrance = new_room(0);
    Room* kitchen = new_room(1);
    Room* living_room = new_room(2);
    Room* bedroom = new_room(3);
    Room* dining_room = new_room(4);
    Room* library = new_room(5);
    Room* ballroom = new_room(6);
    Room* study = new_room(7);
    
    // Set current room to the entrance
    Room* current_room = entrance;
    
    // Game loop
    while(1) {
        // Print current room
        print_room(current_room);
        
        // Set current room as visited
        current_room->visited = 1;
        
        // Check if there is a monster in the room
        if(current_room->monster == 1) {
            printf("The monster has killed you! Game over.\n");
            break;
        }
        
        // Check if there is treasure in the room
        if(current_room->treasure == 1) {
            printf("You have found the treasure! You win!\n");
            break;
        }
        
        // Prompt user for input
        printf("Enter a direction to move (north, east, south, west): ");
        char input[10];
        scanf("%s", input);
        
        // Move player in specified direction
        move_player(&current_room, input);
        
        // Check if the player has visited all rooms
        if(entrance->visited == 1 && kitchen->visited == 1 && living_room->visited == 1 && bedroom->visited == 1 &&
           dining_room->visited == 1 && library->visited == 1 && ballroom->visited == 1 && study->visited == 1) {
            // Generate random number between 1 and 10
            int random = random_num(1, 10);
            
            // If the number is greater than 5, spawn a monster in a random room
            if(random > 5) {
                // Generate random room number between 0 and 7
                int room_num = random_num(0, 7);
                
                // Set monster flag to 1 in the randomly selected room
                switch(room_num) {
                    case 0:
                        entrance->monster = 1;
                        break;
                    case 1:
                        kitchen->monster = 1;
                        break;
                    case 2:
                        living_room->monster = 1;
                        break;
                    case 3:
                        bedroom->monster = 1;
                        break;
                    case 4:
                        dining_room->monster = 1;
                        break;
                    case 5:
                        library->monster = 1;
                        break;
                    case 6:
                        ballroom->monster = 1;
                        break;
                    case 7:
                        study->monster = 1;
                        break;
                }
            }
        }
    }
    
    // Free memory allocated for rooms
    free(entrance);
    free(kitchen);
    free(living_room);
    free(bedroom);
    free(dining_room);
    free(library);
    free(ballroom);
    free(study);
    
    return 0;
}