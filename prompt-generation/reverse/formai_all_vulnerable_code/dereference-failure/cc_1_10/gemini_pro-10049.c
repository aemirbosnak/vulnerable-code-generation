//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_list(int *arr, int n) {
    node *head = NULL;
    node *current = NULL;

    for (int i = 0; i < n; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = arr[i];
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    return head;
}

void print_list(node *head) {
    node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void insert_at_beginning(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
}

void insert_at_index(node **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
    } else {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;

        node *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_beginning(node **head) {
    if (*head == NULL) {
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node **head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void delete_at_index(node **head, int index) {
    if (index == 0) {
        delete_at_beginning(head);
    } else {
        node *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *head = create_list(arr, n);

    printf("Original list: ");
    print_list(head);

    insert_at_beginning(&head, 0);
    printf("List after inserting at beginning: ");
    print_list(head);

    insert_at_end(&head, 6);
    printf("List after inserting at end: ");
    print_list(head);

    insert_at_index(&head, 7, 3);
    printf("List after inserting at index 3: ");
    print_list(head);

    delete_at_beginning(&head);
    printf("List after deleting at beginning: ");
    print_list(head);

    delete_at_end(&head);
    printf("List after deleting at end: ");
    print_list(head);

    delete_at_index(&head, 2);
    printf("List after deleting at index 2: ");
    print_list(head);

    return 0;
}