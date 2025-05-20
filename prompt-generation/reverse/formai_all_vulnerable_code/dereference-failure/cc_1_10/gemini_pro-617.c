//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structs
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} player;

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} monster;

typedef struct {
    char *name;
    int room_number;
    int north;
    int south;
    int east;
    int west;
    int visited;
} room;

// prototypes
player *create_player();
monster *create_monster();
room *create_room();
void print_player(player *p);
void print_monster(monster *m);
void print_room(room *r);
void generate_dungeon();
void play_game();

// global variables
player *player_character;
room *current_room;
room *dungeon[100];

// main function
int main() {
    srand(time(NULL));
    play_game();
    return 0;
}

// functions
player *create_player() {
    player *p = malloc(sizeof(player));
    p->name = "Unnamed Player";
    p->health = 100;
    p->attack = 10;
    p->defense = 10;
    return p;
}

monster *create_monster() {
    monster *m = malloc(sizeof(monster));
    m->name = "Unnamed Monster";
    m->health = 100;
    m->attack = 10;
    m->defense = 10;
    return m;
}

room *create_room() {
    room *r = malloc(sizeof(room));
    r->name = "Unnamed Room";
    r->room_number = 0;
    r->north = -1;
    r->south = -1;
    r->east = -1;
    r->west = -1;
    r->visited = 0;
    return r;
}

void print_player(player *p) {
    printf("Player: %s\n", p->name);
    printf("Health: %d\n", p->health);
    printf("Attack: %d\n", p->attack);
    printf("Defense: %d\n", p->defense);
}

void print_monster(monster *m) {
    printf("Monster: %s\n", m->name);
    printf("Health: %d\n", m->health);
    printf("Attack: %d\n", m->attack);
    printf("Defense: %d\n", m->defense);
}

void print_room(room *r) {
    printf("Room: %s\n", r->name);
    printf("Room Number: %d\n", r->room_number);
    printf("North: %d\n", r->north);
    printf("South: %d\n", r->south);
    printf("East: %d\n", r->east);
    printf("West: %d\n", r->west);
    printf("Visited: %d\n", r->visited);
}

void generate_dungeon() {
    for (int i = 0; i < 100; i++) {
        dungeon[i] = create_room();
    }

    // set up the connections between the rooms
    for (int i = 0; i < 100; i++) {
        // north
        if (i % 10 != 0) {
            dungeon[i]->north = i - 1;
        }

        // south
        if (i % 10 != 9) {
            dungeon[i]->south = i + 1;
        }

        // east
        if (i / 10 != 9) {
            dungeon[i]->east = i + 10;
        }

        // west
        if (i / 10 != 0) {
            dungeon[i]->west = i - 10;
        }
    }
}

void play_game() {
    // create the player character
    player_character = create_player();

    // generate the dungeon
    generate_dungeon();

    // start the player in the first room
    current_room = dungeon[0];

    // game loop
    while (1) {
        // print the current room
        print_room(current_room);

        // get the player's input
        char input;
        printf("Enter a command (n, s, e, w, or q to quit): ");
        scanf(" %c", &input);

        // handle the player's input
        switch (input) {
            case 'n':
                if (current_room->north != -1) {
                    current_room = dungeon[current_room->north];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 's':
                if (current_room->south != -1) {
                    current_room = dungeon[current_room->south];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 'e':
                if (current_room->east != -1) {
                    current_room = dungeon[current_room->east];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 'w':
                if (current_room->west != -1) {
                    current_room = dungeon[current_room->west];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
}