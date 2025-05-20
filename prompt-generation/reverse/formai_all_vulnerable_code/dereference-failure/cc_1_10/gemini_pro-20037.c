//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player's stats
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Player;

// Define the room structure
typedef struct {
    char *name;
    char *description;
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
} Room;

// Create the player
Player *create_player(char *name, int health, int attack, int defense) {
    Player *player = malloc(sizeof(Player));
    player->name = strdup(name);
    player->health = health;
    player->attack = attack;
    player->defense = defense;
    return player;
}

// Create a room
Room *create_room(char *name, char *description, Room *north, Room *south, Room *east, Room *west) {
    Room *room = malloc(sizeof(Room));
    room->name = strdup(name);
    room->description = strdup(description);
    room->north = north;
    room->south = south;
    room->east = east;
    room->west = west;
    return room;
}

// Play the game
void play_game(Player *player, Room *room) {
    // Print the player's stats
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Attack: %d\n", player->attack);
    printf("Defense: %d\n", player->defense);

    // Print the room's description
    printf("%s\n%s\n", room->name, room->description);

    // Get the player's input
    char input[80];
    printf("> ");
    fgets(input, 80, stdin);

    // Parse the player's input
    char *verb = strtok(input, " ");
    char *noun = strtok(NULL, " ");

    // Execute the player's command
    if (strcmp(verb, "go") == 0) {
        if (strcmp(noun, "north") == 0) {
            if (room->north != NULL) {
                room = room->north;
            } else {
                printf("There is no door to the north.\n");
            }
        } else if (strcmp(noun, "south") == 0) {
            if (room->south != NULL) {
                room = room->south;
            } else {
                printf("There is no door to the south.\n");
            }
        } else if (strcmp(noun, "east") == 0) {
            if (room->east != NULL) {
                room = room->east;
            } else {
                printf("There is no door to the east.\n");
            }
        } else if (strcmp(noun, "west") == 0) {
            if (room->west != NULL) {
                room = room->west;
            } else {
                printf("There is no door to the west.\n");
            }
        } else {
            printf("I don't understand that direction.\n");
        }
    } else if (strcmp(verb, "attack") == 0) {
        // Get the target of the player's attack
        char *target = strtok(NULL, " ");

        // Attack the target
        if (strcmp(target, "goblin") == 0) {
            // Get the goblin's stats
            int goblin_health = 10;
            int goblin_attack = 5;
            int goblin_defense = 2;

            // Calculate the damage dealt by the player
            int damage = player->attack - goblin_defense;

            // If the damage is greater than 0, apply it to the goblin
            if (damage > 0) {
                goblin_health -= damage;
            }

            // If the goblin's health reaches 0, the player wins
            if (goblin_health <= 0) {
                printf("You have defeated the goblin!\n");
            } else {
                // Calculate the damage dealt by the goblin
                damage = goblin_attack - player->defense;

                // If the damage is greater than 0, apply it to the player
                if (damage > 0) {
                    player->health -= damage;
                }

                // If the player's health reaches 0, the player loses
                if (player->health <= 0) {
                    printf("You have been defeated by the goblin!\n");
                }
            }
        } else {
            printf("I don't see that target here.\n");
        }
    } else {
        printf("I don't understand that command.\n");
    }

    // If the player's health reaches 0, the game is over
    if (player->health <= 0) {
        printf("Game over!\n");
        exit(0);
    }

    // Recursively call the play_game function
    play_game(player, room);
}

// Create the game world
Room *create_game_world() {
    // Create the rooms
    Room *room1 = create_room("The Entrance", "You are standing in the entrance to a dark and mysterious cave.", NULL, NULL, NULL, NULL);
    Room *room2 = create_room("The Crossroads", "You are standing at a crossroads. There are doors to the north, east, and west.", room1, NULL, NULL, NULL);
    Room *room3 = create_room("The Chamber of Secrets", "You are standing in a large chamber. There is a door to the south.", NULL, room2, NULL, NULL);
    Room *room4 = create_room("The Treasure Room", "You are standing in a small room. There is a chest in the center of the room.", NULL, NULL, NULL, room2);
    Room *room5 = create_room("The Exit", "You are standing at the exit of the cave.", room4, NULL, NULL, NULL);

    // Connect the rooms
    room1->north = room2;
    room2->south = room1;
    room2->east = room3;
    room2->west = room4;
    room3->south = room2;
    room4->east = room2;
    room4->west = room5;
    room5->east = room4;

    // Return the first room
    return room1;
}

// Main function
int main() {
    // Create the player
    Player *player = create_player("The Hero", 100, 10, 5);

    // Create the game world
    Room *world = create_game_world();

    // Play the game
    play_game(player, world);

    return 0;
}