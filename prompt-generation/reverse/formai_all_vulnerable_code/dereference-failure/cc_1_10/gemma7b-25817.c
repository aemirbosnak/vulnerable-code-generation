//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *csv_insert(CSV_Node **head, char **row) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = row;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }

    return new_node;
}

void csv_print(CSV_Node *head) {
    while (head) {
        for (int i = 0; head->data[i] != NULL; i++) {
            printf("%s, ", head->data[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    CSV_Node *csv_head = NULL;

    char **row1 = malloc(MAX_COLS * sizeof(char *));
    row1[0] = "John Doe";
    row1[1] = "New York";
    csv_insert(&csv_head, row1);

    char **row2 = malloc(MAX_COLS * sizeof(char *));
    row2[0] = "Jane Doe";
    row2[1] = "Los Angeles";
    csv_insert(&csv_head, row2);

    csv_print(csv_head);

    return 0;
}