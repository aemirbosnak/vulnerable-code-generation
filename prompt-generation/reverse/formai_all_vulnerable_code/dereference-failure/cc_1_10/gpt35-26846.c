//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* Define the maze */
#define ROW 5
#define COL 5
int maze[ROW][COL] = {
    {0,1,0,0,0},
    {0,1,0,1,0},
    {0,0,0,1,0},
    {0,1,1,1,0},
    {0,0,0,0,0},
};

/* Define a structure to represent a cell in the maze */
struct Node {
    int row, col;
};

/* Define a structure to keep track of the A* search */
struct QueueNode {
    int priority;
    struct Node node;
};

/* Define a priority queue */
struct PriorityQueue {
    int size;
    int capacity;
    struct QueueNode *nodes;
};

/* Create a new node */
struct Node newNode(int row, int col) {
    struct Node node;
    node.row = row;
    node.col = col;
    return node;
}

/* Create a new queue node */
struct QueueNode newQueueNode(int priority, struct Node node) {
    struct QueueNode queueNode;
    queueNode.priority = priority;
    queueNode.node = node;
    return queueNode;
}

/* Swap two queue nodes */
void swapQueueNodes(struct QueueNode *a, struct QueueNode *b) {
    struct QueueNode temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify the priority queue */
void heapify(struct PriorityQueue *queue, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < queue->size && queue->nodes[left].priority < queue->nodes[smallest].priority) {
        smallest = left;
    }

    if (right < queue->size && queue->nodes[right].priority < queue->nodes[smallest].priority) {
        smallest = right;
    }

    if (smallest != idx) {
        swapQueueNodes(&queue->nodes[smallest], &queue->nodes[idx]);
        heapify(queue, smallest);
    }
}

/* Create a new priority queue */
struct PriorityQueue newPriorityQueue(int capacity) {
    struct PriorityQueue queue;
    queue.size = 0;
    queue.capacity = capacity;
    queue.nodes = malloc(capacity * sizeof(struct QueueNode));
    return queue;
}

/* Check if the priority queue is empty */
bool isPriorityQueueEmpty(struct PriorityQueue *queue) {
    return queue->size == 0;
}

/* Get the minimum element of the priority queue */
struct QueueNode getMin(struct PriorityQueue *queue) {
    struct QueueNode min = queue->nodes[0];
    queue->nodes[0] = queue->nodes[queue->size - 1];
    queue->size--;
    heapify(queue, 0);
    return min;
}

/* Push a node to the priority queue */
void push(struct PriorityQueue *queue, int priority, struct Node node) {
    if (queue->size == queue->capacity) {
        return;
    }
    queue->size++;
    int i = queue->size - 1;
    queue->nodes[i] = newQueueNode(priority, node);

    while (i != 0 && queue->nodes[(i - 1) / 2].priority > queue->nodes[i].priority) {
        swapQueueNodes(&queue->nodes[i], &queue->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/* Calculate the heuristic function */
int calculateHeuristic(struct Node current, struct Node goal) {
    return abs(current.row - goal.row) + abs(current.col - goal.col);
}

/* Check if the cell is valid and not blocked */
bool isValid(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 0;
}

/* Check if the goal node has been reached */
bool isGoalNode(struct Node current, struct Node goal) {
    return current.row == goal.row && current.col == goal.col;
}

/* A* Pathfinding Algorithm */
void aStarPathfinding(struct Node start, struct Node goal) {
    int rowDirection[] = {-1, 0, 0, 1};
    int colDirection[] = {0, -1, 1, 0};

    /* Create the closed set and the open set */
    bool closedSet[ROW][COL];
    memset(closedSet, false, sizeof(closedSet));
    struct PriorityQueue openSet = newPriorityQueue(ROW * COL);

    /* Add the start node to the open set */
    push(&openSet, 0, start);

    while (!isPriorityQueueEmpty(&openSet)) {
        struct QueueNode currentQueueNode = getMin(&openSet);
        struct Node current = currentQueueNode.node;

        if (isGoalNode(current, goal)) {
            printf("Goal node has been reached!\n");
            return;
        }

        closedSet[current.row][current.col] = true;

        for (int i = 0; i < 4; i++) {
            int newRow = current.row + rowDirection[i];
            int newCol = current.col + colDirection[i];

            if (isValid(newRow, newCol) && !closedSet[newRow][newCol]) {
                struct Node neighbor = newNode(newRow, newCol);
                int gScore = currentQueueNode.priority + 1;
                int fScore = gScore + calculateHeuristic(neighbor, goal);
                push(&openSet, fScore, neighbor);
            }
        }
    }

    printf("Goal node cannot be reached!\n");
}

int main() {
    struct Node start = newNode(0, 0);
    struct Node goal = newNode(ROW - 1, COL - 1);
    aStarPathfinding(start, goal);
    return 0;
}