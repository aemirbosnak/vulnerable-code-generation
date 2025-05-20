//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10

#define OBSTACLE 'X'
#define START 'S'
#define DESTINATION 'D'
#define EMPTY '_'

typedef struct Node{
    int x, y;
    int g, h, f;
    struct Node* parent;
}Node;

int manhattanDist(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

Node* createNode(int x, int y, int g, int h, Node* parent){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    newNode->parent = parent;
    return newNode;
}

int isValid(int x, int y, char grid[ROW][COL]){
    if (x >= 0 && y >= 0 && x < ROW && y < COL && grid[x][y]==EMPTY)
        return 1;
    return 0;
}

void printGrid(char grid[ROW][COL]){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void printPath(Node* destNode, char grid[ROW][COL]){
    Node* temp = destNode;
    while (temp != NULL){
        grid[temp->x][temp->y] = 'P';
        temp = temp->parent;
    }
    printGrid(grid);
}

Node* aStarSearch(char grid[ROW][COL], int startX, int startY, int destX, int destY){
    int xDir[4] = {1, -1, 0, 0};
    int yDir[4] = {0, 0, 1, -1};

    Node* startNode = createNode(startX, startY, 0, manhattanDist(startX, startY, destX, destY), NULL);

    int foundDest = 0;

    Node* openList[ROW*COL];
    Node* closedList[ROW*COL];
    int openListSize = 1;
    openList[0] = startNode;
    int closedListSize = 0;

    while (openListSize > 0){
        Node* currentNode = openList[0];
        int currentIndex = 0;

        for (int i = 0; i < openListSize; i++){
            if (openList[i]->f < currentNode->f){
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        openListSize--;

        Node* temp = openList[currentIndex];
        openList[currentIndex] = openList[openListSize];
        openList[openListSize] = temp;

        closedList[closedListSize++] = currentNode;

        if (currentNode->x == destX && currentNode->y == destY){
            foundDest = 1;
            return currentNode;
        }

        for (int i = 0; i < 4; i++){
            int new_x = currentNode->x + xDir[i];
            int new_y = currentNode->y + yDir[i];
            int new_g = currentNode->g + 1;
            int new_h = manhattanDist(new_x, new_y, destX, destY);
            int new_f = new_g + new_h;

            if (isValid(new_x, new_y, grid)){
                Node* newNode = createNode(new_x, new_y, new_g, new_h, currentNode);
                int isOpen = 0;
                int isClosed = 0;

                for (int j = 0; j < closedListSize; j++){
                    if (newNode->x == closedList[j]->x && newNode->y == closedList[j]->y){
                        isClosed = 1;
                        break;
                    }
                }

                for (int j = 0; j < openListSize; j++){
                    if (newNode->x == openList[j]->x && newNode->y == openList[j]->y){
                        isOpen = 1;
                        if (newNode->g < openList[j]->g){
                            openList[j]->g = newNode->g;
                            openList[j]->h = newNode->h;
                            openList[j]->f = newNode->f;
                            openList[j]->parent = newNode->parent;
                        }
                        break;
                    }
                }

                if (!isOpen && !isClosed){
                    openList[openListSize++] = newNode;
                }
            }
        }
    }

    if (!foundDest){
        printf("No path found");
        return NULL;
    }
}

int main(){
    char grid[ROW][COL] = {
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY},
        {OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY},
        {EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, OBSTACLE, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, OBSTACLE, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {OBSTACLE, EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, OBSTACLE, DESTINATION, EMPTY, EMPTY, EMPTY},
        {EMPTY, OBSTACLE, OBSTACLE, OBSTACLE, EMPTY, EMPTY, OBSTACLE, OBSTACLE, EMPTY, OBSTACLE},
        {EMPTY, OBSTACLE, EMPTY, OBSTACLE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}
    };

    int startX = 0, startY = 0, destX = 7, destY = 6;
    Node* finalNode = aStarSearch(grid, startX, startY, destX, destY);
    printPath(finalNode, grid);

    return 0;
}