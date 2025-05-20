//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MAP_SIZE 100
#define MAX_PLAYERS 4

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct {
    int x, y;
} point;

typedef struct {
    char name[20];
    point pos;
    int health;
    int score;
} player;

typedef struct {
    char tiles[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int width, height;
} map;

typedef struct {
    player players[MAX_PLAYERS];
    int num_players;
    map *game_map;
} game;

// Function Declarations
void init_game(game *g);
void print_map(map *m);
void move_player(game *g, player *p, enum direction dir);
void check_collisions(game *g);
void update_scores(game *g);
void print_scores(game *g);
void free_game(game *g);

int main() {
    srand(time(NULL));

    game g;

    init_game(&g);

    print_map(g.game_map);

    while (1) {
        for (int i = 0; i < g.num_players; i++) {
            // Get player input
            enum direction dir;
            printf("%s's turn: ", g.players[i].name);
            scanf("%d", &dir);

            // Move player
            move_player(&g, &g.players[i], dir);

            // Check for collisions
            check_collisions(&g);

            // Update scores
            update_scores(&g);

            // Print map and scores
            print_map(g.game_map);
            print_scores(&g);
        }
    }

    free_game(&g);

    return 0;
}

void init_game(game *g) {
    // Initialize map
    g->game_map = malloc(sizeof(map));
    g->game_map->width = 10;
    g->game_map->height = 10;
    for (int i = 0; i < g->game_map->width; i++) {
        for (int j = 0; j < g->game_map->height; j++) {
            g->game_map->tiles[i][j] = '.';
        }
    }

    // Initialize players
    g->num_players = 4;
    for (int i = 0; i < g->num_players; i++) {
        sprintf(g->players[i].name, "Player %d", i + 1);
        g->players[i].pos.x = rand() % g->game_map->width;
        g->players[i].pos.y = rand() % g->game_map->height;
        g->players[i].health = 100;
        g->players[i].score = 0;
    }
}

void print_map(map *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%c", m->tiles[j][i]);
        }
        printf("\n");
    }
}

void move_player(game *g, player *p, enum direction dir) {
    switch (dir) {
    case UP:
        p->pos.y--;
        break;
    case DOWN:
        p->pos.y++;
        break;
    case LEFT:
        p->pos.x--;
        break;
    case RIGHT:
        p->pos.x++;
        break;
    }

    // Wrap around if player goes off the edge of the map
    if (p->pos.x < 0) {
        p->pos.x = g->game_map->width - 1;
    } else if (p->pos.x >= g->game_map->width) {
        p->pos.x = 0;
    }
    if (p->pos.y < 0) {
        p->pos.y = g->game_map->height - 1;
    } else if (p->pos.y >= g->game_map->height) {
        p->pos.y = 0;
    }

    // Update map
    g->game_map->tiles[p->pos.x][p->pos.y] = 'P';
}

void check_collisions(game *g) {
    for (int i = 0; i < g->num_players; i++) {
        for (int j = i + 1; j < g->num_players; j++) {
            if (g->players[i].pos.x == g->players[j].pos.x &&
                g->players[i].pos.y == g->players[j].pos.y) {
                // Collision detected!
                g->players[i].health -= 10;
                g->players[j].health -= 10;
            }
        }
    }
}

void update_scores(game *g) {
    for (int i = 0; i < g->num_players; i++) {
        g->players[i].score += 1;
    }
}

void print_scores(game *g) {
    printf("Scores:\n");
    for (int i = 0; i < g->num_players; i++) {
        printf("%s: %d\n", g->players[i].name, g->players[i].score);
    }
}

void free_game(game *g) {
    free(g->game_map);
}