//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

struct Room {
    int x, y, w, h;
};

struct Dungeon {
    struct Room *rooms;
    int num_rooms;
};

struct Player {
    int x, y;
};

void init_dungeon(struct Dungeon *dungeon) {
    dungeon->num_rooms = 0;
    dungeon->rooms = malloc(sizeof(struct Room) * 100);
}

void generate_room(struct Dungeon *dungeon, int x, int y, int w, int h) {
    struct Room *room = &dungeon->rooms[dungeon->num_rooms++];
    room->x = x;
    room->y = y;
    room->w = w;
    room->h = h;
}

void generate_dungeon(struct Dungeon *dungeon) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (rand() % 100 < 50) {
                generate_room(dungeon, i, j, 1, 1);
            }
        }
    }
}

void draw_dungeon(struct Dungeon *dungeon) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            bool found = false;
            for (int k = 0; k < dungeon->num_rooms; k++) {
                struct Room *room = &dungeon->rooms[k];
                if (i >= room->y && i < room->y + room->h &&
                    j >= room->x && j < room->x + room->w) {
                    printf(".");
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("#");
            }
        }
        printf("\n");
    }
}

void init_player(struct Player *player) {
    player->x = 0;
    player->y = 0;
}

void move_player(struct Player *player, struct Dungeon *dungeon) {
    int dx, dy;

    printf("Enter a direction (w, a, s, d): ");
    scanf("%c", &dx);

    switch (dx) {
        case 'w':
            dy = -1;
            break;
        case 'a':
            dy = 0;
            dx = -1;
            break;
        case 's':
            dy = 1;
            break;
        case 'd':
            dy = 0;
            dx = 1;
            break;
    }

    if (player->x + dx >= 0 && player->x + dx < WIDTH &&
        player->y + dy >= 0 && player->y + dy < HEIGHT) {
        player->x += dx;
        player->y += dy;
    }
}

int main() {
    srand(time(NULL));

    struct Dungeon dungeon;
    init_dungeon(&dungeon);
    generate_dungeon(&dungeon);

    struct Player player;
    init_player(&player);

    while (true) {
        draw_dungeon(&dungeon);
        move_player(&player, &dungeon);
    }

    return 0;
}