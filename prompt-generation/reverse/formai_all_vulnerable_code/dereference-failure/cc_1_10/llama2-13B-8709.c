//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 10
#define PLAYER_COUNT 4

typedef struct {
    char name[20];
    int score;
} player_t;

typedef struct {
    player_t players[PLAYER_COUNT];
    int turn;
} game_t;

game_t *init_game(void);
void print_game_state(game_t *game);
void roll_dice(game_t *game, int dice_num);
void player_move(game_t *game, int player_idx);
void check_win(game_t *game);
void reset_game(game_t *game);

int main(void) {
    srand(time(NULL));

    game_t *game = init_game();

    while (1) {
        print_game_state(game);

        roll_dice(game, 2);

        player_move(game, 0);

        check_win(game);

        if (game->turn == PLAYER_COUNT) {
            reset_game(game);
        }
    }

    return 0;
}

game_t *init_game(void) {
    game_t *game = malloc(sizeof(game_t));

    for (int i = 0; i < PLAYER_COUNT; i++) {
        game->players[i].name[0] = '\0';
        game->players[i].score = 0;
    }

    game->turn = 0;

    return game;
}

void print_game_state(game_t *game) {
    printf("--- Game State ---\n");

    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("Player %d: %s (%d)\n", i, game->players[i].name, game->players[i].score);
    }

    printf("Turn: %d\n", game->turn);
}

void roll_dice(game_t *game, int dice_num) {
    for (int i = 0; i < dice_num; i++) {
        int dice_value = rand() % 6 + 1;
        game->players[game->turn].score += dice_value;
        printf("Player %d rolled %d\n", game->turn, dice_value);
    }
}

void player_move(game_t *game, int player_idx) {
    game->turn = player_idx;
}

void check_win(game_t *game) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (game->players[i].score == 100) {
            printf("Player %d wins!\n", i);
            return;
        }
    }
}

void reset_game(game_t *game) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        game->players[i].score = 0;
    }

    game->turn = 0;
}