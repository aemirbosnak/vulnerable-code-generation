//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

//This is the grid where the pathfinding algorithm runs
int grid[ROW_SIZE][COL_SIZE] = 
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//Structure to represent a grid point
typedef struct Point 
{
    int x;
    int y;
} Point;

//Structure to represent a node 
typedef struct Node 
{
    int gCost;
    int hCost;
    int fCost;
    Point position;
    struct Node* parentNode;
} Node;

//This method returns the Manhattan distance between two points
int getManhattanDistance(Point point1, Point point2) 
{
    return abs(point1.x - point2.x) + abs(point1.y - point2.y);
}

//This method checks if the point is within the grid bounds
bool isPointWithinGrid(Point point) 
{
    return point.x >= 0 && point.x < ROW_SIZE && point.y >= 0 && point.y < COL_SIZE;
}

//This method checks if a point is walkable, i.e. not an obstacle
bool isWalkable(Point point) 
{
    return grid[point.x][point.y] == 0;
}

//This method retrieves the neighbours of a given point 
Point* getNeighbours(Point point) 
{
    Point* neighbours = malloc(8 * sizeof(Point));
    
    for (int i = 0; i < 8; i++) 
    {
        neighbours[i].x = point.x + (i / 3) - 1;
        neighbours[i].y = point.y + (i % 3) - 1;
    }
    
    return neighbours;
}

//This method checks if a point is in a given list of nodes
bool isPointInList(Point point, Node** list, int length) 
{
    for (int i = 0; i < length; i++) 
    {
        if (list[i] != NULL && list[i]->position.x == point.x && list[i]->position.y == point.y) 
        {
            return true;
        }
    }
    
    return false;
}

//This method finds the path from the start to the end point using A* algorithm
Point* findPath(Point start, Point end) 
{
    Node* openList[100] = {0};
    Node* closedList[100] = {0};
    
    int openListLength = 0;
    int closedListLength = 0;
    
    Node* currentNode = malloc(sizeof(Node));
    currentNode->position = start;
    currentNode->gCost = 0;
    currentNode->hCost = getManhattanDistance(start, end);
    currentNode->fCost = currentNode->gCost + currentNode->hCost;
    currentNode->parentNode = NULL;
    
    openList[openListLength++] = currentNode;
    
    while (openListLength > 0) 
    {
        //Find the node with the lowest fCost
        Node* lowestFCostNode = openList[0];
        int lowestFCostIndex = 0;
        
        for (int i = 0; i < openListLength; i++) 
        {
            if (openList[i]->fCost < lowestFCostNode->fCost) 
            {
                lowestFCostNode = openList[i];
                lowestFCostIndex = i;
            }
        }
        
        //Remove the node with the lowest fCost from the open list and add it to the closed list
        openList[lowestFCostIndex] = NULL;
        openListLength--;
        
        closedList[closedListLength++] = lowestFCostNode;
        
        //If the lowest cost node is the goal, we are done
        if (lowestFCostNode->position.x == end.x && lowestFCostNode->position.y == end.y) 
        {
            int pathLength = 0;
            Node* pathNode = lowestFCostNode;
            
            while (pathNode != NULL) 
            {
                pathLength++;
                pathNode = pathNode->parentNode;
            }
            
            Point* path = malloc((pathLength + 1) * sizeof(Point));
            pathNode = lowestFCostNode;
            
            for (int i = pathLength - 1; i >= 0; i--) 
            {
                path[i] = pathNode->position;
                pathNode = pathNode->parentNode;
            }
            
            path[pathLength] = end;
            
            return path;
        }
        
        //Get the neighbours of the lowest cost node
        Point* neighbours = getNeighbours(lowestFCostNode->position);
        
        for (int i = 0; i < 8; i++) 
        {
            Point neighbour = neighbours[i];
            int neighbourGCost = lowestFCostNode->gCost + 1;
            
            if (!isPointWithinGrid(neighbour) || !isWalkable(neighbour) || isPointInList(neighbour, closedList, closedListLength)) 
            {
                continue;
            }
            
            Node* neighbourNode = malloc(sizeof(Node));
            neighbourNode->position = neighbour;
            neighbourNode->gCost = neighbourGCost;
            neighbourNode->hCost = getManhattanDistance(neighbour, end);
            neighbourNode->fCost = neighbourNode->gCost + neighbourNode->hCost;
            neighbourNode->parentNode = lowestFCostNode;
            
            if (!isPointInList(neighbour, openList, openListLength)) 
            {
                openList[openListLength++] = neighbourNode;
            }
            else 
            {
                for (int j = 0; j < openListLength; j++) 
                {
                    if (openList[j] != NULL && openList[j]->position.x == neighbour.x && openList[j]->position.y == neighbour.y) 
                    {
                        if (neighbourNode->fCost < openList[j]->fCost) 
                        {
                            openList[j] = neighbourNode;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return NULL;
}

int main() 
{
    Point start = {4, 0};
    Point end = {9, 9};
    
    Point* path = findPath(start, end);
    
    if (path != NULL) 
    {
        printf("Path found\n");
        
        for (int i = 0; i < ROW_SIZE; i++) 
        {
            for (int j = 0; j < COL_SIZE; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    printf("# ");
                }
                else if (i == start.x && j == start.y) 
                {
                    printf("S ");
                }
                else if (i == end.x && j == end.y) 
                {
                    printf("E ");
                }
                else if (isPointInList((Point){i, j}, path, ROW_SIZE * COL_SIZE)) 
                {
                    printf("* ");
                }
                else 
                {
                    printf(". ");
                }
            }
            
            printf("\n");
        }
    }
    else 
    {
        printf("No path found\n");
    }
    
    return 0;
}