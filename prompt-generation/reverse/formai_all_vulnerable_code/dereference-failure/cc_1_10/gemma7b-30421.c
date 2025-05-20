//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *insert_node(CSV_Node *head, char **row) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = row;
    new_node->next = head;
    return new_node;
}

void print_csv(CSV_Node *head) {
    CSV_Node *current = head;
    while (current) {
        for (int i = 0; i < MAX_COLS; i++) {
            printf("%s, ", current->data[i]);
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    CSV_Node *head = NULL;
    char **row = malloc(MAX_COLS * sizeof(char *));
    row[0] = "John Doe";
    row[1] = "New York";
    row[2] = "USA";

    head = insert_node(head, row);

    row = malloc(MAX_COLS * sizeof(char *));
    row[0] = "Jane Doe";
    row[1] = "Los Angeles";
    row[2] = "USA";

    insert_node(head, row);

    print_csv(head);

    return 0;
}