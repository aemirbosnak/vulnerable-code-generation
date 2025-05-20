//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *csv_insert(CSV_Node *head, char **row) {
    CSV_Node *newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(MAX_COLS * sizeof(char *));
    newNode->next = NULL;

    for (int i = 0; i < MAX_COLS; i++) {
        newNode->data[i] = row[i];
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
    char **row = malloc(MAX_ROWS * sizeof(char *));

    // Assuming you have a CSV parser that fills the 'row' array
    row[0] = "John Doe";
    row[1] = "New York";
    row[2] = "123 Main St";

    head = csv_insert(head, row);

    // Print the CSV data
    CSV_Node *current = head;
    while (current) {
        for (int i = 0; i < MAX_COLS; i++) {
            printf("%s,", current->data[i]);
        }
        printf("\n");
        current = current->next;
    }

    free(row);
    return 0;
}