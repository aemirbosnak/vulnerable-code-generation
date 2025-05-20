//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// define the maze
int maze[ROWS][COLS] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
  { 0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
  { 0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
  { 0, 1, 1, 1, 0, 0, 1, 0, 1, 0},
  { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
  { 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

typedef struct node {
  int x, y;
  int f, g, h;
  struct node* parent;
} node;

node* openSet[ROWS*COLS];
int openSetSize = 0;
bool closedSet[ROWS][COLS];

node* start;
node* goal;

node* newNode(int x, int y, node* parent) {
  node* n = (node*) malloc(sizeof(node));
  n->x = x;
  n->y = y;
  n->f = n->g = n->h = 0;
  n->parent = parent;
  return n;
}

int heuristic(node* n) {
  return abs(n->x - goal->x) + abs(n->y - goal->y);
}

void calculateScores(node* n) {
  n->g = n->parent->g + 1;
  n->h = heuristic(n);
  n->f = n->g + n->h;
}

void updateOpenSet(node* n) {
  int i, j;
  for(i=0; i<openSetSize; i++) {
    if(openSet[i] == n) return;
  }
  openSet[openSetSize++] = n;
}

node* getLowestFScore() {
  node* lowest = openSet[0];
  int i;
  for(i=1; i<openSetSize; i++) {
    if(openSet[i]->f < lowest->f) {
      lowest = openSet[i];
    }
  }
  return lowest;
}

void removeFromOpenSet(node* n) {
  int i,j;
  for(i=0; i<openSetSize; i++) {
    if(openSet[i] == n) {
      for(j=i; j<openSetSize-1; j++) {
        openSet[j] = openSet[j+1];
      }
      openSetSize--;
      return;
    }
  }
}

void printMaze() {
  int i, j;
  printf("\n");
  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      if(maze[i][j] == 0) printf("\u2588\u2588");
      else if(maze[i][j] == 1) printf("  ");
      else if(maze[i][j] == 2) printf("**");
    }
    printf("\n");
  }
}

void reconstructPath(node* n) {
  if(n->parent == NULL) return;
  maze[n->x][n->y] = 2;
  reconstructPath(n->parent);
}

void aStar() {
  int i, j;
  openSet[0] = start;
  openSetSize = 1;

  while(openSetSize != 0) {
    node* current = getLowestFScore();
    if(current == goal) {
      reconstructPath(current);
      return;
    }

    removeFromOpenSet(current);
    closedSet[current->x][current->y] = true;

    int x = current->x;
    int y = current->y;

    // check all the adjacent squares
    for(i=-1; i<=1; i++) {
      for(j=-1; j<=1; j++) {
        if(i == 0 && j == 0) continue; // ignore current node
        if(x+i<0 || x+i>=ROWS || y+j<0 || y+j>=COLS) continue; // ignore out-of-bounds node
        if(maze[x+i][y+j] == 0 || closedSet[x+i][y+j] == true) continue; // ignore blocked nodes
        node* adjNode = newNode(x+i, y+j, current);
        calculateScores(adjNode);
        updateOpenSet(adjNode);
      }
    }
  }
}

int main() {
  start = newNode(1, 1, NULL);
  goal = newNode(8, 8, NULL);
  aStar();
  printMaze();
  
  return 0;
}