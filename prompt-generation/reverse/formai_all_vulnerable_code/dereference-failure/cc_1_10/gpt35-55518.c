//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROW 6
#define COL 10

int a[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node *parent;
} node;

node *openList[ROW*COL];
node *closedList[ROW*COL];

int openListCount = 0;
int closedListCount = 0;

node *startNode;
node *endNode;

void initAStar()
{
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            node *n = (node*)malloc(sizeof(node));
            n->x = i;
            n->y = j;
            n->f = 0;
            n->g = 0;
            n->h = 0;
            n->parent = NULL;
            
            if (a[i][j] == 1){
                openList[openListCount] = n;
                openListCount++;
            }
        }
    }
    
    startNode = openList[0];
    endNode = openList[45];
}

node *getNodeWithLowestF()
{
    int lowestF = openList[0]->f;
    int index = 0;
    
    for (int i = 1; i < openListCount; i++){
        if (openList[i]->f < lowestF){
            lowestF = openList[i]->f;
            index = i;
        }
    }
    
    node *n = openList[index];
    
    for (int i = index; i < openListCount - 1; i++){
        openList[i] = openList[i+1];
    }
    
    openListCount--;
    
    return n;
}

int isNodeInList(node *n, node **list, int count)
{
    for (int i = 0; i < count; i++){
        if (list[i] == n){
            return 1;
        }
    }
    
    return 0;
}

int getGScore(node *n)
{
    int g = 0;
    
    while (n->parent != NULL){
        g++;
        n = n->parent;
    }
    
    return g;
}

int getHScore(node *n)
{
    int d = abs(n->x - endNode->x) + abs(n->y - endNode->y);
    
    return d;
}

void addToOpenList(node *n, node *current)
{
    n->parent = current;
    n->g = getGScore(n);
    n->h = getHScore(n);
    n->f = n->g + n->h;
    openList[openListCount] = n;
    openListCount++;
}

void addToClosedList(node *n)
{
    closedList[closedListCount] = n;
    closedListCount++;
}

int isValidNode(node *n, node *current)
{
    if (n == NULL || n == current || a[n->x][n->y] == 0 || isNodeInList(n, closedList, closedListCount)){
        return 0;
    }
    
    return 1;
}

void printPath(node *n)
{
    if (n == NULL){
        return;
    }
    
    printPath(n->parent);
    printf("(%d, %d) ", n->x, n->y);
}

void aStar()
{
    node *current = startNode;
    
    while (current != endNode){
        if (openListCount == 0){
            printf("Path not found\n");
            return;
        }
        
        current = getNodeWithLowestF();
        addToClosedList(current);
        
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                if (i == 0 && j == 0){
                    continue;
                }
                
                int x = current->x + i;
                int y = current->y + j;
                
                if (isValidNode(openList[x*COL+y], current)){
                    addToOpenList(openList[x*COL+y], current);
                }
            }
        }
    }
    
    printf("Path found: ");
    printPath(endNode);
}

int main()
{
    initAStar();
    aStar();
    
    return 0;
}