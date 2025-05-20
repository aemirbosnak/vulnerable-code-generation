//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define INF 9999

// Struct to hold coordinates
typedef struct {
    int x, y;
} Coordinate;

// Graph structure
typedef struct {
    int grid[MAX][MAX];
    int rows, cols;
} Graph;

// Function to create a new graph
Graph* createGraph(int rows, int cols) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->rows = rows;
    newGraph->cols = cols;
    return newGraph;
}

// Initialize the grid with weights (0 for free path, >0 for obstacles or weighted path)
void initializeGraph(Graph* graph) {
    int grid[MAX][MAX] = {
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0}
    };
    memcpy(graph->grid, grid, sizeof(graph->grid));
}

// Check if the coordinate is within bounds
int isWithinBounds(int x, int y, Graph* graph) {
    return (x >= 0 && x < graph->rows && y >= 0 && y < graph->cols);
}

// A* algorithm to find path from start to goal
int aStar(Graph* graph, Coordinate start, Coordinate goal) {
    int cost[MAX][MAX];
    memset(cost, INF, sizeof(cost));
    cost[start.x][start.y] = 0;

    int closed[MAX][MAX] = {0};
    
    Coordinate queue[MAX * MAX];
    int front = 0, rear = 0;
    
    queue[rear++] = start;

    while (front < rear) {
        Coordinate current = queue[front++];
        
        if (current.x == goal.x && current.y == goal.y) {
            printf("Path found!\n");
            return 1;
        }

        closed[current.x][current.y] = 1;

        // Possible moves (right, left, down, up)
        Coordinate directions[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

        for (int i = 0; i < 4; i++) {
            Coordinate next;
            next.x = current.x + directions[i].x;
            next.y = current.y + directions[i].y;

            if (isWithinBounds(next.x, next.y, graph) && 
                graph->grid[next.x][next.y] == 0 && 
                closed[next.x][next.y] == 0) {
                
                int newCost = cost[current.x][current.y] + 1; // constant cost
                if (newCost < cost[next.x][next.y]) {
                    cost[next.x][next.y] = newCost;
                    queue[rear++] = next;
                }
            }
        }
    }

    printf("No path found!\n");
    return 0;
}

// Main function
int main() {
    int rows = 10;
    int cols = 10;

    // Create and initialize graph
    Graph* graph = createGraph(rows, cols);
    initializeGraph(graph);

    // Define start and goal coordinates
    Coordinate start = {0, 0};
    Coordinate goal = {9, 9};

    // Run A* pathfinding
    aStar(graph, start, goal);

    // Cleanup
    free(graph);
    return 0;
}