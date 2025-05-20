//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 256
#define MAX_ITEMS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int isVisited;
} Location;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int currentLocation;
    char inventory[MAX_ITEMS][MAX_NAME_LENGTH];
    int itemCount;
} Player;

void saveGame(Player *player) {
    FILE *file = fopen("savegame.txt", "w");
    if (file == NULL) {
        printf("Error saving game.\n");
        return;
    }
    fprintf(file, "%s\n%d\n%d\n", player->name, player->health, player->currentLocation);
    for (int i = 0; i < player->itemCount; i++) {
        fprintf(file, "%s\n", player->inventory[i]);
    }
    fclose(file);
    printf("Game saved!\n");
}

void loadGame(Player *player) {
    FILE *file = fopen("savegame.txt", "r");
    if (file == NULL) {
        printf("No saved game found.\n");
        return;
    }
    fscanf(file, "%s", player->name);
    fscanf(file, "%d", &player->health);
    fscanf(file, "%d", &player->currentLocation);
    player->itemCount = 0;
    char item[MAX_NAME_LENGTH];
    while (fscanf(file, "%s", item) != EOF) {
        strcpy(player->inventory[player->itemCount++], item);
    }
    fclose(file);
    printf("Game loaded! Welcome back, %s!\n", player->name);
}

void displayLocation(Location locations[], int currentLocation) {
    printf("%s\n", locations[currentLocation].name);
    printf("%s\n", locations[currentLocation].description);
    locations[currentLocation].isVisited = 1;
}

int main() {
    Player player;
    player.health = 100;
    player.currentLocation = 0;
    player.itemCount = 0;
    char command[20];

    Location locations[] = {
        {"Mysterious Clearing", "You find yourself in a clearing surrounded by tall trees. What will you do?"},
        {"Ancient Ruins", "You stand before ancient ruins, overgrown with vines. A sense of history permeates the air."},
        {"Dark Cave", "A dark, foreboding cave lays ahead. You hear water dripping in the distance."},
        {"Enchanted Grove", "The grove is filled with glowing flowers. It's a sight to behold."}
    };

    printf("Welcome to the Mysterious Forest! What's your name?\n");
    scanf("%s", player.name);
    printf("Hello, %s! You are here to explore the forest.\n", player.name);

    while (1) {
        displayLocation(locations, player.currentLocation);
        
        printf("Your command (move, save, load, exit): ");
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            printf("Where would you like to go? (0: Clearing, 1: Ruins, 2: Cave, 3: Grove): ");
            scanf("%d", &player.currentLocation);
            if (player.currentLocation < 0 || player.currentLocation > 3) {
                printf("Invalid location.\n");
                player.currentLocation = 0; // Reset to default
            }
        } else if (strcmp(command, "save") == 0) {
            saveGame(&player);
        } else if (strcmp(command, "load") == 0) {
            loadGame(&player);
        } else if (strcmp(command, "exit") == 0) {
            printf("Thank you for playing, %s! Goodbye!\n", player.name);
            break;
        } else {
            printf("Unknown command.\n");
        }
    }
    
    return 0;
}