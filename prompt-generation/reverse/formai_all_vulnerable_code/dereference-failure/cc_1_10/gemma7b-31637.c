//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
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
    for (int i = 0; i < MAX_COLS; i++) {
        newNode->data[i] = malloc(MAX_ROWS * sizeof(char));
    }

    memcpy(newNode->data, row, MAX_COLS * sizeof(char *));
    newNode->next = head;
    return newNode;
}

void csv_print(CSV_Node *head) {
    while (head) {
        for (int i = 0; i < MAX_COLS; i++) {
            for (int j = 0; j < MAX_ROWS; j++) {
                printf("%s, ", head->data[i][j]);
            }
            printf("\n");
        }
        head = head->next;
    }
}

int main() {
    CSV_Node *head = NULL;

    char **row1 = malloc(MAX_COLS * sizeof(char *));
    row1[0] = "John Doe";
    row1[1] = "New York";

    csv_insert(head, row1);

    char **row2 = malloc(MAX_COLS * sizeof(char *));
    row2[0] = "Jane Doe";
    row2[1] = "Los Angeles";

    csv_insert(head, row2);

    csv_print(head);

    return 0;
}