//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void generateMaze(Node** head) {
    int i, j, r, c;
    srand(time(NULL));
    r = rand() % MAX_SIZE;
    c = rand() % MAX_SIZE;
    *head = malloc(sizeof(Node));
    (*head)->x = r;
    (*head)->y = c;
    (*head)->next = NULL;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (r != i || c != j) {
                Node* newNode = malloc(sizeof(Node));
                newNode->x = i;
                newNode->y = j;
                newNode->next = NULL;
                ((*head)->next = newNode)->next = NULL;
                head = &newNode;
            }
        }
    }
}

void findRoute(Node* head) {
    int x, y;
    scanf("Enter your starting position (x, y): ");
    scanf("Enter your goal position (x, y): ");
    x = atoi(stdin);
    y = atoi(stdin);

    while (head) {
        if (x == head->x && y == head->y) {
            printf("Path found!\n");
            break;
        } else {
            head = head->next;
        }
    }

    if (head == NULL) {
        printf("No path found.\n");
    }
}

int main() {
    Node* head = NULL;
    generateMaze(&head);
    findRoute(head);
    return 0;
}