//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: standalone
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#define ROW 5 
#define COL 5 

// Structure to store node details
struct node 
{ 
    int row, col;
    int f, g, h; 
    struct node *parent;
}; 

// Check if the node is a valid position
bool isValid(int row, int col) 
{ 
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL); 
} 

// Check if the node is not blocked and is an open path
bool isUnBlocked(int map[][COL], int row, int col) 
{ 
    if (map[row][col] == 1) 
        return true; 
    else
        return false; 
} 

// Check if the destination is reached
bool isDestination(int row, int col, struct node* dest) 
{ 
    if (row == dest->row && col == dest->col) 
        return true; 
    else
        return false; 
} 

// Calculate heuristic cost (Manhattan Distance) from current node to destination
int heuristicCost(int row, int col, struct node* dest) 
{ 
    return abs(row - dest->row) + abs(col - dest->col);
} 

// Trace the parent node for returning the optimized path
void tracePath(struct node* dest) 
{ 
    while (dest != NULL) 
    { 
        printf("(%d,%d) ", dest->row, dest->col); 
        dest = dest->parent; 
    } 
    return; 
} 

// A* Pathfinding Algorithm function
void aStarSearch(int map[][COL], struct node* start, struct node* dest) 
{ 
    // If either the start or destination are blocked, return error
    if (!isUnBlocked(map, start->row, start->col) || !isUnBlocked(map, dest->row, dest->col)) 
    { 
        printf("Start or Destination is blocked\n"); 
        return; 
    } 

    // If start and destination are same, return error
    if (isDestination(start->row, start->col, dest)) 
    { 
        printf("You have already reached the Destination\n"); 
        return; 
    } 

    // Create open and closed lists
    bool closedList[ROW][COL]; 
    memset(closedList, false, sizeof (closedList)); 

    struct node* openList[ROW*COL]; 
    int openListCount = 0; 

    // Add the start node to open list, calculate f,g,h values
    start->f = 0; 
    start->g = 0; 
    start->h = 0; 
    start->parent = NULL; 

    openList[openListCount++] = start; 

    while (openListCount > 0) 
    { 
        // Get the node with minimum f value from open list
        struct node* curr = openList[0]; 
        int index = 0; 
        for (int i = 1; i < openListCount; i++) 
        { 
            if (openList[i]->f < curr->f) 
            { 
                curr = openList[i]; 
                index = i; 
            } 
        } 

        // Remove the current node from open list and add to closed list
        openList[index] = openList[openListCount - 1]; 
        openListCount--; 

        closedList[curr->row][curr->col] = true; 

        // Check all 8 neighbor nodes of current node
        int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
        int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

        for (int i = 0; i < 8; i++) 
        { 
            int tmpRow = curr->row + row[i]; 
            int tmpCol = curr->col + col[i]; 

            // Check if the neighbor node is a valid node
            if (isValid(tmpRow, tmpCol)) 
            { 
                // Check if the destination is reached
                if (isDestination(tmpRow, tmpCol, dest)) 
                { 
                    dest->parent = curr; 
                    tracePath(dest); 
                    return; 
                } 
                else if (!closedList[tmpRow][tmpCol] && isUnBlocked(map, tmpRow, tmpCol)) 
                { 
                    struct node* child = (struct node*)malloc(sizeof(struct node)); 
                    child->row = tmpRow; 
                    child->col = tmpCol; 
                    child->parent = curr; 
                    child->g = curr->g + 1; 
                    child->h = heuristicCost(tmpRow, tmpCol, dest); 
                    child->f = child->g + child->h; 
  
                    // Check if the child node is already in the open list
                    int ii; 
                    bool found = false;
                    for (ii = 0; ii < openListCount; ii++) 
                    { 
                        if (openList[ii]->row == child->row && openList[ii]->col == child->col) 
                        { 
                            found = true; 
                            break; 
                        } 
                    } 
  
                    // If already in open list and has lower f value, update
                    if (found && openList[ii]->f > child->f) 
                    { 
                        openList[ii]->f = child->f; 
                        openList[ii]->g = child->g; 
                        openList[ii]->h = child->h; 
                        openList[ii]->parent = curr; 
                    } 
                    // Else, add the new child node to open list
                    else if (!found) 
                    { 
                        openList[openListCount] = child; 
                        openListCount++; 
                    } 
                } 
            } 
        } 
    } 

    // If destination is not reached, return error
    printf("Destination Cannot be Reached\n"); 
    return; 
} 

int main() 
{ 
    int map[ROW][COL] = 
    { 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 0, 1}, 
        {0, 0, 0, 1, 1}, 
        {1, 1, 1, 1, 0}, 
        {1, 1, 1, 1, 1} 
    }; 

    struct node* start = (struct node*)malloc(sizeof(struct node)); 
    start->row = 0; 
    start->col = 0; 

    struct node* dest = (struct node*)malloc(sizeof(struct node)); 
    dest->row = 3; 
    dest->col = 4; 

    printf("Optimised Path: "); 
    aStarSearch(map, start, dest); 

    return 0; 
}