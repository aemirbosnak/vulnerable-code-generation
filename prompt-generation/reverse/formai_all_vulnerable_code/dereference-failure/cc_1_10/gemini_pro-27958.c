//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_ROW 5
#define MAX_COL 5

// A stack to store the path
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an item to the stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// A Queue to store the path
struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
};

// Function to create a queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to enqueue an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->array[queue->rear] = item;
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to print the maze
void printMaze(int maze[][MAX_COL]) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find the route in the maze
int findRoute(int maze[][MAX_COL], int startRow, int startCol, int endRow, int endCol) {
    // Create a stack to store the path
    struct Stack* stack = createStack(MAX_ROW * MAX_COL);

    // Create a queue to store the path
    struct Queue* queue = createQueue(MAX_ROW * MAX_COL);

    // Push the starting position to the stack
    push(stack, startRow * MAX_COL + startCol);

    // While the stack is not empty
    while (!isEmpty(stack)) {
        // Pop the top element from the stack
        int position = pop(stack);

        // Get the row and column from the position
        int row = position / MAX_COL;
        int col = position % MAX_COL;

        // If the row and column are the same as the end position, then we have found the route
        if (row == endRow && col == endCol) {
            return TRUE;
        }

        // If the row and column are not the same as the end position, then we need to check the adjacent cells
        // Check the cell to the right
        if (col + 1 < MAX_COL && maze[row][col + 1] == 0) {
            push(stack, row * MAX_COL + col + 1);
        }

        // Check the cell to the left
        if (col - 1 >= 0 && maze[row][col - 1] == 0) {
            push(stack, row * MAX_COL + col - 1);
        }

        // Check the cell below
        if (row + 1 < MAX_ROW && maze[row + 1][col] == 0) {
            push(stack, (row + 1) * MAX_COL + col);
        }

        // Check the cell above
        if (row - 1 >= 0 && maze[row - 1][col] == 0) {
            push(stack, (row - 1) * MAX_COL + col);
        }
    }

    // We have not found the route
    return FALSE;
}

int main() {
    // Create a maze
    int maze[MAX_ROW][MAX_COL] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    // Print the maze
    printMaze(maze);

    // Find the route in the maze
    int startRow = 1;
    int startCol = 1;
    int endRow = 3;
    int endCol = 3;
    int result = findRoute(maze, startRow, startCol, endRow, endCol);

    // Print the result
    if (result == TRUE) {
        printf("Route found\n");
    } else {
        printf("Route not found\n");
    }

    return 0;
}