//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Ada Lovelace
/*
 * Ada Lovelace Maze Route Finder Example Program in C
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

/*
 * Maze grid represented by 2D array
 * '0' represents open path and '1' represents blocked path
 */
int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
};

/*
* Structure to represent a point in the maze grid
*/
typedef struct Point {
    int x;
    int y;
} Point;

/*
* Structure to represent a node in the linked list
*/
typedef struct Node {
    Point point;
    struct Node* next;
} Node;

/*
* Representation of the queue
*/
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

/*
* Creates an empty queue
*/
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

/*
* Check if the queue is empty
*/
int isQueueEmpty(Queue* q) {
    return !q->front;
}

/*
* Enqueues a point in the queue
*/
void enqueue(Queue* q, Point p) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->point = p;
    newNode->next = NULL;
   
    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
}

/*
* Dequeues a point from the queue
*/
void dequeue(Queue* q) {
    if (!isQueueEmpty(q)) {
        Node* temp = q->front;
        q->front = q->front->next;
       
        if (!q->front) {
            q->rear = NULL;
        }
       
        free(temp);
    }
}

/*
* Gets the front element of the queue
*/
Point front(Queue* q) {
    return q->front->point;
}

/*
* Perform breadth first search to find the path through the maze
*/
void bfs(Point start, Point end) {
    int visited[ROWS][COLS];
    memset(visited, 0, sizeof visited);
   
    Queue* q = createQueue();
    enqueue(q, start);
    visited[start.x][start.y] = 1;
   
    while (!isQueueEmpty(q)) {
        Point p = front(q);
        dequeue(q);
       
        int x = p.x;
        int y = p.y;
       
        if (x == end.x && y == end.y) {
            printf("Path Found!\n");
            return;
        }
       
        //Check East
        if (y < COLS - 1 && maze[x][y+1] == 0 && !visited[x][y+1]) {
            visited[x][y+1] = 1;
            Point p = {x, y + 1};
            enqueue(q, p);
        }
       
        //Check South
        if (x < ROWS - 1 && maze[x+1][y] == 0 && !visited[x+1][y]) {
            visited[x+1][y] = 1;
            Point p = {x+1, y};
            enqueue(q, p);
        }
       
        //Check West
        if (y > 0 && maze[x][y-1] == 0 && !visited[x][y-1]) {
            visited[x][y-1] = 1;
            Point p = {x, y-1};
            enqueue(q, p);
        }
       
        //Check North
        if (x > 0 && maze[x-1][y] == 0 && !visited[x-1][y]) {
            visited[x-1][y] = 1;
            Point p = {x-1, y};
            enqueue(q, p);
        }
    }
   
    printf("Path not found.\n");
}

/*
* Main function
*/
int main() {
    Point start = {0, 0};
    Point end = {9, 9};
   
    bfs(start, end);
   
    return 0;
}