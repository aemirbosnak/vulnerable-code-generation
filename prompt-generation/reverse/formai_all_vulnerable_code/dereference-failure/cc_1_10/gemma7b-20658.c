//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initialize(Node** head) {
    *head = malloc(sizeof(Node));
    (*head)->x = -1;
    (*head)->y = -1;
    (*head)->next = NULL;
}

void addNode(Node** head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

int main() {
    srand(time(NULL));

    Node* head = NULL;
    initialize(&head);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (rand() % 2 == 0) {
                addNode(&head, x, y);
            }
        }
    }

    for (Node* node = head; node; node = node->next) {
        printf("(%d, %d)\n", node->x, node->y);
    }

    return 0;
}