//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for the room
typedef struct Room {
    char name[20];
    int size;
} Room;

// Structure for the player
typedef struct Player {
    char name[20];
    int health;
} Player;

// Structure for the enemy
typedef struct Enemy {
    char name[20];
    int health;
} Enemy;

// Function to create a room
Room* createRoom(char* name, int size) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->size = size;
    return newRoom;
}

// Function to create a player
Player* createPlayer(char* name, int health) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->health = health;
    return newPlayer;
}

// Function to create an enemy
Enemy* createEnemy(char* name, int health) {
    Enemy* newEnemy = malloc(sizeof(Enemy));
    strcpy(newEnemy->name, name);
    newEnemy->health = health;
    return newEnemy;
}

// Function to print the room
void printRoom(Room* room) {
    printf("Room: %s, Size: %d\n", room->name, room->size);
}

// Function to print the player
void printPlayer(Player* player) {
    printf("Player: %s, Health: %d\n", player->name, player->health);
}

// Function to print the enemy
void printEnemy(Enemy* enemy) {
    printf("Enemy: %s, Health: %d\n", enemy->name, enemy->health);
}

// Function to attack the enemy
void attackEnemy(Enemy* enemy) {
    printf("You attacked the %s with a %s attack!\n", enemy->name, "generic");
    enemy->health -= 10;
    printf("The %s now has %d health remaining.\n", enemy->name, enemy->health);
}

// Function to move the player
void movePlayer(Player* player, Room* room) {
    printf("You are in the %s room.\n", room->name);
    printf("What do you want to do?\n");
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go forward\n");
    printf("4. Go back\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("You went left and found a secret door!\n");
            break;
        case 2:
            printf("You went right and found a trap!\n");
            break;
        case 3:
            printf("You went forward and found a monster!\n");
            attackEnemy(createEnemy("Monster", 100));
            break;
        case 4:
            printf("You went back and found a chest!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

// Function to move the enemy
void moveEnemy(Enemy* enemy, Room* room) {
    int randomMove = rand() % 4;
    switch (randomMove) {
        case 1:
            printf("The %s moved left!\n", enemy->name);
            break;
        case 2:
            printf("The %s moved right!\n", enemy->name);
            break;
        case 3:
            printf("The %s moved forward!\n", enemy->name);
            break;
        case 4:
            printf("The %s moved back!\n", enemy->name);
            break;
    }
}

// Main function
int main() {
    // Create rooms
    Room* room1 = createRoom("Bedroom", 100);
    Room* room2 = createRoom("Bathroom", 50);
    Room* room3 = createRoom("Living Room", 200);
    Room* room4 = createRoom("Kitchen", 150);

    // Create player
    Player* player = createPlayer("John", 100);

    // Create enemy
    Enemy* enemy = createEnemy("Monster", 100);

    // Set initial positions
    printf("You are in the %s room.\n", room1->name);
    printf("There is a door leading to the %s room.\n", room2->name);
    printf("There is a door leading to the %s room.\n", room3->name);
    printf("There is a door leading to the %s room.\n", room4->name);
    printf("There is an enemy in the room!\n");

    // Set initial health
    enemy->health = 100;

    // Game loop
    while (player->health > 0 && enemy->health > 0) {
        // Move player
        movePlayer(player, room1);

        // Move enemy
        moveEnemy(enemy, room1);

        // Print current positions
        printPlayer(player);
        printEnemy(enemy);
    }

    // End game
    if (player->health <= 0) {
        printf("You died!\n");
    } else if (enemy->health <= 0) {
        printf("You defeated the monster!\n");
    }

    // Cleanup
    free(room1);
    free(room2);
    free(room3);
    free(room4);
    free(player);
    free(enemy);

    return 0;
}