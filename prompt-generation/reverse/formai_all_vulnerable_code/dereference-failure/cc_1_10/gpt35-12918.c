//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10
#define INF 9999

// Structure to store the coordinates of a point
struct Point {
  int x;
  int y;
};

// Structure to store details of a particular point/node
struct Node {
  struct Point point; // Coordinates of the Node
  int f, g, h; // f = g + h; g = cost from starting cell to current cell; h = heuristic cost
  struct Node* parent; // Parent of the current Node
  int visited; // Flag to store if the Node has been visited or not
  int obstacle; // Flag to store if the Node is occupied by an obstacle or not
};

// Function to create a new Node with given details
struct Node* newNode(int x, int y) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->point.x = x;
  node->point.y = y;
  node->f = INF;
  node->g = INF;
  node->h = INF;
  node->parent = NULL;
  node->visited = 0;
  node->obstacle = 0;
  return node;
}

// Function to initialize the grid
void initializeGrid(struct Node* grid[][COL]) {
  for(int i=0; i<ROW; i++) {
    for(int j=0; j<COL; j++) {
      grid[i][j] = newNode(i, j);
    }
  }
  grid[0][2]->obstacle = 1;
  grid[1][2]->obstacle = 1;
  grid[2][2]->obstacle = 1;
  grid[3][2]->obstacle = 1;
  grid[4][2]->obstacle = 1;
  grid[5][2]->obstacle = 1;
  grid[6][2]->obstacle = 1;
  grid[7][2]->obstacle = 1;
  grid[8][2]->obstacle = 1;
  grid[9][2]->obstacle = 1;
}

// Function to calculate the euclidean distance between two points
int calculateDistance(struct Point p1, struct Point p2) {
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return (int)sqrt(dx*dx + dy*dy);
}

// Function to check if a given point is within the grid boundaries or not
int isValid(int x, int y) {
  return x>=0 && y>=0 && x<ROW && y<COL;
}

// Function to get the neighboring Nodes of a given Node
void getNeighbors(struct Node* grid[][COL], struct Node* current, struct Node** neighbors) {
  int x = current->point.x;
  int y = current->point.y;
  int count = 0;
  for(int i=-1; i<=1; i++) {
    for(int j=-1; j<=1; j++) {
      if(i==0 && j==0) continue;
      if(isValid(x+i, y+j) && !grid[x+i][y+j]->obstacle) {
        neighbors[count++] = grid[x+i][y+j];
      }
    }
  }
}

// Function to find the Node with minimum f value among a given set of Nodes
struct Node* getMinimum(struct Node** set, int size) {
  struct Node* minNode = set[0];
  for(int i=1; i<size; i++) {
    if(set[i]->f < minNode->f) {
      minNode = set[i];
    }
  }
  return minNode;
}

// Function to check if a Node is present in a given set of Nodes
int isInSet(struct Node** set, struct Node* node, int size) {
  for(int i=0; i<size; i++) {
    if(set[i] == node) {
      return 1;
    }
  }
  return 0;
}

// Function to print the path from starting Node to end Node
void printPath(struct Node* end) {
  if(end->parent == NULL) {
    printf("(%d %d)\n", end->point.x, end->point.y);
    return;
  }
  printPath(end->parent);
  printf("(%d %d)\n", end->point.x, end->point.y);
}

// Function to implement the A* algorithm
void AStar(struct Node* grid[][COL], struct Node* start, struct Node* end) {
  struct Node* openSet[ROW * COL];
  struct Node* closedSet[ROW * COL];
  int openSetSize = 0;
  int closedSetSize = 0;
  start->g = 0;
  start->h = calculateDistance(start->point, end->point);
  start->f = start->g + start->h;
  openSet[openSetSize++] = start;
  while(openSetSize > 0) {
    struct Node* current = getMinimum(openSet, openSetSize);
    if(current == end) {
      printPath(end);
      return;
    }
    openSetSize--;
    closedSet[closedSetSize++] = current;
    struct Node* neighbors[8];
    getNeighbors(grid, current, neighbors);
    for(int i=0; i<8; i++) {
      struct Node* neighbor = neighbors[i];
      if(isInSet(closedSet, neighbor, closedSetSize) || neighbor->obstacle) continue;
      int tentativeGScore = current->g + calculateDistance(current->point, neighbor->point);
      int betterPathFound = 0;
      if(!isInSet(openSet, neighbor, openSetSize)) {
        openSet[openSetSize++] = neighbor;
        betterPathFound = 1;
      }
      else if(tentativeGScore < neighbor->g) {
        betterPathFound = 1;
      }
      if(betterPathFound) {
        neighbor->parent = current;
        neighbor->g = tentativeGScore;
        neighbor->h = calculateDistance(neighbor->point, end->point);
        neighbor->f = neighbor->g + neighbor->h;
      }
    }
  }
  printf("No path found!\n");
}

int main() {
  struct Node* grid[ROW][COL];
  initializeGrid(grid);
  AStar(grid, grid[0][0], grid[5][9]);
  return 0;
}