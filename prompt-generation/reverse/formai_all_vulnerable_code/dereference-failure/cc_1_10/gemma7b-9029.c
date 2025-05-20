//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node* next;
} CSV_Node;

CSV_Node* CSV_Insert(CSV_Node* head, char** data) {
    CSV_Node* newNode = malloc(sizeof(CSV_Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void CSV_Print(CSV_Node* head) {
    while (head) {
        for (int i = 0; head->data[i] != NULL; i++) {
            printf("%s,", head->data[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    CSV_Node* head = NULL;

    char** data = malloc(MAX_LINES * MAX_COLS * sizeof(char*));
    for (int i = 0; i < MAX_LINES; i++) {
        data[i] = malloc(MAX_COLS * sizeof(char));
    }

    // Fill the data with sample CSV content
    data[0][0] = "John Doe";
    data[0][1] = "New York";

    data[1][0] = "Jane Doe";
    data[1][1] = "Los Angeles";

    CSV_Insert(head, data);

    CSV_Print(head);

    free(data);

    return 0;
}