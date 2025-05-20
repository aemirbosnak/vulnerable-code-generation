//GEMINI-pro DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rows and columns in the grid
#define MAX_ROWS 10
#define MAX_COLS 10

// Define the possible directions for the snake to move
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

// Define the structure of a snake segment
typedef struct SnakeSegment {
    int row;
    int col;
} SnakeSegment;

// Define the structure of the snake
typedef struct Snake {
    SnakeSegment *segments;
    int length;
    Direction direction;
} Snake;

// Define the structure of the game board
typedef struct GameBoard {
    char grid[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
} GameBoard;

// Create a new snake
Snake *create_snake(int length, Direction direction) {
    Snake *snake = malloc(sizeof(Snake));
    snake->segments = malloc(sizeof(SnakeSegment) * length);
    snake->length = length;
    snake->direction = direction;
    return snake;
}

// Destroy the snake
void destroy_snake(Snake *snake) {
    free(snake->segments);
    free(snake);
}

// Create a new game board
GameBoard *create_game_board(int num_rows, int num_cols) {
    GameBoard *game_board = malloc(sizeof(GameBoard));
    game_board->num_rows = num_rows;
    game_board->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            game_board->grid[i][j] = ' ';
        }
    }
    return game_board;
}

// Destroy the game board
void destroy_game_board(GameBoard *game_board) {
    free(game_board);
}

// Draw the snake on the game board
void draw_snake(Snake *snake, GameBoard *game_board) {
    for (int i = 0; i < snake->length; i++) {
        game_board->grid[snake->segments[i].row][snake->segments[i].col] = 'S';
    }
}

// Move the snake in the specified direction
void move_snake(Snake *snake, Direction direction) {
    // Get the head of the snake
    SnakeSegment head = snake->segments[0];

    // Move the head in the specified direction
    switch (direction) {
        case UP:
            head.row--;
            break;
        case DOWN:
            head.row++;
            break;
        case LEFT:
            head.col--;
            break;
        case RIGHT:
            head.col++;
            break;
    }

    // Shift the segments of the snake down one
    for (int i = snake->length - 1; i > 0; i--) {
        snake->segments[i] = snake->segments[i - 1];
    }

    // Set the head of the snake to the new position
    snake->segments[0] = head;
}

// Check if the snake has hit itself
int snake_hit_itself(Snake *snake) {
    for (int i = 1; i < snake->length; i++) {
        if (snake->segments[0].row == snake->segments[i].row && snake->segments[0].col == snake->segments[i].col) {
            return 1;
        }
    }
    return 0;
}

// Check if the snake has hit the edge of the game board
int snake_hit_edge(Snake *snake, GameBoard *game_board) {
    if (snake->segments[0].row < 0 || snake->segments[0].row >= game_board->num_rows ||
        snake->segments[0].col < 0 || snake->segments[0].col >= game_board->num_cols) {
        return 1;
    }
    return 0;
}

// Check if the snake has eaten the food
int snake_eat_food(Snake *snake, GameBoard *game_board) {
    if (game_board->grid[snake->segments[0].row][snake->segments[0].col] == 'F') {
        return 1;
    }
    return 0;
}

// Place the food randomly on the game board
void place_food(GameBoard *game_board) {
    int row, col;
    do {
        row = rand() % game_board->num_rows;
        col = rand() % game_board->num_cols;
    } while (game_board->grid[row][col] != ' ');
    game_board->grid[row][col] = 'F';
}

// Print the game board
void print_game_board(GameBoard *game_board) {
    for (int i = 0; i < game_board->num_rows; i++) {
        for (int j = 0; j < game_board->num_cols; j++) {
            printf("%c ", game_board->grid[i][j]);
        }
        printf("\n");
    }
}

// Main game loop
int main() {
    srand(time(NULL));

    // Create a new snake
    Snake *snake = create_snake(3, RIGHT);

    // Create a new game board
    GameBoard *game_board = create_game_board(MAX_ROWS, MAX_COLS);

    // Place the food on the game board
    place_food(game_board);

    // Main game loop
    while (!snake_hit_itself(snake) && !snake_hit_edge(snake, game_board)) {
        // Draw the snake on the game board
        draw_snake(snake, game_board);

        // Print the game board
        print_game_board(game_board);

        // Get the user input
        char input;
        scanf(" %c", &input);

        // Change the direction of the snake based on the user input
        switch (input) {
            case 'w':
                snake->direction = UP;
                break;
            case 's':
                snake->direction = DOWN;
                break;
            case 'a':
                snake->direction = LEFT;
                break;
            case 'd':
                snake->direction = RIGHT;
                break;
        }

        // Move the snake
        move_snake(snake, snake->direction);

        // Check if the snake has eaten the food
        if (snake_eat_food(snake, game_board)) {
            // Increase the length of the snake
            snake->length++;

            // Place the food on the game board
            place_food(game_board);
        }
    }

    // Destroy the snake and the game board
    destroy_snake(snake);
    destroy_game_board(game_board);

    return 0;
}