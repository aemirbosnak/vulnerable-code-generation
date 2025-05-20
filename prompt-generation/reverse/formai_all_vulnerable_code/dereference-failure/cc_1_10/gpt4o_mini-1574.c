//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SHOCKING: The chessboard is represented as a 2D array!
#define BOARD_SIZE 8

char chessboard[BOARD_SIZE][BOARD_SIZE];

// Function Prototypes
void initialize_board();
void print_board();
int is_valid_move(int startX, int startY, int endX, int endY);
void move_piece(int startX, int startY, int endX, int endY);
void get_user_input(int *startX, int *startY, int *endX, int *endY);

// Main Function
int main() {
    initialize_board();
    
    int startX, startY, endX, endY;
    while(1) {
        print_board();
        get_user_input(&startX, &startY, &endX, &endY);
        
        // SHOCKING: Validating the move!
        if(is_valid_move(startX, startY, endX, endY)) {
            move_piece(startX, startY, endX, endY);
        } else {
            printf("Invalid move! Try again...\n");
        }
    }
    
    return 0;
}

// SHOCKING: Initialize the chessboard with pieces in their initial positions!
void initialize_board() {
    const char *initial_setup[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    
    for(int i = 0; i < BOARD_SIZE; i++) {
        strcpy(chessboard[i], initial_setup[i]);
    }
}

// SHOCKING: Printing the chessboard!
void print_board() {
    printf("\n  A B C D E F G H\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessboard[i][j] == '.' ? '.' : chessboard[i][j]);
        }
        printf("\n");
    }
}

// SHOCKING: Function to check if a move is valid! (simplified)
int is_valid_move(int startX, int startY, int endX, int endY) {
    // Assume it's a valid move if destination is empty or within the board
    if(endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // SHOCKING: Move is out of bounds!
    }
    if(chessboard[startX][startY] == '.') {
        return 0; // SHOCKING: No piece to move!
    }
    return 1; // SHOCKING: Move is valid for now!
}

// SHOCKING: Function to move a piece on the chessboard!
void move_piece(int startX, int startY, int endX, int endY) {
    chessboard[endX][endY] = chessboard[startX][startY];
    chessboard[startX][startY] = '.';
    printf("Moved piece from (%d, %d) to (%d, %d)\n", 
           8 - startX, startY + 1, 8 - endX, endY + 1);
}

// SHOCKING: Get user input in the format 'e2 e4'!
void get_user_input(int *startX, int *startY, int *endX, int *endY) {
    char input[10];
    printf("Enter your move (e.g., 'e2 e4'): ");
    
    // SHOCKING: Wait for user input!
    fgets(input, sizeof(input), stdin);
    
    // Convert the input into coordinates!
    char start[3], end[3];
    sscanf(input, "%s %s", start, end);
    
    // Convert to coordinates!
    // SHOCKING: Get coordinates based on user input!
    *startY = start[0] - 'a'; // Column
    *startX = 8 - (start[1] - '0'); // Row

    *endY = end[0] - 'a'; // Column
    *endX = 8 - (end[1] - '0'); // Row

    // SHOCKING: Verify coordinates are valid!
    if(*startX < 0 || *startX >= BOARD_SIZE || 
       *startY < 0 || *startY >= BOARD_SIZE || 
       *endX < 0 || *endX >= BOARD_SIZE || 
       *endY < 0 || *endY >= BOARD_SIZE) {
        printf("Out of bounds! Please enter a valid range.\n");
    }
}