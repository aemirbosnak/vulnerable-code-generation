//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct player {
    char *name;
    int health;
    int attack;
    int defense;
} player;

typedef struct monster {
    char *name;
    int health;
    int attack;
    int defense;
} monster;

typedef struct room {
    char *name;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

typedef struct item {
    char *name;
    char *description;
    int value;
} item;

void print_player(player *p) {
    printf("Name: %s\n", p->name);
    printf("Health: %d\n", p->health);
    printf("Attack: %d\n", p->attack);
    printf("Defense: %d\n", p->defense);
}

void print_monster(monster *m) {
    printf("Name: %s\n", m->name);
    printf("Health: %d\n", m->health);
    printf("Attack: %d\n", m->attack);
    printf("Defense: %d\n", m->defense);
}

void print_room(room *r) {
    printf("Name: %s\n", r->name);
    printf("Description: %s\n", r->description);
}

void print_item(item *i) {
    printf("Name: %s\n", i->name);
    printf("Description: %s\n", i->description);
    printf("Value: %d\n", i->value);
}

void create_player(player *p) {
    p->name = malloc(sizeof(char) * 20);
    strcpy(p->name, "Player");
    p->health = 100;
    p->attack = 10;
    p->defense = 10;
}

void create_monster(monster *m) {
    m->name = malloc(sizeof(char) * 20);
    strcpy(m->name, "Monster");
    m->health = 100;
    m->attack = 10;
    m->defense = 10;
}

void create_room(room *r) {
    r->name = malloc(sizeof(char) * 20);
    strcpy(r->name, "Room");
    r->description = malloc(sizeof(char) * 20);
    strcpy(r->description, "This is a room.");
    r->north = NULL;
    r->east = NULL;
    r->south = NULL;
    r->west = NULL;
}

void create_item(item *i) {
    i->name = malloc(sizeof(char) * 20);
    strcpy(i->name, "Item");
    i->description = malloc(sizeof(char) * 20);
    strcpy(i->description, "This is an item.");
    i->value = 10;
}

int main() {
    srand(time(NULL));

    player *p = malloc(sizeof(player));
    create_player(p);

    monster *m = malloc(sizeof(monster));
    create_monster(m);

    room *r = malloc(sizeof(room));
    create_room(r);

    item *i = malloc(sizeof(item));
    create_item(i);

    printf("Welcome to the game!\n");

    while (1) {
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Use item\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Attack the monster
                m->health -= p->attack - m->defense;
                printf("You attacked the monster for %d damage!\n", p->attack - m->defense);
                if (m->health <= 0) {
                    printf("You killed the monster!\n");
                    return 0;
                }
                break;
            case 2:
                // Defend against the monster's attack
                p->health -= m->attack - p->defense;
                printf("You defended against the monster's attack for %d damage!\n", m->attack - p->defense);
                if (p->health <= 0) {
                    printf("You died!\n");
                    return 0;
                }
                break;
            case 3:
                // Use an item
                if (i->value > 0) {
                    p->health += i->value;
                    printf("You used the item and gained %d health!\n", i->value);
                    i->value = 0;
                } else {
                    printf("You don't have any items to use!\n");
                }
                break;
            case 4:
                // Quit the game
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // The monster's turn
        int monster_choice = rand() % 3 + 1;
        switch (monster_choice) {
            case 1:
                // Attack the player
                p->health -= m->attack - p->defense;
                printf("The monster attacked you for %d damage!\n", m->attack - p->defense);
                if (p->health <= 0) {
                    printf("You died!\n");
                    return 0;
                }
                break;
            case 2:
                // Defend against the player's attack
                m->health -= p->attack - m->defense;
                printf("The monster defended against your attack for %d damage!\n", p->attack - m->defense);
                if (m->health <= 0) {
                    printf("You killed the monster!\n");
                    return 0;
                }
                break;
            case 3:
                // Use an item
                if (i->value > 0) {
                    m->health += i->value;
                    printf("The monster used an item and gained %d health!\n", i->value);
                    i->value = 0;
                } else {
                    printf("The monster doesn't have any items to use!\n");
                }
                break;
        }
    }

    return 0;
}