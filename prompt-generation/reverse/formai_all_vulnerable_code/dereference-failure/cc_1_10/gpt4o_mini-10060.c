//GPT-4o-mini DATASET v1.0 Category: Breakout Game Clone ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20
#define PADDLE_WIDTH 7
#define BRICK_ROWS 5
#define BRICK_COLS 9

char **create_brick_array();
void draw_bricks(char **bricks);
void destroy_bricks(char **bricks);
void draw_paddle(int paddle_pos);
void draw_ball(int ball_x, int ball_y);
void erase_ball(int ball_x, int ball_y);
void game_loop();

int main() {
    initscr();
    curs_set(FALSE);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(100);

    game_loop();

    endwin();
    return 0;
}

void game_loop() {
    int paddle_pos = (WIDTH - PADDLE_WIDTH) / 2;
    int ball_x = WIDTH / 2, ball_y = HEIGHT - 3;
    int velocity_x = 1, velocity_y = -1;
    char **bricks = create_brick_array();

    while (1) {
        clear();
        draw_bricks(bricks);
        draw_paddle(paddle_pos);
        draw_ball(ball_x, ball_y);

        int ch = getch();
        if (ch == KEY_LEFT && paddle_pos > 0) {
            paddle_pos--;
        } else if (ch == KEY_RIGHT && paddle_pos < WIDTH - PADDLE_WIDTH) {
            paddle_pos++;
        }

        if (ball_x <= 0 || ball_x >= WIDTH - 1) {
            velocity_x = -velocity_x; // Bounce off walls
        }

        if (ball_y <= 0) {
            velocity_y = -velocity_y; // Bounce off top
        } else if (ball_y >= HEIGHT - 1) {
            break; // Game over
        }

        // Ball movement
        erase_ball(ball_x, ball_y);
        ball_x += velocity_x;
        ball_y += velocity_y;

        // Paddle collision
        if (ball_y == HEIGHT - 2 && ball_x >= paddle_pos && ball_x < paddle_pos + PADDLE_WIDTH) {
            velocity_y = -velocity_y; // Bounce off paddle
        }

        // Brick collision
        for (int i = 0; i < BRICK_ROWS; i++) {
            for (int j = 0; j < BRICK_COLS; j++) {
                if (bricks[i][j] == 'X' && ball_y == i && ball_x >= j * 4 && ball_x < j * 4 + 4) {
                    bricks[i][j] = ' '; // Destroy the brick
                    velocity_y = -velocity_y; // Bounce off brick
                }
            }
        }

        refresh();
    }

    destroy_bricks(bricks);
    printw("Game Over! Press any key to exit.");
    refresh();
    getch();
}

char **create_brick_array() {
    char **bricks = malloc(BRICK_ROWS * sizeof(char *));
    for (int i = 0; i < BRICK_ROWS; i++) {
        bricks[i] = malloc(BRICK_COLS * sizeof(char));
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j] = 'X'; // Initialize all bricks
        }
    }
    return bricks;
}

void draw_bricks(char **bricks) {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j] == 'X') {
                mvaddch(i, j * 4, 'X'); // Draw brick
            }
        }
    }
}

void draw_paddle(int paddle_pos) {
    for (int i = 0; i < PADDLE_WIDTH; i++) {
        mvaddch(HEIGHT - 2, paddle_pos + i, '=');
    }
}

void draw_ball(int ball_x, int ball_y) {
    mvaddch(ball_y, ball_x, 'O');
}

void erase_ball(int ball_x, int ball_y) {
    mvaddch(ball_y, ball_x, ' ');
}

void destroy_bricks(char **bricks) {
    for (int i = 0; i < BRICK_ROWS; i++) {
        free(bricks[i]);
    }
    free(bricks);
}