//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5
#define ROOM_SIZE 5

typedef struct {
    char name[20];
    int strength;
    int health;
} Monster;

typedef struct {
    char description[50];
    Monster* monster;
    int treasure;
} Room;

Room dungeon[MAX_ROOMS];

// Function prototypes
void generateDungeon();
void encounterMonsters(Room *room);
void exploreDungeon();

int main() {
    srand(time(NULL));  // Seed random number generator
    generateDungeon();  // Generate the dungeon
    exploreDungeon();   // Let the player explore the dungeon
    return 0;
}

void generateDungeon() {
    const char* roomDescriptions[] = {
        "A dark and damp room",
        "A room filled with creepy shadows",
        "A bright and shiny chamber",
        "An eerie silent place",
        "A room with flickering lights"
    };

    for (int i = 0; i < MAX_ROOMS; i++) {
        strcpy(dungeon[i].description, roomDescriptions[rand() % (sizeof(roomDescriptions) / sizeof(char*))]);
        dungeon[i].treasure = rand() % 100;  // Random treasure between 0 to 99

        // Randomly assign monsters
        if (rand() % 2) {  // 50% chance of having a monster
            Monster *monster = (Monster *)malloc(sizeof(Monster));
            sprintf(monster->name, "Monster%d", rand() % MAX_MONSTERS);
            monster->strength = rand() % 20 + 1;  // Random strength between 1 to 20
            monster->health = rand() % 50 + 1;    // Random health between 1 to 50
            dungeon[i].monster = monster;
        } else {
            dungeon[i].monster = NULL;  // No monster in this room
        }
    }
}

void encounterMonsters(Room *room) {
    if (room->monster) {
        printf("You encountered %s!\n", room->monster->name);
        printf("Strength: %d, Health: %d\n", room->monster->strength, room->monster->health);
        printf("Do you want to fight it? (y/n): ");
        
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'y') {
            printf("You fought bravely but %s is too strong!\n", room->monster->name);
            printf("You lost the battle. Game Over!\n");
            free(room->monster);  // Free monster memory
            exit(0);
        } else {
            printf("You decide to avoid the fight and continue exploring.\n");
        }
    } else {
        printf("The room is empty. You found %d gold!\n", room->treasure);
    }
}

void exploreDungeon() {
    printf("Welcome to the Dungeon Explorer!\n");
    char command[20];
    int roomIndex = 0;

    while (1) {
        printf("\nYou are in Room %d: %s\n", roomIndex + 1, dungeon[roomIndex].description);
        encounterMonsters(&dungeon[roomIndex]);

        printf("Do you want to go to the next room? (y/n): ");
        scanf(" %s", command);

        if (strcmp(command, "y") == 0) {
            roomIndex++;
            if (roomIndex >= MAX_ROOMS) {
                printf("You have explored all the rooms! Congratulations!\n");
                break;
            }
        } else {
            printf("Thanks for playing!\n");
            break;
        }
    }

    // Free allocated memory for monsters before exit
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (dungeon[i].monster) {
            free(dungeon[i].monster);
        }
    }
}