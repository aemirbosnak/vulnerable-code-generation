//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int x, y;
    struct Node *parent;
    int g, h;
} Node;

typedef struct PriorityQueue {
    int size;
    struct Node **data;
} PriorityQueue;

PriorityQueue *init_priority_queue(int capacity) {
    PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->data = (Node **) malloc(sizeof(Node *) * capacity);
    return pq;
}

void push_priority_queue(PriorityQueue *pq, Node *node) {
    pq->data[pq->size] = node;
    pq->size++;
    int i = pq->size - 1;
    Node *temp;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->data[i]->g + pq->data[i]->h < pq->data[parent]->g + pq->data[parent]->h) {
            temp = pq->data[i];
            pq->data[i] = pq->data[parent];
            pq->data[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

Node *pop_priority_queue(PriorityQueue *pq) {
    if (pq->size == 0) {
        return NULL;
    }
    Node *result = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    int i = 0;
    Node *temp;
    while (i < pq->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min_index = i;
        if (left < pq->size && pq->data[left]->g + pq->data[left]->h < pq->data[min_index]->g + pq->data[min_index]->h) {
            min_index = left;
        }
        if (right < pq->size && pq->data[right]->g + pq->data[right]->h < pq->data[min_index]->g + pq->data[min_index]->h) {
            min_index = right;
        }
        if (min_index == i) {
            break;
        }
        temp = pq->data[i];
        pq->data[i] = pq->data[min_index];
        pq->data[min_index] = temp;
        i = min_index;
    }
    return result;
}

int main() {
    // Initialize the map and the start and goal positions
    int map[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    Node *start = (Node *) malloc(sizeof(Node));
    start->x = 1;
    start->y = 1;
    Node *goal = (Node *) malloc(sizeof(Node));
    goal->x = 8;
    goal->y = 8;

    // Initialize the priority queue
    PriorityQueue *pq = init_priority_queue(100);

    // Initialize the open and closed sets
    int open_set[10][10];
    int closed_set[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            open_set[i][j] = 0;
            closed_set[i][j] = 0;
        }
    }
    open_set[start->x][start->y] = 1;

    // Loop until the goal is reached or the open set is empty
    while (pq->size > 0) {
        // Get the node with the lowest f-score from the open set
        Node *current = pop_priority_queue(pq);

        // If the current node is the goal, then the path has been found
        if (current->x == goal->x && current->y == goal->y) {
            // Backtrack from the goal to the start to get the path
            Node *path[100];
            int path_length = 0;
            while (current != NULL) {
                path[path_length] = current;
                path_length++;
                current = current->parent;
            }

            // Print the path
            for (int i = path_length - 1; i >= 0; i--) {
                printf("(%d, %d)\n", path[i]->x, path[i]->y);
            }

            break;
        }

        // Add the current node to the closed set
        closed_set[current->x][current->y] = 1;

        // Get the neighbors of the current node
        Node *neighbors[4];
        neighbors[0] = (Node *) malloc(sizeof(Node));
        neighbors[0]->x = current->x + 1;
        neighbors[0]->y = current->y;
        neighbors[1] = (Node *) malloc(sizeof(Node));
        neighbors[1]->x = current->x - 1;
        neighbors[1]->y = current->y;
        neighbors[2] = (Node *) malloc(sizeof(Node));
        neighbors[2]->x = current->x;
        neighbors[2]->y = current->y + 1;
        neighbors[3] = (Node *) malloc(sizeof(Node));
        neighbors[3]->x = current->x;
        neighbors[3]->y = current->y - 1;

        // Loop through the neighbors of the current node
        for (int i = 0; i < 4; i++) {
            // Check if the neighbor is valid and not in the closed set
            if (neighbors[i]->x >= 0 && neighbors[i]->x < 10 && neighbors[i]->y >= 0 && neighbors[i]->y < 10 && map[neighbors[i]->x][neighbors[i]->y] == 0 && closed_set[neighbors[i]->x][neighbors[i]->y] == 0) {
                // Calculate the g-score and h-score of the neighbor
                neighbors[i]->g = current->g + 1;
                neighbors[i]->h = abs(neighbors[i]->x - goal->x) + abs(neighbors[i]->y - goal->y);

                // If the neighbor is not in the open set, then add it to the open set
                if (open_set[neighbors[i]->x][neighbors[i]->y] == 0) {
                    open_set[neighbors[i]->x][neighbors[i]->y] = 1;
                    neighbors[i]->parent = current;
                    push_priority_queue(pq, neighbors[i]);
                }
            }
        }
    }

    // If the goal was not reached, then there is no path
    if (pq->size == 0) {
        printf("No path found.\n");
    }

    // Free the memory used by the priority queue, the open set, and the closed set
    for (int i = 0; i < pq->size; i++) { free(pq->data[i]); }
    free(pq);
    return 0;
}