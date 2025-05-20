//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world
typedef struct {
    char *name;
    char *description;
    int num_exits;
    char **exits;
} Room;

Room rooms[] = {
    { "The Starting Room", "You are in a small, dark room. There is a door to the north.", 1, {"North"} },
    { "The Northern Room", "You are in a larger room with a high ceiling. There are doors to the south and east.", 2, {"South", "East"} },
    { "The Eastern Room", "You are in a long, narrow room. There are doors to the west and south.", 2, {"West", "South"} },
    { "The Southern Room", "You are in a large, open room. There are doors to the north, east, and west.", 3, {"North", "East", "West"} },
};

// Define the player
typedef struct {
    char *name;
    int health;
    int strength;
    Room *current_room;
} Player;

Player player = { "Player", 100, 10, &rooms[0] };

// Define the game engine
void print_room_description() {
    printf("%s\n", player.current_room->description);
}

void print_room_exits() {
    printf("Exits: ");
    for (int i = 0; i < player.current_room->num_exits; i++) {
        printf("%s ", player.current_room->exits[i]);
    }
    printf("\n");
}

void move_player(char *direction) {
    for (int i = 0; i < player.current_room->num_exits; i++) {
        if (strcmp(direction, player.current_room->exits[i]) == 0) {
            player.current_room = &rooms[i];
            return;
        }
    }
    printf("You cannot move in that direction.\n");
}

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are %s, a brave adventurer.\n", player.name);
    printf("You are in %s.\n", player.current_room->name);
    
    while (1) {
        print_room_description();
        print_room_exits();
        
        char input[100];
        printf("> ");
        scanf("%s", input);
        
        if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else if (strcmp(input, "north") == 0) {
            move_player("North");
        } else if (strcmp(input, "south") == 0) {
            move_player("South");
        } else if (strcmp(input, "east") == 0) {
            move_player("East");
        } else if (strcmp(input, "west") == 0) {
            move_player("West");
        } else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}