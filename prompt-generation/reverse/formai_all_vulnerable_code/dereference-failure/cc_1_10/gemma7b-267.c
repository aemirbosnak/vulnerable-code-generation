//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node* next;
} CSV_Node;

CSV_Node* csv_insert(CSV_Node* head, char** data) {
    CSV_Node* newNode = (CSV_Node*)malloc(sizeof(CSV_Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void csv_print(CSV_Node* head) {
    CSV_Node* current = head;

    while (current) {
        for (int r = 0; r < MAX_ROWS; r++) {
            for (int c = 0; c < MAX_COLS; c++) {
                printf("%s ", current->data[r][c]);
            }
            printf("\n");
        }

        current = current->next;
    }
}

int main() {
    CSV_Node* head = NULL;

    char** data = (char**)malloc(MAX_ROWS * sizeof(char*));
    for (int r = 0; r < MAX_ROWS; r++) {
        data[r] = (char*)malloc(MAX_COLS * sizeof(char));
    }

    // Populate the data
    data[0][0] = "John Doe";
    data[0][1] = "New York";
    data[1][0] = "Jane Doe";
    data[1][1] = "Los Angeles";

    head = csv_insert(head, data);

    csv_print(head);

    return 0;
}