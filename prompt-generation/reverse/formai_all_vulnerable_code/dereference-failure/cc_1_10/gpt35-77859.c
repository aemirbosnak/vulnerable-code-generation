//FormAI DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 6  // number of cards
#define ROWS 2
#define COLS 3

void shuffle(int* deck, int n);
void printBoard(int** board, int r, int c);
void updateBoard(int** board, int r1, int c1, int r2, int c2);
int wonGame(int** board, int r, int c);

int main()
{
    printf("Let's play the Memory Game!\n");

    srand(time(NULL));

    // create deck of cards
    int* deck = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        deck[i] = i / 2 + 1;
    }

    // shuffle the deck
    shuffle(deck, size);

    // create the board
    int** board = calloc(ROWS, sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        board[i] = calloc(COLS, sizeof(int));
    }

    // initialize the board
    int k = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = deck[k];
            k++;
        }
    }

    // print the board
    printBoard(board, ROWS, COLS);

    // game loop
    int r1, c1, r2, c2;
    int matches = 0;
    while (matches < size / 2) {
        // get first card
        printf("Enter row and column of first card: ");
        scanf("%d %d", &r1, &c1);
        while (board[r1][c1] == -1) {
            printf("This card has already been matched. Please try again.\n");
            printf("Enter row and column of first card: ");
            scanf("%d %d", &r1, &c1);
        }

        // show first card
        printf("First card: %d\n", board[r1][c1]);

        // get second card
        printf("Enter row and column of second card: ");
        scanf("%d %d", &r2, &c2);
        while (board[r2][c2] == -1) {
            printf("This card has already been matched. Please try again.\n");
            printf("Enter row and column of second card: ");
            scanf("%d %d", &r2, &c2);
        }

        // show second card
        printf("Second card: %d\n", board[r2][c2]);

        // update board
        updateBoard(board, r1, c1, r2, c2);

        // print board
        printBoard(board, ROWS, COLS);

        // check if game won
        if (wonGame(board, ROWS, COLS)) {
            printf("Congratulations, you won the game!\n");
            break;
        }

        // increment number of matches
        matches++;
    }

    // free memory
    free(deck);
    for (int i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

void shuffle(int* deck, int n)
{
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

void printBoard(int** board, int r, int c)
{
    printf("\n  ");
    for (int j = 0; j < c; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < r; i++) {
        printf("%d ", i);
        for (int j = 0; j < c; j++) {
            if (board[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void updateBoard(int** board, int r1, int c1, int r2, int c2)
{
    if (board[r1][c1] == board[r2][c2]) {
        board[r1][c1] = -1;
        board[r2][c2] = -1;
        printf("Congratulations, you found a match!\n");
    } else {
        printf("Sorry, these cards do not match.\n");
    }
}

int wonGame(int** board, int r, int c)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] != -1) {
                return 0;
            }
        }
    }
    return 1;
}