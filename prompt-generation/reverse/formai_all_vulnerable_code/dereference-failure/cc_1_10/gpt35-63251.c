//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10// Define the grid size

bool* grid; // Grid array
int* parent; // Parent array
int* rank; // Rank array

// Function prototypes
void initialize();
void generate();
bool is_percolating();
int find(int);
void join(int, int);
void print_grid();

int main()
{
    srand(time(NULL)); // Seed the random number generator
    initialize(); // Initialize the grid and arrays

    // Generate the randomly filled grid
    generate();

    // Print the grid
    print_grid();

    // Check if the grid is percolating
    bool percolating = is_percolating();

    // Print the percolation result
    if (percolating)
    {
        printf("The grid percolates!\n");
    }
    else
    {
        printf("The grid does not percolate.\n");
    }

    return 0;
}

// Initializes the grid and arrays
void initialize()
{
    // Allocate memory for the grid, parent array, and rank array
    grid = (bool*)malloc(N * N * sizeof(bool));
    parent = (int*)malloc(N * N * sizeof(int));
    rank = (int*)malloc(N * N * sizeof(int));

    // Initialize each cell in the grid to be closed
    for (int i = 0; i < N * N; i++)
    {
        grid[i] = false;
    }

    // Initialize each cell in the parent array to be -1
    for (int i = 0; i < N * N; i++)
    {
        parent[i] = -1;
    }

    // Initialize each cell in the rank array to be 0
    for (int i = 0; i < N * N; i++)
    {
        rank[i] = 0;
    }
}

// Generates a randomly filled grid
void generate()
{
    for (int i = 0; i < N * N; i++)
    {
        if (rand() % 2 == 0)
        {
            grid[i] = true;
        }
    }
}

// Checks if the grid percolates
bool is_percolating()
{
    // Join the top row to the virtual top node
    for (int i = 0; i < N; i++)
    {
        if (grid[i])
        {
            join(i, N * N);
        }
    }

    // Join the bottom row to the virtual bottom node
    for (int i = N * (N - 1); i < N * N; i++)
    {
        if (grid[i])
        {
            join(i, N * N + 1);
        }
    }

    // Check if the virtual top node and virtual bottom node are connected
    return find(N * N) == find(N * N + 1);
}

// Finds the root of the node
int find(int x)
{
    if (parent[x] == -1)
    {
        return x;
    }
    else
    {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

// Joins two nodes together
void join(int x, int y)
{
    int x_root = find(x);
    int y_root = find(y);

    if (x_root == y_root)
    {
        return;
    }

    if (rank[x_root] < rank[y_root])
    {
        parent[x_root] = y_root;
    }
    else if (rank[x_root] > rank[y_root])
    {
        parent[y_root] = x_root;
    }
    else
    {
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}

// Prints the grid
void print_grid()
{
    for (int i = 0; i < N * N; i++)
    {
        if (grid[i])
        {
            printf("# ");
        }
        else
        {
            printf("- ");
        }

        if (i % N == N - 1)
        {
            printf("\n");
        }
    }

    printf("\n");
}