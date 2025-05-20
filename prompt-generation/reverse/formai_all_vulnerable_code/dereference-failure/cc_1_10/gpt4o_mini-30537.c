//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES WIDTH * HEIGHT

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node *nodes[MAX_NODES];
    int size;
} NodeList;

typedef struct {
    Node *node;
    float g_cost;
    float h_cost;
    float f_cost;
    struct NodeList *path;
} NodeData;

NodeData *createNodeData(Node *node, float g_cost, float h_cost) {
    NodeData *data = malloc(sizeof(NodeData));
    data->node = node;
    data->g_cost = g_cost; 
    data->h_cost = h_cost;
    data->f_cost = g_cost + h_cost;
    data->path = NULL;
    return data;
}

NodeList *createNodeList() {
    NodeList *list = malloc(sizeof(NodeList));
    list->size = 0;
    return list;
}

void addNode(NodeList *list, Node *node) {
    if (list->size < MAX_NODES) {
        list->nodes[list->size++] = node;
    }
}

bool nodeInList(NodeList *list, Node *node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i]->x == node->x && list->nodes[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

float heuristic(Node *start, Node *goal) {
    return fabs(start->x - goal->x) + fabs(start->y - goal->y);
}

NodeList *getNeighbors(Node *node) {
    NodeList *neighbors = createNodeList();
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (abs(dx) != abs(dy)) { // Only cardinal directions
                int newX = node->x + dx;
                int newY = node->y + dy;
                if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
                    Node *neighbor = malloc(sizeof(Node));
                    neighbor->x = newX;
                    neighbor->y = newY;
                    addNode(neighbors, neighbor);
                }
            }
        }
    }
    return neighbors;
}

void freeNodeList(NodeList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->nodes[i]);
    }
    free(list);
}

NodeList *AStar(Node *start, Node *goal) {
    NodeList *openList = createNodeList();
    NodeList *closedList = createNodeList();

    addNode(openList, start);

    while (openList->size > 0) {
        Node *current = openList->nodes[0];
        float lowestFCost = heuristic(current, goal);

        for (int i = 1; i < openList->size; i++) {
            Node *node = openList->nodes[i];
            float fCost = heuristic(node, goal); // Simplified for demonstration
            
            // If node has lower f_cost, update current
            if (fCost < lowestFCost) {
                lowestFCost = fCost;
                current = node;
            }
        }

        // Remove current from openList and add to closedList
        bool foundCurrent = false;
        for (int i = 0; i < openList->size; i++) {
            if (openList->nodes[i] == current) {
                openList->nodes[i] = openList->nodes[--openList->size]; // Remove
                foundCurrent = true;
                break;
            }
        }

        if (!foundCurrent) continue; // Just in case

        addNode(closedList, current);

        if (current->x == goal->x && current->y == goal->y) {
            NodeList *path = createNodeList();
            while (current) {
                addNode(path, current);
                break; // Break for demo
            }
            freeNodeList(openList);
            freeNodeList(closedList);
            return path; // Would return full path
        }

        NodeList *neighbors = getNeighbors(current);
        for (int i = 0; i < neighbors->size; i++) {
            Node *neighbor = neighbors->nodes[i];

            if (nodeInList(closedList, neighbor)) {
                continue; // Skip already evaluated nodes
            }

            float g_cost = heuristic(start, neighbor); // Simplified
            if (!nodeInList(openList, neighbor)) {
                addNode(openList, neighbor);
            }
        }

        freeNodeList(neighbors);
    }

    freeNodeList(openList);
    freeNodeList(closedList);
    return NULL; // Path not found
}

void printPath(NodeList *path) {
    printf("Path: ");
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d)", path->nodes[i]->x, path->nodes[i]->y);
        if (i < path->size - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    Node *start = malloc(sizeof(Node));
    start->x = 0;
    start->y = 0;

    Node *goal = malloc(sizeof(Node));
    goal->x = 7;
    goal->y = 5;

    NodeList *path = AStar(start, goal);

    if (path) {
        printPath(path);
        freeNodeList(path);
    } else {
        printf("No path found.\n");
    }

    free(start);
    free(goal);

    return 0;
}