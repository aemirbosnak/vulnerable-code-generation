//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_DESC_LEN 256

struct room {
    char* desc;
    int num_exits;
    int exits[MAX_ROOMS];
};

struct player {
    int room;
    char* name;
};

struct game {
    struct room rooms[MAX_ROOMS];
    struct player player;
};

void init_game(struct game* g) {
    strcpy(g->rooms[0].desc, "You are in a dark and musty room.");
    g->rooms[0].num_exits = 2;
    g->rooms[0].exits[0] = 1;
    g->rooms[0].exits[1] = 2;

    strcpy(g->rooms[1].desc, "You are in a dimly lit hallway.");
    g->rooms[1].num_exits = 3;
    g->rooms[1].exits[0] = 0;
    g->rooms[1].exits[1] = 2;
    g->rooms[1].exits[2] = 3;

    strcpy(g->rooms[2].desc, "You are in a spacious room with a large window.");
    g->rooms[2].num_exits = 4;
    g->rooms[2].exits[0] = 0;
    g->rooms[2].exits[1] = 1;
    g->rooms[2].exits[2] = 3;
    g->rooms[2].exits[3] = 4;

    strcpy(g->rooms[3].desc, "You are in a small room with a door.");
    g->rooms[3].num_exits = 3;
    g->rooms[3].exits[0] = 1;
    g->rooms[3].exits[1] = 2;
    g->rooms[3].exits[2] = 4;

    strcpy(g->rooms[4].desc, "You are in a large room with a high ceiling.");
    g->rooms[4].num_exits = 1;
    g->rooms[4].exits[0] = 2;

    g->player.room = 0;
    g->player.name = "Player";
}

void print_room_desc(struct game* g) {
    printf("%s\n", g->rooms[g->player.room].desc);
}

void print_exit_options(struct game* g) {
    int i;

    printf("You can go to the following rooms:\n");
    for (i = 0; i < g->rooms[g->player.room].num_exits; i++) {
        printf("%d) %s\n", i + 1, g->rooms[g->rooms[g->player.room].exits[i]].desc);
    }
}

int get_player_input(struct game* g) {
    int input;

    printf("> ");
    scanf("%d", &input);

    return input;
}

void process_player_input(struct game* g, int input) {
    int i;

    for (i = 0; i < g->rooms[g->player.room].num_exits; i++) {
        if (input == i + 1) {
            g->player.room = g->rooms[g->player.room].exits[i];
            return;
        }
    }

    printf("Invalid input.\n");
}

void play_game(struct game* g) {
    int input;

    while (1) {
        print_room_desc(g);
        print_exit_options(g);

        input = get_player_input(g);
        process_player_input(g, input);
    }
}

int main() {
    struct game g;

    init_game(&g);
    play_game(&g);

    return 0;
}