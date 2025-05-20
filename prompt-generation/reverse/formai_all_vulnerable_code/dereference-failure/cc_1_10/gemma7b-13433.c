//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ENEMIES 5

typedef struct Room {
    int x, y;
    struct Room* next;
} Room;

typedef struct Enemy {
    int x, y;
    struct Enemy* next;
} Enemy;

Room* generateRooms(int numRooms) {
    Room* head = NULL;
    for (int i = 0; i < numRooms; i++) {
        Room* newRoom = malloc(sizeof(Room));
        newRoom->x = rand() % 20;
        newRoom->y = rand() % 20;
        newRoom->next = head;
        head = newRoom;
    }
    return head;
}

Enemy* generateEnemies(int numEnemies) {
    Enemy* head = NULL;
    for (int i = 0; i < numEnemies; i++) {
        Enemy* newEnemy = malloc(sizeof(Enemy));
        newEnemy->x = rand() % 20;
        newEnemy->y = rand() % 20;
        newEnemy->next = head;
        head = newEnemy;
    }
    return head;
}

void drawMap(Room* rooms, Enemy* enemies) {
    for (Room* room = rooms; room; room = room->next) {
        printf("(%d, %d) ", room->x, room->y);
    }
    printf("\n");
    for (Enemy* enemy = enemies; enemy; enemy = enemy->next) {
        printf("(%d, %d) ", enemy->x, enemy->y);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int numRooms = rand() % MAX_ROOMS;
    int numEnemies = rand() % MAX_ENEMIES;

    Room* rooms = generateRooms(numRooms);
    Enemy* enemies = generateEnemies(numEnemies);

    drawMap(rooms, enemies);

    return 0;
}