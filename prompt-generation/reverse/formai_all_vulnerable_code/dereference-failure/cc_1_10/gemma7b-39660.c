//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10
#define MAX_ENEMY_NUM 5

typedef struct Room {
    int num;
    char name[20];
    struct Room* next;
} Room;

typedef struct Enemy {
    int num;
    char name[20];
    int health;
    struct Enemy* next;
} Enemy;

Room* createRoom(int num, char* name) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->num = num;
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    return newRoom;
}

Enemy* createEnemy(int num, char* name, int health) {
    Enemy* newEnemy = malloc(sizeof(Enemy));
    newEnemy->num = num;
    strcpy(newEnemy->name, name);
    newEnemy->health = health;
    newEnemy->next = NULL;
    return newEnemy;
}

void battle(Enemy* enemy) {
    printf("You are fighting %s.\n", enemy->name);
    int damage = rand() % 5 + 1;
    enemy->health -= damage;
    if (enemy->health <= 0) {
        printf("You have defeated %s.\n", enemy->name);
    } else {
        printf("%s has taken %d damage.\n", enemy->name, damage);
    }
}

int main() {
    // Create a list of rooms
    Room* rooms = createRoom(1, "The Entrance");
    rooms = createRoom(2, "The Hall");
    rooms = createRoom(3, "The Library");
    rooms = createRoom(4, "The Laboratory");
    rooms = createRoom(5, "The Boss's Chamber");

    // Create a list of enemies
    Enemy* enemies = createEnemy(1, "Goblin", 5);
    enemies = createEnemy(2, "skeleton", 7);
    enemies = createEnemy(3, "wizard", 10);
    enemies = createEnemy(4, "dragon", 12);
    enemies = createEnemy(5, "The Final Boss", 15);

    // Randomly choose a room and an enemy
    int roomNum = rand() % MAX_ROOM_NUM + 1;
    int enemyNum = rand() % MAX_ENEMY_NUM + 1;

    // Enter the room and fight the enemy
    printf("You have entered room %d: %s.\n", roomNum, rooms->name);
    battle(enemies->num);

    return 0;
}