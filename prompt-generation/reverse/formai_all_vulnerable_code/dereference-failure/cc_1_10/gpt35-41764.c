//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void displayBoard(char board[ROWS][COLS], int hidden[ROWS][COLS]) {
    printf("\n\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if (hidden[i][j]) {
                printf("* ");
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void shuffleCards(char cards[ROWS*COLS/2]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS*COLS/2; i++) {
        int j = rand() % (ROWS*COLS/2);
        char temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void initializeBoard(char board[ROWS][COLS], int hidden[ROWS][COLS], char cards[ROWS*COLS/2]) {
    shuffleCards(cards);
    int index = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = cards[index];
            hidden[i][j] = 1;
            index++;
        }
    }
}

int selectCard(int *row, int *col) {
    printf("Select a card: ");
    scanf("%d %d", row, col);
    printf("You chose (%d, %d)\n", *row, *col);
}

int main() {
    char cards[ROWS*COLS/2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char board[ROWS][COLS] = {{0}};
    int hidden[ROWS][COLS] = {{0}};
    int firstCardRow, firstCardCol, secondCardRow, secondCardCol;

    initializeBoard(board, hidden, cards);
    displayBoard(board, hidden);

    while(1) {
        printf("\n\n");
        selectCard(&firstCardRow, &firstCardCol);
        hidden[firstCardRow][firstCardCol] = 0;
        displayBoard(board, hidden);

        selectCard(&secondCardRow, &secondCardCol);
        hidden[secondCardRow][secondCardCol] = 0;
        displayBoard(board, hidden);

        if (board[firstCardRow][firstCardCol] == board[secondCardRow][secondCardCol]) {
            printf("Match found!\n");
            hidden[firstCardRow][firstCardCol] = hidden[secondCardRow][secondCardCol] = 0;
            displayBoard(board, hidden);
        } else {
            printf("No match found.\n");
            hidden[firstCardRow][firstCardCol] = hidden[secondCardRow][secondCardCol] = 1;
            displayBoard(board, hidden);
        }
    }

    return 0;
}