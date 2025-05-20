//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 5
#define COLUMN 5
#define INFINITY 10000

int matrix[ROW][COLUMN] = 
{
    {0, 0, 0, 0, 0},
    {0, 0, 5, INFINITY, 0},
    {0, INFINITY, 0, 7, 9},
    {0, INFINITY, INFINITY, 0, 6},
    {0, INFINITY, INFINITY, INFINITY, 0}
};

int heuristic[ROW] = {0, 10, 9, 6, 4};

int g[ROW] = {0, INFINITY, INFINITY, INFINITY, INFINITY};

struct Node
{
    int position;
    int priority;
};
typedef struct Node Node;

struct PriorityQueue
{
    int size;
    Node *nodes;
};
typedef struct PriorityQueue PriorityQueue;

void init_priority_queue(PriorityQueue *q, int size) 
{
    q->size = 0;
    q->nodes = malloc(size * sizeof(Node));
}

void swap(Node *n1, Node *n2) 
{
    Node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void enqueue(PriorityQueue *q, int position) 
{
    Node node = { position, g[position] + heuristic[position]};
    q->nodes[q->size] = node;
    int current = q->size;
    int parent = (current - 1) / 2;
    while (q->nodes[current].priority < q->nodes[parent].priority) 
    {
        swap(&q->nodes[current], &q->nodes[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }
    q->size++;
}

int dequeue(PriorityQueue *q) 
{
    int ret = q->nodes[0].position;
    q->size--;
    q->nodes[0] = q->nodes[q->size];
    int current = 0;
    while (true) 
    {
        int leftChild = current * 2 + 1;
        int rightChild = current * 2 + 2;
        int child = -1;
        if (leftChild >= q->size) 
        {
            break;
        }
        else if (rightChild >= q->size) 
        {
            child = leftChild;
        }
        else 
        {
            child = (q->nodes[leftChild].priority < q->nodes[rightChild].priority) ? leftChild : rightChild;
        }
        if (q->nodes[current].priority > q->nodes[child].priority) 
        {
            swap(&q->nodes[current], &q->nodes[child]);
            current = child;
        }
        else 
        {
            break;
        }
    }
    return ret;
}

void print_path(const int destination) 
{
    if (g[destination] == INFINITY) 
    {
        printf("No Path!\n");
    }
    else 
    {
        int current = destination;
        while (current != 0) 
        {
            printf("%d <- ", current);
            current = matrix[current][4];
        }
        printf("0 : Cost %d\n", g[destination]);
    }
}

void A_star_algorithm(const int startNode, const int destinationNode) 
{
    PriorityQueue q;
    init_priority_queue(&q, ROW);
    enqueue(&q, startNode);
    g[startNode] = 0;
    while (q.size) 
    {
        int current = dequeue(&q);
        if (current == destinationNode) 
        {
            print_path(destinationNode);
            break;
        }
        for (int i=0; i<ROW; i++) 
        {
            if (i==current || matrix[current][i]==INFINITY) continue;
            int tentative_gScore = g[current] + matrix[current][i];
            if (tentative_gScore >= g[i]) continue;
            g[i] = tentative_gScore;
            matrix[i][4] = current;
            enqueue(&q, i);
        }
    }
    free(q.nodes);
}

int main(void) 
{
    A_star_algorithm(0,4);
    return 0;
}