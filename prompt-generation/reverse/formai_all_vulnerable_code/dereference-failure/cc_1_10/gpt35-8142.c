//FormAI DATASET v1.0 Category: Chess engine ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Minimum possible board size
#define MIN_BOARD_SIZE 3

// Maximum possible board size
#define MAX_BOARD_SIZE 8

// Maximum move length
#define MAX_MOVE_LENGTH 10

// Board structure
typedef struct {
    int size;
    char **spaces;
} Board;

// Player structure
typedef struct {
    char name[20];
    char symbol;
} Player;

// Global variables
Player players[2];
Board board;

// Function to check if coordinate is valid
int isValidCoordinate(int row, int col) {
    return row >= 0 && row < board.size && col >= 0 && col < board.size;
}

// Function to initialize the board
void initBoard(int size) {
    board.size = size;
    board.spaces = malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        board.spaces[i] = malloc(size * sizeof(char));
        for (int j = 0; j < size; j++) {
            board.spaces[i][j] = '.';
        }
    }
}

// Function to display the board
void displayBoard() {
    for (int i = 0; i < board.size; i++) {
        for (int j = 0; j < board.size; j++) {
            printf("%c ", board.spaces[i][j]);
        }
        printf("\n");
    }
}

// Function to get player move
char* getPlayerMove(Player player) {
    char* move = malloc(MAX_MOVE_LENGTH * sizeof(char));
    printf("%s's move (%c): ", player.name, player.symbol);
    scanf("%s", move);
    return move;
}

// Function to check if move is valid
int isValidMove(char* move) {
    if (strlen(move) != 2) {
        return 0;
    }
    int col = move[0] - 'a';
    int row = move[1] - '1';
    return isValidCoordinate(row, col) && board.spaces[row][col] == '.';
}

// Function to play the game
void playGame() {
    int currPlayer = 0;
    Player curr = players[currPlayer];
    while (1) {
        displayBoard();
        char* move = getPlayerMove(curr);
        if (isValidMove(move)) {
            int col = move[0] - 'a';
            int row = move[1] - '1';
            board.spaces[row][col] = curr.symbol;
            if (currPlayer == 0) {
                currPlayer = 1;
            } else {
                currPlayer = 0;
            }
            curr = players[currPlayer];
        } else {
            printf("Invalid move, try again...\n");
        }
        free(move);
    }
}

// Main function
int main() {
    printf("Welcome to minimalist chess!\n");
    printf("Enter player 1 name: ");
    scanf("%s", players[0].name);
    players[0].symbol = 'X';
    printf("Enter player 2 name: ");
    scanf("%s", players[1].name);
    players[1].symbol = 'O';
    int size;
    while (1) {
        printf("Enter board size: ");
        scanf("%d", &size);
        if (size < MIN_BOARD_SIZE || size > MAX_BOARD_SIZE) {
            printf("Invalid board size, try again...\n");
        } else {
            break;
        }
    }
    initBoard(size);
    playGame();
    return 0;
}