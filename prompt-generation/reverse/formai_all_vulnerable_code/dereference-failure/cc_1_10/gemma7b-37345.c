//Gemma-7B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *insert(Node *head, char *data) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode) {
        newNode->data = strdup(data);
        newNode->next = NULL;

        if (head) {
            head->next = newNode;
        } else {
            head = newNode;
        }
    }

    return head;
}

void free_list(Node *head) {
    Node *current = head;
    Node *next = NULL;

    while (current) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

int main() {
    Node *head = NULL;

    char *data = "Hello, world!";
    head = insert(head, data);

    data = "Goodbye, cruel world!";
    insert(head, data);

    free_list(head);

    return 0;
}