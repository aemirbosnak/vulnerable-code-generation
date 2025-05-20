//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct room {
    char *name;
    char *description;
    bool visited;
    bool win_room;
    struct room *north_room;
    struct room *south_room;
    struct room *east_room;
    struct room *west_room;
};

typedef struct room Room;

void print_current_room(Room *current)
{
    printf("\n-----------------------------------------------\n");
    printf("%s\n\n", current->name);
    printf("%s\n", current->description);
    printf("\n-----------------------------------------------\n");
}

char *read_input(char *input)
{
    printf("\n> ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = 0;
    
    return input;
}

Room *create_room(char *name, char *description, bool visited, bool win_room)
{
    Room *room = malloc(sizeof(Room));
    room->name = name;
    room->description = description;
    room->visited = visited;
    room->win_room = win_room;
    
    room->north_room = NULL;
    room->south_room = NULL;
    room->east_room = NULL;
    room->west_room = NULL;
    
    return room;
}

void connect_rooms(Room *room1, Room *room2, char *direction)
{
    if (strcmp(direction, "north") == 0) {
        room1->north_room = room2;
        room2->south_room = room1;
    } else if (strcmp(direction, "south") == 0) {
        room1->south_room = room2;
        room2->north_room = room1;
    } else if (strcmp(direction, "east") == 0) {
        room1->east_room = room2;
        room2->west_room = room1;
    } else if (strcmp(direction, "west") == 0) {
        room1->west_room = room2;
        room2->east_room = room1;
    }
}

void play_game(Room *current_room)
{
    char input[50];
    
    while(true) {
        if(current_room->win_room && current_room->visited) {
            printf("\nYou won! Congratulations on escaping the dungeon!\n\n");
            break;
        }
        
        if(!current_room->visited) {
            current_room->visited = true;
            print_current_room(current_room);
        }
        
        printf("Which direction do you want to go? (north, south, east, west)\n");
        read_input(input);
        
        if(strcmp(input, "north") == 0 && current_room->north_room != NULL) {
            current_room = current_room->north_room;
        } else if(strcmp(input, "south") == 0 && current_room->south_room != NULL) {
            current_room = current_room->south_room;
        } else if(strcmp(input, "east") == 0 && current_room->east_room != NULL) {
            current_room = current_room->east_room;
        } else if(strcmp(input, "west") == 0 && current_room->west_room != NULL) {
            current_room = current_room->west_room;
        } else {
            printf("\nYou hit a wall! Try again.\n");
        }
    }
}

int main()
{
    Room *start_room = create_room("Dungeon Entrance",
                                    "You find yourself at the entrance of a dark dungeon.",
                                    false, false);

    Room *room1 = create_room("Armory",
                              "You have entered the armory. There are many weapons and shields lining the walls.",
                              false, false);

    Room *room2 = create_room("Library",
                              "You have entered the library. Books line every shelf, but you notice one book is missing...",
                              false, false);

    Room *room3 = create_room("Chamber",
                              "You have entered the chamber. A large dragon is guarding the exit to the dungeon.",
                              false, true);

    connect_rooms(start_room, room1, "east");
    connect_rooms(start_room, room2, "north");
    connect_rooms(room2, room3, "east");

    play_game(start_room);
    
    return 0;
}