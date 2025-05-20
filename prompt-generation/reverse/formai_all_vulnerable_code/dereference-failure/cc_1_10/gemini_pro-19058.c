//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Shutup compiler! I am Linus, I do what I want!
#pragma GCC diagnostic ignored "-Wunused-function"

// Grid size
#define GRID_SIZE 100

// Probability of a site being open
#define P 0.5

// Union-find data structure
struct UF {
	int *id;
	int *sz;
};

// Create a new union-find data structure
struct UF *UF_create(int n) {
	struct UF *uf = malloc(sizeof(struct UF));
	uf->id = malloc(n * sizeof(int));
	uf->sz = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		uf->id[i] = i;
		uf->sz[i] = 1;
	}
	return uf;
}

// Find the root of the tree containing p
int UF_find(struct UF *uf, int p) {
	while (p != uf->id[p]) {
		uf->id[p] = uf->id[uf->id[p]];
		p = uf->id[p];
	}
	return p;
}

// Merge the trees containing p and q
void UF_union(struct UF *uf, int p, int q) {
	int i = UF_find(uf, p);
	int j = UF_find(uf, q);
	if (i == j) return;
	if (uf->sz[i] < uf->sz[j]) {
		uf->id[i] = j;
		uf->sz[j] += uf->sz[i];
	} else {
		uf->id[j] = i;
		uf->sz[i] += uf->sz[j];
	}
}

// Create a new percolation grid
int **grid_create() {
	int **grid = malloc(GRID_SIZE * sizeof(int *));
	for (int i = 0; i < GRID_SIZE; i++) {
		grid[i] = malloc(GRID_SIZE * sizeof(int));
		for (int j = 0; j < GRID_SIZE; j++) {
			grid[i][j] = (rand() < RAND_MAX * P) ? 1 : 0;
		}
	}
	return grid;
}

// Print the percolation grid
void grid_print(int **grid) {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

// Check if the system percolates
int grid_percolates(int **grid) {
	// Create a union-find data structure
	struct UF *uf = UF_create(GRID_SIZE * GRID_SIZE);

	// Iterate over the grid
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			// If the site is open
			if (grid[i][j]) {
				// Union the site with its neighbors
				if (i > 0 && grid[i - 1][j]) UF_union(uf, i * GRID_SIZE + j, (i - 1) * GRID_SIZE + j);
				if (i < GRID_SIZE - 1 && grid[i + 1][j]) UF_union(uf, i * GRID_SIZE + j, (i + 1) * GRID_SIZE + j);
				if (j > 0 && grid[i][j - 1]) UF_union(uf, i * GRID_SIZE + j, i * GRID_SIZE + j - 1);
				if (j < GRID_SIZE - 1 && grid[i][j + 1]) UF_union(uf, i * GRID_SIZE + j, i * GRID_SIZE + j + 1);
			}
		}
	}

	// Check if the top and bottom rows are connected
	for (int i = 0; i < GRID_SIZE; i++) {
		if (UF_find(uf, i) == UF_find(uf, GRID_SIZE * GRID_SIZE - 1)) {
			return 1;
		}
	}

	// Return 0 if the system does not percolate
	return 0;
}

int main() {
	// Initialize the random number generator
	srand(time(NULL));

	// Create a new percolation grid
	int **grid = grid_create();

	// Print the percolation grid
	grid_print(grid);

	// Check if the system percolates
	int percolates = grid_percolates(grid);

	// Print the result
	printf("The system %s percolate.\n", percolates ? "does" : "does not");

	// Free the percolation grid
	for (int i = 0; i < GRID_SIZE; i++) {
		free(grid[i]);
	}
	free(grid);

	return 0;
}