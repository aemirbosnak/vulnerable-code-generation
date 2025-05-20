//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX 100

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node* nodes;
    int size;
    int capacity;
} PriorityQueue;

typedef struct {
    float f, g, h;
    Node parent;
} NodeCost;

char grid[WIDTH][HEIGHT] = {
    { 'S', '0', '0', '0', '0', '1', '0', '1', '0', '0' },
    { '0', '0', '1', '0', '1', '0', '0', '1', '0', 'E' },
    { '1', '0', '0', '0', '1', '1', '0', '0', '0', '0' },
    { '0', '0', '1', '0', '0', '0', '1', '1', '1', '1' },
    { '0', '0', '0', '1', '0', '0', '0', '0', '0', '0' },
    { '1', '1', '0', '1', '1', '1', '1', '1', '1', '1' },
    { '0', '0', '0', '0', '0', '0', '0', 'E', '0', '0' },
    { '0', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
    { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
    { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' }
};

float heuristic(Node a, Node b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

PriorityQueue* create_priority_queue(int capacity) {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->nodes = malloc(sizeof(Node) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void destroy_priority_queue(PriorityQueue* pq) {
    free(pq->nodes);
    free(pq);
}

void push(PriorityQueue* pq, Node node) {
    if (pq->size < pq->capacity) {
        pq->nodes[pq->size++] = node;
    }
}

Node pop(PriorityQueue* pq) {
    Node minNode = pq->nodes[0];
    int minIndex = 0;

    for (int i = 1; i < pq->size; i++) {
        if (pq->nodes[i].x + pq->nodes[i].y < minNode.x + minNode.y) {
            minNode = pq->nodes[i];
            minIndex = i;
        }
    }

    pq->nodes[minIndex] = pq->nodes[--pq->size]; // Remove the node
    return minNode;
}

bool in_open_set(Node* list, int size, Node node) {
    for (int i = 0; i < size; i++) {
        if (list[i].x == node.x && list[i].y == node.y) {
            return true;
        }
    }
    return false;
}

bool in_closed_set(Node* list, int size, Node node) {
    for (int i = 0; i < size; i++) {
        if (list[i].x == node.x && list[i].y == node.y) {
            return true;
        }
    }
    return false;
}

void print_path(Node* path, int path_size) {
    for (int i = 0; i < path_size; i++) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

void a_star(Node start, Node end) {
    PriorityQueue* openSet = create_priority_queue(MAX);
    Node closedSet[MAX];
    int closedCount = 0;
    
    NodeCost costs[WIDTH][HEIGHT] = {0};
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            costs[i][j].f = costs[i][j].g = costs[i][j].h = INFINITY;

    costs[start.x][start.y].g = 0;
    costs[start.x][start.y].h = heuristic(start, end);
    costs[start.x][start.y].f = costs[start.x][start.y].g + costs[start.x][start.y].h;

    push(openSet, start);

    while (openSet->size > 0) {
        Node current = pop(openSet);
        
        if (current.x == end.x && current.y == end.y) {
            Node path[MAX];
            int path_size = 0;

            for (Node temp = end; temp.x != start.x || temp.y != start.y; temp = costs[temp.x][temp.y].parent) {
                path[path_size++] = temp;
            }
            path[path_size++] = start;

            for (int i = path_size - 1; i >= 0; i--) {
                printf("Path: ");
                print_path(path + i, path_size - i);
            }
            destroy_priority_queue(openSet);
            return;
        }

        closedSet[closedCount++] = current;

        Node neighbors[4] = {
            {current.x, current.y - 1},
            {current.x, current.y + 1},
            {current.x - 1, current.y},
            {current.x + 1, current.y}
        };

        for (int i = 0; i < 4; i++) {
            Node neighbor = neighbors[i];
            
            if (neighbor.x < 0 || neighbor.x >= WIDTH || neighbor.y < 0 || neighbor.y >= HEIGHT) continue;
            if (grid[neighbor.x][neighbor.y] == '1') continue; // Blocked

            if (in_closed_set(closedSet, closedCount, neighbor)) continue;

            float tentative_g = costs[current.x][current.y].g + 1;

            if (!in_open_set(openSet->nodes, openSet->size, neighbor)) {
                push(openSet, neighbor);
            } else if (tentative_g >= costs[neighbor.x][neighbor.y].g) {
                continue;
            }

            costs[neighbor.x][neighbor.y].parent = current;
            costs[neighbor.x][neighbor.y].g = tentative_g;
            costs[neighbor.x][neighbor.y].h = heuristic(neighbor, end);
            costs[neighbor.x][neighbor.y].f = costs[neighbor.x][neighbor.y].g + costs[neighbor.x][neighbor.y].h;
        }
    }
    
    printf("No path found\n");
    destroy_priority_queue(openSet);
}

int main() {
    Node start = {0, 0}; // Start at 'S'
    Node end = {1, 9};   // End at 'E'
    
    a_star(start, end);
    
    return 0;
}