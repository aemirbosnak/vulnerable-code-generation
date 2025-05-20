//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10 // Change this to vary grid size

int SIZE = N; // Global variable for grid size
int top = 0;
int bottom = (N*N) + 1;
int *parent; // array to keep track of parents
int *size; // array to keep track of size of each tree
int *grid; // grid to store state of each site

// Function to initialize grid with blocked sites
void initialize(){
    grid = malloc((N*N+2)*sizeof(int));
    for(int i=0; i<N*N+2; i++){
        grid[i] = 0;
    }
    grid[top] = grid[bottom] = 1; // top and bottom are always open
}

// Function to print grid
void print_grid(){
    for(int i=1; i<=SIZE*SIZE; i++){
        if(i%SIZE == 1){
            printf("\n");
        }
        if(grid[i] == 1){
            printf("⬛️");
        }else{
            printf("⬜️");
        }
    }
    printf("\n");
}

// Function to get index in parent array for (row,col)
int get_index(int row, int col){
    return SIZE*(row-1) + col;
}

// Function to find root of a node
int find(int p){
    while(p != parent[p]){
        parent[p] = parent[parent[p]]; // Path compression
        p = parent[p];
    }
    return p;
}

// Function to check if two sites are connected
int is_connected(int p, int q){
    return find(p) == find(q);
}

// Function to connect two sites
void connect(int p, int q){
    int rootp = find(p);
    int rootq = find(q);
    if(rootp == rootq){
        return;
    }
    if(size[rootp] <= size[rootq]){
        parent[rootp] = rootq;
        size[rootq] += size[rootp];
    }else{
        parent[rootq] = rootp;
        size[rootp] += size[rootq];
    }
}

// Function to open a site
void open_site(int row, int col){
    int index = get_index(row, col);
    if(grid[index] == 1){ // Check if already open
        return;
    }
    grid[index] = 1;
    // Connect adjacent open sites
    if(row > 1 && grid[get_index(row-1, col)] == 1){ // Up
        connect(index, get_index(row-1, col));
    }
    if(row < SIZE && grid[get_index(row+1, col)] == 1){ // Down
        connect(index, get_index(row+1, col));
    }
    if(col > 1 && grid[get_index(row, col-1)] == 1){ // Left
        connect(index, get_index(row, col-1));
    }
    if(col < SIZE && grid[get_index(row, col+1)] == 1){ // Right
        connect(index, get_index(row, col+1));
    }
}

// Function to check if site is open
int is_open(int row, int col){
    int index = get_index(row, col);
    return grid[index] == 1;
}

// Function to check if site is full
int is_full(int row, int col){
    int index = get_index(row, col);
    return is_open(row, col) && is_connected(index, top);
}

// Function to generate random site
void random_site(int *row, int *col){
    *row = rand() % SIZE + 1;
    *col = rand() % SIZE + 1;
}

// Function to simulate percolation
int percolate(){
    srand(time(NULL));
    grid[top] = 1; // Open top
    int row, col;
    while(!is_connected(top, bottom)){
        random_site(&row, &col);
        open_site(row, col);
    }
    return 1;
}

// Main function
int main(){
    parent = malloc((N*N+2)*sizeof(int));
    size = malloc((N*N+2)*sizeof(int));
    initialize();
    for(int i=0; i<N*N+2; i++){
        parent[i] = i;
        size[i] = 1;
    }
    percolate();
    printf("Percolation has occurred!\n");
    printf("Here is the final grid:\n");
    print_grid();
    return 0;
}