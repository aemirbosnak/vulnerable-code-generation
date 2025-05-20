//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GRID_SIZE 4
#define MAX_SCORE 100
#define MAX_ATTEMPTS 100

// Card states
typedef enum {
    CARD_FACE_DOWN,
    CARD_FACE_UP,
    CARD_MATCHED
} CardState;

// Card struct
typedef struct {
    int value;
    CardState state;
} Card;

// Game state struct
typedef struct {
    Card grid[GRID_SIZE][GRID_SIZE];
    int score;
    int attempts;
} GameState;

// Function declarations
void initializeGame(GameState *gameState);
void displayGrid(GameState *gameState);
int getCardValue(GameState *gameState, int row, int col);
void flipCard(GameState *gameState, int row, int col);
void checkMatch(GameState *gameState, int row1, int col1, int row2, int col2);
int isGameWon(GameState *gameState);

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize game state
    GameState gameState;
    initializeGame(&gameState);

    // Game loop
    while (!isGameWon(&gameState) && gameState.attempts < MAX_ATTEMPTS) {
        // Display the grid
        displayGrid(&gameState);

        // Get user input
        int row1, col1, row2, col2;
        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &row2, &col2);

        // Flip the cards
        flipCard(&gameState, row1, col1);
        flipCard(&gameState, row2, col2);

        // Check for a match
        checkMatch(&gameState, row1, col1, row2, col2);

        // Increment the number of attempts
        gameState.attempts++;
    }

    // Game over
    if (isGameWon(&gameState)) {
        printf("Congratulations! You won the game!\n");
    } else {
        printf("Game over! You ran out of attempts.\n");
    }

    return 0;
}

// Initialize the game state
void initializeGame(GameState *gameState) {
    // Initialize the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            gameState->grid[i][j].value = rand() % 8 + 1;
            gameState->grid[i][j].state = CARD_FACE_DOWN;
        }
    }

    // Initialize the score and attempts
    gameState->score = 0;
    gameState->attempts = 0;
}

// Display the grid
void displayGrid(GameState *gameState) {
    printf("  ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            switch (gameState->grid[i][j].state) {
                case CARD_FACE_DOWN:
                    printf("[] ");
                    break;
                case CARD_FACE_UP:
                    printf("%d ", gameState->grid[i][j].value);
                    break;
                case CARD_MATCHED:
                    printf("  ");
                    break;
            }
        }
        printf("\n");
    }
}

// Get the value of a card
int getCardValue(GameState *gameState, int row, int col) {
    return gameState->grid[row][col].value;
}

// Flip a card
void flipCard(GameState *gameState, int row, int col) {
    if (gameState->grid[row][col].state == CARD_FACE_DOWN) {
        gameState->grid[row][col].state = CARD_FACE_UP;
    }
}

// Check for a match
void checkMatch(GameState *gameState, int row1, int col1, int row2, int col2) {
    // Check if the cards match
    if (getCardValue(gameState, row1, col1) == getCardValue(gameState, row2, col2)) {
        // Increment the score
        gameState->score++;

        // Mark the cards as matched
        gameState->grid[row1][col1].state = CARD_MATCHED;
        gameState->grid[row2][col2].state = CARD_MATCHED;
    } else {
        // Flip the cards back down
        flipCard(gameState, row1, col1);
        flipCard(gameState, row2, col2);
    }
}

// Check if the game is won
int isGameWon(GameState *gameState) {
    // Check if all the cards are matched
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (gameState->grid[i][j].state != CARD_MATCHED) {
                return 0;
            }
        }
    }

    return 1;
}