//GPT-4o-mini DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_ROOMS 5
#define MAX_NAME_LENGTH 20

typedef struct Item {
    char name[MAX_NAME_LENGTH];
    struct Item *next;
} Item;

typedef struct Room {
    char description[100];
    struct Room *next;
    Item *items;
} Room;

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int health;
    Item *inventory;
} Player;

Room *create_room(const char *description) {
    Room *new_room = (Room *)malloc(sizeof(Room));
    strcpy(new_room->description, description);
    new_room->next = NULL;
    new_room->items = NULL;
    return new_room;
}

Item *create_item(const char *name) {
    Item *new_item = (Item *)malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->next = NULL;
    return new_item;
}

void add_item_to_room(Room *room, Item *item) {
    item->next = room->items;
    room->items = item;
}

void add_item_to_inventory(Player *player, Item *item) {
    item->next = player->inventory;
    player->inventory = item;
}

void print_inventory(Player *player) {
    printf("Inventory:\n");
    Item *current_item = player->inventory;
    if (!current_item) {
        printf("  (empty)\n");
    } else {
        while (current_item) {
            printf("  - %s\n", current_item->name);
            current_item = current_item->next;
        }
    }
}

void print_room_contents(Room *room) {
    printf("You find:\n");
    Item *current_item = room->items;
    if (!current_item) {
        printf("  (nothing)\n");
    } else {
        while (current_item) {
            printf("  - %s\n", current_item->name);
            current_item = current_item->next;
        }
    }
}

void enter_room(Player *player, Room *room) {
    printf("%s\n", room->description);
    print_room_contents(room);
}

void fight(Player *player) {
    int monster_health = 50;
    int damage;
    srand(time(NULL));
    
    printf("A wild monster attacks you!\n");

    while (player->health > 0 && monster_health > 0) {
        damage = rand() % 10 + 1; // Damage between 1 and 10
        monster_health -= damage;
        printf("You hit the monster for %d damage! Monster health: %d\n", damage, monster_health);
        
        if (monster_health <= 0) {
            printf("You defeated the monster!\n");
            return;
        }

        damage = rand() % 10 + 1; // Monster retaliates
        player->health -= damage;
        printf("The monster hits you for %d damage! Your health: %d\n", damage, player->health);
    }

    printf("You have been defeated by the monster...\n");
}

void input_handler(Player *player, Room *current_room) {
    char command[100];

    while (player->health > 0) {
        printf("\nEnter a command (look, take <item>, fight, inventory, quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline
        
        if (strncmp(command, "look", 4) == 0) {
            enter_room(player, current_room);
        } else if (strncmp(command, "take ", 5) == 0) {
            char item_name[MAX_NAME_LENGTH];
            sscanf(command + 5, "%s", item_name);
            Item *current_item = current_room->items;
            Item *prev_item = NULL;
            
            while (current_item) {
                if (strcmp(current_item->name, item_name) == 0) {
                    if (prev_item) {
                        prev_item->next = current_item->next;
                    } else {
                        current_room->items = current_item->next;
                    }
                    add_item_to_inventory(player, current_item);
                    printf("You took %s.\n", item_name);
                    break;
                }
                prev_item = current_item;
                current_item = current_item->next;
            }
        } else if (strcmp(command, "fight") == 0) {
            fight(player);
        } else if (strcmp(command, "inventory") == 0) {
            print_inventory(player);
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Unknown command.\n");
        }
    }
}

int main() {
    Player player = {"Hero", 100, NULL};
    Room *room1 = create_room("You are in a dark forest.");
    Room *room2 = create_room("You stand in front of a scary cave.");
    Room *room3 = create_room("You've entered a mystical clearing.");
    
    add_item_to_room(room1, create_item("stick"));
    add_item_to_room(room2, create_item("torch"));
    add_item_to_room(room3, create_item("magical stone"));

    room1->next = room2;
    room2->next = room3;

    printf("Welcome to the Adventure Game!\n");
    printf("Enter your name: ");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strcspn(player.name, "\n")] = 0; // Remove newline

    input_handler(&player, room1);

    // Clean up rooms
    free(room1);
    free(room2);
    free(room3);
    return 0;
}