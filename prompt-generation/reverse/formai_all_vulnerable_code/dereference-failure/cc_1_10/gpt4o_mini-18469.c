//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

// A structure to represent a cell in the grid
typedef struct {
    int x, y;
} Cell;

// A structure to represent a pathfinding node
typedef struct Node {
    Cell cell;
    int cost;
    int heuristic;
    struct Node* next;
} Node;

// A simple priority queue for nodes based on cost + heuristic
typedef struct {
    Node* head;
} PriorityQueue;

// Function declarations
void initializeQueue(PriorityQueue* queue);
void enqueue(PriorityQueue* queue, Cell cell, int cost, int heuristic);
Node* dequeue(PriorityQueue* queue);
bool isInQueue(PriorityQueue* queue, Cell cell);
int heuristic(Cell a, Cell b);
bool isValidMove(int row, int col);
void printPath(Cell parent[ROW][COL], Cell start, Cell end);
void aStar(int grid[ROW][COL], Cell start, Cell end);

// Directions for moving in the grid
int rowDir[] = {-1, 1, 0, 0}; // Up, Down
int colDir[] = {0, 0, -1, 1}; // Left, Right

int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Cell start = {0, 0}; // Starting position
    Cell end = {8, 9};   // Ending position

    aStar(grid, start, end);

    return 0;
}

// Initializes the priority queue
void initializeQueue(PriorityQueue* queue) {
    queue->head = NULL;
}

// Enqueues a cell into the priority queue
void enqueue(PriorityQueue* queue, Cell cell, int cost, int heuristic) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->cell = cell;
    newNode->cost = cost;
    newNode->heuristic = heuristic;
    newNode->next = NULL;

    if (queue->head == NULL || (cost + heuristic < queue->head->cost + queue->head->heuristic)) {
        newNode->next = queue->head;
        queue->head = newNode;
    } else {
        Node* current = queue->head;
        while (current->next != NULL && (cost + heuristic) >= (current->next->cost + current->next->heuristic)) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Dequeues a node from the priority queue
Node* dequeue(PriorityQueue* queue) {
    if (queue->head == NULL) {
        return NULL;
    }
    Node* temp = queue->head;
    queue->head = queue->head->next;
    return temp;
}

// Heuristic function estimating distance to target (Manhattan distance)
int heuristic(Cell a, Cell b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Check if the row and column are valid within grid bounds
bool isValidMove(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// Print the final path
void printPath(Cell parent[ROW][COL], Cell start, Cell end) {
    Cell current = end;
    while (current.x != start.x || current.y != start.y) {
        printf("(%d, %d) <- ", current.x, current.y);
        current = parent[current.x][current.y];
    }
    printf("(%d, %d)\n", start.x, start.y);
}

// A* Algorithm for pathfinding
void aStar(int grid[ROW][COL], Cell start, Cell end) {
    bool closedList[ROW][COL] = {false};
    Cell parent[ROW][COL];

    PriorityQueue openList;
    initializeQueue(&openList);
    enqueue(&openList, start, 0, heuristic(start, end));

    while (openList.head != NULL) {
        Node* currentNode = dequeue(&openList);
        Cell currentCell = currentNode->cell;
        free(currentNode);

        // Goal test
        if (currentCell.x == end.x && currentCell.y == end.y) {
            printPath(parent, start, end);
            return;
        }

        closedList[currentCell.x][currentCell.y] = true;

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = currentCell.x + rowDir[i];
            int newCol = currentCell.y + colDir[i];
            Cell neighbor = {newRow, newCol};

            if (isValidMove(newRow, newCol) && grid[newRow][newCol] == 0 && !closedList[newRow][newCol]) {
                if (!isInQueue(&openList, neighbor)) {
                    parent[newRow][newCol] = currentCell;
                    enqueue(&openList, neighbor, currentNode->cost + 1, heuristic(neighbor, end));
                }
            }
        }
    }
    printf("No path found\n");
}

// Check if a cell is already in the priority queue
bool isInQueue(PriorityQueue* queue, Cell cell) {
    Node* current = queue->head;
    while (current != NULL) {
        if (current->cell.x == cell.x && current->cell.y == cell.y) {
            return true;
        }
        current = current->next;
    }
    return false;
}