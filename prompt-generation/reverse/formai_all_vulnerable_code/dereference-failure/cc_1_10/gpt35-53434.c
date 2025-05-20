//FormAI DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    int data;
    struct node* next;
};

// Linked List Initialization
struct node* head = NULL;

// Function to Insert Node at the Beginning of Linked List
void insert_beginning(int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = head;

    head = new_node;
}

// Function to Insert Node at the End of Linked List
void insert_end(int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* ptr = head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;
}

// Function to Delete Node from Linked List
void delete_node(int key) {
    struct node* temp = head;
    struct node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

// Function to Traverse the Linked List and Print the Values
void print_list() {
    struct node* ptr = head;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Main Function
int main() {
    // Inserting Nodes at the Beginning of Linked List
    insert_beginning(10);
    insert_beginning(20);
    insert_beginning(30);
    insert_beginning(40);
    insert_beginning(50);

    printf("Linked List after Inserting Nodes at the Beginning: ");
    print_list();
    printf("\n");

    // Deleting Node from Linked List
    delete_node(30);

    printf("Linked List after Deleting Node with Value 30: ");
    print_list();
    printf("\n");

    // Inserting Nodes at the End of Linked List
    insert_end(60);
    insert_end(70);
    insert_end(80);

    printf("Linked List after Inserting Nodes at the End: ");
    print_list();
    printf("\n");

    return 0;
}