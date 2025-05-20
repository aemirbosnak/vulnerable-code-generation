//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *CSV_Insert(CSV_Node *head, char **row) {
    CSV_Node *newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char));
    newNode->next = NULL;

    for (int i = 0; i < MAX_COLS; i++) {
        newNode->data[0][i] = row[i];
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

    char **row1 = malloc(MAX_COLS * sizeof(char));
    row1[0] = "John Doe";
    row1[1] = "Software Engineer";

    CSV_Insert(head, row1);

    char **row2 = malloc(MAX_COLS * sizeof(char));
    row2[0] = "Jane Doe";
    row2[1] = "Marketing Manager";

    CSV_Insert(head, row2);

    for (CSV_Node *curr = head; curr; curr = curr->next) {
        for (int i = 0; i < MAX_COLS; i++) {
            printf("%s ", curr->data[0][i]);
        }
        printf("\n");
    }

    return 0;
}