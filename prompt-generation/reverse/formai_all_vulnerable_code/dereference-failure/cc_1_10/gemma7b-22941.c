//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
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
    new_node->data = malloc(MAX_COLS * sizeof(char *));
    for (int i = 0; i < MAX_COLS; i++) {
        new_node->data[i] = malloc(MAX_ROWS * sizeof(char));
    }

    memcpy(new_node->data, row, MAX_COLS * sizeof(char *));
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

    // Insert some sample data
    char **row1 = malloc(MAX_COLS * sizeof(char *));
    row1[0] = "John Doe";
    row1[1] = "Software Engineer";

    insert_node(head, row1);

    // Insert more data
    char **row2 = malloc(MAX_COLS * sizeof(char *));
    row2[0] = "Jane Doe";
    row2[1] = "Marketing Manager";

    insert_node(head, row2);

    // Print the data
    for (CSV_Node *node = head; node; node = node->next) {
        for (int i = 0; i < MAX_COLS; i++) {
            printf("%s, ", node->data[i]);
        }
        printf("\n");
    }

    return 0;
}