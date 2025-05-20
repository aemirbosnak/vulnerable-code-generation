//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(Node* head) {
    srand(time(NULL));
    for (int i = 0; i < MAZE_WIDTH * MAZE_HEIGHT; i++) {
        int x = rand() % MAZE_WIDTH;
        int y = rand() % MAZE_HEIGHT;
        Node* node = createNode(x, y);
        head->next = node;
        head = node;
    }
}

void printMaze(Node* head) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            Node* node = head;
            while (node) {
                if (node->x == x && node->y == y) {
                    printf("%c ", '*');
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    Node* head = createNode(0, 0);
    generateMaze(head);
    printMaze(head);

    return 0;
}