//FormAI DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert(Node **head, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *curr_node = *head;

        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }

        curr_node->next = new_node;
    }
}

void print_list(Node *head) {
    Node *curr_node = head;

    while (curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }

    printf("\n");
}

Node *merge(Node *left, Node *right) {
    Node *result = NULL;

    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    }

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void split(Node *source, Node **left, Node **right) {
    Node *slow = source;
    Node *fast = source->next;

    while (fast != NULL) {
        fast = fast->next;

        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

void merge_sort(Node **head) {
    Node *curr_node = *head;
    Node *left = NULL;
    Node *right = NULL;

    if (curr_node == NULL || curr_node->next == NULL) {
        return;
    }

    split(curr_node, &left, &right);
    merge_sort(&left);
    merge_sort(&right);
    *head = merge(left, right);
}

int main() {
    Node *head = NULL;

    insert(&head, 9);
    insert(&head, 13);
    insert(&head, 5);
    insert(&head, 1);
    insert(&head, 7);

    printf("Unsorted list: ");
    print_list(head);

    merge_sort(&head);

    printf("Sorted list: ");
    print_list(head);

    return 0;
}