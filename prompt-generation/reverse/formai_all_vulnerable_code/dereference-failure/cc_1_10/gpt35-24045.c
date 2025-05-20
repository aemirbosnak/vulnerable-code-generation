//FormAI DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void add_node(Node **head, int value) {
    // create a new node
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(Node *head) {
    Node *current = head;
    printf("[ ");

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("]\n");
}

void free_list(Node **head) {
    Node *current = *head;
    while(current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    // create an empty linked list
    Node* head = NULL;

    // add elements to the list
    add_node(&head, 4);
    add_node(&head, 9);
    add_node(&head, 2);
    add_node(&head, 8);

    // print the list
    printf("Original list:\n");
    print_list(head);

    // insert an element at the front
    Node* new_head = malloc(sizeof(Node));
    new_head->data = 1;
    new_head->next = head;
    head = new_head;

    // print the list again
    printf("\nList after inserting at the front:\n");
    print_list(head);

    // remove an element from the list
    Node* current = head;
    Node* prev = NULL;
    int target = 2;

    while(current != NULL) {
        if(current->data == target) {
            break;
        }
        prev = current;
        current = current->next;
    }

    if(current != NULL) {
        if(prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }

    // print the list one last time
    printf("\nList after removing an element:\n");
    print_list(head);

    // free all memory allocated for the list
    free_list(&head);

    return 0;
}