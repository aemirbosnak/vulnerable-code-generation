//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

// define struct for each node on the grid
typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node* parent;
} node;

// define the start and end points
node* start;
node* end;

// define the map grid
int map[ROW][COL] = {
  {0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,0,0}
};

// function to calculate the Manhattan distance (heuristic)
int heuristic(node* current) {
    return abs(current->x - end->x) + abs(current->y - end->y);
}

// function to calculate the path using A* algorithm
void aStar() {
    node* openList[ROW*COL];
    node* closedList[ROW*COL];
    int openCount = 0;
    int closedCount = 0;
    int i, j, k;

    // add the start node to the open list
    start->f = 0;
    start->g = 0;
    start->h = heuristic(start);
    openList[openCount++] = start;

    // loop through the open list until it is empty or the end node is found
    while (openCount > 0) {
        // find the node with the lowest f value in the open list
        int lowestIndex = 0;
        for (i = 0; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        // get the current node and remove it from the open list
        node* current = openList[lowestIndex];

        if (current == end) {
            // the end node has been found, so backtrace the path
            node* path[ROW*COL];
            node* temp = current;
            int pathCount = 0;

            while (temp != NULL) {
                path[pathCount++] = temp;
                temp = temp->parent;
            }

            printf("Path: ");
            for (i = pathCount-1; i >= 0; i--) {
                printf("(%d,%d) ", path[i]->x, path[i]->y);
            }
            return;
        }

        // remove the current node from the open list and add it to the closed list
        for (i = lowestIndex; i < openCount-1; i++) {
            openList[i] = openList[i+1];
        }
        openCount--;
        closedList[closedCount++] = current;

        // check all the neighbor nodes
        for (i = current->x-1; i <= current->x+1; i++) {
            for (j = current->y-1; j <= current->y+1; j++) {
                if (i >= 0 && i < ROW && j >= 0 && j < COL) {
                    if (map[i][j] != 1) { // if the neighbor node is not a wall
                        int isClosed = 0;
                        for (k = 0; k < closedCount; k++) {
                            if (closedList[k]->x == i && closedList[k]->y == j) {
                                isClosed = 1;
                                break;
                            }
                        }
                        if (isClosed == 0) {
                            node* neighbor = malloc(sizeof(node));
                            neighbor->x = i;
                            neighbor->y = j;
                            neighbor->g = current->g + 1;
                            neighbor->h = heuristic(neighbor);
                            neighbor->f = neighbor->g + neighbor->h;
                            neighbor->parent = current;

                            int isOpen = 0;
                            for (k = 0; k < openCount; k++) {
                                if (openList[k]->x == neighbor->x && openList[k]->y == neighbor->y) {
                                    isOpen = 1;
                                    if (neighbor->g < openList[k]->g) {
                                        openList[k]->g = neighbor->g;
                                        openList[k]->f = neighbor->g + openList[k]->h;
                                        openList[k]->parent = neighbor->parent;
                                    }
                                    break;
                                }
                            }
                            if (isOpen == 0) {
                                openList[openCount++] = neighbor;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("No path found!\n");
}

int main() {
    // set the start and end points
    start = malloc(sizeof(node));
    start->x = 1;
    start->y = 1;

    end = malloc(sizeof(node));
    end->x = 8;
    end->y = 8;

    // calculate the path using A* algorithm
    aStar();

    return 0;
}