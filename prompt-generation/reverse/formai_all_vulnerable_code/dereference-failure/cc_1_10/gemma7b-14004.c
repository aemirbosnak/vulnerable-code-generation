//Gemma-7B DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LEN 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    Node* head = NULL;

    // Insert data into the linked list
    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');

    // Define a query
    char query[MAX_QUERY_LEN] = "ab";

    // Query the linked list
    int result = queryList(head, query);

    // Print the result
    if (result) {
        printf("Query successful!\n");
    } else {
        printf("Query failed!\n");
    }

    return 0;
}

int queryList(Node* head, char* query) {
    // Iterate over the linked list
    Node* current = head;
    while (current) {
        // Check if the current node is part of the query
        int i = 0;
        for (char* p = query; p[i] != '\0'; i++) {
            if (current->data == p[i]) {
                return 1;
            }
        }

        // Move to the next node
        current = current->next;
    }

    // Query failed
    return 0;
}