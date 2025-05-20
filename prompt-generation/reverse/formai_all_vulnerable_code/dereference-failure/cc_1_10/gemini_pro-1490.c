//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_ITEMS 10
#define MAX_ROOMS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int attack;
    int defense;
} Character;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[80];
    Character* characters[MAX_ITEMS];
    int num_characters;
} Room;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Room* rooms[MAX_ROOMS];
    int num_rooms;
} World;

World* create_world() {
    World* world = malloc(sizeof(World));
    world->num_rooms = 0;
    return world;
}

void add_room_to_world(World* world, Room* room) {
    world->rooms[world->num_rooms++] = room;
}

Room* create_room(char* name, char* description) {
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    room->num_characters = 0;
    return room;
}

void add_character_to_room(Room* room, Character* character) {
    room->characters[room->num_characters++] = character;
}

Character* create_character(char* name, int health, int attack, int defense) {
    Character* character = malloc(sizeof(Character));
    strcpy(character->name, name);
    character->health = health;
    character->attack = attack;
    character->defense = defense;
    return character;
}

void print_world(World* world) {
    for (int i = 0; i < world->num_rooms; i++) {
        Room* room = world->rooms[i];
        printf("Room: %s\n", room->name);
        printf("Description: %s\n", room->description);
        for (int j = 0; j < room->num_characters; j++) {
            Character* character = room->characters[j];
            printf("Character: %s\n", character->name);
            printf("Health: %d\n", character->health);
            printf("Attack: %d\n", character->attack);
            printf("Defense: %d\n", character->defense);
        }
    }
}

int main() {
    srand(time(NULL));

    World* world = create_world();

    Room* room1 = create_room("Room 1", "This is the first room.");
    add_room_to_world(world, room1);

    Room* room2 = create_room("Room 2", "This is the second room.");
    add_room_to_world(world, room2);

    Character* character1 = create_character("Character 1", 100, 10, 5);
    add_character_to_room(room1, character1);

    Character* character2 = create_character("Character 2", 100, 10, 5);
    add_character_to_room(room2, character2);

    print_world(world);

    return 0;
}