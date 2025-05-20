//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#define ROW 10
#define COL 10

typedef struct {
    int x, y;
} Cell;

typedef struct {
    int row, col;
    int **maze;
    int **visited;
} Block;

typedef struct {
    Cell parent;
    double F;
    double G;
    double H;
} Node;

typedef struct {
    Node *array;
    int maxSize;
    int currentSize;
} PriorityQueue;

Block b = {
    ROW, COL,
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    },
    NULL
};

void display();
void initializeVisited();
PriorityQueue initializeQueue(int size);
void enqueue(Node n, PriorityQueue *queue);
Node dequeue(PriorityQueue *queue);
void swap(Node *n1, Node *n2);
void sortQueue(PriorityQueue *queue);
int isBlocked(int row, int col);
int isGoal(int row, int col);
double getHCost(int row, int col);
double getGCost(int row, int col, Cell parent);
int hasVisited(int row, int col);
void markVisited(int row, int col);
void pathfinding(Cell start, Cell goal);
Node createNode(Cell parent, double F, double G, double H);

int main() {
    b.visited = malloc(sizeof(int*) * ROW);
    for (int i = 0; i < ROW; i++) {
        b.visited[i] = malloc(sizeof(int) * COL);
    }
    initializeVisited();
    display();
    pathfinding((Cell){1, 1}, (Cell){8, 8});
    return 0;
}

void display() {
    putchar('\n');
    for (int i = 0; i < b.row; i++) {
        for (int j = 0; j < b.col; j++) {
            if (isBlocked(i, j)) {
                printf("#");
            } else {
                putchar('-');
            }
        }
        putchar('\n');
    }
}

void initializeVisited() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            b.visited[i][j] = 0;
        }
    }
}

PriorityQueue initializeQueue(int size) {
    PriorityQueue queue;
    queue.maxSize = size;
    queue.currentSize = 0;
    queue.array = malloc(sizeof(Node) * size);
    return queue;
}

void enqueue(Node n, PriorityQueue *queue) {
    if (queue->currentSize == queue->maxSize) {
        return; //queue is full, cannot add any more nodes
    }
    queue->array[queue->currentSize] = n;
    queue->currentSize++;
}

Node dequeue(PriorityQueue *queue) {
    if (queue->currentSize == 0) {
        return (Node){(Cell){-1, -1}, -1, -1, -1}; //queue is empty
    }
    Node n = queue->array[0];
    for (int i = 0; i < queue->currentSize - 1; i++) {
        queue->array[i] = queue->array[i + 1];
    }
    queue->currentSize--;
    return n;
}

void swap(Node *n1, Node *n2) {
    Node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void sortQueue(PriorityQueue *queue) {
    for (int i = 0; i < queue->currentSize - 1; i++) {
        for (int j = i + 1; j < queue->currentSize; j++) {
            if (queue->array[i].F > queue->array[j].F) {
                swap(&queue->array[i], &queue->array[j]);
            }
        }
    }
}

int isBlocked(int row, int col) {
    return b.maze[row][col] == 1;
}

int isGoal(int row, int col) {
    return row == b.row - 2 && col == b.col - 2;
}

double getHCost(int row, int col) {
    //heuristic value is the Manhattan distance between the current cell and the goal cell
    return abs(row - b.row + 2) + abs(col - b.col + 2);
}

double getGCost(int row, int col, Cell parent) {
    //actual cost from the start cell to the current cell
    int dx = row - parent.x;
    int dy = col - parent.y;
    double cost = pow(dx, 2) + pow(dy, 2);
    return sqrt(cost);
}

int hasVisited(int row, int col) {
    return b.visited[row][col] == 1;
}

void markVisited(int row, int col) {
    b.visited[row][col] = 1;
}

void pathfinding(Cell start, Cell goal) {
    PriorityQueue openList = initializeQueue(ROW * COL);
    PriorityQueue closedList = initializeQueue(ROW * COL);
    Node parentNode = createNode((Cell){-1, -1}, 0, 0, 0);
    Node startNode = createNode(start, 0, 0, getHCost(start.x, start.y));
    enqueue(startNode, &openList);
    while (openList.currentSize > 0) {
        Node currentNode = dequeue(&openList);
        if (isGoal(currentNode.parent.x, currentNode.parent.y)) {
            printf("\nPath found!\n");
            return;
        }
        enqueue(currentNode, &closedList);
        int row = currentNode.parent.x;
        int col = currentNode.parent.y;
        double gCost = currentNode.G;
        markVisited(row, col);
        //generate neighbors of current cell
        Cell neighbors[] = {(Cell){row - 1, col}, (Cell){row + 1, col}, (Cell){row, col - 1}, (Cell){row, col + 1}};
        for (int i = 0; i < 4; i++) {
            Cell neighbor = neighbors[i];
            if (!isBlocked(neighbor.x, neighbor.y) && !hasVisited(neighbor.x, neighbor.y)) {
                double gCostNeighbor = gCost + getGCost(neighbor.x, neighbor.y, currentNode.parent);
                double hCostNeighbor = getHCost(neighbor.x, neighbor.y);
                double fCostNeighbor = gCostNeighbor + hCostNeighbor;
                Node neighborNode = createNode(neighbor, fCostNeighbor, gCostNeighbor, hCostNeighbor);
                int foundInOpenList = 0;
                for (int j = 0; j < openList.currentSize; j++) {
                    if (openList.array[j].parent.x == neighbor.x && openList.array[j].parent.y == neighbor.y) {
                        foundInOpenList = 1;
                        if (openList.array[j].F > fCostNeighbor) {
                            openList.array[j] = neighborNode;
                        }
                        break;
                    }
                }
                if (!foundInOpenList) {
                    int foundInClosedList = 0;
                    for (int j = 0; j < closedList.currentSize; j++) {
                        if (closedList.array[j].parent.x == neighbor.x && closedList.array[j].parent.y == neighbor.y) {
                            foundInClosedList = 1;
                            if (closedList.array[j].F > fCostNeighbor) {
                                closedList.array[j] = neighborNode;
                            }
                            break;
                        }
                    }
                    if (!foundInClosedList) {
                        enqueue(neighborNode, &openList);
                    }
                }
            }
        }
        //sort openList by F score
        sortQueue(&openList);
    }
    printf("\nNo path found\n");
}

Node createNode(Cell parent, double F, double G, double H) {
    return (Node){parent, F, G, H};
}