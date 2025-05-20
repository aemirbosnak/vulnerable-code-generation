//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

typedef struct Node {
    struct Node* up;
    struct Node* right;
    struct Node* down;
    struct Node* left;
    int x;
    int y;
} Node;

Node* generateMaze(int size) {
    Node* head = malloc(sizeof(Node));
    head->x = 0;
    head->y = 0;
    head->up = NULL;
    head->right = NULL;
    head->down = NULL;
    head->left = NULL;

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->x = rand() % size;
        newNode->y = rand() % size;
        newNode->up = head;
        newNode->right = NULL;
        newNode->down = NULL;
        newNode->left = NULL;

        head->right = newNode;
        head = newNode;
    }

    return head;
}

void printMaze(Node* head) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            Node* current = head;
            while (current) {
                if (current->x == x && current->y == y) {
                    printf("X ");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    Node* head = generateMaze(MAP_SIZE);
    printMaze(head);

    return 0;
}