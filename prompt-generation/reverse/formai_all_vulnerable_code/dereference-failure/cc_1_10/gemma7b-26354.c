//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int x, y;
    srand(time(NULL));

    // Allocate memory for the first node
    *head = (Node*)malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    // Generate the maze
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if (rand() % 2 == 0) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->x = x;
                newNode->y = y;
                newNode->next = NULL;

                ((*head)->next) = newNode;
                *head = newNode;
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
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    printMaze(head);

    return 0;
}