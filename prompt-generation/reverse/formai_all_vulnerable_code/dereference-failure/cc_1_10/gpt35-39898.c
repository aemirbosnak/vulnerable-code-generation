//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

// Function to randomly assign 0 or 1 to the sites
void random_sites(int* sites) {
    for(int i=0;i<(SIZE*SIZE);i++) {
        sites[i] = rand() % 2;
    }
}

// Function to print all the sites
void print_sites(int* sites) {
    for(int i=0;i<(SIZE*SIZE);i++) {
        printf("%d ", sites[i]);
        if((i+1) % SIZE == 0) {
            printf("\n");
        }
    }
}

// Function to check if the percolation happened or not
int percolate(int* sites) {
    int* temp_sites = (int*)malloc((SIZE*SIZE)*sizeof(int));
    // copying the original sites to temporary ones
    for(int i=0;i<(SIZE*SIZE);i++) {
        temp_sites[i] = sites[i];
    }

    // marking the first row site as open
    for(int i=0;i<SIZE;i++) {
        if(sites[i] == 1) {
            temp_sites[i] = 2;
        }
    }

    // loop to check all the open sites and mark the neighboring open sites in the next row
    // by changing the value from 1 to 2
    int flag = 0;
    for(int i=0;i<SIZE*(SIZE-1);i++) {
        if(temp_sites[i] == 2) {
            if(i > (SIZE-1) && temp_sites[i-SIZE] == 1) {
                temp_sites[i-SIZE] = 2;
            }
            if((i+1) % SIZE != 0 && temp_sites[i+1] == 1) {
                temp_sites[i+1] = 2;
            }
            if(i % SIZE != 0 && temp_sites[i-1] == 1) {
                temp_sites[i-1] = 2;
            }
            if(i < (SIZE*(SIZE-2)) && temp_sites[i+SIZE] == 1) {
                temp_sites[i+SIZE] = 2;
            }
        }
    }

    // checking if there is any open site in the last row
    for(int i=SIZE*(SIZE-1);i<(SIZE*SIZE);i++) {
        if(temp_sites[i] == 2) {
            flag = 1;
            break;
        }
    }

    free(temp_sites);
    return flag;
}

int main() {
    int count = 0;
    srand(time(NULL));
    int* sites = (int*)malloc((SIZE*SIZE)*sizeof(int));
    
    // randomly assigning values to the sites
    random_sites(sites);
    
    // printing the original sites
    printf("Original sites:\n");
    print_sites(sites);
    
    // checking for percolation by repeatedly checking randomly opened sites
    while(!percolate(sites)) {
        int index = rand() % (SIZE*SIZE);
        if(sites[index] == 0) {
            sites[index] = 2;
        }
        count++;
    }

    // printing the final sites
    printf("Final sites:\n");
    print_sites(sites);
    printf("Number of times site was opened to achieve percolation: %d\n", count);

    free(sites);
    return 0;
}