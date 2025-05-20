//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>

#define ROW 10
#define COL 10

// data structure to hold maze
int maze[ROW][COL] = {{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
                      {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                      {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                      {1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
                      {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                      {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                      {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                      {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

// data structure for queue
struct Node {
    int x, y, distance;
};

struct Queue {
    int front, rear;
    int size;
    struct Node *array;
};

// function to create a new queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = size - 1;
    queue->array = (struct Node*)malloc(size * sizeof(struct Node));
    return queue;
}

// check if queue is full
int isFull(struct Queue* queue) {
    return (queue->size == ROW * COL);
}

// check if queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// add item to queue
void enqueue(struct Queue* queue, struct Node item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % (ROW * COL);
    queue->array[queue->rear] = item;
    queue->size++;
}

// remove item from queue
struct Node dequeue(struct Queue* queue) {
    struct Node item = queue->array[queue->front];
    queue->front = (queue->front + 1) % (ROW * COL);
    queue->size--;
    return item;
}

// check if given cell is valid or not
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// get neighbors of given cell
void getNeighbors(int row, int col, struct Node neighbors[]) {
    int count = 0;

    // check top cell
    if (isValid(row-1, col) && maze[row-1][col]) {
        neighbors[count++] = (struct Node){row-1, col, 0};
    }

    // check bottom cell
    if (isValid(row+1, col) && maze[row+1][col]) {
        neighbors[count++] = (struct Node){row+1, col, 0};
    }

    // check left cell
    if (isValid(row, col-1) && maze[row][col-1]) {
        neighbors[count++] = (struct Node){row, col-1, 0};
    }

    // check right cell
    if (isValid(row, col+1) && maze[row][col+1]) {
        neighbors[count++] = (struct Node){row, col+1, 0};
    }

    // set remaining neighbors as invalid
    while (count <= 3) {
        neighbors[count++] = (struct Node){-1, -1, -1};
    }
}

// function to perform breadth first search and find shortest path
int BFS(int startX, int startY, int endX, int endY) {
    // check if start and end points are valid
    if (!maze[startX][startY] || !maze[endX][endY]) {
        return -1;
    }

    // create queue and add start point to it
    struct Queue* queue = createQueue(ROW * COL);  // create queue
    enqueue(queue, (struct Node){startX, startY, 0});  // add start point to queue

    // set distance of start point in maze to 0
    maze[startX][startY] = 0;

    // iterate until queue is empty
    while (!isEmpty(queue)) {
        // get front item in queue
        struct Node curr = dequeue(queue);

        // check if current node is end node
        if (curr.x == endX && curr.y == endY) {
            // free memory used by queue
            free(queue->array);
            free(queue);

            // return distance to end node
            return curr.distance;
        }

        // get neighbors of current node
        struct Node neighbors[4] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
        getNeighbors(curr.x, curr.y, neighbors);

        // iterate over all neighbors
        for (int i = 0; i < 4; i++) {
            // check if neighbor is valid
            if (neighbors[i].x == -1 || neighbors[i].y == -1) {
                continue;
            }

            // set distance of neighbor in maze to current distance + 1
            maze[neighbors[i].x][neighbors[i].y] = curr.distance + 1;

            // add neighbor to queue
            enqueue(queue, (struct Node){neighbors[i].x, neighbors[i].y, curr.distance + 1});
        }
    }

    // free memory used by queue
    free(queue->array);
    free(queue);

    // end node not found, return -1
    return -1;
}

// main function
int main() {
    int startX = 0, startY = 0, endX = 9, endY = 9;
    int distance;

    distance = BFS(startX, startY, endX, endY);

    if (distance != -1) {
        printf("Shortest path from (%d,%d) to (%d,%d) is %d\n", startX, startY, endX, endY, distance);
    } else {
        printf("No path exists from (%d,%d) to (%d,%d)\n", startX, startY, endX, endY);
    }

    return 0;
}