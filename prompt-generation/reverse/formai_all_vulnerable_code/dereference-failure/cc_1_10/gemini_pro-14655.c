//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

enum {
    WALL,
    SPACE
};

struct game {
    int width;
    int height;
    int **map;
};

struct player {
    int x;
    int y;
};

struct game *create_game(int width, int height) {
    struct game *g = malloc(sizeof(struct game));
    g->width = width;
    g->height = height;
    g->map = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        g->map[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            g->map[i][j] = SPACE;
        }
    }
    return g;
}

void destroy_game(struct game *g) {
    for (int i = 0; i < g->height; i++) {
        free(g->map[i]);
    }
    free(g->map);
    free(g);
}

struct player *create_player(struct game *g) {
    struct player *p = malloc(sizeof(struct player));
    p->x = g->width / 2;
    p->y = g->height / 2;
    return p;
}

void destroy_player(struct player *p) {
    free(p);
}

void generate_maze(struct game *g) {
    srand(time(NULL));
    for (int i = 0; i < g->height; i++) {
        for (int j = 0; j < g->width; j++) {
            if (i == 0 || j == 0 || i == g->height - 1 || j == g->width - 1) {
                g->map[i][j] = WALL;
            } else if (rand() % 2 == 1) {
                g->map[i][j] = WALL;
            }
        }
    }
}

void draw_game(struct game *g, struct player *p) {
    for (int i = 0; i < g->height; i++) {
        for (int j = 0; j < g->width; j++) {
            if (g->map[i][j] == WALL) {
                printf("#");
            } else if (i == p->y && j == p->x) {
                printf("@");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void move_player(struct game *g, struct player *p, int dx, int dy) {
    int x = p->x + dx;
    int y = p->y + dy;
    if (x >= 0 && x < g->width && y >= 0 && y < g->height && g->map[y][x] != WALL) {
        p->x = x;
        p->y = y;
    }
}

int main() {
    struct game *g = create_game(WIDTH, HEIGHT);
    generate_maze(g);
    struct player *p = create_player(g);
    draw_game(g, p);
    while (1) {
        int ch = getchar();
        switch (ch) {
            case 'w':
                move_player(g, p, 0, -1);
                break;
            case 's':
                move_player(g, p, 0, 1);
                break;
            case 'a':
                move_player(g, p, -1, 0);
                break;
            case 'd':
                move_player(g, p, 1, 0);
                break;
            case 'q':
                destroy_player(p);
                destroy_game(g);
                return 0;
        }
        draw_game(g, p);
    }
    return 0;
}