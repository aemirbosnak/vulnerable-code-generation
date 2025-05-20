//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_SIZE 10
#define MAX_MONSTER_COUNT 5

typedef struct Room {
    int x, y;
    struct Room* next;
    struct Monster* monsters;
} Room;

typedef struct Monster {
    int health;
    int damage;
    struct Monster* next;
} Monster;

Room* generate_room(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->next = NULL;
    room->monsters = NULL;

    return room;
}

Monster* generate_monster() {
    Monster* monster = malloc(sizeof(Monster));
    monster->health = rand() % MAX_MONSTER_COUNT + 1;
    monster->damage = rand() % MAX_MONSTER_COUNT + 1;
    monster->next = NULL;

    return monster;
}

void destroy_room(Room* room) {
    free(room->monsters);
    free(room);
}

void destroy_monster(Monster* monster) {
    free(monster);
}

int main() {
    int num_rooms = rand() % MAX_ROOM_SIZE + 1;
    Room* rooms = NULL;

    for (int i = 0; i < num_rooms; i++) {
        rooms = generate_room(rand() % MAX_ROOM_SIZE, rand() % MAX_ROOM_SIZE);
        rooms->monsters = generate_monster();
    }

    // Play the game

    destroy_room(rooms);
    destroy_monster(rooms->monsters);

    return 0;
}