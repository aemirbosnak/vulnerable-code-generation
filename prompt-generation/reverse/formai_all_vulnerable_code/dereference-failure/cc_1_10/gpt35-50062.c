//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // define struct for linked list node
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int value) { // function to insert a value at the front of the linked list
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) { // function to print the entire linked list
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void delete(Node** head, int value) { // function to delete an element from the linked list
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) { // if the element to delete is the first element in the linked list
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) { // if the element to delete is not the first element in the linked list
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) { // if the element to delete is not present in the linked list
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    print_list(head);

    delete(&head, 30);
    delete(&head, 60);

    print_list(head);

    return 0;
}