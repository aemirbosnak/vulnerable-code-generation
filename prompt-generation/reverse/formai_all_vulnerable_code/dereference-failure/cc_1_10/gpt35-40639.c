//FormAI DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>

// define the structure of a linked list node
struct node {
    int data;
    struct node* next;
};

// initialize the linked list to be empty
struct node* head = NULL;

// function to add a node to the front of the linked list
void insert_front(int num) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = head;
    head = new_node;
}

// function to print out the linked list
void print_list() {
    struct node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // insert some nodes into the linked list
    insert_front(3);
    insert_front(6);
    insert_front(1);

    // print out the linked list
    print_list();

    // add some more nodes to the linked list
    insert_front(9);
    insert_front(2);
    insert_front(7);

    // print out the linked list again
    print_list();

    // delete the first node from the linked list
    head = head->next;

    // print out the linked list again
    print_list();

    // delete the second node from the linked list
    head->next = head->next->next;

    // print out the linked list again
    print_list();

    return 0;
}