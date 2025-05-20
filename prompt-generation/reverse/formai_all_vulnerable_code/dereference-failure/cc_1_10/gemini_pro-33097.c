//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_list(int n) {
    node *head = NULL;
    for (int i = n; i > 0; i--) {
        node *new_node = malloc(sizeof(node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node *reverse_list(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *new_head = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    node *head = create_list(n);
    printf("Original list: ");
    print_list(head);

    head = reverse_list(head);
    printf("Reversed list: ");
    print_list(head);

    return 0;
}