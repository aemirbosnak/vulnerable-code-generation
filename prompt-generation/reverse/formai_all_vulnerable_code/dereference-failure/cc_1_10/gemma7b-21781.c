//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *insertAtTail(Node *head, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void summarizeText(Node *head) {
    char *summary = malloc(MAX_BUFFER_SIZE);
    summary[0] = '\0';

    Node *current = head;
    while (current) {
        strcat(summary, current->data);
        strcat(summary, " ");
        current = current->next;
    }

    printf("%s", summary);
    free(summary);
}

int main() {
    Node *head = NULL;

    insertAtTail(head, "This is the first sentence.");
    insertAtTail(head, "This is the second sentence.");
    insertAtTail(head, "This is the third sentence.");

    summarizeText(head);

    return 0;
}