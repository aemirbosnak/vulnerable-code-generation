//FormAI DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* A struct that represents a linked list node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to create a new node */
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a new node at the beginning of the list */
void insert_at_beginning(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

/* Function to print the elements of the list */
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

/* Function to remove duplicate elements from the list */
void remove_duplicates(Node* head) {
    Node *current, *runner, *temp;
    current = head;

    while (current != NULL && current->next != NULL) {
        runner = current;
        while (runner->next != NULL) {
            if (current->data == runner->next->data) {
                temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

/* Sample main function */
int main() {
    Node* head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 2);
    printf("Original list: ");
    print_list(head);
    remove_duplicates(head);
    printf("\nList after removing duplicates: ");
    print_list(head);
    printf("\n");
    return 0;
}