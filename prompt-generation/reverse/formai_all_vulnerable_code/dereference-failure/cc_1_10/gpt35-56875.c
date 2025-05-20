//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to initialize the grid with all blocked sites
void initialize(int N, int *grid){
    for(int i=0;i<N*N;i++){
        grid[i] = 0;
    }
}

// Function to open a site at (row,col)
void open(int row, int col, int N, int *grid){
    grid[(row-1)*N+(col-1)] = 1;
}

// Function to check if the site at (row,col) is open
int isOpen(int row, int col, int N, int *grid){
    return grid[(row-1)*N+(col-1)] == 1;
}

// Function to check if there is a full path from top to bottom
int isFullPath(int N, int *grid, int *fullness){
    // Initializing the fullness array to all zeros
    for(int i=0;i<N*N;i++){
        fullness[i] = 0;
    }
    // Marking all open sites in the first row as full
    for(int col=1;col<=N;col++){
        if(isOpen(1,col,N,grid)){
            fullness[(1-1)*N+(col-1)] = 1;
        }
    }
    // Computing the fullness of the remaining rows recursively
    for(int row=2;row<=N;row++){
        for(int col=1;col<=N;col++){
            if(isOpen(row,col,N,grid)){
                if(fullness[(row-2)*N+(col-1)] || (col>1 && fullness[(row-1)*N+(col-2)]) || (col<N && fullness[(row-1)*N+col])){
                    fullness[(row-1)*N+(col-1)] = 1;
                }
            }
        }
    }
    // Checking if there is at least one full site in the last row
    for(int col=1;col<=N;col++){
        if(fullness[(N-1)*N+(col-1)]){
            return 1;
        }
    }
    return 0;
}

// Function to generate a random integer between min and max (inclusive)
int randInt(int min, int max){
    return min + (rand() % (max - min + 1));
}

// Function to simulate the percolation process
int percolate(int N, int *grid, int *fullness){
    int row, col;
    while(!isFullPath(N,grid,fullness)){
        row = randInt(1,N);
        col = randInt(1,N);
        open(row,col,N,grid);
    }
    return 1;
}

int main(){
    // Initializing the random number generator
    srand(time(NULL));
    // Defining the size of the grid
    int N = 10;
    // Allocating memory for the grid and fullness arrays
    int *grid = malloc(N*N*sizeof(int));
    int *fullness = malloc(N*N*sizeof(int));
    // Initializing the grid with all blocked sites
    initialize(N,grid);
    // Running the percolation simulation
    percolate(N,grid,fullness);
    // Printing the final configuration of the grid
    for(int row=1;row<=N;row++){
        for(int col=1;col<=N;col++){
            printf("%c ",isOpen(row,col,N,grid)?'O':'X');
        }
        printf("\n");
    }
    // Freeing the memory allocated for the grid and fullness arrays
    free(grid);
    free(fullness);
}