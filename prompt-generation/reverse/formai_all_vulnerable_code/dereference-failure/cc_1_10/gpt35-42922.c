//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing tuple in priority queue
typedef struct {
    int priority;
    int x;
    int y;
} Tuple;

// Helper function to swap two tuples
void swap(Tuple* a, Tuple* b){
    Tuple temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the priority queue
void min_heapify(Tuple* arr, int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].priority < arr[smallest].priority)
        smallest = left;
    if (right < n && arr[right].priority < arr[smallest].priority)
        smallest = right;
    if (smallest != i){
        swap(&arr[i], &arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

// Function to extract the minimum priority element from the priority queue
Tuple extract_min(Tuple* arr, int* n){
    Tuple min = arr[0];
    arr[0] = arr[(*n)-1];
    (*n)--;
    min_heapify(arr, *n, 0);
    return min;
}

// Function to update priority of an element in the priority queue
void decrease_priority(Tuple* arr, int index, int new_priority){
    arr[index].priority = new_priority;
    while (index > 0 && arr[(index-1)/2].priority > arr[index].priority){
        swap(&arr[index], &arr[(index-1)/2]);
        index = (index-1)/2;
    }
}

// Function to print the path from start to destination
void print_path(int** path, int rows, int cols, int start_x, int start_y, int dest_x, int dest_y){
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Deny thy father and refuse thy name;\n");
    printf("Or, if thou wilt not, be but sworn my love,\n");
    printf("And I'll no longer be a Capulet.\n\n");
    
    int x = dest_x;
    int y = dest_y;
    int length = 0;
    while (x != start_x || y != start_y){
        length++;
        int temp_x = x;
        x = path[temp_x][y] / cols;
        y = path[temp_x][y] % cols;
    }
    printf("By yonder blessed moon I swear\n");
    printf("That tips with silver all these fruit-tree tops,\n");
    printf("And let me see thy shirt that I may tear,\n");
    printf("Out of thy love's poor shirt, a band to wear.\n\n");
    
    printf("The path is as follows:\n");
    while (x != dest_x || y != dest_y){
        printf("Move horizontally %d units and vertically %d units\n", (x < path[x][y]/cols ? 1 : -1) * (path[x][y]/cols - x), (y < path[x][y]%cols ? 1 : -1) * (path[x][y]%cols - y));
        int temp_x = x;
        x = path[temp_x][y] / cols;
        y = path[temp_x][y] % cols;
    }
    printf("\nGood Night, Good night! Parting is such sweet sorrow,\n");
    printf("That I shall say good night till it be morrow.\n");
    printf("Length of the path is %d units.\n", length);
}

// Function to find the shortest path in the maze
void shortest_path(int** maze, int rows, int cols, int start_x, int start_y, int dest_x, int dest_y){
    Tuple* queue = (Tuple*) malloc(rows*cols*sizeof(Tuple));
    int queue_size = 0;
    
    int** distance = (int**) malloc(rows*sizeof(int*));
    int** path = (int**) malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++){
        distance[i] = (int*) malloc(cols*sizeof(int));
        path[i] = (int*) malloc(cols*sizeof(int));
        for (int j = 0; j < cols; j++){
            distance[i][j] = -1;
        }
    }

    queue[queue_size].priority = 0;
    queue[queue_size].x = start_x;
    queue[queue_size].y = start_y;
    distance[start_x][start_y] = 0;
    queue_size++;

    while (queue_size > 0){
        Tuple current = extract_min(queue, &queue_size);
        int x = current.x;
        int y = current.y;
        if (x == dest_x && y == dest_y){
            print_path(path, rows, cols, start_x, start_y, dest_x, dest_y);
            return;
        }

        if (x > 0 && maze[x-1][y] != 1 && distance[x-1][y] == -1){
            int new_distance = distance[x][y] + 1;
            queue[queue_size].priority = new_distance;
            queue[queue_size].x = x-1;
            queue[queue_size].y = y;
            queue_size++;
            distance[x-1][y] = new_distance;
            path[x-1][y] = x*cols + y;
        }

        if (y > 0 && maze[x][y-1] != 1 && distance[x][y-1] == -1){
            int new_distance = distance[x][y] + 1;
            queue[queue_size].priority = new_distance;
            queue[queue_size].x = x;
            queue[queue_size].y = y-1;
            queue_size++;
            distance[x][y-1] = new_distance;
            path[x][y-1] = x*cols + y;
        }

        if (x < rows-1 && maze[x+1][y] != 1 && distance[x+1][y] == -1){
            int new_distance = distance[x][y] + 1;
            queue[queue_size].priority = new_distance;
            queue[queue_size].x = x+1;
            queue[queue_size].y = y;
            queue_size++;
            distance[x+1][y] = new_distance;
            path[x+1][y] = x*cols + y;
        }

        if (y < cols-1 && maze[x][y+1] != 1 && distance[x][y+1] == -1){
            int new_distance = distance[x][y] + 1;
            queue[queue_size].priority = new_distance;
            queue[queue_size].x = x;
            queue[queue_size].y = y+1;
            queue_size++;
            distance[x][y+1] = new_distance;
            path[x][y+1] = x*cols + y;
        }
    }
    printf("O, swear not by the moon, th' inconstant moon,\n");
    printf("That monthly changes in her circled orb,\n");
    printf("Lest that thy love prove likewise variable.\n");
}

int main(){
    int rows = 7;
    int cols = 14;

    // Initialize Maze
    int maze[7][14] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0}
    };

    shortest_path((int**) maze, rows, cols, 1, 2, 6, 11);
    return 0;
}