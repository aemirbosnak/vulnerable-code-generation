//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 5

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    char *name;
    position position;
} player;

typedef struct {
    player *players;
    int num_players;
    int current_player;
} game;

void print_board(game *g) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (g->players[g->current_player].position.x == i && g->players[g->current_player].position.y == j) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void move_player(game *g, int dx, int dy) {
    g->players[g->current_player].position.x += dx;
    g->players[g->current_player].position.y += dy;

    if (g->players[g->current_player].position.x < 0) {
        g->players[g->current_player].position.x = 0;
    } else if (g->players[g->current_player].position.x >= BOARD_SIZE) {
        g->players[g->current_player].position.x = BOARD_SIZE - 1;
    }

    if (g->players[g->current_player].position.y < 0) {
        g->players[g->current_player].position.y = 0;
    } else if (g->players[g->current_player].position.y >= BOARD_SIZE) {
        g->players[g->current_player].position.y = BOARD_SIZE - 1;
    }
}

int main() {
    game g;

    g.num_players = 2;
    g.players = malloc(sizeof(player) * g.num_players);

    g.players[0].name = "Player 1";
    g.players[0].position.x = 0;
    g.players[0].position.y = 0;

    g.players[1].name = "Player 2";
    g.players[1].position.x = BOARD_SIZE - 1;
    g.players[1].position.y = BOARD_SIZE - 1;

    g.current_player = 0;

    while (1) {
        print_board(&g);

        printf("%s's turn\n", g.players[g.current_player].name);

        char input[10];
        scanf("%s", input);

        if (strcmp(input, "w") == 0) {
            move_player(&g, 0, -1);
        } else if (strcmp(input, "a") == 0) {
            move_player(&g, -1, 0);
        } else if (strcmp(input, "s") == 0) {
            move_player(&g, 0, 1);
        } else if (strcmp(input, "d") == 0) {
            move_player(&g, 1, 0);
        }

        g.current_player = (g.current_player + 1) % g.num_players;
    }

    return 0;
}