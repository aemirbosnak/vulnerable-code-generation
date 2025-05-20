//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: random
// Percolation Simulator
// By: RandomGenius

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent grid node
struct Node
{
   int value;
   int isOpen;
   int isConnected;
};

// Function to initialize grid
void initializeGrid(struct Node** grid, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            grid[i][j].value = 0;
            grid[i][j].isOpen = 0;
            grid[i][j].isConnected = 0;
        }
    }
}

// Function to randomly open nodes
void openRandomNodes(struct Node** grid, int size, float threshold)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            float rand_num = ((float) rand() / (float) RAND_MAX);
            if(rand_num < threshold)
            {
                grid[i][j].isOpen = 1;
            }
        }
    }
}

// Function to check if two nodes are connected
int isConnected(struct Node** grid, int size, int node1_x, int node1_y, int node2_x, int node2_y)
{
    if(grid[node1_x][node1_y].isConnected == 1 && grid[node2_x][node2_y].isConnected == 1)
        return 1;

    if(grid[node1_x][node1_y].isOpen == 0 || grid[node2_x][node2_y].isOpen == 0)
        return 0;

    if(abs(node1_x - node2_x) + abs(node1_y - node2_y) > 1)
        return 0;

    return 1;
}

// Function to connect two nodes
void connectNodes(struct Node** grid, int size, int node1_x, int node1_y, int node2_x, int node2_y)
{
    if(!isConnected(grid, size, node1_x, node1_y, node2_x, node2_y))
        return;

    grid[node1_x][node1_y].isConnected = 1;
    grid[node2_x][node2_y].isConnected = 1;

    // check for connecting clusters
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(isConnected(grid, size, node1_x, node1_y, i, j))
            {
                grid[i][j].isConnected = 1;
            }
        }
    }
}

// Function to check if percolation has occured
int hasPercolated(struct Node** grid, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(grid[0][i].isConnected == 1 && grid[size-1][i].isConnected == 1)
            return 1;
    }

    return 0;
}

// Function to print grid
void printGrid(struct Node** grid, int size)
{
    printf("--------------------\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j].isOpen);
        }
        printf("\n");
    }
    printf("--------------------\n");
}

int main()
{

    int size = 10;
    float threshold = 0.6;

    // Allocate memory for grid
    struct Node** grid = (struct Node**) malloc(size * sizeof(struct Node*));
    for(int i = 0; i < size; i++)
    {
        grid[i] = (struct Node*) malloc(size * sizeof(struct Node));
    }

    // Seed random number generator
    srand(time(NULL));

    // Initialize grid
    initializeGrid(grid, size);

    // Open random nodes
    openRandomNodes(grid, size, threshold);

    // Print initial grid
    printf("Initial Grid\n");
    printGrid(grid, size);

    // Connect nodes
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i > 0)
            {
                connectNodes(grid, size, i, j, i-1, j);
            }
            if(j > 0)
            {
                connectNodes(grid, size, i, j, i, j-1);
            }
        }
    }

    // Print final grid
    printf("Final Grid\n");
    printGrid(grid, size);

    // Check for percolation
    if(hasPercolated(grid, size))
    {
        printf("Percolation Has Occured!\n");
    }
    else
    {
        printf("Percolation Has Not Occured!\n");
    }

    // Free memory
    for(int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}