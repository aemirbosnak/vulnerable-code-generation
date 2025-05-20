//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *insert_node(CSV_Node *head, char **row) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = row;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

int main() {
    CSV_Node *head = NULL;

    char **row = malloc(MAX_COLS * sizeof(char *));
    row[0] = "John Doe";
    row[1] = "New York";
    insert_node(head, row);

    row = malloc(MAX_COLS * sizeof(char *));
    row[0] = "Jane Doe";
    row[1] = "Los Angeles";
    insert_node(head, row);

    row = malloc(MAX_COLS * sizeof(char *));
    row[0] = "Bill Smith";
    row[1] = "Chicago";
    insert_node(head, row);

    for (CSV_Node *curr = head; curr; curr = curr->next) {
        printf("%s, %s\n", curr->data[0], curr->data[1]);
    }

    return 0;
}