//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: decentralized
#include <stdio.h>

#define ROW 5
#define COL 5

typedef struct Node
{
    int row;
    int col;
    struct Node *parent;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *q, Node *node);
Node *dequeue(Queue *q);
int isValid(int row, int col, int visited[ROW][COL]);
int isDestination(int row, int col, int dest[2]);
void printPath(Node *dest);
void BFS(int maze[ROW][COL], int src[2], int dest[2]);

int main()
{
    int maze[ROW][COL] = {
        {1, 1, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 1, 1}
    };
    int src[2] = {0, 0};
    int dest[2] = {3, 4};

    BFS(maze, src, dest);

    return 0;
}

void BFS(int maze[ROW][COL], int src[2], int dest[2])
{
    int visited[ROW][COL] = {0};
    Queue q = {NULL, NULL};

    visited[src[0]][src[1]] = 1;
    Node *srcNode = (Node *) malloc(sizeof(Node));
    srcNode->row = src[0];
    srcNode->col = src[1];
    srcNode->parent = NULL;
    enqueue(&q, srcNode);

    while (q.front != NULL)
    {
        Node *currNode = dequeue(&q);
        int currRow = currNode->row;
        int currCol = currNode->col;

        if (isDestination(currRow, currCol, dest))
        {
            printf("Path found!\n");
            printPath(currNode);
            return;
        }

        if (isValid(currRow-1, currCol, visited) && maze[currRow-1][currCol])
        {
            visited[currRow-1][currCol] = 1;
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->row = currRow-1;
            newNode->col = currCol;
            newNode->parent = currNode;
            enqueue(&q, newNode);
        }

        if (isValid(currRow+1, currCol, visited) && maze[currRow+1][currCol])
        {
            visited[currRow+1][currCol] = 1;
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->row = currRow+1;
            newNode->col = currCol;
            newNode->parent = currNode;
            enqueue(&q, newNode);
        }

        if (isValid(currRow, currCol-1, visited) && maze[currRow][currCol-1])
        {
            visited[currRow][currCol-1] = 1;
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->row = currRow;
            newNode->col = currCol-1;
            newNode->parent = currNode;
            enqueue(&q, newNode);
        }

        if (isValid(currRow, currCol+1, visited) && maze[currRow][currCol+1])
        {
            visited[currRow][currCol+1] = 1;
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->row = currRow;
            newNode->col = currCol+1;
            newNode->parent = currNode;
            enqueue(&q, newNode);
        }
    }

    printf("No path found.\n");
}

int isValid(int row, int col, int visited[ROW][COL])
{
    return (row >= 0 && row < ROW && col >= 0 && col < COL && !visited[row][col]);
}

int isDestination(int row, int col, int dest[2])
{
    return (row == dest[0] && col == dest[1]);
}

void printPath(Node *dest)
{
    while (dest->parent != NULL)
    {
        printf("(%d, %d) -> ", dest->row, dest->col);
        dest = dest->parent;
    }
    printf("(%d, %d)\n", dest->row, dest->col);
}

void enqueue(Queue *q, Node *node)
{
    if (q->front == NULL)
        q->front = node;
    else
        q->rear->parent = node;

    q->rear = node;
    node->parent = NULL;
}

Node *dequeue(Queue *q)
{
    Node *temp = q->front;
    q->front = q->front->parent;
    return temp;
}