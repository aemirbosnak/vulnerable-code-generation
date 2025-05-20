//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

enum { FALSE, TRUE };

typedef struct {
    int id;
    int size;
    int *towers;
} tower_t;

typedef struct {
    tower_t *towers;
    int num_towers;
} game_t;

game_t *create_game(int num_towers) {
    game_t *game = malloc(sizeof(game_t));
    game->num_towers = num_towers;
    game->towers = malloc(sizeof(tower_t) * num_towers);
    for (int i = 0; i < num_towers; i++) {
        game->towers[i].id = i;
        game->towers[i].size = 0;
        game->towers[i].towers = NULL;
    }
    return game;
}

void destroy_game(game_t *game) {
    for (int i = 0; i < game->num_towers; i++) {
        free(game->towers[i].towers);
    }
    free(game->towers);
    free(game);
}

int add_tower(game_t *game, int tower, int size) {
    if (tower < 0 || tower >= game->num_towers) {
        return FALSE;
    }
    if (game->towers[tower].size >= size) {
        return FALSE;
    }
    game->towers[tower].towers = realloc(game->towers[tower].towers, sizeof(int) * size);
    game->towers[tower].size = size;
    return TRUE;
}

int remove_tower(game_t *game, int tower) {
    if (tower < 0 || tower >= game->num_towers) {
        return FALSE;
    }
    if (game->towers[tower].size == 0) {
        return FALSE;
    }
    game->towers[tower].size--;
    return TRUE;
}

int move_tower(game_t *game, int from, int to) {
    if (from < 0 || from >= game->num_towers) {
        return FALSE;
    }
    if (to < 0 || to >= game->num_towers) {
        return FALSE;
    }
    if (game->towers[from].size == 0) {
        return FALSE;
    }
    if (game->towers[to].size > 0 && game->towers[from].towers[game->towers[from].size - 1] > game->towers[to].towers[game->towers[to].size - 1]) {
        return FALSE;
    }
    game->towers[to].towers = realloc(game->towers[to].towers, sizeof(int) * (game->towers[to].size + 1));
    game->towers[to].towers[game->towers[to].size] = game->towers[from].towers[game->towers[from].size - 1];
    game->towers[to].size++;
    game->towers[from].size--;
    return TRUE;
}

int is_solved(game_t *game) {
    for (int i = 0; i < game->num_towers - 1; i++) {
        if (game->towers[i].size > 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void print_game(game_t *game) {
    for (int i = 0; i < game->num_towers; i++) {
        for (int j = 0; j < game->towers[i].size; j++) {
            printf("%d ", game->towers[i].towers[j]);
        }
        printf("\n");
    }
}

int main() {
    game_t *game = create_game(3);
    add_tower(game, 0, 3);
    add_tower(game, 1, 0);
    add_tower(game, 2, 0);
    while (!is_solved(game)) {
        for (int i = 0; i < game->num_towers; i++) {
            for (int j = 0; j < game->num_towers; j++) {
                if (i != j) {
                    move_tower(game, i, j);
                }
            }
        }
    }
    print_game(game);
    destroy_game(game);
    return 0;
}