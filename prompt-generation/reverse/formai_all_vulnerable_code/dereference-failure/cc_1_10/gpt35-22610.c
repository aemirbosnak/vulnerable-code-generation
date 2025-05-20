//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROW 8
#define COL 8

// Structure representing a node in the graph
typedef struct node {
    int x, y;      // Node coordinates
    int f, g, h;   // Cost functions
    struct node *parent;  // Parent node
} node;

// Utility function to check if a node is inside the maze
int isInsideMaze(int x, int y)
{
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Utility function to check if a node is not blocked
int isNotBlocked(int maze[][COL], int x, int y)
{
    return maze[x][y] == 0;
}

// Utility function to check if a node is the destination node
int isDestination(int x, int y, node *dest)
{
    return (x == dest->x && y == dest->y);
}

// Utility function to calculate the heuristic value between
// the current node and the destination node using the Manhattan distance
int calculateHeuristic(node *current, node *dest)
{
    return abs(current->x - dest->x) + abs(current->y - dest->y);
}

// Utility function to add adjacent nodes to the open list
void addAdjacentNodes(node *current, node *openList[], int *openListSize, int closedList[][COL], int maze[][COL], node *dest)
{
    int x, y, newG, newH, newF;

    // Generate adjacent nodes
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++) {
        x = current->x + row[i];
        y = current->y + col[i];

        // Check if adjacent node is inside the maze and not blocked
        if (isInsideMaze(x, y) && isNotBlocked(maze, x, y)) {
            node *adjacent = malloc(sizeof(node));
            adjacent->x = x;
            adjacent->y = y;
            adjacent->parent = current;

            // Calculate cost functions
            newG = current->g + 1;
            newH = calculateHeuristic(adjacent, dest);
            newF = newG + newH;

            // Add adjacent node to open list if it's not already in the closed list or open list
            if (closedList[x][y] == 0) {
                adjacent->g = newG;
                adjacent->h = newH;
                adjacent->f = newF;
                openList[*openListSize] = adjacent;
                (*openListSize)++;
            } else {
                free(adjacent);  // Free memory if node is already in the closed list
            }
        }
    }
}

// Utility function to print the maze with path
void printMazeWithPath(int maze[][COL], node *path)
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                if (path != NULL && path->x == i && path->y == j) {
                    printf("* ");  // Node in path
                } else {
                    printf(". ");  // Empty node
                }
            } else {
                printf("# ");  // Blocked node
            }
        }
        printf("\n");
    }
}

// Main function implementing A* Pathfinding Algorithm
void findPath(int maze[][COL], node *start, node *dest)
{
    // Initialize open list and add start node
    int openListSize = 0;
    node *openList[ROW * COL] = {NULL};
    start->g = 0;
    start->h = calculateHeuristic(start, dest);
    start->f = start->g + start->h;
    openList[openListSize++] = start;

    // Initialize closed list
    int closedList[ROW][COL] = {0};

    // Loop until the open list is empty or the destination node is found
    while (openListSize > 0) {
        // Get node with the lowest f value from the open list
        node *current = openList[0];
        int currentIdx = 0;
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < current->f) {
                current = openList[i];
                currentIdx = i;
            }
        }

        // Remove current node from the open list and add it to the closed list
        openList[currentIdx] = openList[--openListSize];
        closedList[current->x][current->y] = 1;

        // If the current node is the destination node, print the path and return
        if (isDestination(current->x, current->y, dest)) {
            printf("Path found!\n");
            printMazeWithPath(maze, current);
            return;
        }

        // Generate adjacent nodes and add them to the open list
        addAdjacentNodes(current, openList, &openListSize, closedList, maze, dest);
    }

    // If the destination node was not found and the open list is empty, print "Path not found"
    printf("Path not found.\n");
}

// Driver function
int main()
{
    int maze[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };

    // Initialize start and destination nodes
    node *start = malloc(sizeof(node));
    start->x = 0;
    start->y = 0;
    node *dest = malloc(sizeof(node));
    dest->x = 7;
    dest->y = 7;

    // Find the path from start to destination node
    findPath(maze, start, dest);

    return 0;
}