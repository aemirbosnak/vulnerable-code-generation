//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int x;
    int y;
    struct Node* next;
};

struct Node* createNode(int x, int y) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void addNode(struct Node* head, struct Node* newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void generateMaze(struct Node** maze, int size) {
    srand(time(NULL)); // Initialize random seed
    struct Node* currentNode = createNode(0, 0);
    struct Node* nextNode = createNode(0, 1);
    addNode(maze, currentNode);
    addNode(maze, nextNode);
    int x = 1, y = 0;
    while (x < size && y < size) {
        int dx = 1;
        int dy = 0;
        int count = 0;
        while (count < size - 1) {
            struct Node* temp = currentNode;
            int nx = temp->x;
            int ny = temp->y;
            struct Node* newNode = createNode(nx, ny);
            addNode(maze, newNode);
            currentNode = newNode;
            count++;
            if (count % 2 == 0) {
                dx = 0;
                dy = 1;
            } else {
                dx = 1;
                dy = 0;
            }
        }
        x += dx;
        y += dy;
    }
}

int main() {
    int size = 10;
    struct Node* maze = NULL;
    generateMaze(&maze, size);
    printf("Maze generated with %d nodes.\n", size * size - 1);
    struct Node* node = maze;
    while (node!= NULL) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->next;
    }
    return 0;
}