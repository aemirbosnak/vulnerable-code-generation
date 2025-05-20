//GEMINI-pro DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define SNAKE_LEN 5

typedef struct {
    int x, y;
} Point;

typedef enum {
    UP, RIGHT, DOWN, LEFT
} Direction;

typedef struct {
    Point *body;
    int length;
    Direction dir;
} Snake;

typedef struct {
    int x, y;
} Fruit;

void init_game(Snake *snake, Fruit *fruit) {
    snake->length = SNAKE_LEN;
    snake->body = malloc(sizeof(Point) * snake->length);
    for (int i = 0; i < snake->length; i++) {
        snake->body[i].x = WIDTH / 2 - i;
        snake->body[i].y = HEIGHT / 2;
    }
    snake->dir = RIGHT;

    fruit->x = rand() % WIDTH;
    fruit->y = rand() % HEIGHT;
}

void draw_game(Snake *snake, Fruit *fruit) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == snake->body[0].x && y == snake->body[0].y) {
                printf("O");
            } else if (x == fruit->x && y == fruit->y) {
                printf("F");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void update_snake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i].x = snake->body[i - 1].x;
        snake->body[i].y = snake->body[i - 1].y;
    }

    switch (snake->dir) {
        case UP:
            snake->body[0].y--;
            break;
        case RIGHT:
            snake->body[0].x++;
            break;
        case DOWN:
            snake->body[0].y++;
            break;
        case LEFT:
            snake->body[0].x--;
            break;
    }
}

void check_collisions(Snake *snake, Fruit *fruit) {
    // Check if the snake has eaten the fruit
    if (snake->body[0].x == fruit->x && snake->body[0].y == fruit->y) {
        fruit->x = rand() % WIDTH;
        fruit->y = rand() % HEIGHT;
        snake->length++;
    }

    // Check if the snake has hit itself
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y) {
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));

    Snake snake;
    Fruit fruit;
    init_game(&snake, &fruit);

    while (1) {
        // Get the player's input
        char input = getchar();

        // Update the snake's direction
        switch (input) {
            case 'w':
                snake.dir = UP;
                break;
            case 'd':
                snake.dir = RIGHT;
                break;
            case 's':
                snake.dir = DOWN;
                break;
            case 'a':
                snake.dir = LEFT;
                break;
        }

        // Update the snake's position
        update_snake(&snake);

        // Check for collisions
        check_collisions(&snake, &fruit);

        // Draw the game
        draw_game(&snake, &fruit);
    }

    return 0;
}