//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define N 100

// Probability of a site being open
#define P 0.5

// Data structure for a site
typedef struct site {
    int x, y;
    int open;
} site;

// Data structure for a cluster
typedef struct cluster {
    int size;
    site *sites;
} cluster;

// Function to create a new site
site *new_site(int x, int y) {
    site *s = malloc(sizeof(site));
    s->x = x;
    s->y = y;
    s->open = 0;
    return s;
}

// Function to create a new cluster
cluster *new_cluster(site *s) {
    cluster *c = malloc(sizeof(cluster));
    c->size = 1;
    c->sites = malloc(sizeof(site));
    c->sites[0] = *s;
    return c;
}

// Function to merge two clusters
void merge_clusters(cluster *c1, cluster *c2) {
    c1->size += c2->size;
    c1->sites = realloc(c1->sites, c1->size * sizeof(site));
    for (int i = 0; i < c2->size; i++) {
        c1->sites[c1->size - 1 - i] = c2->sites[i];
    }
    free(c2);
}

// Function to perform a depth-first search to find all sites in a cluster
void dfs(site *s, cluster *c) {
    if (s->open) {
        s->open = 0;
        c->size++;
        c->sites = realloc(c->sites, c->size * sizeof(site));
        c->sites[c->size - 1] = *s;
        dfs(new_site(s->x - 1, s->y), c);
        dfs(new_site(s->x + 1, s->y), c);
        dfs(new_site(s->x, s->y - 1), c);
        dfs(new_site(s->x, s->y + 1), c);
    }
}

// Function to simulate percolation
int percolate(site *grid[N][N]) {
    // Initialize the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = new_site(i, j);
            grid[i][j]->open = (rand() < RAND_MAX * P);
        }
    }

    // Perform depth-first search to find all clusters
    cluster clusters[N * N];
    int num_clusters = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]->open) {
                dfs(grid[i][j], &clusters[num_clusters++]);
            }
        }
    }

    // Merge clusters until there is only one cluster left
    while (num_clusters > 1) {
        // Find the two largest clusters
        int max_size1 = 0, max_size2 = 0;
        int max_index1 = -1, max_index2 = -1;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].size > max_size1) {
                max_size2 = max_size1;
                max_index2 = max_index1;
                max_size1 = clusters[i].size;
                max_index1 = i;
            } else if (clusters[i].size > max_size2) {
                max_size2 = clusters[i].size;
                max_index2 = i;
            }
        }

        // Merge the two largest clusters
        merge_clusters(&clusters[max_index1], &clusters[max_index2]);

        // Remove the smaller cluster from the list of clusters
        for (int i = max_index2; i < num_clusters - 1; i++) {
            clusters[i] = clusters[i + 1];
        }
        num_clusters--;
    }

    // Check if the largest cluster percolates
    cluster *largest_cluster = &clusters[0];
    for (int i = 0; i < largest_cluster->size; i++) {
        if (largest_cluster->sites[i].y == 0 || largest_cluster->sites[i].y == N - 1) {
            return 1;
        }
    }

    return 0;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the grid
    site *grid[N][N];

    // Print the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]->open);
        }
        printf("\n");
    }

    // Simulate percolation
    int percolates = percolate(grid);

    // Print the result
    printf("Percolates: %d\n", percolates);

    return 0;
}