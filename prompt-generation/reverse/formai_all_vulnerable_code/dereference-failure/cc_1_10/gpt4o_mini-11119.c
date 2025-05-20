//GPT-4o-mini DATASET v1.0 Category: Pac-Man Game Clone ; Style: scientific
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define GHOST_COUNT 1
#define DOTS_COUNT 10

typedef struct {
    int x, y;
} Entity;

typedef struct {
    Entity* ghosts;
    Entity player;
    int score;
    char map[HEIGHT][WIDTH];
} Game;

void initialize_game(Game* game) {
    game->score = 0;
    game->player.x = 1;
    game->player.y = 1;

    // Initialize ghosts
    game->ghosts = (Entity*)malloc(GHOST_COUNT * sizeof(Entity));
    game->ghosts[0].x = WIDTH - 2;
    game->ghosts[0].y = HEIGHT - 2;

    // Initialize map
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            if (r == 0 || r == HEIGHT - 1 || c == 0 || c == WIDTH - 1) {
                game->map[r][c] = '#'; // walls
            } else {
                game->map[r][c] = '.'; // dots
            }
        }
    }
}

void draw_game(Game* game) {
    clear();
    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++) {
            if (r == game->player.y && c == game->player.x) {
                printw("P"); // Player
            } else if (r == game->ghosts[0].y && c == game->ghosts[0].x) {
                printw("G"); // Ghost
            } else {
                printw("%c", game->map[r][c]); // Game map
            }
        }
        printw("\n");
    }
    printw("Score: %d\n", game->score);
    refresh();
}

void move_player(Game* game, int dx, int dy) {
    int new_x = game->player.x + dx;
    int new_y = game->player.y + dy;

    if (game->map[new_y][new_x] != '#') {
        if (game->map[new_y][new_x] == '.') {
            game->score++;
            game->map[new_y][new_x] = ' '; // Remove the dot
        }
        game->player.x = new_x;
        game->player.y = new_y;
    }
}

void move_ghost(Game* game) {
    int direction = rand() % 4;
    int dx = 0, dy = 0;

    switch (direction) {
        case 0: dx = 1; break; // Move right
        case 1: dx = -1; break; // Move left
        case 2: dy = 1; break; // Move down
        case 3: dy = -1; break; // Move up
    }

    int new_x = game->ghosts[0].x + dx;
    int new_y = game->ghosts[0].y + dy;

    if (game->map[new_y][new_x] != '#') {
        game->ghosts[0].x = new_x;
        game->ghosts[0].y = new_y;
    }
}

int main() {
    Game game;
    initialize_game(&game);
    
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    srand(time(NULL));

    while (1) {
        move_ghost(&game);
        draw_game(&game);

        int ch = getch();
        switch (ch) {
            case KEY_UP: move_player(&game, 0, -1); break;
            case KEY_DOWN: move_player(&game, 0, 1); break;
            case KEY_LEFT: move_player(&game, -1, 0); break;
            case KEY_RIGHT: move_player(&game, 1, 0); break;
            case 27: // Escape key
                goto end_game;
        }
    }

end_game:
    free(game.ghosts);
    endwin();
    return 0;
}