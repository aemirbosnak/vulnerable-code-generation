//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

//Definition of a node
struct Node {
    int data;
    struct Node* next;
};

//Insert a new node at the beginning of the linked list
void insert_beginning(struct Node** head, int new_data) {
    //Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    //Assign data to the new node
    new_node->data = new_data;
    //Point the new node to the current head of the linked list
    new_node->next = *head;
    //Point the head to the new node
    *head = new_node;
}

//Insert a new node after a given node
void insert_after(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node must not be NULL\n");
        return;
    }
    //Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    //Assign data to the new node
    new_node->data = new_data;
    //Point the new node to the next node
    new_node->next = prev_node->next;
    //Point the previous node to the new node
    prev_node->next = new_node;
}

//Insert a new node at the end of the linked list
void insert_end(struct Node** head, int new_data) {
    //Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    //Assign data to the new node
    new_node->data = new_data;
    //Make the new node the last node
    new_node->next = NULL;
    if (*head == NULL) {
        //If the linked list is empty, the new node becomes the head node
        *head = new_node;
        return;
    }
    //Iterate to the last node
    while (last->next != NULL) {
        last = last->next;
    }
    //Point the last node to the new node
    last->next = new_node;
}

//Delete a node from the linked list
void delete_node(struct Node** head, int key) {
    //Initialize the previous node to NULL
    struct Node* prev_node = NULL;
    //Initialize the current node to the head node
    struct Node* current_node = *head;
    //Iterate through the linked list to find the node with the given key
    while (current_node != NULL && current_node->data != key) {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        //If the node with the given key is not found, print an error message
        printf("Node with the given key not found\n");
        return;
    }
    if (prev_node == NULL) {
        //If the head node needs to be deleted
        *head = current_node->next;
    }
    else {
        //Point the previous node to the current node's next node
        prev_node->next = current_node->next;
    }
    //Free the memory allocated for the current node
    free(current_node);
}

//Swap two nodes of the linked list, given their data values
void swap_nodes(struct Node** head, int x, int y) {
    if (x == y) {
        return;
    }
    //Search for the nodes with the given data values, and keep track of the previous nodes
    struct Node* prev_x = NULL;
    struct Node* current_x = *head;
    while (current_x != NULL && current_x->data != x) {
        prev_x = current_x;
        current_x = current_x->next;
    }
    struct Node* prev_y = NULL;
    struct Node* current_y = *head;
    while (current_y != NULL && current_y->data != y) {
        prev_y = current_y;
        current_y = current_y->next;
    }
    if (current_x == NULL || current_y == NULL) {
        //If either of the nodes with the given data values are not present in the linked list, print an error message
        printf("One or both nodes not found\n");
        return;
    }
    if (prev_x == NULL) {
        //If the first node needs to be swapped, set the new head to the second node
        *head = current_y;
    }
    else {
        prev_x->next = current_y;
    }
    if (prev_y == NULL) {
        //If the second node needs to be swapped, set its next node to the first node's next node
        *head = current_x;
    }
    else {
        prev_y->next = current_x;
    }
    //Swap the next pointers of the two nodes
    struct Node* temp = current_x->next;
    current_x->next = current_y->next;
    current_y->next = temp;
}

//Print the linked list
void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

//Driver program to test the linked list operations
int main() {
    struct Node* head = NULL;
    //Insert some nodes at the beginning
    insert_beginning(&head, 4);
    insert_beginning(&head, 3);
    //Insert a node at the end
    insert_end(&head, 5);
    //Insert a node after the first node
    insert_after(head, 2);
    //Delete a node
    delete_node(&head, 3);
    //Print the linked list
    printf("Linked list: ");
    print_list(head);
    //Swap two nodes
    swap_nodes(&head, 4, 2);
    //Print the linked list again
    printf("Linked list after swapping: ");
    print_list(head);
    return 0;
}