//Gemma-7B DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(Node));
    tail = head;

    // Insert data into the first node
    printf("Enter data for the first node: ");
    scanf("%s", tail->data);

    // Create a loop to insert more nodes if desired
    char insert_more = 'y';
    while (insert_more == 'y') {
        // Allocate memory for a new node
        tail->next = malloc(sizeof(Node));
        tail = tail->next;

        // Insert data into the new node
        printf("Enter data for the new node: ");
        scanf("%s", tail->data);
        printf("Insert more nodes (y/n)? ");
        scanf("%c", &insert_more);
    }

    // Print the data of each node in the list
    printf("Data of each node in the list:\n");
    Node* current = head;
    while (current) {
        printf("%s\n", current->data);
        current = current->next;
    }

    // Free the memory allocated for the nodes
    free(head);

    return 0;
}