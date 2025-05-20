//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 6
#define COLUMN 6

void displayTable (int table[ROW][COLUMN]) {
    int i, j;
    
    printf("\n\t\t Current Table \n");
    printf("\t   ");
    for (i = 1; i <= COLUMN; i++)
        printf("%d ", i);
    printf("\n\t  ");
    for (i = 0; i <= COLUMN; i++)
        printf("---");
    for (i = 0; i < ROW; i++) {
        printf("\n\t%d| ", i + 1);
        for (j = 0; j < COLUMN; j++)
            printf("%d ", table[i][j]);
    }
    printf("\n\n");
}

int isValidSquare(int table[ROW][COLUMN], int i, int j) {
    return (i >= 0 && i < ROW && j >= 0 && j < COLUMN && table[i][j] == 0);
}

int getNumNeighbors (int table[ROW][COLUMN], int i, int j) {
    int count = 0;

    if (isValidSquare(table, i - 1, j))   count++;
    if (isValidSquare(table, i + 1, j))   count++;
    if (isValidSquare(table, i, j - 1))   count++;
    if (isValidSquare(table, i, j + 1))   count++;

    return count;
}

void getValidNeighbors (int table[ROW][COLUMN], int i, int j, int *neighbors) {
    int k = 0;

    if (isValidSquare(table, i - 1, j))   neighbors[k++] = (i - 1) * COLUMN + j;
    if (isValidSquare(table, i + 1, j))   neighbors[k++] = (i + 1) * COLUMN + j;
    if (isValidSquare(table, i, j - 1))   neighbors[k++] = i * COLUMN + j - 1;
    if (isValidSquare(table, i, j + 1))   neighbors[k++] = i * COLUMN + j + 1;

    neighbors[k] = -1;
}

void shuffleArray (int *array, int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main () {
    int table[ROW][COLUMN] = {0};
    int neighbors[4], i, j, numNeighbors, numSquares;
    int *availableSquares;
    int chosenSquare, currentSquare, moveCount = 0, maxMoves;
    
    srand((unsigned) time(NULL));
    maxMoves = ROW*COLUMN;
    availableSquares = (int *) malloc(sizeof(int) * maxMoves);

    currentSquare = rand() % (ROW*COLUMN);
    i = currentSquare / COLUMN;
    j = currentSquare % COLUMN;

    while (moveCount < maxMoves) {
        table[i][j] = ++moveCount;
        numNeighbors = getNumNeighbors(table, i, j);
        if (numNeighbors == 0) break;
        getValidNeighbors(table, i, j, neighbors);
        shuffleArray(neighbors, 4);
        numSquares = 0;
        for (i = 0; neighbors[i] != -1; i++) {
            if (isValidSquare(table, neighbors[i]/COLUMN, neighbors[i]%COLUMN)) {
                availableSquares[numSquares++] = neighbors[i];
            }
        }
        if (numSquares == 0) break;
        chosenSquare = availableSquares[rand() % numSquares];
        i = chosenSquare / COLUMN;
        j = chosenSquare % COLUMN;
    }

    displayTable(table);
    free(availableSquares);
    return 0;
}