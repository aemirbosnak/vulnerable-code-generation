//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ROW 6
#define COL 6

typedef struct Coordinate {
    int x,y;
    struct Coordinate *parent;
} Coordinate;

typedef struct Node {
    Coordinate *coord;
    int f,g,h;
    struct Node *next;
} Node;

Node *closedList = NULL;
Node *openList = NULL;
Coordinate *start = NULL;
Coordinate *end = NULL;
Coordinate *path[ROW*COL];
int pathLen = 0;

// Function to create Coordinate object
Coordinate* createCoord(int x, int y, Coordinate *parent) {
    Coordinate *temp = (Coordinate*)malloc(sizeof(Coordinate));
    temp->x = x;
    temp->y = y;
    temp->parent = parent;
    return temp;
}

// Function to create a Node object
Node* createNode(Coordinate *coord, int f, int g, int h) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->coord = coord;
    temp->f = f;
    temp->g = g;
    temp->h = h;
    temp->next = NULL;
    return temp;
}

// Function to add node in open list
void addOpenList(Node *node) {
    if(openList == NULL) {
        openList = node;
    }
    else if(node->f < openList->f) {
        node->next = openList;
        openList = node;
    }
    else {
        Node *temp = openList;
        while(temp->next != NULL && node->f >= temp->next->f) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
}

// Function to remove node from open list
void removeOpenList(Node *node) {
    if(node == openList) {
        openList = openList->next;
    }
    else {
        Node *temp = openList;
        while(temp->next != node) {
            temp = temp->next;
        }
        temp->next = node->next;
    }
}

// Function to add node in closed list
void addClosedList(Node *node) {
    if(closedList == NULL) {
        closedList = node;
    }
    else {
        node->next = closedList;
        closedList = node;
    }
}

// Function to check if a coordinate is valid
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check if a coordinate is blocked or not
int isBlocked(int grid[][COL], int row, int col) {
    return grid[row][col] == 1;
}

// Function to check if a coordinate is in open/closed list or not
Node* isInList(Node *list, Coordinate *coord) {
    Node *temp = list;
    while(temp != NULL) {
        if(temp->coord->x == coord->x && temp->coord->y == coord->y) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to calculate heuristic distance between two coordinates
int heuristic(Coordinate *start, Coordinate *end) {
    return abs(start->x - end->x) + abs(start->y - end->y);
}

// Function to find path from start to end using A* algorithm
void aStar(int grid[][COL], int startRow, int startCol, int endRow, int endCol) {
    int i,j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            if(i == startRow && j == startCol) {
                start = createCoord(i,j,NULL);
            }
            if(i == endRow && j == endCol) {
                end = createCoord(i,j,NULL);
            }
        }
    }
    addOpenList(createNode(start, heuristic(start, end), 0, heuristic(start, end)));
    while(openList != NULL) {
        Node *current = openList;
        if(current->coord->x == end->x && current->coord->y == end->y) {
            while(current != NULL) {
                path[pathLen++] = current->coord;
                current = current->coord->parent;
            }
            return;
        }
        removeOpenList(current);
        addClosedList(current);
        int row = current->coord->x;
        int col = current->coord->y;
        int gNew, hNew, fNew;
        Coordinate *successors[8];
        for(i=-1; i<=1; i++) {
            for(j=-1; j<=1; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(isValid(row+i, col+j) && !isBlocked(grid, row+i, col+j)) {
                    successors[(i+1)*3+j+1] = createCoord(row+i, col+j, current->coord);
                }
                else {
                    successors[(i+1)*3+j+1] = NULL;
                }
            }
        }
        for(i=0; i<8; i++) {
            if(successors[i] != NULL) {
                Node *successorNode = isInList(closedList, successors[i]);
                if(successorNode != NULL) {
                    continue;
                }
                gNew = current->g + 1;
                hNew = heuristic(successors[i], end);
                fNew = gNew + hNew;
                successorNode = isInList(openList, successors[i]);
                if(successorNode == NULL) {
                    successorNode = createNode(successors[i], fNew, gNew, hNew);
                    addOpenList(successorNode);
                }
                else if(fNew < successorNode->f) {
                    successorNode->f = fNew;
                    successorNode->g = gNew;
                    successorNode->h = hNew;
                    successorNode->coord->parent = current->coord;
                }
            }
        }
    }
}

int main() {
    int grid[ROW][COL] = {
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,1,0}
    };
    aStar(grid, 0, 0, 5, 5);
    if(pathLen > 0) {
        printf("Path found from start to end:\n");
        int i;
        for(i=pathLen-1; i>=0; i--) {
            printf("(%d,%d)\n", path[i]->x, path[i]->y);
        }
    }
    else {
        printf("No path found from start to end\n");
    }
    return 0;
}