//Gemma-7B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *insert_node(Node *head, char *data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = strdup(data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    Node *head = NULL;

    char *data = malloc(10);
    if (data == NULL) {
        return EXIT_FAILURE;
    }

    data = "Hello, world!";

    insert_node(head, data);

    if (head != NULL) {
        printf("%s", head->data);
    } else {
        perror("Error inserting node");
    }

    free(data);
    free(head);

    return EXIT_SUCCESS;
}