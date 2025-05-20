//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ENEMIES 5

typedef struct Room {
    int x, y;
    struct Room* next;
    struct Enemy* enemies;
} Room;

typedef struct Enemy {
    int type;
    int health;
    struct Enemy* next;
} Enemy;

Room* generate_room(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->next = NULL;
    room->enemies = NULL;
    return room;
}

Enemy* generate_enemy(int type, int health) {
    Enemy* enemy = malloc(sizeof(Enemy));
    enemy->type = type;
    enemy->health = health;
    enemy->next = NULL;
    return enemy;
}

void traverse_room(Room* room) {
    for (Enemy* enemy = room->enemies; enemy; enemy = enemy->next) {
        printf("Enemy: %d, Health: %d\n", enemy->type, enemy->health);
    }
}

int main() {
    int seed = time(NULL);
    srand(seed);

    Room* rooms = NULL;
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms = generate_room(rand() % 10, rand() % 10);
    }

    traverse_room(rooms);

    return 0;
}