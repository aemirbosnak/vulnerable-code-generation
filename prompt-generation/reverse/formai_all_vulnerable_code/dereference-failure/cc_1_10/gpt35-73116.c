//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

/* Define the game board structure */
typedef struct {
    int rows;
    int cols;
    char **board;
} Board;

/* Define the Pac-Man and ghost data structures */
typedef struct {
    int row;
    int col;
    int lives;
    int score;
    int direction; // 0 = left, 1 = up, 2 = right, 3 = down
} PacMan;

typedef struct {
    int row;
    int col;
    int direction;
} Ghost;

/* Initialize the game board */
void initBoard(Board *board) {
    board->rows = MAX_ROWS;
    board->cols = MAX_COLS;
    board->board = malloc(sizeof(char*) * MAX_ROWS);
    for (int i = 0; i < MAX_ROWS; i++) {
        board->board[i] = malloc(sizeof(char) * MAX_COLS);
        for (int j = 0; j < MAX_COLS; j++) {
            if (i == 0 || i == MAX_ROWS - 1 || j == 0 || j == MAX_COLS - 1) {
                board->board[i][j] = '#';
            } else {
                board->board[i][j] = ' ';
            }
        }
    }
}

/* Print the game board */
void printBoard(Board board, PacMan pacman, Ghost ghost) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (i == pacman.row && j == pacman.col) {
                printf("P");
            } else if (i == ghost.row && j == ghost.col) {
                printf("G");
            } else {
                printf("%c", board.board[i][j]);
            }
        }
        printf("\n");
    }
}

/* Place the Pac-Man and ghost in random spots on the board */
void placeEntities(Board board, PacMan *pacman, Ghost *ghost) {
    srand(time(NULL));
    do {
        pacman->row = rand() % MAX_ROWS;
        pacman->col = rand() % MAX_COLS;
    } while (board.board[pacman->row][pacman->col] != ' ');
    do {
        ghost->row = rand() % MAX_ROWS;
        ghost->col = rand() % MAX_COLS;
    } while (board.board[ghost->row][ghost->col] != ' ');
}

/* Move the Pac-Man and ghost based on their current directions */
void moveEntities(Board board, PacMan *pacman, Ghost *ghost) {
    switch (pacman->direction) {
        case 0: // Move left
            if (board.board[pacman->row][pacman->col - 1] == ' ') {
                pacman->col--;
            }
            break;
        case 1: // Move up
            if (board.board[pacman->row - 1][pacman->col] == ' ') {
                pacman->row--;
            }
            break;
        case 2: // Move right
            if (board.board[pacman->row][pacman->col + 1] == ' ') {
                pacman->col++;
            }
            break;
        case 3: // Move down
            if (board.board[pacman->row + 1][pacman->col] == ' ') {
                pacman->row++;
            }
            break;
    }

    switch (ghost->direction) {
        case 0: // Move left
            if (board.board[ghost->row][ghost->col - 1] == ' ') {
                ghost->col--;
            }
            break;
        case 1: // Move up
            if (board.board[ghost->row - 1][ghost->col] == ' ') {
                ghost->row--;
            }
            break;
        case 2: // Move right
            if (board.board[ghost->row][ghost->col + 1] == ' ') {
                ghost->col++;
            }
            break;
        case 3: // Move down
            if (board.board[ghost->row + 1][ghost->col] == ' ') {
                ghost->row++;
            }
            break;
    }
}

/* Update the game state */
void updateGameState(Board board, PacMan *pacman, Ghost *ghost) {
    moveEntities(board, pacman, ghost);

    // Check for collision between Pac-Man and ghost
    if (pacman->row == ghost->row && pacman->col == ghost->col) {
        pacman->lives--;
        placeEntities(board, pacman, ghost);
    }
}

/* Play the game */
void playGame(Board board, PacMan pacman, Ghost ghost) {
    while (pacman.lives > 0) {
        int input = getchar();
        if (input == 'a') {
            pacman.direction = 0;
        } else if (input == 'w') {
            pacman.direction = 1;
        } else if (input == 'd') {
            pacman.direction = 2;
        } else if (input == 's') {
            pacman.direction = 3;
        }
        updateGameState(board, &pacman, &ghost);
        printBoard(board, pacman, ghost);
        printf("Score: %d\nLives: %d\n", pacman.score, pacman.lives);
    }
    printf("Game over!\n");
}

int main() {
    Board board;
    initBoard(&board);

    PacMan pacman;
    pacman.lives = 3;
    pacman.score = 0;
    pacman.direction = 0;
    Ghost ghost;
    ghost.direction = 0;

    placeEntities(board, &pacman, &ghost);
    printBoard(board, pacman, ghost);
    playGame(board, pacman, ghost);

    return 0;
}