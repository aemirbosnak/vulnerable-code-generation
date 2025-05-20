//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insert(Node* head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    insert(head, 0, 0);
    insert(head, 1, 0);
    insert(head, 2, 0);
    insert(head, 3, 0);
    insert(head, 4, 0);
    insert(head, 5, 0);
    insert(head, 6, 0);
    insert(head, 7, 0);
    insert(head, 8, 0);
    insert(head, 9, 0);

    int x, y;
    scanf("Enter the starting position (x, y): ", &x, &y);

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int i = 0;
    while (head && head->x != x && head->y != y) {
        for (int j = 0; j < 4; j++) {
            int nx = head->x + dx[j];
            int ny = head->y + dy[j];

            if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX) {
                insert(head, nx, ny);
            }
        }
        head = head->next;
        i++;
    }

    if (head) {
        printf("The path to the goal position (x, y):\n");
        while (head) {
            printf("(%d, %d)\n", head->x, head->y);
            head = head->next;
        }
    } else {
        printf("No path found.\n");
    }

    return 0;
}