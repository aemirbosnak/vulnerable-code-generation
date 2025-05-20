//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROWS 6
#define COLS 9

/* Define the start and end points for the algorithm */
int startRow = 0;
int startCol = 0;
int endRow = 5;
int endCol = 8;

/* Define the map for pathfinding */
int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0}};

/* Define node structure for the algorithm */
struct node {
  int row, col;
  int f, g, h;
  struct node *parent;
};

/* Initialize the open and closed lists */
struct node* openList[ROWS*COLS];
int openListCount = 0;
struct node* closedList[ROWS*COLS];
int closedListCount = 0;

/**
 * Function to check if a given node is in the closed list
 */
bool isInClosedList(int row, int col) {
  for(int i = 0; i < closedListCount; i++) {
    if(closedList[i]->row == row && closedList[i]->col == col) {
      return true;
    }
  }
  return false;
}

/**
 * Function to check if a given node is in the open list
 */
struct node* isInOpenList(int row, int col) {
  for(int i = 0; i < openListCount; i++) {
    if(openList[i]->row == row && openList[i]->col == col) {
      return openList[i];
    }
  }
  return NULL;
}

/**
 * Function to calculate the H value of a given node - the estimated distance to the goal node based on Manhattan distance
 */
int heuristic(int row, int col) {
  return abs(row - endRow) + abs(col - endCol);
}

/**
 * Function to add a node to the open list in order
 */
void addToOpenList(struct node* newNode) {
  int i;
  for(i = 0; i < openListCount; i++) {
    if(openList[i]->f >= newNode->f) {
      break;
    }
  }
  for(int j = openListCount; j > i; j--) {
    openList[j] = openList[j-1];
  }
  openList[i] = newNode;
  openListCount++;
}

/**
 * Function to find the best node in the open list based on its F value and remove it from the open list
 */
struct node* getBestNodeFromOpenList() {
  struct node* bestNode = openList[0];
  int bestIndex = 0;
  for(int i = 1; i < openListCount; i++) {
    if(openList[i]->f < bestNode->f) {
      bestNode = openList[i];
      bestIndex = i;
    }
  }
  for(int j = bestIndex; j < openListCount-1; j++) {
    openList[j] = openList[j+1];
  }
  openListCount--;
  return bestNode;
}

/**
 * Function to print the path from the start to end node
 */
void printPath(struct node* endNode) {
  struct node* currentNode = endNode;
  printf("\nPath:\n");
  while(currentNode) {
    printf("  row: %d, col: %d\n", currentNode->row, currentNode->col);
    currentNode = currentNode->parent;
  }
}

/**
 * Function to run the A* algorithm
 */
void AStar() {

  // Initialize start and end nodes
  struct node* startNode = (struct node*) malloc(sizeof(struct node));
  startNode->row = startRow;
  startNode->col = startCol;
  startNode->parent = NULL;
  startNode->g = 0;
  startNode->h = heuristic(startRow, startCol);
  startNode->f = startNode->g + startNode->h;

  struct node* endNode = (struct node*) malloc(sizeof(struct node));
  endNode->row = endRow;
  endNode->col = endCol;
  endNode->parent = NULL;
  endNode->g = INT_MAX;
  endNode->h = 0;
  endNode->f = endNode->g + endNode->h;

  // Add start node to the open list
  addToOpenList(startNode);

  while(openListCount > 0) {
    // Get the best node from the open list
    struct node* currentNode = getBestNodeFromOpenList();

    // Check if we have reached the end node
    if(currentNode->row == endRow && currentNode->col == endCol) {
      printPath(currentNode);
      break;
    }

    // Add the current node to the closed list
    closedList[closedListCount++] = currentNode;

    // Check neighboring nodes
    for(int dx = -1; dx <= 1; dx++) {
      for(int dy = -1; dy <= 1; dy++) {
        int newRow = currentNode->row + dx;
        int newCol = currentNode->col + dy;

        // Skip nodes outside the map or on the diagonal
        if(newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS || (dx != 0 && dy != 0)) {
          continue;
        }

        // Skip nodes that are obstacles
        if(map[newRow][newCol] == 0) {
          continue;
        }

        // Calculate the G value of the new node
        int newG = currentNode->g + abs(dx) + abs(dy);

        // Check if the node is already in the closed list
        if(isInClosedList(newRow, newCol)) {
          continue;
        }

        // Get the node (if in the open list) or create a new node
        struct node* newNode = isInOpenList(newRow, newCol);
        if(!newNode) {
          newNode = (struct node*) malloc(sizeof(struct node));
          newNode->row = newRow;
          newNode->col = newCol;
          newNode->parent = currentNode;
          newNode->h = heuristic(newRow, newCol);
        }

        // Check if the new path is shorter and update the node accordingly
        if(newG < newNode->g) {
          newNode->g = newG;
          newNode->f = newNode->g + newNode->h;
          newNode->parent = currentNode;

          // Add the new node to the open list
          if(!isInOpenList(newRow, newCol)) {
            addToOpenList(newNode);
          }
        }
      }
    }
  }
}

int main() {
  AStar();
  return 0;
}