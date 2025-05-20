//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *csv_insert(CSV_Node *head, char **row) {
    CSV_Node *newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(MAX_LINES * sizeof(char *));
    newNode->next = NULL;

    for (int i = 0; row[i] != NULL; i++) {
        newNode->data[i] = strdup(row[i]);
    }

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    CSV_Node *head = NULL;
    char **row = malloc(MAX_LINES * sizeof(char *));

    // Fill the row with sample data
    row[0] = "John Doe";
    row[1] = "123 Main St.";
    row[2] = "New York, NY 10001";

    // Insert the row into the CSV list
    head = csv_insert(head, row);

    // Print the data from the CSV list
    for (CSV_Node *node = head; node; node = node->next) {
        for (int i = 0; node->data[i] != NULL; i++) {
            printf("%s, ", node->data[i]);
        }
        printf("\n");
    }

    return 0;
}