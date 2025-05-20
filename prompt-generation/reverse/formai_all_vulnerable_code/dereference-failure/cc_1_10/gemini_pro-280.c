//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N_TOWERS 3

typedef struct {
    char* name;
    int num_discs;
    int* discs;
} Tower;

typedef struct {
    Tower towers[N_TOWERS];
    int num_moves;
} Game;

void print_game(Game* game) {
    for (int i = 0; i < N_TOWERS; i++) {
        printf("%s: ", game->towers[i].name);
        for (int j = 0; j < game->towers[i].num_discs; j++) {
            printf("%d ", game->towers[i].discs[j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid_move(Game* game, int from_tower, int to_tower) {
    if (from_tower == to_tower) {
        return false;
    }
    if (game->towers[from_tower].num_discs == 0) {
        return false;
    }
    if (game->towers[to_tower].num_discs > 0 && game->towers[from_tower].discs[game->towers[from_tower].num_discs - 1] > game->towers[to_tower].discs[game->towers[to_tower].num_discs - 1]) {
        return false;
    }
    return true;
}

void move_disc(Game* game, int from_tower, int to_tower) {
    if (!is_valid_move(game, from_tower, to_tower)) {
        return;
    }
    int disc = game->towers[from_tower].discs[game->towers[from_tower].num_discs - 1];
    game->towers[from_tower].num_discs--;
    game->towers[to_tower].num_discs++;
    game->towers[to_tower].discs[game->towers[to_tower].num_discs - 1] = disc;
    game->num_moves++;
}

bool is_solved(Game* game) {
    return game->towers[2].num_discs == game->towers[0].num_discs;
}

void solve_tower_of_hanoi(Game* game) {
    if (is_solved(game)) {
        return;
    }
    int from_tower = 0;
    int to_tower = 1;
    int aux_tower = 2;
    while (!is_solved(game)) {
        if (is_valid_move(game, from_tower, to_tower)) {
            move_disc(game, from_tower, to_tower);
        } else if (is_valid_move(game, from_tower, aux_tower)) {
            move_disc(game, from_tower, aux_tower);
        } else if (is_valid_move(game, aux_tower, to_tower)) {
            move_disc(game, aux_tower, to_tower);
        }
        if (from_tower == 0) {
            from_tower = 1;
            to_tower = 2;
            aux_tower = 0;
        } else if (from_tower == 1) {
            from_tower = 2;
            to_tower = 0;
            aux_tower = 1;
        } else if (from_tower == 2) {
            from_tower = 0;
            to_tower = 1;
            aux_tower = 2;
        }
    }
}

int main() {
    Game game;
    game.towers[0].name = "A";
    game.towers[0].num_discs = 3;
    game.towers[0].discs = malloc(sizeof(int) * game.towers[0].num_discs);
    for (int i = 0; i < game.towers[0].num_discs; i++) {
        game.towers[0].discs[i] = i + 1;
    }
    game.towers[1].name = "B";
    game.towers[1].num_discs = 0;
    game.towers[1].discs = malloc(sizeof(int) * game.towers[1].num_discs);
    game.towers[2].name = "C";
    game.towers[2].num_discs = 0;
    game.towers[2].discs = malloc(sizeof(int) * game.towers[2].num_discs);
    game.num_moves = 0;

    print_game(&game);
    solve_tower_of_hanoi(&game);
    print_game(&game);
    printf("Number of moves: %d\n", game.num_moves);
    return 0;
}