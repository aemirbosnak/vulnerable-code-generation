//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define SIZE 4
#define MAX_MOVES 20

// Struct for Game Board
struct Board {
    int** grid;
    int rows;
    int cols;
    int moves;
    int curr_x;
    int curr_y;
};

// Function to create game board
struct Board create_board() {
    // Allocate memory for the board grid
    int** grid = (int**) malloc(SIZE*sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (int*) malloc(SIZE*sizeof(int));
    }

    // Set all grid elements to 0
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // Initialize board struct values
    struct Board board = {
        .grid = grid,
        .rows = SIZE,
        .cols = SIZE,
        .moves = 0,
        .curr_x = rand() % SIZE,
        .curr_y = rand() % SIZE
    };

    // Set initial grid value
    board.grid[board.curr_x][board.curr_y] = 1;

    return board;
}

// Function to print game board
void print_board(struct Board board) {
    for (int i = 0; i < board.rows; i++) {
        for (int j = 0; j < board.cols; j++) {
            printf("%d ", board.grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if game is won
int check_win(struct Board board) {
    int last_num = 0;
    for (int i = 0; i < board.rows; i++) {
        for (int j = 0; j < board.cols; j++) {
            if (board.grid[i][j] != last_num+1) {
                return 0;
            }
            last_num++;
        }
    }
    return 1;
}

// Function to get user input for move
int get_move() {
    char move[10];
    printf("Enter move (up, down, left, right): ");
    scanf("%s", move);

    if (strcmp(move, "up") == 0) {
        return 1;
    } else if (strcmp(move, "down") == 0) {
        return 2;
    } else if (strcmp(move, "left") == 0) {
        return 3;
    } else if (strcmp(move, "right") == 0) {
        return 4;
    } else {
        printf("Invalid move! Try again.\n");
        return get_move();
    }
}

// Function to make move on game board
void make_move(struct Board* board, int move) {
    switch(move) {
        case 1: // UP
            if (board->curr_x == 0) {
                printf("Invalid move! Try again.\n");
                break;
            }
            board->grid[board->curr_x][board->curr_y] = 0;
            board->curr_x--;
            board->grid[board->curr_x][board->curr_y] = board->moves+1;
            board->moves++;
            break;

        case 2: // DOWN
            if (board->curr_x == board->rows-1) {
                printf("Invalid move! Try again.\n");
                break;
            }
            board->grid[board->curr_x][board->curr_y] = 0;
            board->curr_x++;
            board->grid[board->curr_x][board->curr_y] = board->moves+1;
            board->moves++;
            break;

        case 3: // LEFT
            if (board->curr_y == 0) {
                printf("Invalid move! Try again.\n");
                break;
            }
            board->grid[board->curr_x][board->curr_y] = 0;
            board->curr_y--;
            board->grid[board->curr_x][board->curr_y] = board->moves+1;
            board->moves++;
            break;

        case 4: // RIGHT
            if (board->curr_y == board->cols-1) {
                printf("Invalid move! Try again.\n");
                break;
            }
            board->grid[board->curr_x][board->curr_y] = 0;
            board->curr_y++;
            board->grid[board->curr_x][board->curr_y] = board->moves+1;
            board->moves++;
            break;

        default:
            printf("Invalid move! Try again.\n");
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create game board
    struct Board board = create_board();

    // Print initial board
    printf("Starting Game!\n");
    print_board(board);

    // Loop for user moves
    for (int i = 0; i < MAX_MOVES; i++) {
        // Get user move and make it
        int move = get_move();
        make_move(&board, move);

        // Print updated board
        print_board(board);

        // Check if game is won
        if (check_win(board)) {
            printf("Congratulations! You won in %d moves.\n", board.moves);
            return 0;
        }
    }

    // Game over if maximum moves reached
    printf("Game over! Maximum moves reached.\n");
    return 0;
}