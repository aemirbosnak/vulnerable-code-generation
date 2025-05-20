//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

struct room {
    int x, y;
    char *description;
    struct room *north, *east, *south, *west;
};

struct player {
    int x, y;
    int health;
};

struct monster {
    int x, y;
    int health;
};

struct room *create_room(int x, int y, char *description) {
    struct room *room = malloc(sizeof(struct room));
    room->x = x;
    room->y = y;
    room->description = description;
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

void destroy_room(struct room *room) {
    free(room->description);
    free(room);
}

struct player *create_player(int x, int y) {
    struct player *player = malloc(sizeof(struct player));
    player->x = x;
    player->y = y;
    player->health = 100;
    return player;
}

void destroy_player(struct player *player) {
    free(player);
}

struct monster *create_monster(int x, int y) {
    struct monster *monster = malloc(sizeof(struct monster));
    monster->x = x;
    monster->y = y;
    monster->health = 100;
    return monster;
}

void destroy_monster(struct monster *monster) {
    free(monster);
}

void print_room(struct room *room) {
    printf("%s\n", room->description);
}

void print_player(struct player *player) {
    printf("Player is at (%d, %d) with %d health.\n", player->x, player->y, player->health);
}

void print_monster(struct monster *monster) {
    printf("Monster is at (%d, %d) with %d health.\n", monster->x, monster->y, monster->health);
}

int main() {
    srand(time(NULL));

    // Create rooms
    struct room *rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = create_room(rand() % 10, rand() % 10, "A dark and creepy room.");
    }

    // Connect rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        // North
        if (rooms[i]->y > 0) {
            rooms[i]->north = rooms[i - 1];
        }

        // East
        if (rooms[i]->x < 9) {
            rooms[i]->east = rooms[i + 1];
        }

        // South
        if (rooms[i]->y < 9) {
            rooms[i]->south = rooms[i + 10];
        }

        // West
        if (rooms[i]->x > 0) {
            rooms[i]->west = rooms[i - 1];
        }
    }

    // Create player
    struct player *player = create_player(0, 0);

    // Create monster
    struct monster *monster = create_monster(9, 9);

    // Game loop
    while (player->health > 0 && monster->health > 0) {
        // Print player and monster
        print_player(player);
        print_monster(monster);

        // Get player input
        char input;
        printf("Enter a direction (n, e, s, w): ");
        scanf(" %c", &input);

        // Move player
        switch (input) {
            case 'n':
                if (player->y > 0) {
                    player->y--;
                }
                break;
            case 'e':
                if (player->x < 9) {
                    player->x++;
                }
                break;
            case 's':
                if (player->y < 9) {
                    player->y++;
                }
                break;
            case 'w':
                if (player->x > 0) {
                    player->x--;
                }
                break;
        }

        // Check if player is in the same room as the monster
        if (player->x == monster->x && player->y == monster->y) {
            // Attack monster
            monster->health -= 10;
            printf("You attacked the monster!\n");

            // Attack player
            player->health -= 10;
            printf("The monster attacked you!\n");
        }

        // Print the room the player is in
        print_room(rooms[player->x + player->y * 10]);
    }

    // Check if player won or lost
    if (player->health <= 0) {
        printf("You died!\n");
    } else {
        printf("You win!\n");
    }

    // Clean up
    for (int i = 0; i < MAX_ROOMS; i++) {
        destroy_room(rooms[i]);
    }
    destroy_player(player);
    destroy_monster(monster);

    return 0;
}