//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
//Welcome to the Percolation Simulator in C!
//Are you ready to explore a world of percolation clusters and probabilities?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the size of the grid
#define N 10

//Define the directions of the neighbouring cells
#define RIGHT 1
#define LEFT -1
#define UP -N
#define DOWN N

//Function to check if a cell is open
int is_open(int *grid, int i, int j)
{
    return *(grid + i*N + j);
}

//Function to open a cell
void open(int *grid, int i, int j)
{
    *(grid + i*N + j) = 1;
}

//Function to connect two open cells
void connect(int *grid, int i1, int j1, int i2, int j2)
{
    int id1 = i1*N + j1;
    int id2 = i2*N + j2;
    *(grid + id1) = *(grid + id2);
}

//Function to find the root of a cluster
int root(int *grid, int id)
{
    while(id != *(grid + id))
    {
        *(grid + id) = *(grid + *(grid + id));
        id = *(grid + id);
    }
    return id;
}

//Function to check if two cells are in the same cluster
int is_connected(int *grid, int i1, int j1, int i2, int j2)
{
    int id1 = i1*N + j1;
    int id2 = i2*N + j2;
    return root(grid, id1) == root(grid, id2);
}

//Main function to simulate percolation
int main()
{
    srand(time(NULL)); //Seed for random number generation
    
    int *grid = malloc(N*N*sizeof(int)); //Allocate memory for grid
    
    //Initialize array to zeroes
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            *(grid + i*N + j) = 0;
        }
    }
    
    int open_sites = 0; //Counter for number of open sites
    int p = 0.5; //Probability of opening a site
    
    //Open random cells until the system percolates
    while(!is_connected(grid, 0, 0, N-1, N-1))
    {
        int i = rand()%N;
        int j = rand()%N;
        
        if(!is_open(grid, i, j))
        {
            open(grid, i, j);
            open_sites++;
            
            //Connect to neighbouring cells if they are open
            if(i > 0 && is_open(grid, i-1, j))
            {
                connect(grid, i, j, i-1, j);
            }
            if(i < N-1 && is_open(grid, i+1, j))
            {
                connect(grid, i, j, i+1, j);
            }
            if(j > 0 && is_open(grid, i, j-1))
            {
                connect(grid, i, j, i, j-1);
            }
            if(j < N-1 && is_open(grid, i, j+1))
            {
                connect(grid, i, j, i, j+1);
            }
        }
        
        //Calculate the current percolation probability
        float probability = (float)open_sites/(N*N);
        
        printf("Simulating...\n");
        printf("Number of open sites: %d\n", open_sites);
        printf("Current percolation probability: %.2f\n", probability);
        printf("------------------------\n\n");
        
        //Wait for a moment before continuing the loop
        for(int i=0; i<100000000; i++);
    }
    
    //Print the final percolation probability
    float final_probability = (float)open_sites/(N*N);
    printf("System percolated!\n");
    printf("Final percolation probability: %.2f\n\n", final_probability);
    
    free(grid); //Free memory
    
    return 0; //End of program
}