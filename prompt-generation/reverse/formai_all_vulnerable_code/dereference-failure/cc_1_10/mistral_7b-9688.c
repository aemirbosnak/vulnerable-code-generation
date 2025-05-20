//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char data[MAX_LEN];
    int count;
    struct Node *next;
} Node;

void push(Node **head, char *str) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->data, str);
    new_node->next = *head;
    new_node->count = 1;
    *head = new_node;
}

Node *pop(Node **head) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return temp;
}

int isEmpty(Node *head) {
    return head == NULL;
}

int main() {
    Node *head = NULL;
    char str[MAX_LEN];

    while (1) {
        printf("Enter a string (or type 'exit' to quit): ");
        scanf("%s", str);

        if (strcmp(str, "exit") == 0) {
            break;
        }

        push(&head, str);
    }

    Node *current = head;
    printf("\nCurrent elements in the stack: \n");

    while (!isEmpty(head)) {
        printf("%s ", current->data);
        current = pop(&head);
    }

    free(head);

    return 0;
}