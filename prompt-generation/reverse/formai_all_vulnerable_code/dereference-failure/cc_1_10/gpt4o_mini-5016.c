//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    bool whiteToMove;
} GameState;

void initializeBoard(GameState *state) {
    char initialBoard[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    };
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            state->board[i][j] = initialBoard[i][j];
    state->whiteToMove = true;
}

void printBoard(GameState *state) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", state->board[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(GameState *state, int startX, int startY, int endX, int endY) {
    char piece = state->board[startX][startY];
    // Basic rule: A piece cannot move to a square that it occupies with the same color
    if ((piece >= 'a' && state->whiteToMove) || (piece <= 'Z' && !state->whiteToMove)) {
        return false;
    }
    // This is a simplified check. Add checks for each piece type later.
    return true;
}

void makeMove(GameState *state, int startX, int startY, int endX, int endY) {
    state->board[endX][endY] = state->board[startX][startY];
    state->board[startX][startY] = ' ';
    state->whiteToMove = !state->whiteToMove;
}

int evaluateBoard(GameState *state) {
    int score = 0;
    // Basic evaluation based on piece material
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = state->board[i][j];
            if (piece == 'P') score += 1;
            else if (piece == 'N' || piece == 'B') score += 3;
            else if (piece == 'R') score += 5;
            else if (piece == 'Q') score += 9;
            else if (piece == 'K') score += 0; // King has no material value
            else if (piece == 'p') score -= 1;
            else if (piece == 'n' || piece == 'b') score -= 3;
            else if (piece == 'r') score -= 5;
            else if (piece == 'q') score -= 9;
            else if (piece == 'k') score -= 0;
        }
    }
    return score;
}

int minimax(GameState *state, int depth, bool maximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard(state);
    }

    if (maximizingPlayer) {
        int maxEval = -10000;
        // Here, we should generate possible moves and iterate through them
        // For the sake of brevity, we'll skip move generation in this example.
        // In a complete AI, you'd generate moves and call minimax on the resulting state.
        return maxEval;  // Placeholder
    } else {
        int minEval = 10000;
        // Here, similar move generation should be applied
        return minEval;  // Placeholder
    }
}

int main() {
    GameState state;
    initializeBoard(&state);
    while (true) {
        printBoard(&state);
        if (state.whiteToMove) {
            printf("White's turn (Enter your move as e2 e4): ");
        } else {
            printf("Black's turn (AI playing): ");
            // Implement actual AI move here
        }

        char start[3], end[3];
        if (state.whiteToMove) {
            scanf("%s %s", start, end);
            int startX = 8 - (start[1] - '0'); // Converting to array index
            int startY = start[0] - 'a';       // Converting to array index
            int endX = 8 - (end[1] - '0');     // Converting to array index
            int endY = end[0] - 'a';           // Converting to array index

            if (isValidMove(&state, startX, startY, endX, endY)) {
                makeMove(&state, startX, startY, endX, endY);
            } else {
                printf("Invalid move!\n");
            }
        } else {
            // AI Move generation and decision (could call minimax here)
        }
    }
    return 0;
}