//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define CELL_SIZE 10
#define CELL_COLORS "GREEN RED BLUE YELLOW"
#define CELL_SHAPES "RECTANGLE CIRCLE TRIANGLE SQUARE"

typedef struct cell {
    char shape[5];  // shape of the cell (e.g. "RECTANGLE", "CIRCLE", etc.)
    char color[5];  // color of the cell (e.g. "GREEN", "RED", etc.)
    int x;         // x-coordinate of the cell
    int y;         // y-coordinate of the cell
} cell_t;

// Function to print the game board
void print_board(cell_t* board, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            printf("%c%c%c", board[i * height + j].shape[0], board[i * height + j].color[0], " ");
        }
        printf("\n");
    }
}

// Function to update the game board
void update_board(cell_t* board, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Check if the cell is alive (i.e. has a neighbor that is alive)
            if (is_alive(board, i, j)) {
                // If the cell is alive, apply the rules
                if (board[i * height + j].shape[0] == 'R' && board[i * height + j].color[0] == 'B') {  // Rule 1: If a red cell is born, it stays red
                    board[i * height + j].color[0] = 'R';
                } else if (board[i * height + j].shape[0] == 'G' && board[i * height + j].color[0] == 'E') {  // Rule 2: If a green cell is born, it stays green
                    board[i * height + j].color[0] = 'G';
                } else if (board[i * height + j].shape[0] == 'B' && board[i * height + j].color[0] == 'Y') {  // Rule 3: If a blue cell is born, it stays blue
                    board[i * height + j].color[0] = 'B';
                } else {  // Rule 4: If a cell is born and has no alive neighbors, it dies
                    board[i * height + j].color[0] = ' ';
                }
            }
        }
    }
}

// Function to check if a cell is alive
int is_alive(cell_t* board, int x, int y) {
    int i, j;
    int count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (board[x + i * WIDTH + y + j].shape[0] != ' ' && board[x + i * WIDTH + y + j].color[0] != ' ') {
                count++;
            }
        }
    }
    return count > 0;
}

int main() {
    srand(time(NULL));
    cell_t* board = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        board[i].shape[0] = CELL_SHAPES[rand() % strlen(CELL_SHAPES)];
        board[i].color[0] = CELL_COLORS[rand() % strlen(CELL_COLORS)];
        board[i].x = rand() % WIDTH;
        board[i].y = rand() % HEIGHT;
    }

    while (1) {
        update_board(board, WIDTH, HEIGHT);
        print_board(board, WIDTH, HEIGHT);
        sleep(1);
    }

    return 0;
}