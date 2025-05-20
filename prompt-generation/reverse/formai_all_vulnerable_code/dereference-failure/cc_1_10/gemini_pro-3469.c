//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} node_t;

node_t *create_node(char data) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error allocating memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(node_t **head, char data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

char pop(node_t **head) {
    if (*head == NULL) {
        printf("Error: stack is empty.\n");
        exit(1);
    }
    char data = (*head)->data;
    node_t *next = (*head)->next;
    free(*head);
    *head = next;
    return data;
}

int is_palindrome(char *str) {
    node_t *stack = NULL;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        push(&stack, str[i]);
    }
    if (len % 2 == 1) {
        pop(&stack);
    }
    for (int i = len / 2; i < len; i++) {
        if (pop(&stack) != str[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char *str = "racecar";
    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}