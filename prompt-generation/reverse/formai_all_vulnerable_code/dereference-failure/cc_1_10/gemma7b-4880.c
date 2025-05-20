//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complete
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

void generate_map(Room* head) {
    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < MAX_ROOMS; i++) {
        Room* new_room = malloc(sizeof(Room));
        new_room->x = rand() % 10 + 1;
        new_room->y = rand() % 10 + 1;
        new_room->next = head;
        head = new_room;
    }
}

void place_enemies(Enemy* head) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        Enemy* new_enemy = malloc(sizeof(Enemy));
        new_enemy->x = rand() % 10 + 1;
        new_enemy->y = rand() % 10 + 1;
        new_enemy->next = head;
        head = new_enemy;
    }
}

int main() {
    Room* head = NULL;
    generate_map(head);

    Enemy* enemy_head = NULL;
    place_enemies(enemy_head);

    // Game loop here
    return 0;
}