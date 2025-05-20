//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
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
    new_node->next = NULL;

    for (int i = 0; i < MAX_COLS; i++) {
        new_node->data[i] = malloc(MAX_ROWS * sizeof(char));
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            new_node->data[i][j] = row[i][j];
        }
    }

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

int main() {
    CSV_Node *head = NULL;
    char **row = malloc(MAX_ROWS * sizeof(char *));
    for (int i = 0; i < MAX_ROWS; i++) {
        row[i] = malloc(MAX_COLS * sizeof(char));
    }

    // Fill the row data with sample values
    row[0][0] = 'a';
    row[0][1] = 'b';
    row[1][0] = 'c';
    row[1][1] = 'd';

    head = insert_node(head, row);

    // Print the data from the CSV node
    CSV_Node *current = head;
    while (current) {
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                printf("%c ", current->data[i][j]);
            }
            printf("\n");
        }
        current = current->next;
    }

    return 0;
}