//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

//Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

//Function prototypes
void init_list(Node** head);
void add_node(Node** head, int data);
void delete_node(Node** head, int data);
void print_list(Node* head);

int main() {
    Node* head = NULL;
    init_list(&head);
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    print_list(head);
    delete_node(&head, 20);
    print_list(head);
    return 0;
}

//Function to initialize an empty list
void init_list(Node** head) {
    *head = NULL;
}

//Function to add a node to the end of the list
void add_node(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

//Function to delete a node with a given data value
void delete_node(Node** head, int data) {
    Node* curr_node = *head;
    Node* prev_node = NULL;
    while (curr_node!= NULL && curr_node->data!= data) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (curr_node == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    if (prev_node == NULL) {
        *head = curr_node->next;
    }
    else {
        prev_node->next = curr_node->next;
    }
    free(curr_node);
}

//Function to print the list
void print_list(Node* head) {
    Node* curr_node = head;
    printf("List: ");
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}