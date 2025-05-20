//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ITEM_LEN 20
#define MAX_BUFFER_LEN 100

typedef struct Player {
    char name[MAX_NAME_LEN];
    int health;
    char items[5][MAX_ITEM_LEN];
    int itemCount;
} Player;

typedef struct Location {
    char description[MAX_BUFFER_LEN];
    struct Location *next;
} Location;

void initializePlayer(Player *player) {
    printf("Enter your character's name: ");
    fgets(player->name, MAX_NAME_LEN, stdin);
    strtok(player->name, "\n"); // Remove trailing newline
    player->health = 100;
    player->itemCount = 0;
}

void initLocation(Location *location, const char *description) {
    strncpy(location->description, description, MAX_BUFFER_LEN);
    location->next = NULL;
}

void addLocation(Location **head, const char *description) {
    Location *newLocation = (Location *) malloc(sizeof(Location));
    initLocation(newLocation, description);
    newLocation->next = *head;
    *head = newLocation;
}

void displayCurrentLocation(Location *location) {
    printf("%s\n", location->description);
}

void pickUpItem(Player *player, const char *item) {
    if (player->itemCount < 5) {
        strncpy(player->items[player->itemCount], item, MAX_ITEM_LEN);
        player->itemCount++;
        printf("You picked up a %s.\n", item);
    } else {
        printf("You cannot carry more items.\n");
    }
}

void showInventory(Player *player) {
    printf("Your inventory:\n");
    for (int i = 0; i < player->itemCount; i++) {
        printf(" - %s\n", player->items[i]);
    }
    if (player->itemCount == 0) {
        printf(" - (empty)\n");
    }
}

int main() {
    Player player;
    Location *currentLocation = NULL;
    char command[MAX_BUFFER_LEN];

    initializePlayer(&player);

    addLocation(&currentLocation, "You are in a dark room. There's a door to the north.");
    addLocation(&currentLocation, "You are outside. It's a sunny day. You can see the forest in the east.");
    addLocation(&currentLocation, "You are in a dense forest. There's a stream nearby and you can hear birds.");
    
    Location *locationPointer = currentLocation;

    while (1) {
        displayCurrentLocation(locationPointer);

        printf("What do you want to do? (pickup [item], inventory, next, quit): ");
        fgets(command, MAX_BUFFER_LEN, stdin);
        strtok(command, "\n"); // Remove trailing newline
        
        if (strncmp(command, "pickup ", 7) == 0) {
            char item[MAX_ITEM_LEN];
            sscanf(command + 7, "%s", item);
            pickUpItem(&player, item);
        } else if (strcmp(command, "inventory") == 0) {
            showInventory(&player);
        } else if (strcmp(command, "next") == 0) {
            if (locationPointer->next != NULL) {
                locationPointer = locationPointer->next;
            } else {
                printf("You have reached the end of the locations.\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("Thank you for playing, %s!\n", player.name);
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Clean up the allocated locations
    while (currentLocation != NULL) {
        Location *temp = currentLocation;
        currentLocation = currentLocation->next;
        free(temp);
    }

    return 0;
}