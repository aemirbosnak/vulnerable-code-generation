//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 50
#define BALL_RADIUS 10
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 20
#define PADDLE_SPEED 5

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point paddle1;
    Point paddle2;
} Paddle;

typedef struct {
    Point ball;
    Point paddle1;
    Point paddle2;
} Game;

void draw_paddle(Paddle* paddle) {
    printf("|");
    printf(" ");
    printf("|");
    printf(" ");
    printf("|");
    printf(" ");
    printf("|");
    printf(" ");
    printf("|");
}

void draw_ball(Game* game) {
    printf("^");
    printf(" ");
    printf("^");
}

void draw_game(Game* game) {
    draw_paddle(&game->paddle1);
    draw_paddle(&game->paddle2);
    draw_ball(game);
}

void move_paddle(Paddle* paddle, int key) {
    if (key == 'w') {
        paddle->paddle1.y -= PADDLE_SPEED;
    }
    if (key =='s') {
        paddle->paddle1.y += PADDLE_SPEED;
    }
    if (key == 'd') {
        paddle->paddle2.y -= PADDLE_SPEED;
    }
    if (key == 'a') {
        paddle->paddle2.y += PADDLE_SPEED;
    }
}

void move_ball(Game* game) {
    int dx = 0;
    int dy = 0;

    if (game->ball.y > HEIGHT - BALL_RADIUS) {
        dy = -1;
    } else if (game->ball.y < 0) {
        dy = 1;
    }

    if (game->ball.x > WIDTH - BALL_RADIUS) {
        dx = -1;
    } else if (game->ball.x < 0) {
        dx = 1;
    }

    game->ball.x += dx;
    game->ball.y += dy;
}

int main() {
    srand(time(NULL));

    Game game;
    game.paddle1.x = WIDTH / 2;
    game.paddle1.y = HEIGHT / 2;
    game.paddle2.x = WIDTH / 2;
    game.paddle2.y = HEIGHT - PADDLE_HEIGHT - 10;
    game.ball.x = WIDTH / 2;
    game.ball.y = HEIGHT / 2;

    printf("Welcome to Pong!\n");
    printf("Player 1: Up and Down Arrow Keys\n");
    printf("Player 2: W, S, A, D\n");

    while (1) {
        draw_game(&game);

        if (game.ball.y < 0 || game.ball.y > HEIGHT - BALL_RADIUS) {
            game.ball.y = (game.ball.y + (BALL_RADIUS / 2)) - (HEIGHT - BALL_RADIUS);
        }
        if (game.ball.x < 0 || game.ball.x > WIDTH - BALL_RADIUS) {
            game.ball.x = (game.ball.x + (BALL_RADIUS / 2)) - (WIDTH - BALL_RADIUS);
        }

        move_paddle(&game.paddle1, getchar());
        move_paddle(&game.paddle2, getchar());
        move_ball(&game);

        if (game.ball.x < 0 || game.ball.x > WIDTH - BALL_RADIUS || game.ball.y < 0 || game.ball.y > HEIGHT - BALL_RADIUS) {
            break;
        }

        if (game.ball.x < game.paddle1.x - BALL_RADIUS && game.ball.y < game.paddle1.y - BALL_RADIUS) {
            game.ball.x = game.paddle2.x + BALL_RADIUS;
            game.ball.y = game.paddle2.y - BALL_RADIUS;
            game.paddle2.y += 1;
        } else if (game.ball.x > game.paddle1.x + BALL_RADIUS && game.ball.y < game.paddle1.y - BALL_RADIUS) {
            game.ball.x = game.paddle2.x - BALL_RADIUS;
            game.ball.y = game.paddle2.y - BALL_RADIUS;
            game.paddle2.y += 1;
        } else if (game.ball.x < game.paddle2.x - BALL_RADIUS && game.ball.y < game.paddle2.y - BALL_RADIUS) {
            game.ball.x = game.paddle1.x + BALL_RADIUS;
            game.ball.y = game.paddle1.y - BALL_RADIUS;
            game.paddle1.y += 1;
        } else if (game.ball.x > game.paddle2.x + BALL_RADIUS && game.ball.y < game.paddle2.y - BALL_RADIUS) {
            game.ball.x = game.paddle1.x - BALL_RADIUS;
            game.ball.y = game.paddle1.y - BALL_RADIUS;
            game.paddle1.y += 1;
        }
    }

    return 0;
}