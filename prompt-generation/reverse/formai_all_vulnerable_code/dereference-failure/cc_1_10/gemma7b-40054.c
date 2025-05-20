//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node* next;
} CSV_Node;

CSV_Node* CSV_Insert(CSV_Node* head, char* line) {
    CSV_Node* newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(MAX_COLS * sizeof(char*));
    newNode->next = NULL;

    for (int i = 0; i < MAX_COLS; i++) {
        newNode->data[i] = NULL;
    }

    int i = 0;
    char* p = line;
    for (; *p != '\0'; p++) {
        if (*p == ',') {
            newNode->data[i++] = malloc(MAX_LINES * sizeof(char));
            memset(newNode->data[i], '\0', MAX_LINES * sizeof(char));
        } else {
            newNode->data[i++] = p;
        }
    }

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    CSV_Node* head = NULL;

    char* line = "John Doe,123 Main St,New York,NY 10001";
    CSV_Insert(head, line);

    line = "Jane Doe,456 Oak Ave,Los Angeles,CA 90012";
    CSV_Insert(head, line);

    line = "Peter Pan,Neverland,Neverland,PN 123";
    CSV_Insert(head, line);

    for (CSV_Node* node = head; node; node = node->next) {
        printf("Name: %s\n", node->data[0]);
        printf("Address: %s\n", node->data[1]);
        printf("City: %s\n", node->data[2]);
        printf("State: %s\n", node->data[3]);
        printf("Zip: %s\n", node->data[4]);
        printf("\n");
    }

    return 0;
}