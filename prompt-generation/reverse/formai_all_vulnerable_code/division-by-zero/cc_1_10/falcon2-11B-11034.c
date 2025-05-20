//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pacman_pos {
    int x;
    int y;
} pacman_pos;

typedef struct ghost_pos {
    int x;
    int y;
} ghost_pos;

typedef struct food_pos {
    int x;
    int y;
} food_pos;

typedef struct game_state {
    int score;
    pacman_pos pacman;
    ghost_pos ghosts[4];
    food_pos food[4];
} game_state;

void init_game(game_state* game) {
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        game->ghosts[i].x = rand() % (int)(game->pacman.x - 2) + 2;
        game->ghosts[i].y = rand() % (int)(game->pacman.y - 2) + 2;
    }

    for (int i = 0; i < 4; i++) {
        game->food[i].x = rand() % (int)(game->pacman.x - 2) + 2;
        game->food[i].y = rand() % (int)(game->pacman.y - 2) + 2;
    }

    game->score = 0;
    game->pacman.x = rand() % (int)(game->pacman.x - 2) + 2;
    game->pacman.y = rand() % (int)(game->pacman.y - 2) + 2;
}

void print_game_state(game_state* game) {
    printf("Score: %d\n", game->score);
    printf("Pacman: (%d, %d)\n", game->pacman.x, game->pacman.y);
    printf("Ghosts:\n");
    for (int i = 0; i < 4; i++) {
        printf("(%d, %d)\n", game->ghosts[i].x, game->ghosts[i].y);
    }
    printf("Food:\n");
    for (int i = 0; i < 4; i++) {
        printf("(%d, %d)\n", game->food[i].x, game->food[i].y);
    }
}

void update_game_state(game_state* game) {
    for (int i = 0; i < 4; i++) {
        if (game->pacman.x == game->ghosts[i].x && game->pacman.y == game->ghosts[i].y) {
            game->score++;
            game->ghosts[i].x = rand() % (int)(game->pacman.x - 2) + 2;
            game->ghosts[i].y = rand() % (int)(game->pacman.y - 2) + 2;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (game->pacman.x == game->food[i].x && game->pacman.y == game->food[i].y) {
            game->food[i].x = rand() % (int)(game->pacman.x - 2) + 2;
            game->food[i].y = rand() % (int)(game->pacman.y - 2) + 2;
        }
    }
}

int main() {
    game_state game;
    init_game(&game);

    while (1) {
        print_game_state(&game);
        update_game_state(&game);
        printf("\nPress any key to continue...");
        getchar();
    }

    return 0;
}