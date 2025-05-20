//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void initializeGame(int* matrix, int n);
void displayMatrix(int* matrix, int n);
int selectCell(int* matrix, int n);
void revealCell(int* matrix, int n, int index);
void playGame(int* matrix, int n);

int main()
{
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n*n];

    initializeGame(matrix, n);
    displayMatrix(matrix, n);
    playGame(matrix, n);

    return 0;
}

// function to initialize the game
void initializeGame(int* matrix, int n)
{
    srand(time(0)); // seeding the random number generator

    // setting all the cells to 0
    for(int i=0; i<n*n; i++) {
        *(matrix + i) = 0;
    }

    // randomly selecting 10 cells and marking them as mines
    for(int i=0; i<10; i++) {
        int index = rand() % (n*n);
        if(*(matrix + index) == -1) {
            i--; // if the same cell has already been selected as mines, do not count it again
        } else {
            *(matrix + index) = -1; // mark the cell as mine
        }
    }

    // setting the values of each cell depending on the number of mines in the surrounding cells
    for(int i=0; i<n*n; i++) {
        if(*(matrix + i) == -1) { // if the cell is a mine, skip this iteration
            continue;
        }
        int count = 0;
        if(i % n != 0 && *(matrix + i - 1) == -1) { // left
            count++;
        }
        if(i % n != n-1 && *(matrix + i + 1) == -1) { // right
            count++;
        }
        if(i >= n && *(matrix + i - n) == -1) { // top
            count++;
        }
        if(i < n*(n-1) && *(matrix + i + n) == -1) { // bottom
            count++;
        }
        if(i >= n && i % n != 0 && *(matrix + i - n - 1) == -1) { // top-left diagonal
            count++;
        }
        if(i >= n && i % n != n-1 && *(matrix + i - n + 1) == -1) { // top-right diagonal
            count++;
        }
        if(i < n*(n-1) && i % n != 0 && *(matrix + i + n - 1) == -1) { // bottom-left diagonal
            count++;
        }
        if(i < n*(n-1) && i % n != n-1 && *(matrix + i + n + 1) == -1) { // bottom-right diagonal
            count++;
        }
        *(matrix + i) = count;
    }
}

// function to display the matrix
void displayMatrix(int* matrix, int n)
{
    printf("\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(*(matrix + i*n + j) == -1) {
                printf("* "); // mine cell
            } else {
                printf("%d ", *(matrix + i*n + j)); // numbered cell
            }
        }
        printf("\n");
    }
}

// function to display the available cells which can be selected
int selectCell(int* matrix, int n)
{
    int index;
    do {
        printf("\nEnter the index of the cell to select (1 to %d): ", n*n);
        scanf("%d", &index);
        index--;
        if(*(matrix + index) <= -2) {
            printf("This cell has already been selected. Please choose a different one.\n");
        }
    } while(*(matrix + index) <= -2);
    return index;
}

// function to reveal the selected cell and any neighboring cells which are not mines
void revealCell(int* matrix, int n, int index)
{
    *(matrix + index) = -2; // mark the selected cell as visited
    if(*(matrix + index) == -1) { // if the selected cell is a mine, game over
        printf("\nGAME OVER!\n");
        displayMatrix(matrix, n);
        exit(0);
    } else if(*(matrix + index) == 0) { // if the selected cell has no surrounding mines, reveal all surrounding cells recursively
        int i = index / n;
        int j = index % n;
        if(i > 0 && *(matrix + (i-1)*n + j) != -1 && *(matrix + (i-1)*n + j) != -2) { // top
            revealCell(matrix, n, (i-1)*n + j);
        }
        if(j > 0 && *(matrix + i*n + j-1) != -1 && *(matrix + i*n + j-1) != -2) { // left
            revealCell(matrix, n, i*n + j-1);
        }
        if(j < n-1 && *(matrix + i*n + j+1) != -1 && *(matrix + i*n + j+1) != -2) { // right
            revealCell(matrix, n, i*n + j+1);
        }
        if(i < n-1 && *(matrix + (i+1)*n + j) != -1 && *(matrix + (i+1)*n + j) != -2) { // bottom
            revealCell(matrix, n, (i+1)*n + j);
        }
        if(i > 0 && j > 0 && *(matrix + (i-1)*n + j-1) != -1 && *(matrix + (i-1)*n + j-1) != -2) { // top-left diagonal
            revealCell(matrix, n, (i-1)*n + j-1);
        }
        if(i > 0 && j < n-1 && *(matrix + (i-1)*n + j+1) != -1 && *(matrix + (i-1)*n + j+1) != -2) { // top-right diagonal
            revealCell(matrix, n, (i-1)*n + j+1);
        }
        if(i < n-1 && j > 0 && *(matrix + (i+1)*n + j-1) != -1 && *(matrix + (i+1)*n + j-1) != -2) { // bottom-left diagonal
            revealCell(matrix, n, (i+1)*n + j-1);
        }
        if(i < n-1 && j < n-1 && *(matrix + (i+1)*n + j+1) != -1 && *(matrix + (i+1)*n + j+1) != -2) { // bottom-right diagonal
            revealCell(matrix, n, (i+1)*n + j+1);
        }
    }
}

// function to play the game
void playGame(int* matrix, int n)
{
    int selected = 0;
    while(selected < n*n - 10) { // while there are still cells which are not mines and have not been selected
        int index = selectCell(matrix, n);
        revealCell(matrix, n, index);
        displayMatrix(matrix, n);
        selected++;
    }
    printf("\nCongratulations! You have won the game!\n");
    displayMatrix(matrix, n);
}