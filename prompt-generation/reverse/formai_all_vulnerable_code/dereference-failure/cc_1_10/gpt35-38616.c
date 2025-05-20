//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct {
    int row, col;
    double f, g, h;
} Node;

Node **initMap();
void printMap(Node **map);
double calcDistance(Node start, Node end);
Node *findMinF(Node **openList);
void getPath(Node *start, Node *end);

int main() {
    Node **map = initMap();
    printMap(map);
    
    Node *start = &map[1][1];
    Node *end = &map[7][7];
    getPath(start, end);
    
    return 0;
}

Node **initMap() {
    Node **map = (Node **)malloc(sizeof(Node) * ROW);
    
    for (int i = 0; i < ROW; i++) {
        map[i] = (Node *)malloc(sizeof(Node) * COL);
        for (int j = 0; j < COL; j++) {
            map[i][j].row = i;
            map[i][j].col = j;
            map[i][j].f = 0;
            map[i][j].g = 0;
            map[i][j].h = 0;
        }
    }
    
    return map;
}

void printMap(Node **map) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("(%d,%d) ", map[i][j].row, map[i][j].col);
        }
        printf("\n");
    }
}

double calcDistance(Node start, Node end) {
    return sqrt(pow((end.row - start.row), 2) + pow((end.col - start.col), 2));
}

Node *findMinF(Node **openList) {
    Node *minFNode = NULL;
    double minF = INFINITY;
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (openList[i][j].f != 0 && openList[i][j].f < minF) {
                minF = openList[i][j].f;
                minFNode = &openList[i][j];
            }
        }
    }
    
    return minFNode;
}

void getPath(Node *start, Node *end) {
    Node **closedList = initMap();
    Node **openList = initMap();
    
    start->g = 0;
    start->h = calcDistance(*start, *end);
    start->f = start->g + start->h;
    
    openList[start->row][start->col] = *start;
    
    while(openList[end->row][end->col].f == 0) {
        
        Node *current = findMinF(openList);
        
        openList[current->row][current->col].f = 0;
        closedList[current->row][current->col] = *current;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                
                if (i == 0 && j == 0)
                    continue;
                    
                int newRow = current->row + i;
                int newCol = current->col + j;
                
                if (newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COL)
                    continue;
                
                double tentativeG = current->g + calcDistance(*current, openList[newRow][newCol]);
                
                if (closedList[newRow][newCol].f != 0 && tentativeG >= closedList[newRow][newCol].g)
                    continue;
                
                if (openList[newRow][newCol].f == 0 || tentativeG < openList[newRow][newCol].g) {
                    openList[newRow][newCol].row = newRow;
                    openList[newRow][newCol].col = newCol;
                    openList[newRow][newCol].g = tentativeG;
                    openList[newRow][newCol].h = calcDistance(openList[newRow][newCol], *end);
                    openList[newRow][newCol].f = openList[newRow][newCol].g + openList[newRow][newCol].h;
                }
                
            }
        }
        
    }
    
    Node *current = end;
    while (current->row != start->row || current->col != start->col) {
        printf("(%d,%d) <- ", current->row, current->col);
        double minF = INFINITY;
        Node *next = NULL;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                
                if (i == 0 && j == 0)
                    continue;
                    
                int newRow = current->row + i;
                int newCol = current->col + j;
                
                if (newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COL)
                    continue;
                
                if (closedList[newRow][newCol].f != 0 && closedList[newRow][newCol].f < minF) {
                    minF = closedList[newRow][newCol].f;
                    next = &closedList[newRow][newCol];
                }
                
            }
        }
        
        current = next;
    }
    
    printf("(%d,%d)", start->row, start->col);
}