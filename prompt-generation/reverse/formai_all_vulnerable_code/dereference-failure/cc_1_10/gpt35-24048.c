//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
Function to generate random numbers between 0 and 1
*/
float randomNum(){
    return (float) rand() / (float) RAND_MAX;
}

/*
Function to run the percolation simulation
*/
int percolation(int n, float p){
    int *site = (int *) malloc(sizeof(int) * n*n);
    int *open = (int *) calloc(sizeof(int), n*n);
    int row, col, index;
    int top, right, bottom, left;
    int water_flag = 0;
    
    // Initializing all sites as blocked
    for(int i=0; i < n*n; i++){
        site[i] = 0;
    }
    
    // Open the sites with probability p
    for(row=0; row < n; row++){
        for(col = 0; col < n; col++){
            index = row * n + col;
            if(randomNum() < p){
                site[index] = 1;
            }
        }
    }
    
    // Open the top and bottom virtual sites
    for(col=0; col < n; col++){
        index = col;
        open[index] = 1;
        index = (n-1) * n + col;
        open[index] = 1;
    }
    
    // Open the connected sites and check for percolation
    for(int i=0; i < n*n; i++){
        if(site[i] == 1){
            row = i / n;
            col = i % n;
            index = row * n + col;
            top = (row - 1) * n + col;
            right = row * n + col + 1;
            bottom = (row + 1) * n + col;
            left = row * n + col - 1;
            
            // Check if the site is connected to the top virtual site
            if(row == 0){
                open[index] = 1;
            }
            else{
                if(open[top] == 1){
                    open[index] = 1;
                }
            }
            
            // Check if the site is connected to the bottom virtual site
            if(row == n-1){
                if(open[index] == 1){
                    water_flag = 1;
                }
            }
            else{
                if(open[bottom] == 1){
                    open[index] = 1;
                }
            }
            
            // Check if the site is connected to the left site
            if(col > 0){
                if(open[left] == 1){
                    open[index] = 1;
                }
            }
            
            // Check if the site is connected to the right site
            if(col < n-1){
                if(open[right] == 1){
                    open[index] = 1;
                }
            }
        }
        if(water_flag == 1){
            break;
        }
    }
    
    // Free memory
    free(site);
    free(open);
    
    return water_flag;
}

/*
Main function to run the simulation and print the output
*/
int main(){
    srand(time(NULL));
    int n = 20;
    float p = 0.6;
    int water_flag;
    
    water_flag = percolation(n, p);
    if(water_flag == 1){
        printf("Water percolates!\n");
    }
    else{
        printf("Water does not percolate :(\n");
    }
    
    return 0;
}