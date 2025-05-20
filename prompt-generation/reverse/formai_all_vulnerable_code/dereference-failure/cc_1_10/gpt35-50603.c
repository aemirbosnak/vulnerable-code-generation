//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the size of the grid
#define ROW 10
#define COL 10

// define the start and end point on the grid
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

// define the max number of nodes on the grid
#define MAX_NODES ROW * COL

// define the directions for movement on the grid
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// define structure for each node on the grid
struct Node {
    int row;
    int col;
    bool visited;
    bool blocked;
    bool end;
    int cost;
    int fScore;
    int gScore;
    struct Node* parent;
};

// define function to create and initialize a node on the grid
struct Node* createNode(int row, int col) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->visited = false;
    node->blocked = false;
    node->end = (row == END_ROW && col == END_COL) ? true : false;
    node->cost = 1;
    node->fScore = 0;
    node->gScore = 0;
    node->parent = NULL;
    return node;
}

// define function to get a node on the grid given its row and column
struct Node* getNode(struct Node** grid, int row, int col) {
    return &grid[row][col];
}

// define function to initialize the grid with nodes
void initializeGrid(struct Node** grid) {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            grid[row][col] = *createNode(row, col);
        }
    }
}

// define function to print the grid
void printGrid(struct Node** grid) {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (grid[row][col].visited) {
                printf("# ");
            } else if (grid[row][col].blocked) {
                printf("X ");
            } else if (grid[row][col].end) {
                printf("E ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// define function to check if a node is a valid neighbor
bool isValidNeighbor(struct Node* node) {
    return (node->row >= 0 && node->row < ROW
        && node->col >= 0 && node->col < COL
        && !node->visited && !node->blocked);
}

// define function to get the neighbors of a node
struct Node** getNeighbors(struct Node** grid, struct Node* node, int* count) {
    struct Node** neighbors = (struct Node**) malloc(sizeof(struct Node*) * 4);
    *count = 0;

    struct Node* neighbor = getNode(grid, node->row - 1, node->col);
    if (isValidNeighbor(neighbor)) {
        neighbor->parent = node;
        neighbors[*count] = neighbor;
        (*count)++;
    }

    neighbor = getNode(grid, node->row, node->col + 1);
    if (isValidNeighbor(neighbor)) {
        neighbor->parent = node;
        neighbors[*count] = neighbor;
        (*count)++;
    }

    neighbor = getNode(grid, node->row + 1, node->col);
    if (isValidNeighbor(neighbor)) {
        neighbor->parent = node;
        neighbors[*count] = neighbor;
        (*count)++;
    }

    neighbor = getNode(grid, node->row, node->col - 1);
    if (isValidNeighbor(neighbor)) {
        neighbor->parent = node;
        neighbors[*count] = neighbor;
        (*count)++;
    }

    return neighbors;
}

// define function to calculate the cost of movement between two nodes
int calculateCost(struct Node* current, struct Node* neighbor) {
    return current->cost + neighbor->cost;
}

// define function to calculate the heuristic distance between two nodes
int calculateDistance(struct Node* node1, struct Node* node2) {
    int dx = abs(node1->row - node2->row);
    int dy = abs(node1->col - node2->col);
    return dx + dy;
}

// define function to perform A* search algorithm on the grid
void A_star(struct Node** grid) {
    // initialize start node
    struct Node* startNode = getNode(grid, START_ROW, START_COL);
    startNode->fScore = calculateDistance(startNode, getNode(grid, END_ROW, END_COL));
    startNode->visited = true;

    // initialize open and closed lists
    struct Node* openList[MAX_NODES];
    int openListCount = 1;
    openList[0] = startNode;
    struct Node* closedList[MAX_NODES];
    int closedListCount = 0;

    // loop through open list until it is empty or goal is found
    while (openListCount > 0) {
        // get node with lowest fScore from open list
        int lowestIndex = 0;
        for (int i = 1; i < openListCount; i++) {
            if (openList[i]->fScore < openList[lowestIndex]->fScore) {
                lowestIndex = i;
            }
        }
        struct Node* current = openList[lowestIndex];

        // remove current node from open list and add to closed list
        for (int i = lowestIndex; i < openListCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openListCount--;
        closedList[closedListCount++] = current;

        // if goal is found, return the path
        if (current->end) {
            printf("\nPath Found!\n");
            while (current != NULL) {
                current->visited = true;
                current = current->parent;
            }
            return;
        }

        // get neighbors of current node and calculate scores
        int neighborCount = 0;
        struct Node** neighbors = getNeighbors(grid, current, &neighborCount);
        for (int i = 0; i < neighborCount; i++) {
            struct Node* neighbor = neighbors[i];
            int tentativeGScore = current->gScore + calculateCost(current, neighbor);

            // if neighbor is already in closed list and has a lower gScore, skip it
            bool skip = false;
            for (int j = 0; j < closedListCount; j++) {
                if (closedList[j] == neighbor && tentativeGScore >= neighbor->gScore) {
                    skip = true;
                    break;
                }
            }
            if (skip) {
                continue;
            }

            // if neighbor is not in open list or has a lower gScore, add it
            bool found = false;
            for (int j = 0; j < openListCount; j++) {
                if (openList[j] == neighbor) {
                    if (tentativeGScore < neighbor->gScore) {
                        neighbor->parent = current;
                        neighbor->gScore = tentativeGScore;
                        neighbor->fScore = neighbor->gScore + calculateDistance(neighbor, getNode(grid, END_ROW, END_COL));
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                neighbor->parent = current;
                neighbor->gScore = tentativeGScore;
                neighbor->fScore = neighbor->gScore + calculateDistance(neighbor, getNode(grid, END_ROW, END_COL));
                openList[openListCount++] = neighbor;
            }
        }
    }
    printf("\nPath not found!\n");
}

int main() {
    // dynamically allocate memory for the grid
    struct Node** grid = (struct Node**) malloc(sizeof(struct Node*) * ROW);
    for (int i = 0; i < ROW; i++) {
        grid[i] = (struct Node*) malloc(sizeof(struct Node) * COL);
    }

    // initialize the grid and add obstacles
    initializeGrid(grid);
    getNode(grid, 1, 2)->blocked = true;
    getNode(grid, 2, 2)->blocked = true;
    getNode(grid, 3, 2)->blocked = true;
    getNode(grid, 4, 2)->blocked = true;
    getNode(grid, 5, 2)->blocked = true;
    getNode(grid, 6, 2)->blocked = true;
    getNode(grid, 7, 2)->blocked = true;
    getNode(grid, 8, 2)->blocked = true;
    getNode(grid, 1, 7)->blocked = true;
    getNode(grid, 2, 7)->blocked = true;
    getNode(grid, 3, 7)->blocked = true;
    getNode(grid, 4, 7)->blocked = true;
    getNode(grid, 5, 7)->blocked = true;
    getNode(grid, 6, 7)->blocked = true;
    getNode(grid, 7, 7)->blocked = true;
    getNode(grid, 8, 7)->blocked = true;

    // print the initial grid
    printf("Initial Grid:\n");
    printGrid(grid);

    // run the A* algorithm on the grid
    A_star(grid);

    // print the final grid
    printf("\nFinal Grid:\n");
    printGrid(grid);

    // free the memory allocated for the grid
    for (int i = 0; i < ROW; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}