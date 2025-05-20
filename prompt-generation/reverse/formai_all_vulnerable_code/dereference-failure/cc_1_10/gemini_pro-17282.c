//GEMINI-pro DATASET v1.0 Category: Breakout Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 25
#define PADDLE_WIDTH   5
#define BALL_SIZE       1
#define BRICK_WIDTH     5
#define BRICK_HEIGHT    2

struct term {
    int fd;
    struct termios orig;
};
struct ball {
    int x, y;
    int dx, dy;
};
struct paddle {
    int x, y;
};
struct brick {
    int x, y;
    int w, h;
};

struct term *term;
struct ball *ball;
struct paddle *paddle;
struct brick *bricks;
int bricks_left;

void die(const char *msg)
{
    perror(msg);
    tcsetattr(term->fd, TCSANOW, &term->orig);
    exit(EXIT_FAILURE);
}

void init_term()
{
    term = malloc(sizeof(struct term));
    term->fd = STDIN_FILENO;

    if (tcgetattr(term->fd, &term->orig))
        die("tcgetattr");

    struct termios termios = term->orig;
    termios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP
                       | IXON);
    termios.c_oflag &= ~OPOST;
    termios.c_lflag &= ~(ECHO | ICANON | ISIG | TOSTOP);
    termios.c_cc[VMIN] = 1;
    termios.c_cc[VTIME] = 0;

    if (tcsetattr(term->fd, TCSANOW, &termios))
        die("tcsetattr");
}

void reset_ball()
{
    ball->x = SCREEN_WIDTH / 2;
    ball->y = SCREEN_HEIGHT - 1;
    ball->dx = 1;
    ball->dy = -1;
}

void init_game()
{
    ball = malloc(sizeof(struct ball));
    paddle = malloc(sizeof(struct paddle));
    bricks = malloc(sizeof(struct brick) * (SCREEN_WIDTH / BRICK_WIDTH));
    bricks_left = SCREEN_WIDTH / BRICK_WIDTH;

    paddle->x = SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2;
    paddle->y = SCREEN_HEIGHT - 1;

    for (int i = 0; i < SCREEN_WIDTH / BRICK_WIDTH; i++) {
        bricks[i].x = i * BRICK_WIDTH;
        bricks[i].y = 3;
        bricks[i].w = BRICK_WIDTH;
        bricks[i].h = BRICK_HEIGHT;
    }

    reset_ball();
}

void draw_screen()
{
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            char c = ' ';
            if (y == 0 || y == SCREEN_HEIGHT - 1)
                c = '=';
            else if (x == 0 || x == SCREEN_WIDTH - 1)
                c = '|';
            else if (paddle->x <= x && x <= paddle->x + PADDLE_WIDTH
                     && paddle->y == y)
                c = '=';
            else if (ball->x == x && ball->y == y)
                c = 'o';
            else if (bricks_left > 0) {
                for (int i = 0; i < SCREEN_WIDTH / BRICK_WIDTH; i++) {
                    if (bricks[i].x <= x && x <= bricks[i].x + BRICK_WIDTH
                     && bricks[i].y <= y && y <= bricks[i].y + BRICK_HEIGHT)
                        c = '*';
                }
            }

            putchar(c);
        }
        putchar('\n');
    }
    fflush(stdout);
}

void move_ball()
{
    ball->x += ball->dx;
    ball->y += ball->dy;

    if (ball->x < 0 || ball->x >= SCREEN_WIDTH)
        ball->dx = -ball->dx;
    if (ball->y < 0 || ball->y >= SCREEN_HEIGHT)
        ball->dy = -ball->dy;

    if (ball->x >= paddle->x && ball->x <= paddle->x + PADDLE_WIDTH
     && ball->y == paddle->y - 1)
        ball->dy = -ball->dy;

    for (int i = 0; i < SCREEN_WIDTH / BRICK_WIDTH; i++) {
        if (ball->x >= bricks[i].x && ball->x <= bricks[i].x + BRICK_WIDTH
         && ball->y >= bricks[i].y && ball->y <= bricks[i].y + BRICK_HEIGHT) {
            ball->dy = -ball->dy;
            bricks_left--;
            bricks[i].x = -1;
        }
    }
}

void handle_input()
{
    char c = getchar();

    switch (c) {
    case 'a':
    case 'A':
    case 'h':
    case 'H':
        if (paddle->x > 0)
            paddle->x--;
        break;
    case 'd':
    case 'D':
    case 'l':
    case 'L':
        if (paddle->x + PADDLE_WIDTH < SCREEN_WIDTH)
            paddle->x++;
        break;
    case 'q':
    case 'Q':
        exit(EXIT_SUCCESS);
        break;
    }
}

void loop()
{
    while (1) {
        handle_input();
        move_ball();
        draw_screen();
        usleep(10000);
    }
}

int main()
{
    init_term();
    init_game();
    loop();
    tcsetattr(term->fd, TCSANOW, &term->orig);
    free(term);
    free(ball);
    free(paddle);
    free(bricks);
    return EXIT_SUCCESS;
}