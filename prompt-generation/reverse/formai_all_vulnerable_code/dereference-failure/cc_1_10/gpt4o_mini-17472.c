//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define ROW 10
#define COL 10
#define INF INT_MAX

typedef struct {
    int x;
    int y;
} Node;

typedef struct {
    Node* nodes;
    int count;
} NodeList;

typedef struct {
    Node parent;
    int g; // Distance from start node
    int h; // Heuristic distance to end node
    int f; // Total cost g + h
} PathNode;

// Function prototypes
int isSafe(int grid[ROW][COL], int x, int y);
int heuristic(Node a, Node b);
void addNode(NodeList *list, Node node);
NodeList createNodeList();
void freeNodeList(NodeList *list);
bool isNodeInList(NodeList list, Node node);
NodeList aStarPathfinding(int grid[ROW][COL], Node start, Node end);
void printPath(NodeList path);

int main() {
    int grid[ROW][COL] = {
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 },
        { 0, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
        { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 }
    };
    
    Node start = {0, 0}; // Starting point
    Node end = {9, 9};   // Ending point

    NodeList path = aStarPathfinding(grid, start, end);
    printPath(path);
    
    freeNodeList(&path);
    return 0;
}

int isSafe(int grid[ROW][COL], int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] == 0);
}

int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void addNode(NodeList *list, Node node) {
    list->nodes[list->count++] = node;
}

NodeList createNodeList() {
    NodeList list;
    list.count = 0;
    list.nodes = (Node*)malloc(ROW * COL * sizeof(Node));
    return list;
}

void freeNodeList(NodeList *list) {
    free(list->nodes);
    list->count = 0;
}

bool isNodeInList(NodeList list, Node node) {
    for (int i = 0; i < list.count; i++) {
        if (list.nodes[i].x == node.x && list.nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

NodeList aStarPathfinding(int grid[ROW][COL], Node start, Node end) {
    NodeList openList = createNodeList();
    NodeList closedList = createNodeList();
    
    PathNode pathNodes[ROW][COL];
    memset(pathNodes, 0, sizeof(pathNodes));
    
    addNode(&openList, start);
    
    while (openList.count != 0) {
        Node current = openList.nodes[0]; 
        for (int i = 1; i < openList.count; i++) {
            if (pathNodes[openList.nodes[i].x][openList.nodes[i].y].f < pathNodes[current.x][current.y].f) {
                current = openList.nodes[i];
            }
        }

        if (current.x == end.x && current.y == end.y) {
            NodeList path = createNodeList();
            while (current.x != start.x || current.y != start.y) {
                addNode(&path, current);
                current = pathNodes[current.x][current.y].parent;
            }
            addNode(&path, start);
            freeNodeList(&openList);
            freeNodeList(&closedList);
            return path;
        }

        openList.nodes[0] = openList.nodes[--openList.count];

        addNode(&closedList, current);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (abs(dx) + abs(dy) != 1)) {
                    continue; // Skip diagonals and the current node
                }
                Node neighbor = {current.x + dx, current.y + dy};
                if (isSafe(grid, neighbor.x, neighbor.y) && !isNodeInList(closedList, neighbor)) {
                    if (!isNodeInList(openList, neighbor)) {
                        pathNodes[neighbor.x][neighbor.y].parent = current;
                        pathNodes[neighbor.x][neighbor.y].g = pathNodes[current.x][current.y].g + 1;
                        pathNodes[neighbor.x][neighbor.y].h = heuristic(neighbor, end);
                        pathNodes[neighbor.x][neighbor.y].f = pathNodes[neighbor.x][neighbor.y].g + pathNodes[neighbor.x][neighbor.y].h;
                        addNode(&openList, neighbor);
                    }
                }
            }
        }
    }
    
    freeNodeList(&openList);
    freeNodeList(&closedList);
    return createNodeList(); // Return empty path
}

void printPath(NodeList path) {
    if (path.count == 0) {
        printf("No path found!\n");
        return;
    }
    printf("Path found:\n");
    for (int i = path.count - 1; i >= 0; i--) {
        printf("(%d, %d) ", path.nodes[i].x, path.nodes[i].y);
    }
    printf("\n");
}