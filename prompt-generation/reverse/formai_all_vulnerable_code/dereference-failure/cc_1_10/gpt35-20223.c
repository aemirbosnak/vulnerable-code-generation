//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct Node {
    int x, y;
    struct Node *parent;
    bool isObstacle;
    bool isVisited;
    double f, g, h;
} Node;

typedef struct List {
    Node *node;
    struct List *next;
} List;

double heuristic(Node *start, Node *end) {
    int dx = abs(start->x - end->x);
    int dy = abs(start->y - end->y);
    return sqrt(dx * dx + dy * dy);
}

Node* createNode(int x, int y) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = NULL;
    node->isObstacle = false;
    node->isVisited = false;
    node->f = node->g = node->h = 0;
    return node;
}

void addNode(List **list, Node *node) {
    List *newNode = (List*) malloc(sizeof(List));
    newNode->node = node;
    newNode->next = *list;
    *list = newNode;
}

void freeList(List *list) {
    while (list != NULL) {
        List *tmp = list->next;
        free(list);
        list = tmp;
    }
}

bool hasNode(List *list, Node *node) {
    while (list != NULL) {
        if (list->node == node) {
            return true;
        }
        list = list->next;
    }
    return false;
}

Node* findLowestF(List *list) {
    Node *minNode = list->node;
    List *tmp = list;
    while (tmp != NULL) {
        if (tmp->node->f < minNode->f) {
            minNode = tmp->node;
        }
        tmp = tmp->next;
    }
    return minNode;
}

List* removeNode(List *list, Node *node) {
    if (list == NULL) {
        return NULL;
    }
    if (list->node == node) {
        List *tmp = list->next;
        free(list);
        return tmp;
    }
    list->next = removeNode(list->next, node);
    return list;
}

void printPath(Node *node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d, %d)\n", node->x, node->y);
}

int main() {
    Node *start = createNode(0, 0);
    Node *end = createNode(5, 8);

    Node *grid[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = createNode(i, j);
        }
    }

    // Add obstacles
    grid[2][1]->isObstacle = true;
    grid[2][2]->isObstacle = true;
    grid[2][3]->isObstacle = true;
    grid[2][4]->isObstacle = true;
    grid[2][5]->isObstacle = true;
    grid[2][6]->isObstacle = true;
    grid[2][7]->isObstacle = true;

    List *openList = NULL;
    List *closedList = NULL;
    addNode(&openList, start);

    while (openList != NULL) {
        Node *current = findLowestF(openList);
        if (current == end) {
            printf("Path Found!\n");
            printPath(current);
            break;
        }
        openList = removeNode(openList, current);
        addNode(&closedList, current);

        // Explore neighbors
        for (int i = current->x - 1; i <= current->x + 1; i++) {
            for (int j = current->y - 1; j <= current->y + 1; j++) {
                if (i >= 0 && i < ROW && j >= 0 && j < COL) {
                    Node *neighbor = grid[i][j];
                    if (neighbor != current && !neighbor->isVisited && !neighbor->isObstacle) {
                        neighbor->g = current->g + 1;
                        neighbor->h = heuristic(neighbor, end);
                        neighbor->f = neighbor->g + neighbor->h;
                        neighbor->parent = current;
                        if (hasNode(openList, neighbor)) {
                            Node *openNode = openList->node;
                            if (neighbor->g < openNode->g) {
                                openNode->g = neighbor->g;
                                openNode->h = neighbor->h;
                                openNode->f = openNode->g + openNode->h;
                                openNode->parent = neighbor->parent;
                            }
                        } else {
                            addNode(&openList, neighbor);
                        }
                    }
                }
            }
        }
        current->isVisited = true;
    }

    freeList(openList);
    freeList(closedList);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            free(grid[i][j]);
        }
    }

    free(start);
    free(end);

    return 0;
}