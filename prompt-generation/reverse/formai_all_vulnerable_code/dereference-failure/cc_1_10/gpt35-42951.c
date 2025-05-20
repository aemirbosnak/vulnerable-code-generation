//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5
#define START_ROW 0
#define START_COL 0
#define FINISH_ROW 4
#define FINISH_COL 4
#define BLOCKED_CHAR 'X'
#define PATH_CHAR '*'
#define NODE_EXPLORED_CHAR '.'

typedef struct Node Node;
struct Node 
{
   int row;
   int col;
   int g_cost;
   int f_cost;
   Node* parent;
};

Node* createNode(int row, int col, int g_cost, int f_cost, Node* parent) 
{
   Node* n = (Node*) malloc(sizeof(Node));
   n->row = row;
   n->col = col;
   n->g_cost = g_cost;
   n->f_cost = f_cost;
   n->parent = parent;
   return n;
}

int heuristicEstimate(int row, int col) 
{
   int x_dist = abs(col - FINISH_COL);
   int y_dist = abs(row - FINISH_ROW);
   return x_dist + y_dist;
}

Node* getLowestFCostNode(Node** openList, int openListSize) 
{
   Node* lowestFNode = openList[0];
   for(int i = 1; i < openListSize; i++) 
   {
      if(openList[i]->f_cost < lowestFNode->f_cost) 
      {
         lowestFNode = openList[i];
      }
   }
   return lowestFNode;
}

int isOnList(Node** list, int listSize, int row, int col) 
{
   for(int i = 0; i < listSize; i++) 
   {
      if(list[i]->row == row && list[i]->col == col) 
      {
         return i;
      }
   }
   return -1;
}

void reconstructPath(Node* current) 
{
   char grid[ROW][COL];
   memset(grid, ' ', ROW * COL);

   while(current != NULL) 
   {
      grid[current->row][current->col] = PATH_CHAR;
      current = current->parent;
   }

   printf("--- PATH ---\n");
   for(int row = 0; row < ROW; row++) 
   {
      for(int col = 0; col < COL; col++) 
      {
         printf("%c ", grid[row][col]);
      }
      printf("\n");
   }
}

void astar(char maze[][COL]) 
{
   int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

   Node* start = createNode(START_ROW, START_COL, 0, heuristicEstimate(START_ROW, START_COL), NULL);
   Node* openList[ROW * COL] = {start};
   int openListSize = 1;
   Node* closedList[ROW * COL] = {(Node*) malloc(sizeof(Node))};
   int closedListSize = 0;
   int pathFound = 0;

   while(openListSize > 0) 
   {
      Node* currentNode = getLowestFCostNode(openList, openListSize);

      if(currentNode->row == FINISH_ROW && currentNode->col == FINISH_COL) 
      {
         reconstructPath(currentNode);
         pathFound = 1;
         break;
      }

      int nodeIndexOnOpen = isOnList(openList, openListSize, currentNode->row, currentNode->col);
      openList[nodeIndexOnOpen] = openList[openListSize - 1];
      openListSize--;

      closedList[closedListSize] = currentNode;
      closedListSize++;

      for(int i = 0; i < 8; i++) 
      {
         int adjacentX = currentNode->col + directions[i][1];
         int adjacentY = currentNode->row + directions[i][0];

         if(adjacentX < 0 || adjacentY < 0 || adjacentX >= COL || adjacentY >= ROW) 
         {
            continue;
         }
         if(maze[adjacentY][adjacentX] == BLOCKED_CHAR) 
         {
            continue;
         }

         int neighborIndexOnOpen = isOnList(openList, openListSize, adjacentY, adjacentX);
         int neighborIndexOnClosed = isOnList(closedList, closedListSize, adjacentY, adjacentX);

         int tentative_g_cost = currentNode->g_cost + 1;
         int tentative_f_cost = tentative_g_cost + heuristicEstimate(adjacentY, adjacentX);

         if(neighborIndexOnClosed != -1 && tentative_f_cost >= closedList[neighborIndexOnClosed]->f_cost) 
         {
            continue;
         }
         if(neighborIndexOnOpen == -1 || tentative_f_cost < openList[neighborIndexOnOpen]->f_cost) 
         {
            Node* neighborNode = createNode(adjacentY, adjacentX, tentative_g_cost, tentative_f_cost, currentNode);
            if(neighborIndexOnOpen == -1) 
            {
               openList[openListSize] = neighborNode;
               openListSize++;
            } 
            else 
            {
               openList[neighborIndexOnOpen] = neighborNode;
            }
         }
      }
   }

   if(!pathFound) 
   {
      printf("No path found.\n");
   }
}

int main() 
{
   char maze[ROW][COL] = {
      {' ', 'X', 'X', ' ', ' '},
      {' ', ' ', ' ', 'X', ' '},
      {'X', ' ', 'X', ' ', ' '},
      {' ', ' ', ' ', 'X', ' '},
      {' ', 'X', ' ', ' ', ' '}
   };
   
   printf("- PARANOID A* PATHFINDING ALGORITHM EXAMPLE -\n");

   astar(maze);
   
   return 0;
}