//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8 //number of rows in the graph
#define COLS 8 //number of columns in the graph
#define START_ROW 1 //start node row index
#define START_COL 1 //start node column index
#define END_ROW 6 //end node row index
#define END_COL 6 //end node column index

//node struct to represent each cell in the graph
typedef struct Node {
    int row, col; //row and column index of the cell
    int g, h, f; //cost values for A* algorithm
    struct Node* parent; //pointer to parent node in the path
} Node;

//function to initialize a new node
Node* newNode(int row, int col) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->g = 0; //initial cost to reach this node
    node->h = abs(row - END_ROW) + abs(col - END_COL); //estimated cost to reach the end node
    node->f = node->g + node->h; //total cost
    node->parent = NULL;
    return node;
}

//function to check if given node is a valid cell in the graph
int isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

//function to check if given node is either blocked or already visited
int isBlocked(int grid[ROWS][COLS], int row, int col, int visited[ROWS][COLS]) {
    return (grid[row][col] == 1 || visited[row][col] == 1);
}

//function to find the shortest path using A* algorithm
void AStar(int grid[ROWS][COLS]) {
    //initialize start and end nodes
    Node* start = newNode(START_ROW, START_COL);
    Node* end = newNode(END_ROW, END_COL);
    
    //initialize open and closed lists
    Node* openList[ROWS * COLS] = { NULL }; //max possible size of open list
    Node* closedList[ROWS * COLS] = { NULL }; //max possible size of closed list
    
    //initialize visited array to keep track of visited cells
    int visited[ROWS][COLS] = { 0 };
    
    //add start node to open list
    int openCount = 1;
    openList[0] = start;
    
    //loop until end node is found or open list is empty
    while (openCount > 0) {
        //find the node with lowest 'f' value in open list
        int minIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[minIndex]->f) {
                minIndex = i;
            }
        }
        
        //get the node with lowest 'f' value
        Node* current = openList[minIndex];
        
        //if end node is found, print the path and return
        if (current->row == end->row && current->col == end->col) {
            printf("Path: ");
            Node* node = current;
            while (node != NULL) {
                printf("(%d,%d) ", node->row, node->col);
                node = node->parent;
            }
            printf("\n");
            return;
        }
        
        //remove current from open list and add to closed list
        openList[minIndex] = openList[openCount - 1];
        openCount--;
        closedList[current->row * COLS + current->col] = current;
        
        //check all the neighbors of current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int row = current->row + i;
                int col = current->col + j;
                
                //skip current node and out of bounds nodes
                if (i == 0 && j == 0 || !isValid(row, col)) {
                    continue;
                }
                
                //skip blocked or visited nodes
                if (isBlocked(grid, row, col, visited)) {
                    continue;
                }
                
                //calculate cost to reach neighbor node
                int g = current->g + abs(i) + abs(j);
                
                //if neighbor is already in open list, update its cost value
                Node* neighbor = NULL;
                for (int k = 0; k < openCount; k++) {
                    if (openList[k]->row == row && openList[k]->col == col) {
                        neighbor = openList[k];
                        break;
                    }
                }
                
                //if neighbor is already in closed list, skip it
                if (neighbor == NULL) {
                    for (int k = 0; k < ROWS * COLS; k++) {
                        if (closedList[k] != NULL && closedList[k]->row == row && closedList[k]->col == col) {
                            neighbor = closedList[k];
                            break;
                        }
                    }
                }
                
                //if neighbor is not in any list, add it to open list
                if (neighbor == NULL) {
                    neighbor = newNode(row, col);
                    neighbor->g = g;
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current;
                    openList[openCount] = neighbor;
                    openCount++;
                }
                //if neighbor is already in open list, update its values if new path is shorter
                else if (g < neighbor->g) {
                    neighbor->g = g;
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current;
                }
            }
        }
        
        //mark current node as visited (only after checking all its neighbors)
        visited[current->row][current->col] = 1;
    }
    
    //if end node is not found, print message
    printf("No path found.\n");
}

int main() {
    //initialize 2D array to represent the graph
    int grid[ROWS][COLS] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 1, 0, 0 },
        { 0, 1, 0, 0, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 1, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    
    //find shortest path using A* algorithm
    AStar(grid);
    
    return 0;
}