//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int health;
} Player;

typedef struct {
    int width, height;
    char **tiles;
    Player *players;
    int num_players;
} Game;

void init_game(Game *game, int width, int height, int num_players) {
    srand(time(NULL));
    game->width = width;
    game->height = height;
    game->tiles = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        game->tiles[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            game->tiles[i][j] = '.';
        }
    }
    game->players = malloc(sizeof(Player) * num_players);
    game->num_players = num_players;
    for (int i = 0; i < num_players; i++) {
        game->players[i].position.x = rand() % width;
        game->players[i].position.y = rand() % height;
        game->players[i].health = 100;
    }
}

void free_game(Game *game) {
    for (int i = 0; i < game->height; i++) {
        free(game->tiles[i]);
    }
    free(game->tiles);
    free(game->players);
}

void print_game(Game *game) {
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            printf("%c", game->tiles[i][j]);
        }
        printf("\n");
    }
}

void move_player(Game *game, Player *player, int dx, int dy) {
    if (player->position.x + dx >= 0 && player->position.x + dx < game->width &&
        player->position.y + dy >= 0 && player->position.y + dy < game->height) {
        game->tiles[player->position.y][player->position.x] = '.';
        player->position.x += dx;
        player->position.y += dy;
        game->tiles[player->position.y][player->position.x] = '0' + player->health;
    }
}

void main() {
    Game game;
    init_game(&game, 32, 32, 2);
    print_game(&game);
    while (1) {
        for (int i = 0; i < game.num_players; i++) {
            int dx, dy;
            scanf(" %d %d", &dx, &dy);
            move_player(&game, &game.players[i], dx, dy);
            print_game(&game);
        }
    }
    free_game(&game);
}