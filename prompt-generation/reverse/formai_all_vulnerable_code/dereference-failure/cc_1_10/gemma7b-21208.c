//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void summarize(Node *head) {
    Node *current = head;
    char *summary = malloc(MAX_BUFFER_SIZE);
    int summary_length = 0;

    while (current) {
        char *node_data = current->data;
        int node_data_length = strlen(node_data);

        if (node_data_length > summary_length) {
            summary_length = node_data_length;
            summary = realloc(summary, MAX_BUFFER_SIZE * summary_length);
        }

        strcat(summary, node_data);
        current = current->next;
    }

    printf("Summary:\n%s", summary);

    free(summary);
}

int main() {
    Node *head = NULL;

    // Create some sample nodes
    Node *node1 = malloc(sizeof(Node));
    node1->data = "This is the first node.";
    node1->next = NULL;

    Node *node2 = malloc(sizeof(Node));
    node2->data = "This is the second node.";
    node2->next = NULL;

    Node *node3 = malloc(sizeof(Node));
    node3->data = "This is the third node.";
    node3->next = NULL;

    head = node1;
    head->next = node2;
    head->next->next = node3;

    summarize(head);

    return 0;
}