//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printBoard(char** board, int rows, int cols);
int getRand(int maxNum);

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the game board: ");
    scanf("%d %d", &rows, &cols);

    // Allocate space for the game board dynamically
    char** board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        board[i] = (char*)malloc(cols * sizeof(char));
    }

    // Initialize game board with random characters
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int randNum = getRand(26);  // Generate random number between 0 and 25
            board[i][j] = (char)('A' + randNum);  // Add to game board
        }
    }

    printf("\nWelcome to the Game!\n");
    printf("Rules:\n1. Find words by joining letters in sequence.\n2. Total score will be displayed at the end.\n");
    
    int score = 0;
    while (1) {  // Loop until user chooses to exit
        printBoard(board, rows, cols);
        printf("Enter word you found (or 'exit' to quit): ");
        char word[20];
        scanf("%s", word);

        if (strcmp(word, "exit") == 0) {
            break;
        }
        
        // Check if word is valid
        int wordFound = 0;
        for (int i = 0; i < rows && !wordFound; i++) {  // Loop through each row of board
            for (int j = 0; j < cols && !wordFound; j++) {  // Loop through each column of board   
                if (board[i][j] == word[0]) {  // Check if first letter of word matches board letter
                    int len = strlen(word);
                    
                    if (i+len <= rows) {  // Check if remaining letters fit in same row
                        int letterIdx = 1;
                        for (; letterIdx < len; letterIdx++) {  // Loop through each letter of word
                            if (board[i+letterIdx][j] != word[letterIdx]) {  // Check if letter in word matches board letter
                                break;
                            }
                        }
                        
                        if (letterIdx == len) {  // All letters in word found in same row
                            wordFound = 1;
                        }
                    }
                    
                    if (!wordFound && j+len <= cols) {  // Check if remaining letters fit in same column
                        int letterIdx = 1;
                        for (; letterIdx < len; letterIdx++) {  // Loop through each letter of word
                            if (board[i][j+letterIdx] != word[letterIdx]) { // Check if letter in word matches board letter
                                break;
                            }
                        }
                        
                        if (letterIdx == len) {  // All letters in word found in same column
                            wordFound = 1;
                        }
                    }
                }
            }
        }
        
        if (wordFound) {
            printf("Congratulations, you found the word '%s'! +10 points\n", word);
            score += 10;
        } else {
            printf("Sorry, the word '%s' was not found on the board.\n", word);
        }

        printf("Current score: %d\n", score);
    }

    // Free memory allocated for game board
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    printf("Final score: %d\nGoodbye!\n", score);
    return 0;
}

// Function to print game board
void printBoard(char** board, int rows, int cols) {
    printf("\nCurrent game board:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to generate random number between 0 and maxNum
int getRand(int maxNum) {
    return rand() % maxNum;
}