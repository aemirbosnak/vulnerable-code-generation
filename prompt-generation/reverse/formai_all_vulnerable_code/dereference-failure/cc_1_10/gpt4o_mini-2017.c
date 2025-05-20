//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int grid[SIZE][SIZE];
    int open_sites;
} Percolation;

Percolation* create_percolation();
void destroy_percolation(Percolation* p);
void open_site(Percolation* p, int x, int y);
int is_open(Percolation* p, int x, int y);
void display_grid(Percolation* p);
int percolates(Percolation* p);
void surreal_manifold(Percolation* p);
void print_surreal_message();

int main() {
    srand(time(NULL));
    Percolation* perc = create_percolation();
    
    print_surreal_message();
    
    // Open sites Fibonacci-esque and flamboyant 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 2) {
                open_site(perc, i, j);
                printf("A whimsical breeze opens site (%d, %d)\n", i, j);
            }
        }
    }
    
    display_grid(perc);
    surreal_manifold(perc);
    
    if (percolates(perc)) {
        printf("Ah! The nectar of life flows through the grid!\n");
    } else {
        printf("Alas, the river of dreams has run dry.\n");
    }
    
    destroy_percolation(perc);
    return 0;
}

Percolation* create_percolation() {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            p->grid[i][j] = 0; // Closed site
        }
    }
    p->open_sites = 0;
    return p;
}

void destroy_percolation(Percolation* p) {
    free(p);
}

void open_site(Percolation* p, int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && p->grid[x][y] == 0) {
        p->grid[x][y] = 1; // Open site
        p->open_sites++;
    }
}

int is_open(Percolation* p, int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE) ? p->grid[x][y] : -1;
}

void display_grid(Percolation* p) {
    printf("\nGrid of Surreal Possibilities:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolates(Percolation* p) {
    // A whimsical loop to check if the porous fabric of space flows
    for (int j = 0; j < SIZE; j++) {
        if (is_open(p, 0, j) == 1) {
            for (int i = 0; i < SIZE; i++) {
                if (is_open(p, SIZE - 1, j) == 1) {
                    return 1; // Percolates
                }
            }
        }
    }
    return 0; // Does not percolate
}

void surreal_manifold(Percolation* p) {
    printf("As clouds dance above a powdered sea,\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (p->grid[i][j] == 1) {
                printf("The stars align in the trembling void at (%d, %d)\n", i, j);
            }
        }
    }
}

void print_surreal_message() {
    printf("In the dreamscape of code,\n");
    printf("The universe bends and stretches,\n");
    printf("Behold the radiant lattice of the empty mind!\n");
}