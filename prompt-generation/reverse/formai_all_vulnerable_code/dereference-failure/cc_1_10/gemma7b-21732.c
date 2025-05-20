//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOM 5
#define MAX_ENEMY 3
#define MAX_ITEMS 2

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Enemy* enemies;
    struct Item* items;
} Room;

typedef struct Enemy {
    char name[20];
    int health;
    struct Enemy* next;
} Enemy;

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Room* createRoom(char* name) {
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, name);
    room->next = NULL;
    room->enemies = NULL;
    room->items = NULL;
    return room;
}

Enemy* createEnemy(char* name, int health) {
    Enemy* enemy = malloc(sizeof(Enemy));
    strcpy(enemy->name, name);
    enemy->health = health;
    enemy->next = NULL;
    return enemy;
}

Item* createItem(char* name, int quantity) {
    Item* item = malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

void playGame() {
    // Create a list of rooms
    Room* rooms = createRoom("The Grand Hall");
    rooms = createRoom("The Kitchen");
    rooms = createRoom("The Library");

    // Create a list of enemies
    Enemy* enemies = createEnemy("Goblin", 10);
    enemies = createEnemy("orc", 15);

    // Create a list of items
    Item* items = createItem("sword", 1);
    items = createItem("shield", 1);

    // Place the enemies and items in the rooms
    rooms->enemies = enemies;
    rooms->items = items;

    // Start the game
    printf("Welcome to the future, traveler!\n");
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);

    // Traverse the rooms
    for (Room* room = rooms; room; room = room->next) {
        printf("You are in %s.\n", room->name);

        // Fight the enemies
        for (Enemy* enemy = room->enemies; enemy; enemy = enemy->next) {
            printf("You encounter a %s with %d health.\n", enemy->name, enemy->health);
            printf("Enter 'attack' to fight: ");
            char command[20];
            scanf("%s", command);

            // Fight the enemy
            if (strcmp(command, "attack") == 0) {
                enemy->health -= 1;
                if (enemy->health <= 0) {
                    printf("You have slain the %s.\n", enemy->name);
                } else {
                    printf("The %s is still alive.\n", enemy->name);
                }
            } else {
                printf("Invalid command.\n");
            }
        }

        // Gather items
        for (Item* item = room->items; item; item = item->next) {
            printf("You find a %s with %d quantity.\n", item->name, item->quantity);
            printf("Enter 'take' to take the item: ");
            char command[20];
            scanf("%s", command);

            // Take the item
            if (strcmp(command, "take") == 0) {
                item->quantity--;
                if (item->quantity <= 0) {
                    printf("You have taken the last %s.\n", item->name);
                } else {
                    printf("You have taken a %s.\n", item->name);
                }
            } else {
                printf("Invalid command.\n");
            }
        }
    }

    // End the game
    printf("Thank you for playing, %s.\n", name);
}

int main() {
    playGame();
    return 0;
}