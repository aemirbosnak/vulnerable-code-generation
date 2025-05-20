//FormAI DATASET v1.0 Category: Linked list operations ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *next;
};

// Define function prototypes
struct node *create(int);
struct node *insert_beginning(struct node *, int);
struct node *insert_end(struct node *, int);
struct node *delete(struct node *, int);
void display(struct node *);

int main() {
    struct node *head = NULL;
    
    // Create three nodes
    head = create(10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    
    // Display the initial list
    printf("Initial List: ");
    display(head);
    
    // Insert a node at the beginning
    head = insert_beginning(head, 5);
    printf("\nList after inserting 5 at the beginning: ");
    display(head);
    
    // Insert a node at the end
    head = insert_end(head, 40);
    printf("\nList after inserting 40 at the end: ");
    display(head);
    
    // Delete a node
    head = delete(head, 20);
    printf("\nList after deleting 20: ");
    display(head);
    
    return 0;
}

// Function to create a new node
struct node *create(int val) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning
struct node *insert_beginning(struct node *head, int val) {
    struct node *new_node = create(val);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end
struct node *insert_end(struct node *head, int val) {
    struct node *new_node = create(val);
    if(head == NULL) {
        head = new_node;
        return head;
    }
    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to delete a node
struct node *delete(struct node *head, int val) {
    if(head == NULL) {
        printf("List is empty.");
        return head;
    }
    if(head->data == val) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node *temp = head;
    while(temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if(temp->next == NULL) {
        printf("Element not found.");
        return head;
    }
    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
    return head;
}

// Function to display the list
void display(struct node *head) {
    if(head == NULL) {
        printf("List is empty.");
        return;
    }
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}