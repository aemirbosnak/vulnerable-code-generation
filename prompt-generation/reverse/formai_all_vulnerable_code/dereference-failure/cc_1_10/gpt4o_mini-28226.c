//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Size of the game board (4x4)

void initializeBoard(char board[SIZE][SIZE], char symbols[SIZE * SIZE]);
void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]);
bool checkMatch(char board[SIZE][SIZE], int firstChoice[2], int secondChoice[2]);
void getInput(int choice[2]);
bool isGameCompleted(bool revealed[SIZE][SIZE]);
void shuffleArray(char* array, int size);

int main() {
    char board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};
    char symbols[SIZE * SIZE] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};

    srand(time(NULL));
    shuffleArray(symbols, SIZE * SIZE);
    initializeBoard(board, symbols);

    printf("Welcome to the C Memory Game! Try to find matching pairs of cards.\n");
    
    int firstChoice[2], secondChoice[2];
    while (!isGameCompleted(revealed)) {
        printBoard(board, revealed);
        printf("Choose the coordinates of the first card (row column): ");
        getInput(firstChoice);
        
        revealed[firstChoice[0]][firstChoice[1]] = true;
        printBoard(board, revealed);
        
        printf("Choose the coordinates of the second card (row column): ");
        getInput(secondChoice);
        
        revealed[secondChoice[0]][secondChoice[1]] = true;
        printBoard(board, revealed);
        
        if (!checkMatch(board, firstChoice, secondChoice)) {
            printf("Not a match! Try again.\n");
            revealed[firstChoice[0]][firstChoice[1]] = false;
            revealed[secondChoice[0]][secondChoice[1]] = false;
        } else {
            printf("You found a match!\n");
        }
    }

    printf("Congratulations! You've matched all the pairs!\n");
    return 0;
}

void initializeBoard(char board[SIZE][SIZE], char symbols[SIZE * SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = symbols[i * SIZE + j];
        }
    }
}

void printBoard(char board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" ? ");
            }
        }
        printf("\n");
    }
}

bool checkMatch(char board[SIZE][SIZE], int firstChoice[2], int secondChoice[2]) {
    return board[firstChoice[0]][firstChoice[1]] == board[secondChoice[0]][secondChoice[1]];
}

void getInput(int choice[2]) {
    scanf("%d %d", &choice[0], &choice[1]);
}

bool isGameCompleted(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void shuffleArray(char* array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}