//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define N 10 // grid size
#define P 0.6 // probability of a site being open

bool *grid; // grid to hold open or blocked sites
int *top; // array to hold top row connections 
int *bottom; // array to hold bottom row connections
int count = 0; // counter for number of sites connected to top row
pthread_mutex_t lock; //mutex for synchronization

// function to check if site is open
bool is_open(int row, int col) {
    if (row < 0 || col < 0 || row >= N || col >= N) return false; // out of bounds
    return *(grid + row * N + col);
}

// function to connect two sites
void connect(int *arr, int index1, int index2) {
    int root1 = *(arr + index1);
    int root2 = *(arr + index2);
    if (root1 == root2) return; // already connected
    for (int i = 0; i < N*N; i++) { // change root of all items with root1 to root2
        if (*(arr + i) == root1) {
            *(arr + i) = root2;
        }
    }
}

// function to check if top row is connected to bottom row
bool is_percolated() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int index = i * N + j;
            if (is_open(i, j)) {
                if (i == 0) { // site is in top row
                    pthread_mutex_lock(&lock);
                    *(top + j) = index;
                    count++;
                    pthread_mutex_unlock(&lock);
                }
                if (i == N-1) { // site is in bottom row
                    bool connected = false;
                    for (int k = 0; k < N; k++) {
                        if (*(bottom + k) != -1 && (*(bottom + k) / N) == (index / N)) { // check if site is connected to a top row site
                            pthread_mutex_lock(&lock);
                            connected = true;
                            count++;
                            pthread_mutex_unlock(&lock);
                            break;
                        }
                    }
                    if (!connected) *(bottom + j) = index; // add to bottom row
                }
                if (i != 0 && i != N-1) { // site is in middle rows
                    if (is_open(i-1, j)) connect(grid, index, index-N); // connect to top
                    if (is_open(i+1, j)) connect(grid, index, index+N); // connect to bottom
                    if (is_open(i, j-1)) connect(grid, index, index-1); // connect to left
                    if (is_open(i, j+1)) connect(grid, index, index+1); // connect to right
                }
            }
        }
    }
    return (count > 0);
}

// function to randomly open sites in grid
void open_sites() {
    srand(time(NULL)); // seed random number generator
    for (int i = 0; i < N*N; i++) {
        if ((double) rand() / (double) RAND_MAX < P) {
            *(grid + i) = true;
        }
    }
}

// function to print grid
void print_grid() {
    printf("   ");
    for (int j = 0; j < N; j++) printf("%d ", j%10);
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%2d ", i);
        for (int j = 0; j < N; j++) {
            if (*(grid + i*N + j)) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

// function for each thread to call
void *percolate(void *thread_id) {
    is_percolated(); // check if the grid percolates
    pthread_exit(NULL);
}

int main() {
    grid = (bool*) calloc(N*N, sizeof(bool)); // allocate memory for grid
    top = (int*) calloc(N, sizeof(int)); // allocate memory for top row connections
    bottom = (int*) calloc(N, sizeof(int)); // allocate memory for bottom row connections
    for (int i = 0; i < N; i++) {
        *(bottom + i) = -1; // initialize bottom row connections to -1
    }
    open_sites(); // randomly open sites in grid
    print_grid(); // print grid
    printf("\n");
    pthread_t threads[N]; // create array of threads
    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, percolate, (void *) i); // create threads
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL); // wait for threads to finish
    }
    if (is_percolated()) printf("The grid percolates!\n"); // check if the grid percolates
    else printf("The grid does not percolate.\n");
    free(grid); // free grid memory
    free(top); // free top row connections memory
    free(bottom); // free bottom row connections memory
    pthread_mutex_destroy(&lock); // destroy mutex
    return 0;
}