//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef enum {
    GHOST,
    ZOMBIE,
    VAMPIRE,
    WITCH,
    WEREWOLF
} MonsterType;

typedef struct {
    MonsterType type;
    int strength;
    int fear;
} Monster;

typedef struct {
    char* description;
    Monster* monsters[MAX_MONSTERS];
    int monster_count;
} Room;

Room* createRoom(char* description) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->description = description;
    newRoom->monster_count = 0;
    return newRoom;
}

Monster* createMonster(MonsterType type) {
    Monster* newMonster = (Monster*)malloc(sizeof(Monster));
    newMonster->type = type;
    newMonster->strength = rand() % 100 + 1; // Strength between 1 and 100
    newMonster->fear = rand() % 100 + 1; // Fear between 1 and 100
    return newMonster;
}

void addMonsterToRoom(Room* room, Monster* monster) {
    if (room->monster_count < MAX_MONSTERS) {
        room->monsters[room->monster_count] = monster;
        room->monster_count++;
    } else {
        printf("Room is already full of monsters!\n");
    }
}

void printRoom(Room* room) {
    printf("You have entered: %s\n", room->description);
    if (room->monster_count > 0) {
        printf("Monsters in this room:\n");
        for (int i = 0; i < room->monster_count; i++) {
            Monster* monster = room->monsters[i];
            const char* monsterNames[] = { "Ghost", "Zombie", "Vampire", "Witch", "Werewolf" };
            printf("- %s (Strength: %d, Fear: %d)\n", monsterNames[monster->type], monster->strength, monster->fear);
        }
    } else {
        printf("This room is empty.\n");
    }
}

void simulateHaunt(Room* rooms[], int room_count) {
    for (int i = 0; i < room_count; i++) {
        sleep(2);
        printRoom(rooms[i]);
        if (rooms[i]->monster_count > 0) {
            int escapeChance = rand() % 100;
            if (escapeChance < 50) {
                printf("You managed to escape!\n");
            } else {
                printf("You were caught by a monster!\n");
                break;
            }
        }
    }
}

void freeResources(Room* rooms[], int room_count) {
    for (int i = 0; i < room_count; i++) {
        for (int j = 0; j < rooms[i]->monster_count; j++) {
            free(rooms[i]->monsters[j]);
        }
        free(rooms[i]);
    }
}

int main() {
    srand(time(NULL));

    Room* rooms[MAX_ROOMS];
    rooms[0] = createRoom("The Dark Hallway");
    rooms[1] = createRoom("The Creepy Basement");
    rooms[2] = createRoom("The Abandoned Attic");
    rooms[3] = createRoom("The Blood-Stained Kitchen");
    rooms[4] = createRoom("The Haunted Living Room");
    rooms[5] = createRoom("The Sinister Bathroom");
    rooms[6] = createRoom("The Shadowy Bedroom");
    rooms[7] = createRoom("The Ghostly Garden");
    rooms[8] = createRoom("The Sleepless Library");
    rooms[9] = createRoom("The Phantasmic Hall of Mirrors");

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rand() % 2) { // Randomly decide if this room will have monsters
            int monster_count = rand() % 6; // 0 to 5 monsters
            for (int j = 0; j < monster_count; j++) {
                MonsterType type = rand() % 5; // Randomly select a monster type
                Monster* monster = createMonster(type);
                addMonsterToRoom(rooms[i], monster);
            }
        }
    }

    printf("Welcome to the Haunted House Simulator!\n");
    simulateHaunt(rooms, MAX_ROOMS);

    freeResources(rooms, MAX_ROOMS);
    return 0;
}