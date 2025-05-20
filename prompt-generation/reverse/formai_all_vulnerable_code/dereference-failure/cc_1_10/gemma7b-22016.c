//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *csv_insert(CSV_Node *head, char **row) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));
    new_node->next = NULL;

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            new_node->data[i][j] = row[i][j];
        }
    }

    if (head) {
        head->next = new_node;
    } else {
        head = new_node;
    }

    return head;
}

int main() {
    CSV_Node *head = NULL;

    char **row1 = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));
    row1[0] = "John Doe";
    row1[1] = "New York";

    csv_insert(head, row1);

    char **row2 = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));
    row2[0] = "Jane Doe";
    row2[1] = "Los Angeles";

    csv_insert(head, row2);

    for (CSV_Node *node = head; node; node = node->next) {
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                printf("%s ", node->data[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}