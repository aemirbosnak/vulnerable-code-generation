//GEMINI-pro DATASET v1.0 Category: Space Invaders Game Clone ; Style: secure
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
    char symbol;
} Entity;

typedef struct {
    Entity player;
    Entity *invaders;
    int num_invaders;
    int score;
    bool game_over;
} Game;

void init_game(Game *game) {
    game->player.x = WIDTH / 2;
    game->player.y = HEIGHT - 1;
    game->player.symbol = '^';

    game->num_invaders = 50;
    game->invaders = malloc(sizeof(Entity) * game->num_invaders);
    for (int i = 0; i < game->num_invaders; i++) {
        game->invaders[i].x = rand() % WIDTH;
        game->invaders[i].y = rand() % (HEIGHT / 2);
        game->invaders[i].symbol = 'O';
    }

    game->score = 0;
    game->game_over = false;
}

void draw_game(Game *game) {
    system("clear");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == game->player.x && y == game->player.y) {
                printf("%c", game->player.symbol);
            } else {
                bool found_invader = false;
                for (int i = 0; i < game->num_invaders; i++) {
                    if (x == game->invaders[i].x && y == game->invaders[i].y) {
                        printf("%c", game->invaders[i].symbol);
                        found_invader = true;
                        break;
                    }
                }
                if (!found_invader) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    printf("Score: %d\n", game->score);
}

void update_game(Game *game) {
    // Move invaders
    for (int i = 0; i < game->num_invaders; i++) {
        game->invaders[i].y++;
        if (game->invaders[i].y >= HEIGHT) {
            game->invaders[i].y = 0;
            game->invaders[i].x = rand() % WIDTH;
        }
    }

    // Check for collisions
    for (int i = 0; i < game->num_invaders; i++) {
        if (game->invaders[i].x == game->player.x && game->invaders[i].y == game->player.y) {
            game->game_over = true;
            break;
        }
    }

    // Check if player has won
    if (game->num_invaders == 0) {
        game->game_over = true;
    }
}

void handle_input(Game *game) {
    char input = getchar();
    switch (input) {
        case 'a':
            if (game->player.x > 0) {
                game->player.x--;
            }
            break;
        case 'd':
            if (game->player.x < WIDTH - 1) {
                game->player.x++;
            }
            break;
        case 'w':
            if (game->player.y > 0) {
                game->player.y--;
            }
            break;
        case 's':
            if (game->player.y < HEIGHT - 1) {
                game->player.y++;
            }
            break;
    }
}

int main() {
    srand(time(NULL));

    Game game;
    init_game(&game);

    while (!game.game_over) {
        draw_game(&game);
        update_game(&game);
        handle_input(&game);
    }

    if (game.score == game.num_invaders) {
        printf("You win!\n");
    } else {
        printf("Game over!\n");
    }

    free(game.invaders);

    return 0;
}