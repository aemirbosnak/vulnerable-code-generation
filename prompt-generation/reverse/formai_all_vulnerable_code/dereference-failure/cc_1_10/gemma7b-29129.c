//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *csv_insert(CSV_Node *head, char **row);

int main() {

    CSV_Node *head = NULL;

    // Simulate some CSV data
    char **row1 = malloc(10);
    row1[0] = "John Doe";
    row1[1] = "New York";
    row1[2] = "123 Main St";

    char **row2 = malloc(10);
    row2[0] = "Jane Doe";
    row2[1] = "Los Angeles";
    row2[2] = "456 Oak Ave";

    char **row3 = malloc(10);
    row3[0] = "Bill Smith";
    row3[1] = "Chicago";
    row3[2] = "789 Oak Park Ave";

    // Insert rows into the CSV list
    head = csv_insert(head, row1);
    head = csv_insert(head, row2);
    head = csv_insert(head, row3);

    // Print the CSV data
    CSV_Node *current = head;
    while (current) {
        for (int i = 0; current->data[i] != NULL; i++) {
            printf("%s, ", current->data[i]);
        }
        printf("\n");
        current = current->next;
    }

    return 0;
}

CSV_Node *csv_insert(CSV_Node *head, char **row) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = row;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    CSV_Node *current = head;
    while (current->next) {
        current = current->next;
    }

    current->next = new_node;

    return head;
}