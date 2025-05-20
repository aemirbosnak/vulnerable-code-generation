//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void generateMaze(Node* head) {
    srand(time(NULL));
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if (rand() % 2 == 0) {
                head = createNode(x, y);
            }
        }
    }
}

void printMaze(Node* head) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if (head->x == x && head->y == y) {
                printf("O ");
            } else {
                printf(" . ");
            }
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = createNode(0, 0);
    generateMaze(head);
    printMaze(head);

    return 0;
}