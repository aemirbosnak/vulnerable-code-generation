//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 9
#define COL 10

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->nodes = (Node *)malloc(capacity * sizeof(Node));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && (minHeap->nodes[left].x < minHeap->nodes[smallest].x ||
                                 (minHeap->nodes[left].x == minHeap->nodes[smallest].x && minHeap->nodes[left].y < minHeap->nodes[smallest].y))) {
        smallest = left;
    }
    if (right < minHeap->size && (minHeap->nodes[right].x < minHeap->nodes[smallest].x ||
                                 (minHeap->nodes[right].x == minHeap->nodes[smallest].x && minHeap->nodes[right].y < minHeap->nodes[smallest].y))) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&minHeap->nodes[idx], &minHeap->nodes[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap *minHeap, Node node) {
    if (minHeap->size == minHeap->capacity) return;
    minHeap->nodes[minHeap->size] = node;
    int current = minHeap->size++;
    while (current != 0 && (minHeap->nodes[current].x < minHeap->nodes[(current - 1) / 2].x ||
                           (minHeap->nodes[current].x == minHeap->nodes[(current - 1) / 2].x && minHeap->nodes[current].y < minHeap->nodes[(current - 1) / 2].y))) {
        swap(&minHeap->nodes[current], &minHeap->nodes[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

Node extractMin(MinHeap *minHeap) {
    if (minHeap->size <= 0) return (Node) {-1, -1};
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->nodes[0];
    }
    Node root = minHeap->nodes[0];
    minHeap->nodes[0] = minHeap->nodes[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

bool isSafe(int row, int col, int grid[ROW][COL], bool visited[ROW][COL]) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && 
           (grid[row][col] == 1 && !visited[row][col]);
}

void printPath(Node parent[], int j) {
    if (parent[j].x == -1 && parent[j].y == -1) return;
    printPath(parent, parent[j].x * COL + parent[j].y);
    printf("-> (%d, %d) ", parent[j].x, parent[j].y);
}

void aStar(int grid[ROW][COL], Node start, Node end) {
    if (!isSafe(start.x, start.y, grid, (bool[ROW][COL]){})) return;
    if (!isSafe(end.x, end.y, grid, (bool[ROW][COL]){})) return;

    bool visited[ROW][COL] = {false};
    Node parent[ROW * COL];
    MinHeap *minHeap = createMinHeap(ROW * COL);
    
    insertMinHeap(minHeap, start);
    parent[start.x * COL + start.y] = (Node) {-1, -1};

    while (minHeap->size) {
        Node current = extractMin(minHeap);

        if (current.x == end.x && current.y == end.y) {
            printf("Path Found: ");
            printPath(parent, current.x * COL + current.y);
            printf("-> (%d, %d)\n", end.x, end.y);
            return;
        }

        visited[current.x][current.y] = true;

        for (int rowOffset = -1; rowOffset <= 1; rowOffset++) {
            for (int colOffset = -1; colOffset <= 1; colOffset++) {
                if ((rowOffset == 0 && colOffset == 0) || (abs(rowOffset) == abs(colOffset))) continue;

                int newRow = current.x + rowOffset;
                int newCol = current.y + colOffset;

                if (isSafe(newRow, newCol, grid, visited)) {
                    visited[newRow][newCol] = true;
                    int gNew = current.x + current.y + 1; // Distance from the start node
                    parent[newRow * COL + newCol] = current;
                    insertMinHeap(minHeap, (Node) {gNew, newRow * COL + newCol});
                }
            }
        }
    }
    printf("Path Not Found\n");
    free(minHeap->nodes);
    free(minHeap);
}

int main() {
    int grid[ROW][COL] = {
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    Node start = {0, 0}; // Starting point
    Node end = {8, 9};   // Destination point

    aStar(grid, start, end);

    return 0;
}