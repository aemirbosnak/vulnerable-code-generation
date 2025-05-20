//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node *next;
} Node;

Node *create_node(char *value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%s ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    char *input = "int main(int argc, char **argv) { printf(\"Hello, world!\n\"); }";
    char *token;
    char *delim = " ";

    Node *head = NULL;

    token = strtok(input, delim);
    while (token != NULL) {
        Node *node = create_node(token);
        if (head == NULL) {
            head = node;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
        token = strtok(NULL, delim);
    }

    print_list(head);

    return 0;
}