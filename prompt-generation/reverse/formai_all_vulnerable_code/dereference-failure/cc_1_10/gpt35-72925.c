//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 20
#define MAX_RESP_LEN 40

struct Room {
    char name[MAX_NAME_LEN];
    char description[MAX_RESP_LEN];
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west; 
};

struct Item {
    char name[MAX_NAME_LEN];
    char description[MAX_RESP_LEN];
    struct Item *next;
};

struct Player {
    char name[MAX_NAME_LEN];
    struct Item *inventory;
    struct Room *location;
};

struct Response {
    char key[MAX_RESP_LEN];
    char name[MAX_RESP_LEN]; 
    struct Response *next;
};

const struct Response responses[] = {
    {"north", "go north"},
    {"south", "go south"},
    {"east", "go east"},
    {"west", "go west"},
    {"look", "look around"},
    {"inventory", "check inventory"}
};

struct Item *create_item(char *name, char *description) {
    struct Item *item = (struct Item*) malloc(sizeof(struct Item));
    strcpy(item->name, name);
    strcpy(item->description, description);
    item->next = NULL;
    return item;
}

struct Room *create_room(char *name, char *description, struct Room *north, struct Room *south, struct Room *east, struct Room *west) {
    struct Room *room = (struct Room*) malloc(sizeof(struct Room));
    strcpy(room->name, name);
    strcpy(room->description, description);
    room->north = north;
    room->south = south;
    room->east = east;
    room->west = west;
    return room;
}

struct Room *get_direction(struct Room *location, char *direction) {
    if (strcasecmp(direction, "north") == 0) {
        return location->north;
    } else if (strcasecmp(direction, "south") == 0) {
        return location->south;
    } else if (strcasecmp(direction, "east") == 0) {
        return location->east;
    } else if (strcasecmp(direction, "west") == 0) {
        return location->west;
    }
    return NULL;
}

void add_item(struct Player *player, struct Item *item) {
    if (player->inventory == NULL) {
        player->inventory = item;
    } else {
        struct Item *current_item = player->inventory;
        while (current_item->next != NULL) {
            current_item = current_item->next;
        }
        current_item->next = item;
    }
}

void remove_item(struct Player *player, struct Item *item) {
    if (player->inventory == item) {
        player->inventory = item->next;
        free(item);
    } else {
        struct Item *current_item = player->inventory;
        while (current_item->next != NULL) {
            if (current_item->next == item) {
                current_item->next = item->next;
                free(item);
                return;
            }
            current_item = current_item->next;
        }
    }
}

void print_responses() {
    printf("You can:\n");
    int i;
    for (i = 0; i < 6; i++) {
        printf("- %s\n", responses[i].name);
    }
}

void print_inventory(struct Player *player) {
    if (player->inventory == NULL) {
        printf("You don't have anything in your inventory.\n");
    } else {
        printf("You have:\n");
        struct Item *current_item = player->inventory;
        while (current_item != NULL) {
            printf("- %s: %s\n", current_item->name, current_item->description);
            current_item = current_item->next;
        }
    }
}

struct Response *get_response(char *input) {
    int i;
    for (i = 0; i < 6; i++) {
        if (strcasecmp(input, responses[i].key) == 0) {
            struct Response *res = (struct Response*) malloc(sizeof(struct Response));
            strcpy(res->key, responses[i].key);
            strcpy(res->name, responses[i].name);
            res->next = NULL;
            return res;
        }
    }
    return NULL;
}

int main() {
    // Create rooms
    struct Room *bedroom = create_room("Bedroom", "You are in your bedroom.", NULL, NULL, NULL, NULL);
    struct Room *living_room = create_room("Living Room", "You are in your living room.", NULL, NULL, NULL, NULL);
    struct Room *kitchen = create_room("Kitchen", "You are in your kitchen.", NULL, NULL, NULL, NULL);
    struct Room *bathroom = create_room("Bathroom", "You are in your bathroom.", NULL, NULL, NULL, NULL);

    // Connect rooms
    bedroom->east = living_room;
    living_room->west = bedroom;
    living_room->north = kitchen;
    kitchen->south = living_room;
    living_room->east = bathroom;
    bathroom->west = living_room;

    // Create items
    struct Item *money = create_item("Money", "Some cash that you carry around.");
    struct Item *pen = create_item("Pen", "A pen that you can use to write.");

    // Set starting location and inventory
    struct Player player;
    strcpy(player.name, "Player");
    player.inventory = money;
    player.location = bedroom;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Your starting location is the %s. %s\n", player.location->name, player.location->description);
    print_responses();

    while (1) {
        char input[MAX_RESP_LEN];
        scanf("%[^\n]%*c", input);

        struct Response *response = get_response(input);

        if (response != NULL) {
            if (strcasecmp(response->key, "north") == 0 || strcasecmp(response->key, "south") == 0 || strcasecmp(response->key, "east") == 0 || strcasecmp(response->key, "west") == 0) {
                struct Room *direction = get_direction(player.location, response->key);
                if (direction != NULL) {
                    player.location = direction;
                    printf("%s. %s\n", player.location->name, player.location->description);
                } else {
                    printf("You can't go that way.\n");
                }
            } else if (strcasecmp(response->key, "look") == 0) {
                printf("%s\n", player.location->description);
            } else if (strcasecmp(response->key, "inventory") == 0) {
                print_inventory(&player);
            }
        } else {
            printf("I don't understand what you mean.\n");
        }

        free(response);
    }

    return 0;
}