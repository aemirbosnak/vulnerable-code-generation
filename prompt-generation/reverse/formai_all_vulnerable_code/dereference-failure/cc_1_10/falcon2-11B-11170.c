//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 4
#define COLS 4

typedef struct {
    int row;
    int col;
} Coord;

typedef struct {
    char *image;
    Coord position;
} Card;

Card *cards[ROWS][COLS];
int currentCard[ROWS][COLS];
int openCards[ROWS][COLS];
int matches[ROWS][COLS];
int matchCount = 0;

void shuffleCards(void) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int temp = cards[i][j]->position.row;
            cards[i][j]->position.row = cards[ROWS-1][j]->position.row;
            cards[ROWS-1][j]->position.row = temp;

            temp = cards[i][j]->position.col;
            cards[i][j]->position.col = cards[i][COLS-1]->position.col;
            cards[i][COLS-1]->position.col = temp;
        }
    }
}

void printCards(void) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", cards[i][j]->image[0]);
        }
        printf("\n");
    }
}

void moveCard(int row, int col) {
    Card *temp = cards[row][col];
    int tempRow = cards[row][col]->position.row;
    int tempCol = cards[row][col]->position.col;
    cards[row][col]->position.row = row;
    cards[row][col]->position.col = col;
    cards[tempRow][tempCol]->position.row = tempRow;
    cards[tempRow][tempCol]->position.col = tempCol;
    if (cards[row][col]->image[0] == cards[tempRow][tempCol]->image[0]) {
        matches[row][col] += 1;
        matches[tempRow][tempCol] += 1;
        matchCount += 2;
    }
}

int main(int argc, char *argv[]) {
    int i, j;
    int row, col;
    char *image;
    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            cards[i][j] = (Card*)malloc(sizeof(Card));
            cards[i][j]->image = (char*)malloc(sizeof(char)*5);
            sprintf(cards[i][j]->image, "%c", 'C');
            cards[i][j]->position.row = i;
            cards[i][j]->position.col = j;
        }
    }

    shuffleCards();

    while (matchCount < 4 * 4) {
        printCards();
        printf("Moves left: %d\n", ROWS * COLS - matchCount);
        printf("Choose a card to move\n");
        scanf("%d %d", &row, &col);
        if (currentCard[row][col] == 0) {
            moveCard(row, col);
            currentCard[row][col] = 1;
        }
        printCards();
        printf("Moves left: %d\n", ROWS * COLS - matchCount);
        if (matchCount == ROWS * COLS) {
            printf("Congratulations! You have found all the matches.\n");
            break;
        }
    }

    printf("The final score is: %d\n", matchCount);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            free(cards[i][j]->image);
            free(cards[i][j]);
        }
    }
    free(cards);

    return 0;
}