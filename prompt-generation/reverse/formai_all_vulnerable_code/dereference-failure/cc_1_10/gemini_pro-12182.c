//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

node *parse(char *input) {
    node *head = NULL;
    node *tail = NULL;

    char *token = strtok(input, " ");
    while (token != NULL) {
        node *new_node = malloc(sizeof(node));
        new_node->data = token;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            tail->next = new_node;
        }

        tail = new_node;

        token = strtok(NULL, " ");
    }

    return head;
}

void print(node *head) {
    node *current = head;

    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }

    printf("\n");
}

void free_list(node *head) {
    node *current = head;

    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    char *input = "This is a test of the parser";

    node *head = parse(input);
    print(head);
    free_list(head);

    return 0;
}