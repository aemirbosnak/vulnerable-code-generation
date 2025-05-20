//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_list(int *arr, int size) {
    node *head = NULL;
    node *curr = NULL;
    for (int i = 0; i < size; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = arr[i];
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            curr = head;
        } else {
            curr->next = new_node;
            curr = new_node;
        }
    }
    return head;
}

void print_list(node *head) {
    node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

node *insert_at_beginning(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

node *insert_at_end(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return head;
    }
    node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

node *insert_at_index(node *head, int data, int index) {
    if (index == 0) {
        return insert_at_beginning(head, data);
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    node *curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

node *delete_from_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *new_head = head->next;
    free(head);
    return new_head;
}

node *delete_from_end(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}

node *delete_from_index(node *head, int index) {
    if (index == 0) {
        return delete_from_beginning(head);
    }
    node *curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = create_list(arr, size);
    print_list(head);  // 1 2 3 4 5
    head = insert_at_beginning(head, 0);
    print_list(head);  // 0 1 2 3 4 5
    head = insert_at_end(head, 6);
    print_list(head);  // 0 1 2 3 4 5 6
    head = insert_at_index(head, 3, 2);
    print_list(head);  // 0 1 2 3 4 3 5 6
    head = delete_from_beginning(head);
    print_list(head);  // 1 2 3 4 3 5 6
    head = delete_from_end(head);
    print_list(head);  // 1 2 3 4 3 5
    head = delete_from_index(head, 2);
    print_list(head);  // 1 2 4 3 5
    return 0;
}