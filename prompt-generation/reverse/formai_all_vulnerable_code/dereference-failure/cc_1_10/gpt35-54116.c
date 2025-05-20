//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GHOSTS 20
#define MAX_PLAYERS 2

typedef struct Room {
    int number;
    int isHaunted;
    char* description;
    char* ghost;
    struct Room* connectingRooms[4];
} Room;

typedef struct Player {
    char* name;
    Room* currentRoom;
} Player;

typedef struct Ghost {
    char* name;
    Room* location;
} Ghost;

void createConnections(Room** rooms);
void createGhosts(Room** rooms, Ghost** ghosts);
void movePlayers(Player** players, Room** rooms);
void moveGhosts(Ghost** ghosts, Room** rooms);
void printDescription(Player* player);

int main() {
    srand(time(NULL));
    Room* rooms[MAX_ROOMS];
    Ghost* ghosts[MAX_GHOSTS];
    Player* players[MAX_PLAYERS];
    int playerCount = 0;

    // Create rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = (Room*)malloc(sizeof(Room));
        rooms[i]->number = i;
        rooms[i]->isHaunted = rand() % 2;
        rooms[i]->description = (char*)malloc(sizeof(char) * 50);
        sprintf(rooms[i]->description, "You are in room %d", i);

        // Set random connecting rooms
        for (int j = 0; j < 4; j++) {
            rooms[i]->connectingRooms[j] = rooms[rand() % MAX_ROOMS];
        }
    }

    // Create ghosts
    createGhosts(rooms, ghosts);

    // Add players
    players[playerCount] = (Player*)malloc(sizeof(Player));
    players[playerCount]->name = "Player 1";
    players[playerCount]->currentRoom = rooms[rand() % MAX_ROOMS];
    playerCount++;

    // Game loop
    while (1) {
        // Move players
        movePlayers(players, rooms);

        // Move ghosts
        moveGhosts(ghosts, rooms);

        // Print room description
        for (int i = 0; i < playerCount; i++) {
            printf("\n%s:\n", players[i]->name);
            printDescription(players[i]);
        }

        // Check for ghosts in room
        for (int i = 0; i < playerCount; i++) {
            for (int j = 0; j < MAX_GHOSTS; j++) {
                if (ghosts[j]->location == players[i]->currentRoom) {
                    printf("\n%s:\n", ghosts[j]->name);
                    printf("Boo!\n");
                }
            }
        }
    }

    return 0;
}

void createConnections(Room** rooms) {
    // Set connecting rooms for each room
}

void createGhosts(Room** rooms, Ghost** ghosts) {
    // Create ghosts
}

void movePlayers(Player** players, Room** rooms) {
    // Move players
}

void moveGhosts(Ghost** ghosts, Room** rooms) {
    // Move ghosts
}

void printDescription(Player* player) {
    printf("%s\n", player->currentRoom->description);
    printf("Connecting rooms:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d: Room %d\n", i, player->currentRoom->connectingRooms[i]->number);
    }
}