//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define BOARD_SIZE 4

void ShowBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" _____ _____ _____ _____ \n");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|     ");
        }
        printf("|\n");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|  %d%d ", i, j);
        }
        printf("|\n");
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != -1) {
                printf("|  %d  ", board[i][j]);
            } else {
                printf("|     ");
            }
        }
        printf("|\n");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|_____");
        }
        printf("|\n");
    }
}

int IsValid(int **board, int *row, int *col) {
    if ((*row < 0) || (*row >= BOARD_SIZE) || (*col < 0) || (*col >= BOARD_SIZE)) {
        printf("Invalid move! Please enter a number from 00 to 33.\n");
        return 0;
    } else if (board[*row][*col] != -1) {
        printf("Invalid move! That cell has already been revealed.\n");
        return 0;
    }
    return 1;
}

void Shuffle(int **arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = *arr[i];
        *arr[i] = *arr[j];
        *arr[j] = temp;
    }
}

int** InitDeck() {
    int** deck = (int**)malloc(sizeof(int*) * BOARD_SIZE * BOARD_SIZE / 2);
    if (deck == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        deck[i] = (int*)malloc(sizeof(int) * 2);
        if (deck[i] == NULL) {
            printf("Failed to allocate memory.\n");
            exit(1);
        }
        deck[i][0] = i;
        deck[i][1] = i;
    }
    return deck;
}

void FreeDeck(int **deck) {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        free(deck[i]);
    }
    free(deck);
}

int** InitBoard() {
    int** board = (int**)malloc(sizeof(int*) * BOARD_SIZE);
    if (board == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(sizeof(int) * BOARD_SIZE);
        if (board[i] == NULL) {
            printf("Failed to allocate memory.\n");
            exit(1);
        }
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
        }
    }
    return board;
}

void FreeBoard(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

void Play() {
    srand(time(NULL));
    int *row = (int*)malloc(sizeof(int));
    int *col = (int*)malloc(sizeof(int));
    int numPairsRevealed = 0;
    int **deck = InitDeck();
    Shuffle(deck, BOARD_SIZE * BOARD_SIZE / 2);
    int **board = InitBoard();
    while (numPairsRevealed < BOARD_SIZE * BOARD_SIZE / 2) {
        ShowBoard(board);
        printf("Enter row and col separated by space (ex: 02): ");
        scanf("%d %d", row, col);
        if (IsValid(board, row, col)) {
            board[*row][*col] = deck[*row * BOARD_SIZE / 2 + *col / 2][*col % 2];
            if (*row > 0 && board[*row - 1][*col] != -1 && board[*row - 1][*col] == board[*row][*col]) {
                numPairsRevealed++;
                board[*row - 1][*col] = deck[(*row - 1) * BOARD_SIZE / 2 + (*col) / 2][*col % 2];
            }
            if (*row < BOARD_SIZE - 1 && board[*row + 1][*col] != -1 && board[*row + 1][*col] == board[*row][*col]) {
                numPairsRevealed++;
                board[*row + 1][*col] = deck[(*row + 1) * BOARD_SIZE / 2 + (*col) / 2][*col % 2];
            }
            if (*col > 0 && board[*row][*col - 1] != -1 && board[*row][*col - 1] == board[*row][*col]) {
                numPairsRevealed++;
                board[*row][*col - 1] = deck[(*row) * BOARD_SIZE / 2 + (*col - 1) / 2][(*col - 1) % 2];
            }
            if (*col < BOARD_SIZE - 1 && board[*row][*col + 1] != -1 && board[*row][*col + 1] == board[*row][*col]) {
                numPairsRevealed++;
                board[*row][*col + 1] = deck[(*row) * BOARD_SIZE / 2 + (*col + 1) / 2][(*col + 1) % 2];
            }
        }
    }
    printf("Congratulations! You have revealed all pairs.\n");
    ShowBoard(board);
    FreeDeck(deck);
    FreeBoard(board);
}

int main() {
    Play();
    return 0;
}