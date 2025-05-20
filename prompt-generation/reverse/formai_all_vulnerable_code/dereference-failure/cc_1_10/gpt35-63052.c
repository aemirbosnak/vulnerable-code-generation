//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

struct node {
    int x, y;
    struct node* next;
};

typedef struct node* Node;

Node front = NULL;
Node rear = NULL;

int grid[ROW][COL] = {
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1}
};

int visited[ROW][COL] = {0};

int isValid(char row, char col) {
    if(row < 0 || col < 0 || row >= ROW || col >= COL || visited[row][col] || grid[row][col] != 1) {
        return 0;
    }
    return 1;
}

void enqueue(char row, char col) {
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->x = row;
    newNode->y = col;
    newNode->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    Node temp = front;
    if(front == NULL) {
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

void BFS(char startX, char startY, char endX, char endY) {
    enqueue(startX, startY);
    visited[startX][startY] = 1;
    while(front != NULL) {
        Node current = front;
        if(current->x == endX && current->y == endY) {
            return;
        }
        if(isValid(current->x + 1, current ->y)) {
            enqueue(current->x + 1, current->y);
            visited[current->x + 1][current->y] = 1;
        }
        if(isValid(current->x, current ->y + 1)) {
            enqueue(current->x, current->y + 1);
            visited[current->x][current->y + 1] = 1;
        }
        if(isValid(current->x - 1, current ->y)) {
            enqueue(current->x - 1, current->y);
            visited[current->x - 1][current->y] = 1;
        }
        if(isValid(current->x, current ->y - 1)) {
            enqueue(current->x, current->y - 1);
            visited[current->x][current->y - 1] = 1;
        }
        dequeue();
    }
}

int main() {
    BFS(0, 0, 9, 9);
    if(visited[9][9]) {
        printf("Path found!");
    } else {
        printf("No path found.");
    }
    return 0;
}