//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x, y;
    struct node *next;
} node;

node *head = NULL, *tail = NULL;

void push(int x, int y) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int pop(int *x, int *y) {
    if (head == NULL) {
        return 0;
    }
    *x = head->x;
    *y = head->y;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    return 1;
}

int main() {
    int maze[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int start_x = 1, start_y = 1;
    int end_x = 8, end_y = 8;

    push(start_x, start_y);

    while (head != NULL) {
        int x, y;
        pop(&x, &y);

        if (x == end_x && y == end_y) {
            printf("Found the path!\n");
            break;
        }

        if (maze[x][y + 1] == 0) {
            push(x, y + 1);
        }
        if (maze[x + 1][y] == 0) {
            push(x + 1, y);
        }
        if (maze[x][y - 1] == 0) {
            push(x, y - 1);
        }
        if (maze[x - 1][y] == 0) {
            push(x - 1, y);
        }
    }

    if (head == NULL) {
        printf("No path found!\n");
    }

    return 0;
}