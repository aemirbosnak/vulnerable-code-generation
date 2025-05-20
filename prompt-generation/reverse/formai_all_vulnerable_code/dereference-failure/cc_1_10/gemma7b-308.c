//Gemma-7B DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 7

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

typedef struct Game {
    Player* head;
    int current_player;
    int game_over;
    int board[BOARD_SIZE];
} Game;

void initialize_game(Game* game) {
    game->head = NULL;
    game->current_player = 0;
    game->game_over = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[i] = 0;
    }
}

void add_player(Game* game, char* name) {
    Player* new_player = malloc(sizeof(Player));
    strcpy(new_player->name, name);
    new_player->score = 0;
    new_player->next = NULL;

    if (game->head == NULL) {
        game->head = new_player;
    } else {
        game->head->next = new_player;
        game->head = new_player;
    }
}

void make_move(Game* game, int move) {
    if (game->board[move] == 0 && game->game_over == 0) {
        game->board[move] = game->current_player;
        game->current_player = (game->current_player + 1) % MAX_PLAYERS;
    }
}

void check_game_over(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i] == game->board[i+1] && game->board[i] != 0) {
            game->game_over = 1;
            break;
        }
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (game->head->score == BOARD_SIZE - 1) {
            game->game_over = 1;
            break;
        }
    }
}

int main() {
    Game* game = malloc(sizeof(Game));
    initialize_game(game);

    add_player(game, "John");
    add_player(game, "Mary");
    add_player(game, "Bob");
    add_player(game, "Alice");

    make_move(game, 0);
    make_move(game, 2);
    make_move(game, 4);
    make_move(game, 6);

    check_game_over(game);

    if (game->game_over) {
        printf("Game Over!");
    } else {
        printf("Next move:");
    }

    return 0;
}