//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
    int flag; // used for checking if given cell has percolated
    int val;  // value inside current cell (0 or 1)
};

void display(int n, struct node *arr) {
    printf("\n\t\tGRID STATE\n");
    for(int i=0; i<n*n; i++) {
        if(i%n==0) printf("\n");
        if(arr[i].flag) printf("\t!"); // perculated cell
        else if(arr[i].val) printf("\t*"); //open path
        else printf("\t#"); // blocked path
    }
    printf("\n");
}

//root_index() returns index of the root element for given element index
int root_index(int i, int *parent) {
    while(parent[i]!=i)
        i = parent[i];
    return i;
}

//perculate() takes 2 indices i and j, union their roots for amalgamation
void perculate(int i, int j, int *parent) {
    int p = root_index(i, parent);
    int q = root_index(j, parent);
    if(p!=q)
        parent[q] = p;
}

//Amalgamation only possible between open cells - returns -1 if not possible
int linkable(int i, int j, int *parent, struct node *arr) {
    if(arr[i].val==0 || arr[j].val==0) //blocked cell
        return -1;
    if(root_index(i, parent)==root_index(j, parent)) // already belongs to same cluster
        return -1;
    return 1;
}

int percolation(int n) {
    int count = 0; // maintains number of cells that have perculated
    struct node *grid = malloc(n*n*sizeof(struct node)); //memory allocation
    int *parent = malloc(n*n*sizeof(int)); //memory allocation for array parent[] for union-find
    
    //init grid with values of all cells as zero
    for(int i=0; i<n*n; i++) {
        grid[i].flag = 0;
        grid[i].val = 0;
    }

    //generating values of cells randomly (0 or 1)
    srand(time(NULL));
    for(int i=0; i<n*n; i++)
        grid[i].val = rand()%2;

    // Initializing array parent[] with index values
    for(int i=0; i<n*n; i++)
        parent[i] = i;

    //linking cells, unlil a path is formed between 1st & last cell
    int connected = 0;
    while(!connected) {
        int i = rand()%(n*n);
        int j = rand()%(n*n);
        if(linkable(i,j,parent,grid) != -1) {
            perculate(i, j, parent);
            if(root_index(0, parent)==root_index(n*n-1, parent))
                connected = 1;
        }
        count++; // incrementing the count of perculated cells
        grid[root_index(i, parent)].flag = 1; // marking the cells that have perculated
        grid[root_index(j, parent)].flag = 1;
    }

    display(n, grid); // display grid

    printf("SIZE OF GRID : %dx%d\n\n", n, n);
    printf("TOTAL CELLS : %d\n", n*n);
    printf("PERCOLATED CELL COUNT : %d\n", count);
    printf("PERCOLATION PROBABILITY : %.3f%%\n\n", (float)count/(n*n)*100);

    free(grid); //freeing memory
    free(parent); //freeing memory
}

int main() {
    int n;
    printf("Enter size of grid (integer) : ");
    scanf("%d", &n);
    percolation(n);
    return 0;
}