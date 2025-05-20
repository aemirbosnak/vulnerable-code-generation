//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 5
#define MAX_ENEMY 3

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Enemy* enemies;
} Room;

typedef struct Enemy {
    char name[20];
    int health;
    struct Enemy* next;
} Enemy;

Room* createRoom(char* name) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->enemies = NULL;
    return newRoom;
}

Enemy* createEnemy(char* name, int health) {
    Enemy* newEnemy = malloc(sizeof(Enemy));
    strcpy(newEnemy->name, name);
    newEnemy->health = health;
    newEnemy->next = NULL;
    return newEnemy;
}

void playGame() {
    // Create a list of rooms
    Room* rooms = createRoom("The Lobby");
    rooms = createRoom("The Kitchen");
    rooms = createRoom("The Bedroom");

    // Create a list of enemies
    Enemy* enemies = createEnemy("The Ghost", 100);
    enemies = createEnemy("The Skeleton", 50);
    enemies = createEnemy("The Vampire", 25);

    // Move the player through the rooms
    printf("You are in %s.\n", rooms->name);

    // Fight the enemies
    for (Enemy* enemy = enemies; enemy; enemy = enemy->next) {
        printf("You are fighting %s.\n", enemy->name);
        int battle = rand() % 2;
        if (battle == 0) {
            printf("You win!\n");
            enemy->health = 0;
        } else {
            printf("You lose!\n");
            enemy->health = 100;
        }
    }

    // End the game
    printf("You have won the game!\n");
}

int main() {
    playGame();
    return 0;
}