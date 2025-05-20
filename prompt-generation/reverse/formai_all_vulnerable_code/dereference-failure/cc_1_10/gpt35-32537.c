//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLOSED 0
#define OPEN 1

typedef struct disjoint_set{
    int parent;
    int size;
}disjoint_set_t;

//to get index in 1D array
int get_index(int x, int y, int size_y){
    return x*size_y + y;
}

//initialize a new set
void make_set(disjoint_set_t *set, int index){
    set[index].parent = index;
    set[index].size = 1;
}

//find the root of the set
int find(disjoint_set_t *set, int index){
    while(index != set[index].parent){
        //path compression
        set[index].parent = set[set[index].parent].parent;
        index = set[index].parent;
    }
    return index;
}

//check if two cells are in the same set
int is_connected(disjoint_set_t *set, int p, int q){
    return (find(set, p) == find(set, q));
}

//unify two sets into one
void union_set(disjoint_set_t *set, int p, int q){
    int root_p = find(set, p);
    int root_q = find(set, q);

    if(root_p == root_q)
        return;
    
    //balance by size
    if(set[root_p].size < set[root_q].size){
        set[root_p].parent = root_q;
        set[root_q].size += set[root_p].size;
    }
    else{
        set[root_q].parent = root_p;
        set[root_p].size += set[root_q].size;
    }
}

//initialize the grid
void initialize_grid(int **grid, int size_x, int size_y){
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_y;j++){
            grid[i][j] = CLOSED;
        }
    }
}

//print the grid
void print_grid(int **grid, int size_x, int size_y){
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_y;j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//randomly open n cells
void random_open(int **grid, int size_x, int size_y, int n){
    int count = 0;

    while(count<n){
        int x = rand()%size_x;
        int y = rand()%size_y;

        if(grid[x][y] == CLOSED){
            grid[x][y] = OPEN;
            count++;
        }
    }

}

//initialize all disjoint sets
void initialize_sets(disjoint_set_t *set, int size_x, int size_y){
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_y;j++){
            int index = get_index(i, j, size_y);
            make_set(set, index);
        }
    }
}

//connect a cell with its open neighbors
void connect_neighbors(disjoint_set_t *set, int **grid, int x, int y, int size_x, int size_y){
    int index = get_index(x, y, size_y);

    if(grid[x][y] == CLOSED)
        return;

    //check left neighbor
    if(y-1 >= 0 && grid[x][y-1] == OPEN){
        union_set(set, index, get_index(x, y-1, size_y));
    }

    //check right neighbor
    if(y+1 < size_y && grid[x][y+1] == OPEN){
        union_set(set, index, get_index(x, y+1, size_y));
    }

    //check top neighbor
    if(x-1 >= 0 && grid[x-1][y] == OPEN){
        union_set(set, index, get_index(x-1, y, size_y));
    }

    //check bottom neighbor
    if(x+1 < size_x && grid[x+1][y] == OPEN){
        union_set(set, index, get_index(x+1, y, size_y));
    }
}

//check if the grid percolates
int percolates(disjoint_set_t *set, int size_x, int size_y){
    for(int j=0;j<size_y;j++){
        if(is_connected(set, get_index(0, j, size_y), get_index(size_x-1, j, size_y))){
            return 1;
        }
    }
    return 0;
}

int main(){

    int size_x = 10;
    int size_y = 10;
    int n = 30;

    int **grid = (int **)malloc(size_x*sizeof(int *));
    for(int i=0;i<size_x;i++){
        grid[i] = (int *)malloc(size_y*sizeof(int));
    }

    disjoint_set_t *set = (disjoint_set_t *)malloc(size_x*size_y*sizeof(disjoint_set_t));

    //initialize random seed
    srand(time(NULL));
    
    //initialize the grid
    initialize_grid(grid, size_x, size_y);

    //randomly open cells
    random_open(grid, size_x, size_y, n);

    //initialize sets
    initialize_sets(set, size_x, size_y);

    //connect neighbors
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_y;j++){
            connect_neighbors(set, grid, i, j, size_x, size_y);
        }
    }

    //print the grid
    print_grid(grid, size_x, size_y);

    //check if the grid percolates
    printf("Percolates: %d\n", percolates(set, size_x, size_y));

    for(int i=0;i<size_x;i++){
        free(grid[i]);
    }
    free(grid);
    free(set);

    return 0;
}