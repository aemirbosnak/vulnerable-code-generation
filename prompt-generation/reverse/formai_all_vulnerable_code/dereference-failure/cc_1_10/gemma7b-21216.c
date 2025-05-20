//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *CSV_Insert(CSV_Node *head, char **row) {
    CSV_Node *newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(sizeof(char *) * 10);
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

    char **row1 = malloc(sizeof(char *) * 10);
    row1[0] = "John Doe";
    row1[1] = "New York";
    row1[2] = "123 Main St";

    CSV_Insert(head, row1);

    char **row2 = malloc(sizeof(char *) * 10);
    row2[0] = "Jane Doe";
    row2[1] = "Los Angeles";
    row2[2] = "456 Oak Ave";

    CSV_Insert(head, row2);

    for (CSV_Node *node = head; node != NULL; node = node->next) {
        for (int i = 0; node->data[i] != NULL; i++) {
            printf("%s, ", node->data[i]);
        }

        printf("\n");
    }

    return 0;
}