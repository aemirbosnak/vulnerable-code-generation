//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#define ROW 6
#define COL 6

// A structure to represent a point in 2D space
struct Point {
   int x, y;
};

// A function to check if a given cell (row, col) can be included in BFS or not
int isValid(int row, int col) {
   // Returns true if row and col are in range
   return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// A function to check if the given cell is blocked or not
int isUnBlocked(int** grid, int row, int col) {
   // Returns true if the cell is not blocked else false
   if (grid[row][col] == 0)
      return (1);
   else
      return (0);
}

// A function to enqueue a node to the queue
void enqueue(struct Point point, struct Point* queue, int* rear) {
   queue[*rear] = point;
   (*rear)++;
}

// A function to dequeue a node from the queue
struct Point dequeue(struct Point* queue, int* front) {
   (*front)++;
   return queue[*front - 1];
}

// A function to find the shortest path between a given start cell and a destination cell.
void BFS(int** grid, struct Point start, struct Point end) {
   // If the start point and destination point are same
   if (start.x == end.x && start.y == end.y) {
      printf("Source and destination are the same\n");
      return;
   }
   // If either the start or the end cell is blocked
   if (!isUnBlocked(grid, start.x, start.y) || !isUnBlocked(grid, end.x, end.y)) {
      printf("Either the start or the end cell is blocked, no path exists\n");
      return;
   }

   // Initialize the visited array, distance array and queue
   int visited[ROW][COL] = { 0 };
   int distance[ROW][COL] = { 0 };
   struct Point queue[ROW * COL];
   int rear = 0;
   int front = 0;

   int row[] = { -1, 0, 1, 0 };
   int col[] = { 0, 1, 0, -1 };
   // Mark the starting cell as visited and enqueue it
   visited[start.x][start.y] = 1;
   enqueue(start, queue, &rear);

   // Loop until there are no more elements in queue
   while (front != rear) {
      // Dequeue a cell from the queue and get its adjacent cells
      struct Point current = dequeue(queue, &front);

      if (current.x == end.x && current.y == end.y) {
         // If we have reached the destination cell
         printf("Shortest path length is %d\n", distance[current.x][current.y]);
         return;
      }

      // Check for all adjacent cells
      for (int i = 0; i < 4; i++) {
         int newRow = current.x + row[i];
         int newCol = current.y + col[i];
         // If the adjacent cell is valid, unblocked, and not visited yet
         if (isValid(newRow, newCol) && isUnBlocked(grid, newRow, newCol) && !visited[newRow][newCol]) {
            // Increment the path length and mark it as visited
            distance[newRow][newCol] = distance[current.x][current.y] + 1;
            visited[newRow][newCol] = 1;
            // Enqueue the adjacent cell
            struct Point adjCell = { newRow, newCol };
            enqueue(adjCell, queue, &rear);
         }
      }
   }
   printf("Destination not found\n");
   return;
}

// Driver function
int main() {
   int** grid = (int**)malloc(sizeof(int*) * ROW);
   for (int i = 0; i < ROW; i++)
      grid[i] = (int*)malloc(sizeof(int) * COL);

   // Initialize the grid
   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++)
         grid[i][j] = 1; // Unblocked
   }

   // Add the obstacles
   grid[1][3] = 0;
   grid[2][1] = 0;
   grid[2][5] = 0;
   grid[3][3] = 0;
   grid[4][2] = 0;

   struct Point start = { 3, 0 };
   struct Point end = { 0, 5 };
   printf("The grid:\n");
   // Print the grid
   for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
         if (grid[i][j] == 1)
            printf("%d ", 0);
         else
            printf("%d ", 1);
      }
      printf("\n");
   }
   BFS(grid, start, end);
   return 0;
}