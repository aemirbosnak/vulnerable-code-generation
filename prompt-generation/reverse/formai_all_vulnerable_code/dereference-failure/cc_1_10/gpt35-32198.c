//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 20

typedef struct {
    int x;
    int y;
} Coordinate;

char map[ROWS][COLS] = {
    {"###################"},
    {"#.................#"},
    {"###.#.###.#.#.###.#"},
    {"#...#...#.#.#.#...#"},
    {"#.###.#.#.#.#.#.#.#"},
    {"#.#...#.#.#.#.#.#.#"},
    {"#.#.#.#.#.#.#.#.#.#"},
    {"#.#.#.#.#.#.#.#.#.#"},
    {"#...#...#.......#.#"},
    {"###################"}
};

Coordinate start = {1, 1};
Coordinate end = {ROWS-2, COLS-2};

typedef struct _Node {
    Coordinate coord;
    struct _Node* parent;
    bool checked;
} Node;

Node* heap[ROWS*COLS];
int heapSize = 0;

void addToHeap(Node* node) {
    heap[++heapSize] = node;
    int i = heapSize;
    while (i > 1) {
        if (heap[i]->coord.x + heap[i]->coord.y < heap[i/2]->coord.x + heap[i/2]->coord.y) {
            Node* temp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = temp;
        }
        i /= 2;
    }
}

Node* removeFromHeap() {
    Node* ret = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (i*2 <= heapSize) {
        int left = i*2;
        int right = i*2+1;
        if (right <= heapSize && heap[right]->coord.x + heap[right]->coord.y < heap[left]->coord.x + heap[left]->coord.y) {
            if (heap[right]->coord.x + heap[right]->coord.y < heap[i]->coord.x + heap[i]->coord.y) {
                Node* temp = heap[i];
                heap[i] = heap[right];
                heap[right] = temp;
                i = right;
            } else {
                break; // heap property satisfied
            }
        } else {
            if (heap[left]->coord.x + heap[left]->coord.y < heap[i]->coord.x + heap[i]->coord.y) {
                Node* temp = heap[i];
                heap[i] = heap[left];
                heap[left] = temp;
                i = left;
            } else {
                break; // heap property satisfied
            }
        }
    }
    return ret;
}

void printPath(Node* node) {
    if (node != NULL) {
        printPath(node->parent);
        printf("(%d,%d) ", node->coord.x, node->coord.y);
    }
}

int main() {
    // create starting node
    Node* startNode = (Node*) malloc(sizeof(Node));
    startNode->coord = start;
    startNode->parent = NULL;
    startNode->checked = false;
    addToHeap(startNode);
    
    while (heapSize > 0) {
        Node* currNode = removeFromHeap();
        currNode->checked = true;
        
        // if we reached the destination, print path and exit
        if (currNode->coord.x == end.x && currNode->coord.y == end.y) {
            printPath(currNode);
            printf("\n");
            return 0;
        }
        
        // check all adjacent nodes
        int x = currNode->coord.x;
        int y = currNode->coord.y;
        
        // West
        if (y-1 >= 0 && map[x][y-1] != '#' && !currNode->checked) {
            Node* newNode = (Node*) malloc(sizeof(Node));
            newNode->coord = (Coordinate) {x, y-1};
            newNode->parent = currNode;
            newNode->checked = false;
            addToHeap(newNode);
        }
        
        // East
        if (y+1 < COLS && map[x][y+1] != '#' && !currNode->checked) {
            Node* newNode = (Node*) malloc(sizeof(Node));
            newNode->coord = (Coordinate) {x, y+1};
            newNode->parent = currNode;
            newNode->checked = false;
            addToHeap(newNode);
        }
        
        // North
        if (x-1 >= 0 && map[x-1][y] != '#' && !currNode->checked) {
            Node* newNode = (Node*) malloc(sizeof(Node));
            newNode->coord = (Coordinate) {x-1, y};
            newNode->parent = currNode;
            newNode->checked = false;
            addToHeap(newNode);
        }
        
        // South
        if (x+1 < ROWS && map[x+1][y] != '#' && !currNode->checked) {
            Node* newNode = (Node*) malloc(sizeof(Node));
            newNode->coord = (Coordinate) {x+1, y};
            newNode->parent = currNode;
            newNode->checked = false;
            addToHeap(newNode);
        }
    }
    
    // if we got here, there is no path to the destination
    printf("No path found.\n");
    
    return 0;
}