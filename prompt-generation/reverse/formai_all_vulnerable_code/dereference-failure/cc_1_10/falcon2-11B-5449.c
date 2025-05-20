//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Room {
    int width;
    int height;
    char** tiles;
    int num_monsters;
} Room;

typedef struct Monster {
    int health;
    int attack;
} Monster;

int main() {
    srand(time(NULL)); // Set seed for random number generator

    // Create a 10x10 grid of rooms
    Room* rooms = malloc(10 * sizeof(Room));
    for (int i = 0; i < 10; i++) {
        rooms[i].width = rand() % 5 + 1; // Random width between 1 and 5
        rooms[i].height = rand() % 5 + 1; // Random height between 1 and 5
        rooms[i].tiles = malloc(rooms[i].width * sizeof(char*));
        for (int j = 0; j < rooms[i].width; j++) {
            rooms[i].tiles[j] = malloc(rooms[i].height * sizeof(char));
            for (int k = 0; k < rooms[i].height; k++) {
                rooms[i].tiles[j][k] = '.'; // Floor tile
            }
        }
        rooms[i].num_monsters = rand() % 3 + 1; // Random number of monsters between 1 and 3
        for (int j = 0; j < rooms[i].num_monsters; j++) {
            int monster_type = rand() % 3 + 1; // Random monster type
            int monster_health = rand() % 5 + 1; // Random monster health
            int monster_attack = rand() % 5 + 1; // Random monster attack

            Monster* monster = malloc(sizeof(Monster));
            monster->health = monster_health;
            monster->attack = monster_attack;

            rooms[i].tiles[rand() % rooms[i].width][rand() % rooms[i].height] = 'M'; // Place monster in a random tile
        }
    }

    // Print the generated rooms
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < rooms[i].width; j++) {
            for (int k = 0; k < rooms[i].height; k++) {
                printf("%c", rooms[i].tiles[j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}