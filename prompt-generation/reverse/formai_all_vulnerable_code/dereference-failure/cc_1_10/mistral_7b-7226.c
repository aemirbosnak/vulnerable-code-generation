//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define MONSTERS 3
#define MAX_MONSTER 2

typedef struct Room {
    int id;
    int isHaunted;
    int monsters[MAX_MONSTER];
} Room;

typedef struct Monster {
    int id;
    char name[20];
    int health;
} Monster;

void createRooms(Room rooms[]) {
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].id = i + 1;
        rooms[i].isHaunted = rand() % 2;
        for (int j = 0; j < MAX_MONSTER; j++) {
            rooms[i].monsters[j] = -1;
        }
    }
}

void spawnMonsters(Room rooms[]) {
    srand(time(NULL));
    for (int i = 0; i < MONSTERS; i++) {
        int roomId = rand() % ROOMS;
        if (rooms[roomId].isHaunted) {
            for (int j = 0; j < MAX_MONSTER; j++) {
                if (rooms[roomId].monsters[j] == -1) {
                    Monster monster;
                    strcpy(monster.name, ("Monster " + (char)(i + 'A')));
                    monster.health = rand() % 10 + 5;
                    rooms[roomId].monsters[j] = i;
                    printf("Monster %s spawned in room %d.\n", monster.name, roomId);
                    break;
                }
            }
        }
    }
}

void exploreRoom(Room room) {
    if (room.isHaunted) {
        int monsterIndex;
        for (int i = 0; i < MAX_MONSTER; i++) {
            if (room.monsters[i] != -1) {
                Monster monster = { .id = room.monsters[i], .health = room.monsters[i] };
                printf("Encountered %s in room %d. Health: %d.\n", monster.name, room.id, monster.health);
                room.monsters[i] = -1;
                break;
            }
        }
    } else {
        printf("Room %d is not haunted.\n", room.id);
    }
}

int main() {
    Room rooms[ROOMS];
    createRooms(rooms);
    spawnMonsters(rooms);
    int currentRoom = 1;
    while (1) {
        exploreRoom(rooms[currentRoom]);
        int newRoom = rand() % (ROOMS - 1) + 1;
        if (newRoom != currentRoom) {
            currentRoom = newRoom;
            printf("Moved to room %d.\n", currentRoom);
        }
    }
    return 0;
}