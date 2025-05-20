//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10

//Function to check if site is connected to top row
int is_connected_to_top(int **grids, int row, int col) {
    if(row == 0) {
        return 1;
    }
    if(grids[row-1][col] == 1) {
        return 1;
    }
    if(col > 0 && grids[row][col-1] == 1) {
        return 1;
    }
    if(col < COL - 1 && grids[row][col+1] == 1) {
        return 1;
    }
    return 0;
}

//Recursive function to check if site is full
void check_full(int **grids, int row, int col) {
    if(row < 0 || row >= ROW || col < 0 || col >= COL || grids[row][col] == 0) {
        return;
    }
    grids[row][col] = 2; //mark site as full
    if(is_connected_to_top(grids, row, col)) {
        check_full(grids, row-1, col); //top
        check_full(grids, row, col-1); //left
        check_full(grids, row, col+1); //right
        check_full(grids, row+1, col); //bottom
    }
}

int main() {
    int **grids, count=0;
    srand(time(NULL));

    //Allocate memory to 2D grid
    grids = (int **) malloc(ROW * sizeof(int *));
    for(int i=0; i<ROW; i++) {
        grids[i] = (int *) malloc(COL * sizeof(int));
    }

    //Initialize grid with random values
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            grids[i][j] = (rand() % 2);
        }
    }

    printf("Initial grid:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d ", grids[i][j]);
        }
        printf("\n");
    }

    //Check if any site is full
    for(int j=0; j<COL; j++) {
        if(grids[ROW-1][j] == 1) {
            check_full(grids, ROW-1, j);
        }
    }

    //Count the number of full sites
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(grids[i][j] == 2) {
                count++;
            }
        }
    }

    printf("Number of full sites: %d\n", count);

    //Free memory allocated to grid
    for(int i=0; i<ROW; i++) {
        free(grids[i]);
    }
    free(grids);

    return 0;
}