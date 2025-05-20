//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node **head_ref, int new_data) {
    Node *new_node = create_node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node *pop(Node **head_ref) {
    Node *temp = (*head_ref);
    if (temp == NULL)
        return NULL;
    Node *next = temp->next;
    (*head_ref) = next;
    free(temp);
    return temp;
}

int search(Node *head, int x) {
    Node *current = head;
    while (current!= NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

void print_list(Node *node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    printf("Linked List: ");
    print_list(head);
    int search_data = 30;
    if (search(head, search_data))
        printf("\n%d found in the list", search_data);
    else
        printf("\n%d not found in the list", search_data);
    return 0;
}