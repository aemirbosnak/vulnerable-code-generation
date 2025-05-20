//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int width;
    int height;
    int *grid;
} Percolation;

void init_percolation(Percolation *p, int width, int height) {
    p->width = width;
    p->height = height;
    p->grid = (int *)malloc(width * height * sizeof(int));

    for (int i = 0; i < width * height; i++) {
        p->grid[i] = BLOCKED;   
    }
}

void free_percolation(Percolation *p) {
    free(p->grid);
}

int index(Percolation *p, int row, int col) {
    return row * p->width + col;
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->height || col < 0 || col >= p->width) {
        return;
    }
    p->grid[index(p, row, col)] = OPEN;
}

bool is_open(Percolation *p, int row, int col) {
    return p->grid[index(p, row, col)] == OPEN;
}

bool is_full(Percolation *p, int row, int col) {
    if (!is_open(p, row, col)) return false;

    // Check if the site can connect to the top
    if (row == 0) return true; // If it's in the first row, it's full

    return is_open(p, row - 1, col); // Check the site above
}

void display_grid(Percolation *p) {
    for (int i = 0; i < p->height; i++) {
        for (int j = 0; j < p->width; j++) {
            printf("%c ", is_open(p, i, j) ? 'O' : 'X');
        }
        printf("\n");
    }
}

bool percolates(Percolation *p) {
    for (int col = 0; col < p->width; col++) {
        // Check if any site in the bottom row is full
        if (is_full(p, p->height - 1, col)) {
            return true; // Percolates
        }
    }
    return false; // Does not percolate
}

void random_open_sites(Percolation *p, double probability) {
    for (int i = 0; i < p->height; i++) {
        for (int j = 0; j < p->width; j++) {
            if ((double)rand() / RAND_MAX < probability) {
                open_site(p, i, j);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <width> <height> <open_probability>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    double open_probability = atof(argv[3]);

    srand(time(NULL));

    Percolation p;
    init_percolation(&p, width, height);
    random_open_sites(&p, open_probability);

    printf("Percolation grid:\n");
    display_grid(&p);

    if (percolates(&p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(&p);
    return 0;
}