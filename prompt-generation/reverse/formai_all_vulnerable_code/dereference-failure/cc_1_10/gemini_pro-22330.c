//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the room struct
typedef struct room {
    char* name;
    char* description;
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
} room;

// Define the player struct
typedef struct player {
    char* name;
    int health;
    int attack;
    int defense;
    room* current_room;
} player;

// Define the monster struct
typedef struct monster {
    char* name;
    int health;
    int attack;
    int defense;
} monster;

// Create the rooms
room* create_room(char* name, char* description) {
    room* new_room = (room*)malloc(sizeof(room));
    new_room->name = strdup(name);
    new_room->description = strdup(description);
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

// Create the player
player* create_player(char* name, int health, int attack, int defense, room* current_room) {
    player* new_player = (player*)malloc(sizeof(player));
    new_player->name = strdup(name);
    new_player->health = health;
    new_player->attack = attack;
    new_player->defense = defense;
    new_player->current_room = current_room;
    return new_player;
}

// Create the monster
monster* create_monster(char* name, int health, int attack, int defense) {
    monster* new_monster = (monster*)malloc(sizeof(monster));
    new_monster->name = strdup(name);
    new_monster->health = health;
    new_monster->attack = attack;
    new_monster->defense = defense;
    return new_monster;
}

// Print the room description
void print_room_description(room* room) {
    printf("%s\n", room->description);
}

// Print the player stats
void print_player_stats(player* player) {
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Attack: %d\n", player->attack);
    printf("Defense: %d\n", player->defense);
}

// Print the monster stats
void print_monster_stats(monster* monster) {
    printf("Name: %s\n", monster->name);
    printf("Health: %d\n", monster->health);
    printf("Attack: %d\n", monster->attack);
    printf("Defense: %d\n", monster->defense);
}

// Handle the player's input
void handle_input(player* player) {
    char input[100];
    printf("> ");
    fgets(input, 100, stdin);

    if (strcmp(input, "north\n") == 0) {
        if (player->current_room->north != NULL) {
            player->current_room = player->current_room->north;
        } else {
            printf("You cannot go north.\n");
        }
    } else if (strcmp(input, "east\n") == 0) {
        if (player->current_room->east != NULL) {
            player->current_room = player->current_room->east;
        } else {
            printf("You cannot go east.\n");
        }
    } else if (strcmp(input, "south\n") == 0) {
        if (player->current_room->south != NULL) {
            player->current_room = player->current_room->south;
        } else {
            printf("You cannot go south.\n");
        }
    } else if (strcmp(input, "west\n") == 0) {
        if (player->current_room->west != NULL) {
            player->current_room = player->current_room->west;
        } else {
            printf("You cannot go west.\n");
        }
    } else if (strcmp(input, "look\n") == 0) {
        print_room_description(player->current_room);
    } else if (strcmp(input, "stats\n") == 0) {
        print_player_stats(player);
    } else if (strcmp(input, "quit\n") == 0) {
        exit(0);
    } else {
        printf("Invalid input.\n");
    }
}

// Battle the monster
void battle(player* player, monster* monster) {
    int player_turn = 1;

    while (player->health > 0 && monster->health > 0) {
        if (player_turn) {
            int damage = player->attack - monster->defense;
            if (damage < 0) {
                damage = 0;
            }
            monster->health -= damage;
            printf("You attacked the %s for %d damage.\n", monster->name, damage);
        } else {
            int damage = monster->attack - player->defense;
            if (damage < 0) {
                damage = 0;
            }
            player->health -= damage;
            printf("The %s attacked you for %d damage.\n", monster->name, damage);
        }
        player_turn = !player_turn;
    }

    if (player->health <= 0) {
        printf("You have died.\n");
        exit(0);
    } else {
        printf("You have defeated the %s!\n", monster->name);
    }
}

// Play the game
void play_game(player* player) {
    while (1) {
        print_room_description(player->current_room);
        handle_input(player);

        if (player->current_room->north != NULL && player->current_room->north->name == "Exit") {
            printf("You have won the game!\n");
            exit(0);
        }

        if (player->current_room->east != NULL && player->current_room->east->name == "Monster Room") {
            monster* monster = create_monster("Orc", 100, 10, 5);
            battle(player, monster);
        }
    }
}

// Main function
int main() {
    // Create the rooms
    room* room1 = create_room("Starting Room", "You are in a small, dark room. There is a door to the north.");
    room* room2 = create_room("Monster Room", "You are in a large, dark room. There is a monster in the center of the room.");
    room* room3 = create_room("Exit", "You are in a small, bright room. There is a door to the south.");

    // Connect the rooms
    room1->north = room2;
    room2->east = room3;
    room3->south = room1;

    // Create the player
    player* player = create_player("Player", 100, 10, 5, room1);

    // Play the game
    play_game(player);

    return 0;
}