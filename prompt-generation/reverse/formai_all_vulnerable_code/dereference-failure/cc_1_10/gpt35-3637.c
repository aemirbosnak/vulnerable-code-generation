//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* struct definition to represent a percolation system */
struct percolation_system {
    int size;
    bool **grid;
};

/* function to initialize the percolation system */
void initialize_system(struct percolation_system *system) {
    system->grid = (bool **) malloc(system->size * sizeof(bool *));
    for(int i = 0; i < system->size; i++) {
        system->grid[i] = (bool *) malloc(system->size * sizeof(bool));
        for(int j = 0; j < system->size; j++) {
            system->grid[i][j] = false; // initialize all sites as blocked
        }
    }
}

/* function to open up a site in the system */
void open_site(struct percolation_system *system, int row, int col) {
    system->grid[row][col] = true;
}

/* function to check if a site is open */
bool is_site_open(struct percolation_system *system, int row, int col) {
    return system->grid[row][col];
}

/* function to check if the system percolates */
bool does_percolate(struct percolation_system *system) {
    bool *top_row = (bool *) malloc(system->size * sizeof(bool));
    for(int i = 0; i < system->size; i++) {
        top_row[i] = is_site_open(system, 0, i); // stores if each site in the top row is open
    }
    bool *bottom_row = (bool *) malloc(system->size * sizeof(bool));
    for(int i = 0; i < system->size; i++) {
        bottom_row[i] = is_site_open(system, system->size-1, i); // stores if each site in the bottom row is open
    }
    // checks if there is a path of open sites from top row to bottom row
    bool percolates = false;
    for(int i = 0; i < system->size; i++) {
        if(top_row[i]) {
            for(int j = 0; j < system->size; j++) {
                if(bottom_row[j] && system->grid[i][j]) {
                    percolates = true;
                    break;
                }
            }
        }
        if(percolates) {
            break;
        }
    }
    free(top_row);
    free(bottom_row);
    return percolates;
}

/* function to free the memory allocated to the percolation system */
void free_system(struct percolation_system *system) {
    for(int i = 0; i < system->size; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
}

int main(void) {
    srand(time(NULL));
    printf("Welcome to the Percolation Simulator!\n");
    printf("Please enter the size of the percolation system: ");
    int size;
    scanf("%d", &size);
    struct percolation_system system = {size};
    initialize_system(&system);
    printf("Please enter the probability of a site being open (0 to 1): ");
    double probability;
    scanf("%lf", &probability);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            double rand_value = (double) rand() / (double) RAND_MAX;
            if(rand_value <= probability) {
                open_site(&system, i, j);
            }
        }
    }
    if(does_percolate(&system)) {
        printf("Hooray! The system percolates!\n");
    } else {
        printf("Oops! The system does not percolate.\n");
    }
    free_system(&system);
    return 0;
}