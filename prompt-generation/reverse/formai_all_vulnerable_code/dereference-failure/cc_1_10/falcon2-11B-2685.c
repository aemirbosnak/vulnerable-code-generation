//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: relaxed
// A simple linked list implementation in C
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insert_at_beginning(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    struct Node* temp = *head;
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Function to delete a node from the list
void delete_node(struct Node** head, int data) {
    struct Node* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp->next!= NULL && temp->next->data!= data)
            temp = temp->next;
        if (temp->next == NULL)
            return;
        struct Node* del_node = temp->next;
        temp->next = temp->next->next;
        free(del_node);
    }
}

// Function to print the list
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the length of the list
int list_length(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);

    printf("List before deleting 10: ");
    print_list(head);
    delete_node(&head, 10);

    printf("\nList after deleting 10: ");
    print_list(head);

    printf("\nLength of the list: %d\n", list_length(head));

    return 0;
}