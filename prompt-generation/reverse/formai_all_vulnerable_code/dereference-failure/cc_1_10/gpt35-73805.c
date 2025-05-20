//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

struct node {
    int row, col;
    int g_val, f_val;
    struct node* parent;
};

struct node** createNode(int row, int col, int g_val, int f_val, struct node* parent) {
    struct node** newNode = (struct node**)malloc(sizeof(struct node*));
    (*newNode) = (struct node*)malloc(sizeof(struct node));
    (*newNode)->row = row;
    (*newNode)->col = col;
    (*newNode)->g_val = g_val;
    (*newNode)->f_val = f_val;
    (*newNode)->parent = parent;
    return newNode;
}

int isValid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

int isDestination(int row, int col, struct node* dest) {
    return (row == dest->row && col == dest->col);
}

int calculateHVal(int row, int col, struct node* dest) {
    int hVal = abs(row - dest->row) + abs(col - dest->col);
    return hVal;
}

struct node** getSuccessors(int row, int col, int gVal, struct node* parent, struct node* dest, int maze[][COL], int* count) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    struct node** successors = (struct node**)malloc(4 * sizeof(struct node*));
    (*count) = 0;
    for(int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if(isValid(newRow, newCol) && maze[newRow][newCol] == 0) {
            int newGVal = gVal + 1;
            int newFVal = newGVal + calculateHVal(newRow, newCol, dest);
            successors[(*count)] = (*createNode)(newRow, newCol, newGVal, newFVal, parent);
            (*count)++;
        }
    }

    return successors;
}

void freeMemory(struct node** nodes, int count) {
    for(int i = 0; i < count; i++) {
        free(nodes[i]);
    }
    free(nodes);
}

void printPath(struct node* current) {
    if(current == NULL) {
        return;
    }
    printPath(current->parent);
    printf("(%d, %d)\n", current->row, current->col);
}

void aStarSearch(int maze[][COL], struct node* start, struct node* dest) {
    int visited[ROW][COL] = {0};
    struct node** opened = (struct node**)malloc(ROW * COL * sizeof(struct node*));
    int countOpened = 0;
    struct node** closed = (struct node**)malloc(ROW * COL * sizeof(struct node*));
    int countClosed = 0;
    struct node** successors;
    int countSuccessors = 0;

    opened[countOpened++] = start;

    while(countOpened > 0) {
        struct node* current;
        int index = 0;
        for(int i = 0; i < countOpened; i++) {
            if(opened[i]->f_val < opened[index]->f_val) {
                index = i;
            }
        }

        current = opened[index];
        visited[current->row][current->col] = 1;

        if(isDestination(current->row, current->col, dest)) {
            printf("The shortest path is:\n");
            printPath(current);
            return;
        }

        countSuccessors = 0;
        successors = getSuccessors(current->row, current->col, current->g_val, current, dest, maze, &countSuccessors);

        for(int i = 0; i < countSuccessors; i++) {
            int flagOpened = 0;
            int flagClosed = 0;

            if(visited[successors[i]->row][successors[i]->col] == 1) {
                continue;
            }

            successors[i]->f_val += successors[i]->g_val;

            for(int j = 0; j < countOpened; j++) {
                if(opened[j]->row == successors[i]->row && opened[j]->col == successors[i]->col &&
                   opened[j]->f_val < successors[i]->f_val) {
                    flagOpened = 1;
                    break;
                }
            }

            for(int j = 0; j < countClosed; j++) {
                if(closed[j]->row == successors[i]->row && closed[j]->col == successors[i]->col &&
                   closed[j]->f_val < successors[i]->f_val) {
                    flagClosed = 1;
                    break;
                }
            }

            if(flagOpened || flagClosed) {
                continue;
            }

            opened[countOpened++] = successors[i];
        }

        closed[countClosed++] = current;
        for(int i = 0; i < countOpened; i++) {
            if(opened[i]->row == current->row && opened[i]->col == current->col) {
                opened[i] = NULL;
                for(int j = i; j < countOpened - 1; j++) {
                    opened[j] = opened[j+1];
                }
                countOpened--;
                break;
            }
        }
        
        freeMemory(successors, countSuccessors);
    }

}

int main() {
    int maze[ROW][COL] = {
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
    };

    struct node* start = (*createNode)(0, 0, 0, 0, NULL);
    struct node* dest = (*createNode)(7, 7, 0, 0, NULL);

    aStarSearch(maze, start, dest);

    return 0;
}