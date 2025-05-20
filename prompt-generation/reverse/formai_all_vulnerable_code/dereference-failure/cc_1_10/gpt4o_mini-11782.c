//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define SIZE 10
#define OPEN 1
#define BLOCKED 0

int grid[SIZE][SIZE];
int percolates = 0;
pthread_mutex_t lock;

typedef struct {
    int row;
    int col;
} Cell;

void init_grid() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            grid[i][j] = (rand() % 100 < 50) ? OPEN : BLOCKED; // 50% probability
        }
    }
}

void print_grid() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%s ", grid[i][j] == OPEN ? "O" : "X");
        }
        printf("\n");
    }
}

void *check_percolation(void *arg) {
    Cell *cell = (Cell *)arg;

    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i] == OPEN) {
            if (grid[SIZE-1][i] == OPEN) {
                pthread_mutex_lock(&lock);
                percolates = 1;
                pthread_mutex_unlock(&lock);
                return NULL;
            }
        }
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t threads[SIZE];
    pthread_mutex_init(&lock, NULL);

    init_grid();
    printf("Initial Grid:\n");
    print_grid();

    for (int i = 0; i < SIZE; i++) {
        Cell *cell = malloc(sizeof(Cell));
        cell->row = 0;
        cell->col = i;
        pthread_create(&threads[i], NULL, check_percolation, (void *)cell);
    }

    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    if (percolates) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    pthread_mutex_destroy(&lock);
    return 0;
}