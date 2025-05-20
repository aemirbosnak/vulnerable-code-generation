//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define OPEN ' '
#define BLOCKED '#'

bool **grid; // 2D array to hold percolation grid
int size; // size of grid
int openSites = 0; // number of open sites in the grid

// Function to allocate memory for grid and initialize all sites to blocked
void makeGrid(){
    grid = malloc(sizeof(bool*) * size);
    for(int i = 0; i < size; i++){
        grid[i] = malloc(sizeof(bool) * size);
        for(int j = 0; j < size; j++){
            grid[i][j] = false;
        }
    }
}

// Function to randomly open up a site
void openSite(){
    int x = rand()%size;
    int y = rand()%size;
    if(!grid[x][y]){
        grid[x][y] = true;
        openSites++;
    }
}

// Function to check if a site is open
bool isOpen(int i, int j){
    if(i < 0 || j < 0 || i >= size || j >= size){
        return false;
    }
    return grid[i][j];
}

// Function to check if given site is connected to top
bool isTopConnected(int i, int j){
    if(i == 0){
        return true;
    }
    if(isOpen(i-1, j)){
        return true;
    }
    if(j > 0 && isOpen(i, j-1)){
        return true;
    }
    if(j < size-1 && isOpen(i, j+1)){
        return true;
    }
    return false;
}

// Function to check if given site is connected to bottom
bool isBottomConnected(int i, int j){
    if(i == size-1){
        return true;
    }
    if(isOpen(i+1, j)){
        return true;
    }
    if(j > 0 && isOpen(i, j-1)){
        return true;
    }
    if(j < size-1 && isOpen(i, j+1)){
        return true;
    }
    return false;
}

// Function to check if percolation has occured
bool doesPercolate(){
    for(int i = 0; i < size; i++){
        if(isOpen(size-1, i) && isTopConnected(size-1, i)){
            return true;
        }
    }
    return false;
}

// Function to print the current state of the grid
void printGrid(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid[i][j]){
                printf("%c ", OPEN);
            } else {
                printf("%c ", BLOCKED);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    srand(time(NULL)); // Initialize random seed
    printf("Enter size of grid: ");
    scanf("%d", &size);
    makeGrid();
    printf("Initial grid:\n");
    printGrid();
    while(!doesPercolate()){ // continue until percolation occurs
        openSite();
        printGrid();
    }
    printf("Percolation occured!\n");
    printf("Total open sites: %d\n", openSites);
    return 0;
}