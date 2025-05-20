//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_CREATURES 10

typedef struct Creature {
    char name[30];
    int strength;
    struct Creature *next;
} Creature;

typedef struct Player {
    char name[30];
    Creature *teamHead;
    struct Player *next;
} Player;

Player *playerList = NULL;

Player* createPlayer(char *name) {
    Player *newPlayer = (Player *)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->teamHead = NULL;
    newPlayer->next = NULL;
    return newPlayer;
}

Creature* createCreature(char *name, int strength) {
    Creature *newCreature = (Creature *)malloc(sizeof(Creature));
    strcpy(newCreature->name, name);
    newCreature->strength = strength;
    newCreature->next = NULL;
    return newCreature;
}

void addPlayer(char *name) {
    if (playerList == NULL) {
        playerList = createPlayer(name);
    } else {
        Player *current = playerList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createPlayer(name);
    }
}

void addCreatureToPlayer(char *playerName, char *creatureName, int strength) {
    Player *current = playerList;
    while (current != NULL) {
        if (strcmp(current->name, playerName) == 0) {
            Creature *newCreature = createCreature(creatureName, strength);
            newCreature->next = current->teamHead;
            current->teamHead = newCreature;
            return;
        }
        current = current->next;
    }
    printf("Player not found!\n");
}

void displayPlayerTeam(char *playerName) {
    Player *current = playerList;
    while (current != NULL) {
        if (strcmp(current->name, playerName) == 0) {
            printf("%s's Team:\n", current->name);
            Creature *creature = current->teamHead;
            while (creature != NULL) {
                printf("  Creature Name: %s, Strength: %d\n", creature->name, creature->strength);
                creature = creature->next;
            }
            return;
        }
        current = current->next;
    }
    printf("Player not found!\n");
}

void displayAllTeams() {
    Player *current = playerList;
    while (current != NULL) {
        displayPlayerTeam(current->name);
        current = current->next;
    }
}

int main() {
    char playerName[30];
    char creatureName[30];
    int strength, choice, numPlayers = 0;

    while (1) {
        printf("\n1. Add Player\n2. Add Creature to Player\n3. Display Player Team\n4. Display All Teams\n5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (numPlayers < MAX_PLAYERS) {
                    printf("Enter player name: ");
                    scanf("%s", playerName);
                    addPlayer(playerName);
                    numPlayers++;
                } else {
                    printf("Maximum players reached!\n");
                }
                break;
            case 2:
                printf("Enter player name: ");
                scanf("%s", playerName);
                printf("Enter creature name: ");
                scanf("%s", creatureName);
                printf("Enter creature strength: ");
                scanf("%d", &strength);
                addCreatureToPlayer(playerName, creatureName, strength);
                break;
            case 3:
                printf("Enter player name to display their team: ");
                scanf("%s", playerName);
                displayPlayerTeam(playerName);
                break;
            case 4:
                displayAllTeams();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}