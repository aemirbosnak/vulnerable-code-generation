//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char data;
    struct _node *next;
} Node;

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_list(Node *head) {
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        printf("%c -> ", curr->data);
    }
    printf("NULL\n");
}

Node *create_node(char data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        error_exit("Out of memory!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void append(Node **head_ref, char new_data) {
    Node *new_node = create_node(new_data);

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node *last = *head_ref;

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

int main(int argc, char **argv) {
    Node *head = NULL;

    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; argv[1][i] != '\0'; ++i) {
        append(&head, argv[1][i]);
    }

    print_list(head);

    Node *curr = head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}