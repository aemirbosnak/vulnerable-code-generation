//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

//Defining constants for the maximum rows and columns
#define ROW 10
#define COL 10

//Creating a structure for nodes
struct Node{
    int row;
    int col;
    int dist;
    struct Node* parent;
};

int maze[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//Defining functions to check the validity of the next move and whether the node is the destination or not
int isValid(int row, int col){
    if(row<0 || row>=ROW || col<0 || col>=COL) return 0;
    if(maze[row][col] == 0) return 0;
    return 1;
}

int isDestination(int row, int col, struct Node dest){
    if(row == dest.row && col == dest.col) return 1;
    return 0;
}

//Defining the function to print the optimal path
void printPath(struct Node* node){
    if(node == NULL) return;
    printPath(node->parent);
    printf("(%d,%d) ", node->row, node->col);
}

//Defining the main function
int main()
{
    //Defining the coordinates of the source and destination nodes
    struct Node src = {0, 0, 0, NULL};
    struct Node dest = {ROW-1, COL-1, 0, NULL};

    //Defining the array for the visited nodes
    int visited[ROW][COL];
    memset(visited, 0, sizeof visited);

    //Defining the array for the node directions
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    //Creating a queue for nodes
    struct Node** queue = (struct Node**) malloc(sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear] = &src;
    rear++;

    //Looping until the queue is empty
    while(front < rear){
        struct Node* curr = queue[front];
        front++;

        //If destination is found, print the optimal path and exit the program
        if(isDestination(curr->row, curr->col, dest)){
            printf("The optimal path found is\n");
            printPath(curr);
            return 0;
        }

        //Looping through all the valid neighbor nodes
        for(int i=0;i<4;i++){
            int row = curr->row + dx[i];
            int col = curr->col + dy[i];

            //Checking if the node is valid and if it has been visited before
            if(isValid(row, col) && !visited[row][col]){
                visited[row][col] = 1;

                //Creating a new node based on the current node and adding it to the queue
                struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
                newNode->row = row;
                newNode->col = col;
                newNode->parent = curr;
                newNode->dist = curr->dist + 1;

                queue = (struct Node**) realloc(queue, sizeof(struct Node*)*(rear+1));
                queue[rear] = newNode;
                rear++;
            }
        }
    }

    printf("No optimal path found!\n");

    return 0;
}